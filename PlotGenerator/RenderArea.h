#pragma once

#include <QWidget>
#include <vector>
#include <PlotEntity.h>
#include <QBrush>
#include <QPen>
#include <array>

using namespace std;

class RenderArea : public QWidget
{
	Q_OBJECT

public:
	vector<PlotEntity>* pEntities = nullptr;
	QPen pen = QPen(palette().dark().color());
	QBrush brush = QBrush(Qt::NoBrush);

	array<float, 4>  boundingBox;
	int dx = 0;
	int dy = 0;
	float theta = 0;
	array<int, 2> screenSize = { 1, 1 };
	//float scale = 1;

public:
	RenderArea(QWidget *parent = 0);
	~RenderArea();

	void draw_entities();
	void draw_entity(QPainter& painter, PlotEntity& entity);
	void draw_screen(QPainter& painter);
	void draw_bounding_box(QPainter& painter);

	void transform_painter(QPainter& painter, float cx, float cy, float scale);
	float calculate_scale_to_fit_screen();
	array<float, 2> calculate_center_for_draw();

public slots:

protected:
	void paintEvent(QPaintEvent *event) override;
};
