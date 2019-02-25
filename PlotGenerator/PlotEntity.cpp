#include "PlotEntity.h"



PlotEntity::PlotEntity()
{
}


PlotEntity::PlotEntity(int ID, float x, float y, float r, float red, float green, float blue)
{
	m_ID = ID;
	m_x = x;
	m_y = y;
	m_r = r;

	m_color = QColor(red * 255, green * 255, blue * 255);
}

PlotEntity::~PlotEntity()
{
}
