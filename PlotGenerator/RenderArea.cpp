#include "RenderArea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
	: QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
}

RenderArea::~RenderArea()
{
}



void RenderArea::draw_entities()
{
	QPainter painter(this);
	float scale = calculate_scale_to_fit_screen();
	transform_painter(painter, width() / 2, height() / 2, scale);
	painter.setPen(pen);
	painter.setBrush(brush);

	if (pEntities != nullptr)
	{
		array<float, 2> centerForDraw = calculate_center_for_draw();
		for (auto& plotEntity : *pEntities)
		{
			draw_entity(painter, plotEntity);
		}
		draw_bounding_box(painter);
	}

	draw_screen(painter);
}



void RenderArea::draw_entity(QPainter& painter, PlotEntity& entity)
{
	painter.save();

	float x = entity.get_X() - (boundingBox.at(0) + boundingBox.at(1)) / 2;
	float y = entity.get_Y() - (boundingBox.at(2) + boundingBox.at(3)) / 2;
	float transformedX = x*cos(theta)+y*sin(theta)+dx;
	float transformedY = -x * sin(theta) + y * cos(theta) + dy;

	painter.translate(transformedX, -transformedY);
	painter.drawRect(QRect(-1.5, -1.5, 3, 3));
	//painter.drawPoint(0, 0);
	painter.restore();
}



void RenderArea::draw_screen(QPainter& painter)
{
	painter.setPen(palette().dark().color());
	painter.setBrush(Qt::NoBrush);
	painter.drawRect(QRect(-screenSize.at(0) / 2, -screenSize.at(1) / 2, screenSize.at(0), screenSize.at(1)));
}



void RenderArea::draw_bounding_box(QPainter& painter)
{
	painter.setPen(palette().dark().color());
	painter.setBrush(Qt::NoBrush);

	float right = (boundingBox.at(0) - boundingBox.at(1))/2;
	float up = (boundingBox.at(2) - boundingBox.at(3))/2;
	array<float, 2> rotateRU = { right*cos(theta) + up * sin(theta), -right * sin(theta) + up * cos(theta) };
	array<float, 2> rotateLU = { -right*cos(theta) + up * sin(theta), right * sin(theta) + up * cos(theta) };
	array<float, 2> rotateLD = { -right * cos(theta) + -up * sin(theta), right * sin(theta) + -up * cos(theta) };
	array<float, 2> rotateRD = { right * cos(theta) + -up * sin(theta), -right * sin(theta) + -up * cos(theta) };

	painter.drawLine(rotateRU.at(0)+dx, -rotateRU.at(1)-dy, rotateLU.at(0) + dx, -rotateLU.at(1) - dy);
	painter.drawLine(rotateLU.at(0) + dx, -rotateLU.at(1) - dy, rotateLD.at(0) + dx, -rotateLD.at(1) - dy);
	painter.drawLine(rotateLD.at(0) + dx, -rotateLD.at(1) - dy, rotateRD.at(0) + dx, -rotateRD.at(1) - dy);
	painter.drawLine(rotateRD.at(0) + dx, -rotateRD.at(1) - dy, rotateRU.at(0) + dx, -rotateRU.at(1) - dy);

	//painter.drawRect(QRect(rotateRU.at(0)+dx, -(rotateRU.at(1)+dy), -2*rotateRU.at(0)+dx, -(-2*rotateRU.at(1)+dy)));
}



void RenderArea::transform_painter(QPainter& painter, float cx, float cy, float scale)
{
	painter.translate(cx, cy);
	painter.scale(scale, scale);
}



float RenderArea::calculate_scale_to_fit_screen()
{
	float wScale = width() / screenSize.at(0);
	float hScale = height() / screenSize.at(1);

	if (wScale > hScale)
		return hScale;
	else
		return wScale;
}



array<float, 2> RenderArea::calculate_center_for_draw()
{
	float cx = -(boundingBox.at(0) + boundingBox.at(1)) / 2 + dx;
	float cy = -(boundingBox.at(2) + boundingBox.at(3)) / 2 + dy;
	return { cx, cy };
}



void RenderArea::paintEvent(QPaintEvent *event)
{
	draw_entities();
}
