#include "PlotGenerator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PlotGenerator w;
	w.show();
	return a.exec();
}
