#pragma once

#include <QColor>

class PlotEntity
{
private:
	int m_ID = -1;
	float m_x = 0;
	float m_y = 0;
	float m_r = 0;
	QColor m_color;

public:
	PlotEntity();
	PlotEntity(int ID, float x, float y, float r, float red, float green, float blue);
	virtual ~PlotEntity();

	int get_ID() const { return m_ID; }
	float get_X() const { return m_x; }
	float get_Y() const { return m_y; }
	float get_R() const { return m_r; }
	QColor get_color() const { return m_color; }

	void set_X(float x) { m_x = x; }
	void set_Y(float y) { m_y = y; }
	void set_R(float r) { m_r = r; }
	void set_color(QColor color) { m_color = color; }
};

