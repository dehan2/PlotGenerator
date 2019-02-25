#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PlotGenerator.h"
#include <vector>
#include "PlotEntity.h"
#include <string>
#include <QFileInfo>

using namespace std;

class PlotGenerator : public QMainWindow
{
	Q_OBJECT

private:
	QFileInfo m_bcfFileInfo;
	vector<PlotEntity> m_entities;
	array<float, 4>  m_boundingBox;
	int m_dx = 0;
	int m_dy = 0;
	float m_theta = 0;
	array<int, 2> m_screenSize = { 0, 0 };

public:
	PlotGenerator(QWidget *parent = Q_NULLPTR);
	string translate_to_window_path(const QString& QfilePath) const;
	void calculate_bounding_box();
	

public slots:
	void load_bcf_file();
	void update_screen();
	void plot_edited();
	void save_plot_file();

private:
	Ui::PlotGeneratorClass ui;
};
