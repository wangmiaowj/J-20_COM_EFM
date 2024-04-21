#pragma once
#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "CockpitAPI_Declare.h"
#include "Maths.h"
//=========================================================================//
//
//		FILE NAME	: Table.h
//		AUTHOR		: Joshua Nelson
//		Copyright	: Joshua Nelson
//		DATE		: May 2020
//
//		DESCRIPTION	:	Vec3 class with added operator overloads to make maths easier.
//
//================================ Includes ===============================//
//=========================================================================//

class Table
{
public:
	Table(const std::vector<double>& table, double min, double max) :
		m_table(table),
		m_min(min),
		m_max(max)
	{
		m_dx = (max - min) / ((double)table.size() - 1);
		m_minIndex = min / m_dx;
	}

	double operator()(double value)
	{

		if (m_table.size() == 1)
			return m_table[0];

		double index = (value - m_min) / m_dx;

		int lower = floor(index);
		int upper = ceil(index);

		if (lower == upper)
			upper++;

		if (lower < 0)
			return m_table.front();
		if (upper >= m_table.size())
			return m_table.back();

		double lowerX = (double)lower * m_dx + m_min;
		double upperX = (double)upper * m_dx + m_min;

		return (value - lowerX) * ((m_table[upper] - m_table[lower]) / (upperX - lowerX)) + m_table[lower];
	}

private:
	const std::vector<double> m_table;
	double m_dx;
	double m_min;
	double m_max;
	int m_minIndex;
};

class ZeroTable
{
public:
	ZeroTable(const std::vector<double>& table, double min, double max) :
		m_table(table),
		m_min(min),
		m_max(max)
	{
		m_dx = (max - min) / ((double)table.size() - 1);
		m_minIndex = min / m_dx;
	}

	double operator()(double value)
	{

		if (m_table.size() == 1)
			return m_table[0];

		double index = (value - m_min) / m_dx;

		int lower = floor(index);
		int upper = ceil(index);

		if (lower == upper)
			upper++;

		if (lower < 0)
		{
			return (value - m_min) * (m_table.front() / m_min) + m_table.front();
		}
		if (upper >= m_table.size())
			return m_table.back();

		double lowerX = (double)lower * m_dx + m_min;
		double upperX = (double)upper * m_dx + m_min;

		return (value - lowerX) * ((m_table[upper] - m_table[lower]) / (upperX - lowerX)) + m_table[lower];
	}

private:
	const std::vector<double> m_table;
	double m_dx;
	double m_min;
	double m_max;
	int m_minIndex;
};


class EdParam
{
public:
	EdParam() :
		param(0),
		tg(-128),
		tgText("NULL"),
		cur(-128),
		dt(-128),
		mode(0),
		min(0),
		max(1)
	{

	}
	EdParam(void* paramHandle, double target, double current, double rate) :
		param(paramHandle),
		tg(target),
		tgText("NULL"),
		cur(current),
		dt(rate),
		mode(1),
		min(0),
		max(1)
	{

	}
	EdParam(void* paramHandle, double target, double current, double rate, double min, double max) :
		param(paramHandle),
		tg(target),
		tgText("NULL"),
		cur(current),
		dt(rate),
		mode(1),
		min(min),
		max(max)
	{

	}
	EdParam(void* paramHandle, double target) :
		param(paramHandle),
		tg(target),
		tgText("NULL"),
		cur(-128),
		dt(-128),
		mode(0),
		min(0),
		max(1)
	{

	}
	EdParam(void* paramHandle, const char* target) :
		param(paramHandle),
		tgText(target),
		tg(-128),
		cur(-128),
		dt(-128),
		mode(2),
		min(0),
		max(1)
	{

	}
	void update(EDPARAM& cockpitAPI)
	{
		if (mode == 1)
		{
			if (abs(tg - cur) < dt)
			{
				cur = tg;
			}
			else if (tg > cur)
			{
				cur = clamp(cur + dt, min, max);
			}
			else if (tg < cur)
			{
				cur = clamp(cur - dt, min, max);
			}
			cockpitAPI.setParamNumber(param, cur);
		}
		else if (mode == 0)
		{
			cockpitAPI.setParamNumber(param, tg);
		}
		else
		{
			cockpitAPI.setParamString(param, tgText);
		}
	}
	void* param;
	double tg;
	const char* tgText;
	double cur;
	double dt;
	double min, max;
	int mode;//0 直接更新tg，1更新cur，2更新text
private:

};


#endif
