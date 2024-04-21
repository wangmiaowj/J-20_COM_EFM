#pragma once
#include <vector>
#include "include/FM/wHumanCustomPhysicsAPI.h"
class LERX
{
public:
	LERX(std::vector<LERX_vortex_spline_point> points) :
		m_points(points)
	{

	}

	inline void setOpacity(double opacity)
	{
		m_opacity = opacity;
	}

	inline double getOpacity() const
	{
		return m_opacity;
	}

	inline LERX_vortex_spline_point* getArrayPointer()
	{
		return (m_points.size() && m_opacity != 0.0) ? &m_points[0] : (LERX_vortex_spline_point*)NULL;
	}

	inline size_t size() const
	{
		return m_points.size();
	}

private:
	std::vector<LERX_vortex_spline_point> m_points;
	double m_opacity = 0.0;
};