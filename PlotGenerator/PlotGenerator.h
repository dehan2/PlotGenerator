#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PlotGenerator.h"

class PlotGenerator : public QMainWindow
{
	Q_OBJECT

public:
	PlotGenerator(QWidget *parent = Q_NULLPTR);

private:
	Ui::PlotGeneratorClass ui;
};
