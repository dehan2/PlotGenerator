#include "PlotGenerator.h"
#include <sstream>
#include <fstream>
#include <QFileDialog>
#include <iostream>
#include <random>
#include <ctime>

#define _USE_MATH_DEFINES
#include <math.h>

PlotGenerator::PlotGenerator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	update_screen();
	plot_edited();
	showMaximized();
}



string PlotGenerator::translate_to_window_path(const QString& QfilePath) const
{
	string filePath = QfilePath.toLocal8Bit();

	size_t i = filePath.find('/');
	while (i != string::npos)
	{
		string part1 = filePath.substr(0, i);
		string part2 = filePath.substr(i + 1);
		filePath = part1 + R"(\)" + part2; // Use "\\\\" instead of R"(\\)" if your compiler doesn't support C++11's raw string literals
		i = filePath.find('/', i + 1);
	}
	return filePath;
}


void PlotGenerator::calculate_bounding_box()
{
	m_boundingBox = { -FLT_MAX, FLT_MAX, -FLT_MAX, FLT_MAX };

	for (auto& entity : m_entities)
	{
		m_boundingBox.at(0) = entity.get_X() > m_boundingBox.at(0) ? entity.get_X() : m_boundingBox.at(0);
		m_boundingBox.at(1) = entity.get_X() < m_boundingBox.at(1) ? entity.get_X() : m_boundingBox.at(1);
		m_boundingBox.at(2) = entity.get_Y() > m_boundingBox.at(2) ? entity.get_Y() : m_boundingBox.at(2);
		m_boundingBox.at(3) = entity.get_Y() < m_boundingBox.at(3) ? entity.get_Y() : m_boundingBox.at(3);
	}

	ui.label_plot_width->setText(QString::number(m_boundingBox.at(0) - m_boundingBox.at(1)));
	ui.label_plot_height->setText(QString::number(m_boundingBox.at(2) - m_boundingBox.at(3)));
	ui.renderArea->boundingBox = m_boundingBox;
	ui.renderArea->update();
}



void PlotGenerator::load_bcf_file()
{
	QString QfilePath = QFileDialog::getOpenFileName(this, tr("Open BCF File"), NULL, tr("BCF file(*.bcf)"));
	m_bcfFileInfo = QFileInfo(QfilePath);

	string filePath = translate_to_window_path(QfilePath);
	ifstream bcfFile(filePath.data());
	if (bcfFile.is_open()) 
	{
		string line;
		int index = 0;
		while (getline(bcfFile, line))
		{
			istringstream iss(line);
			string token;
			iss >> token;
			if (token.compare(string("#")) == 0)
				continue;

			if (m_entities.size() == 0) //first line
			{
				m_entities.resize(stoi(token));
			}
			else if(token.size() > 0) //plot files
			{
				int ID = stoi(token);
				iss >> token;
				float x = stof(token);
				iss >> token;
				float y = stof(token);
				iss >> token;
				float r = stof(token);
				iss >> token;
				float red = stof(token);
				iss >> token;
				float green = stof(token);
				iss >> token;
				float blue = stof(token);

				m_entities.at(index) = PlotEntity(index+1, x, y, r, red, green, blue);
				index++;
			}
		}
		cout << "BCF read finish: " <<m_entities.size()<< endl;
		bcfFile.close();
		ui.label_num_entities->setText(QString::number(m_entities.size()));
		ui.renderArea->pEntities = &m_entities;
		calculate_bounding_box();
	}
	else
		cout << "Fail to read BCF file" << endl;

	ui.renderArea->update();
}



void PlotGenerator::update_screen()
{
	int width = ui.lineEdit_screen_width->text().toInt();
	int height = ui.lineEdit_screen_height->text().toInt();
	m_screenSize = { width, height };
	ui.renderArea->screenSize = m_screenSize;
	ui.renderArea->update();
}



void PlotGenerator::plot_edited()
{
	m_dx = ui.lineEdit_dx->text().toInt();
	m_dy = ui.lineEdit_dy->text().toInt();
	float angle = -ui.lineEdit_theta->text().toFloat();
	m_theta = angle / 180 * M_PI;
	ui.renderArea->dx = m_dx;
	ui.renderArea->dy = m_dy;
	ui.renderArea->theta = m_theta;
	ui.renderArea->update();
}



void PlotGenerator::save_plot_file()
{
	default_random_engine engine;
	engine.seed(time(0));
	uniform_real_distribution<> dist;

	string bcfDirectory = translate_to_window_path(m_bcfFileInfo.absoluteDir().absolutePath());
	string bcfFileName = m_bcfFileInfo.fileName().section(".", 0, 0).toLocal8Bit();
	string plotFilePath = bcfDirectory + string("\\") + bcfFileName + string(".plot");
	ofstream plotFile(plotFilePath);
	plotFile << m_entities.size() << "\n";
	for (auto& entity : m_entities)
	{
		QColor color = entity.get_color();
		array<double, 4> rgb = { 0, 0, 0 };
		color.getRgbF(&rgb.at(0), &rgb.at(1), &rgb.at(2));

		float x = entity.get_X() - (m_boundingBox.at(0) + m_boundingBox.at(1)) / 2;
		float y = entity.get_Y() - (m_boundingBox.at(2) + m_boundingBox.at(3)) / 2;
		float transformedX = x * cos(m_theta) + y * sin(m_theta) + m_dx;
		float transformedY = -x * sin(m_theta) + y * cos(m_theta) + m_dy;

		plotFile << entity.get_ID() << "\t" << transformedX + 0.1*dist(engine) << "\t" << transformedY+ 0.1*dist(engine) << "\t" << 0.1*dist(engine) << "\t" << 0 << "\t" << rgb.at(0) << "\t" << rgb.at(1) << "\t" << rgb.at(2) << "\n";
	}
	plotFile.close();
}
