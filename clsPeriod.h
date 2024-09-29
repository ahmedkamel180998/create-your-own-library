#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsPeriod
{
public:
	clsDate dateFrom;
	clsDate dateTo;
	clsPeriod(clsDate dateFrom, clsDate dateTo)
	{
		this->dateFrom = dateFrom;
		this->dateTo = dateTo;
	}

	void Print()
	{
		cout << "Period Start: ";
		dateFrom.print();

		cout << "Period End: ";
		dateTo.print();
	}

	static bool isOverlapPeriods(clsPeriod period1, clsPeriod period2)
	{
		if
			((clsDate::compareDates(period2.dateTo, period1.dateFrom) == clsDate::before)
				||
				(clsDate::compareDates(period2.dateFrom, period1.dateTo) == clsDate::after)
				)
		{
			return false;
		}
		else
			return true;
	}
	bool isOverlapPeriods(clsPeriod period2)
	{
		return isOverlapPeriods(*this, period2);
	}

	static unsigned short periodLength(clsPeriod period, bool includeEndDate = false)
	{
		return clsDate::calculateDiffInDays(period.dateFrom, period.dateTo, includeEndDate);
	}
	unsigned short periodLength(bool includeEndDate = false)
	{
		return periodLength(*this, includeEndDate);
	}

	static bool isDateWithinPeriod(clsPeriod period1, clsDate date1)
	{
		return ((!clsDate::isBefore(date1, period1.dateFrom) || clsDate::isEqual(date1, period1.dateFrom)) && (clsDate::isBefore(date1, period1.dateTo) || clsDate::isEqual(date1, period1.dateTo)));
	}
	bool isDateWithinPeriod(clsDate date1)
	{
		return isDateWithinPeriod(*this, date1);
	}

	static clsDate getOverlapStart(clsPeriod period1, clsPeriod period2)
	{
		if (clsDate::compareDates(period1.dateFrom, period2.dateFrom) == clsDate::before)
			return period2.dateFrom;
		else if (clsDate::compareDates(period1.dateFrom, period2.dateFrom) == clsDate::after)
			return period1.dateFrom;
		else if (clsDate::compareDates(period1.dateFrom, period2.dateFrom) == clsDate::equal)
			return period1.dateFrom;
	}
	clsDate getOverlapStart(clsPeriod period2)
	{
		return getOverlapStart(*this, period2);
	}

	static clsDate getOverlapEnd(clsPeriod period1, clsPeriod period2)
	{
		if (clsDate::compareDates(period1.dateTo, period2.dateTo) == clsDate::after)
			return period2.dateTo;
		else if (clsDate::compareDates(period1.dateTo, period2.dateTo) == clsDate::before)
			return period1.dateTo;
		else if (clsDate::compareDates(period1.dateTo, period2.dateTo) == clsDate::equal)
			return period1.dateTo;
	}
	clsDate getOverlapEnd(clsPeriod period2)
	{
		return getOverlapEnd(*this, period2);
	}

	static unsigned short overlapDays(clsDate overlapStart, clsDate overlapEnd)
	{
		return clsDate::calculateDiffInDays(overlapStart, overlapEnd, true);
	}
};
