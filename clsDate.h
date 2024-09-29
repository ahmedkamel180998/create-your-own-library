#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "clsString.h"
using namespace std;

class clsDate
{
	unsigned short _day;
	unsigned short _month;
	unsigned short _year;
public:
	enum enCompareDatesCases
	{
		before = -1,
		equal = 0,
		after = 1
	};
	// date constructors
	clsDate()
	{
		*this = getCurrentDate();
	}
	clsDate(string userDate)
	{
		*this = convertDateStringToClass(userDate);

	}
	clsDate(unsigned short userDay, unsigned short userMonth, unsigned short userYear)
	{
		_day = userDay;
		_month = userMonth;
		_year = userYear;
	}
	clsDate(unsigned short daysFromBeginning, unsigned short userYear)
	{
		*this = calculateSpecificDateFromDays(daysFromBeginning, userYear);
	}

	// set and get properties
	void setDay(unsigned short userDay)
	{
		_day = userDay;
	}
	unsigned short getDay()
	{
		return _day;
	}
	__declspec(property(get = getDay, put = setDay)) unsigned short day;
	void setMonth(unsigned short userMonth)
	{
		_month = userMonth;
	}
	unsigned short getMonth()
	{
		return _month;
	}
	__declspec(property(get = getMonth, put = setMonth)) unsigned short month;
	void setYear(unsigned short userYear)
	{
		_year = userYear;
	}
	unsigned short getYear()
	{
		return _year;
	}
	__declspec(property(get = getYear, put = setYear)) unsigned short year;

	// read functions
	unsigned short readNumber(string message)
	{
		unsigned short number = 0;
		while (number <= 0)
		{
			cout << message;
			cin >> number;
		}
		return number;
	}

	unsigned short readNumber(string message, unsigned short from, unsigned short to)
	{
		unsigned short number = 0;
		while (number < from || number > to)
		{
			cout << message;
			cin >> number;
		}
		return number;
	}

	unsigned short readDaysInMonth(unsigned short userYear, unsigned short userMonth)
	{
		unsigned short maxDaysInMonth = calculateDaysInMonth(userYear, userMonth);
		return readNumber("\nPlease Enter Your Day From [1 to " + to_string(maxDaysInMonth) + "] ?    ", 1, maxDaysInMonth);
	}

	// print date string
	static clsDate convertDateStringToClass(string userDate, string delimiter = "/")
	{
		unsigned short day, month, year;
		vector <string> splitWords = clsString::split(userDate, delimiter);
		day = stoi(splitWords[0]);
		month = stoi(splitWords[1]);
		year = stoi(splitWords[2]);
		return clsDate(day, month, year);
	}

	static string dateToString(clsDate date)
	{
		string dateString = "";
		dateString += to_string(date.day) + "/";
		dateString += to_string(date.month) + "/";
		dateString += to_string(date.year);
		return dateString;
	}
	string dateToString()
	{
		return dateToString(*this);
	}

	void print()
	{
		cout << "Date: " << dateToString() << endl;
		cout << "----------------\n" << endl;
	}

	// date validation
	static clsDate getCurrentDate()
	{
		unsigned short day, month, year;
		time_t localTime = time(0);
		tm* ptrTime = localtime(&localTime);
		year = ptrTime->tm_year + 1900;
		month = ptrTime->tm_mon + 1;
		day = ptrTime->tm_mday;
		return clsDate(day, month, year);
	}

	static bool validateLeapYear(unsigned short userYear)
	{
		return (((userYear % 4) == 0) && ((userYear % 100) != 0)) || ((userYear % 400) == 0);
	}
	bool validateLeapYear()
	{
		return validateLeapYear(year);
	}

	static bool isValidDate(clsDate userDate)
	{
		return (userDate.month >= 1 && userDate.month <= 12) ? (userDate.day <= calculateDaysInMonth(userDate.year, userDate.month) ? true : false) : false;
	}
	bool isValidDate()
	{
		return isValidDate(*this);
	}

	// calculate [days - hours - minutes - seconds] in year - month
	static unsigned short calculateDaysInYear(unsigned short userYear)
	{
		return (validateLeapYear(userYear)) ? 366 : 365;
	}
	unsigned short calculateDaysInYear()
	{
		return calculateDaysInYear(year);
	}

	static unsigned short calculateHoursInYear(unsigned short userYear)
	{
		return calculateDaysInYear(userYear) * 24;
	}
	unsigned short calculateHoursInYear()
	{
		return calculateHoursInYear(year);
	}

	static unsigned int calculateMinutesInYear(unsigned short userYear)
	{
		return calculateHoursInYear(userYear) * 60;
	}
	unsigned int calculateMinutesInYear()
	{
		return calculateMinutesInYear(year);
	}

	static unsigned int calculateSecondsInYear(unsigned short userYear)
	{
		return calculateMinutesInYear(userYear) * 60;
	}
	unsigned int calculateSecondsInYear()
	{
		return calculateSecondsInYear(year);
	}

	static unsigned short calculateDaysInMonth(unsigned short userYear, unsigned short userMonth)
	{
		return (userMonth == 4) || (userMonth == 6) || (userMonth == 9) || (userMonth == 11) ? 30 : (userMonth != 2) ? 31 : (validateLeapYear(userYear)) ? 29 : 28;
	}
	unsigned short calculateDaysInMonth()
	{
		return calculateDaysInMonth(year, month);
	}

	static unsigned short calculateHoursInMonth(unsigned short userYear, unsigned short userMonth)
	{
		return calculateDaysInMonth(userYear, userMonth) * 24;
	}
	unsigned short calculateHoursInMonth()
	{
		return calculateDaysInMonth(year, month);
	}

	static unsigned short calculateMinutesInMonth(unsigned short userYear, unsigned short userMonth)
	{
		return calculateHoursInMonth(userYear, userMonth) * 60;
	}
	unsigned short calculateMinutesInMonth()
	{
		return calculateMinutesInMonth(year, month);
	}

	static unsigned int calculateSecondsInMonth(unsigned short userYear, unsigned short userMonth)
	{
		return calculateMinutesInMonth(userYear, userMonth) * 60;
	}
	unsigned int calculateSecondsInMonth()
	{
		return calculateSecondsInMonth(year, month);
	}

	// print calendar
	static unsigned short calculateD(unsigned short userYear, unsigned short userMonth, unsigned short userDay)
	{
		unsigned short a, y, m;
		a = (14 - userMonth) / 12;
		y = userYear - a;
		m = userMonth + (12 * a) - 2;
		return (userDay + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	static unsigned short calculateD(clsDate date)
	{
		unsigned short a, y, m;
		a = (14 - date.month) / 12;
		y = date.year - a;
		m = date.month + (12 * a) - 2;
		return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	unsigned short calculateD()
	{
		return calculateD(year, month, day);
	}

	static string printDayName(unsigned short userYear, unsigned short userMonth, unsigned short userDay)
	{
		string dayName[9] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		short d = calculateD(userYear, userMonth, userDay);

		return dayName[d];
	}
	static string printDayName(unsigned short dayOfWeekOrder)
	{
		string dayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		return dayName[dayOfWeekOrder];
	}
	static string printDayShortName(unsigned short dayOfWeekOrder)
	{
		string dayName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return dayName[dayOfWeekOrder];
	}
	string printDayName()
	{
		return printDayName(year, month, day);
	}

	static string printMonth(unsigned short userMonth)
	{
		string monthName[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return monthName[userMonth];
	}
	string printMonth()
	{
		return printMonth(month);
	}

	static void printCalendar(unsigned short userYear, unsigned short userMonth, unsigned short userDay)
	{
		string dayName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		short daysInMonth = calculateDaysInMonth(userYear, userMonth);
		short d = calculateD(userYear, userMonth, userDay);
		short rowCounter = 0;
		short dayCounter = 1;

		// print month header
		cout << "\n\n" << "---------------" << printMonth(userMonth) << "---------------" << endl;

		// print calendar header
		for (short i = 0; i < 7; i++)
		{
			cout << right << setw(3) << dayName[i] << "  ";
		}
		cout << endl;

		// print calendar
		for (short i = 0; i < 35; i++)
		{
			cout << right << setw(3);
			if (i < d)
				cout << "     ";
			else
			{
				cout << dayCounter << "  ";
				if (dayCounter == daysInMonth)
					break;
				dayCounter++;
			}
			rowCounter++;
			if (rowCounter == 7)
			{
				cout << endl;
				rowCounter = 0;
			}
		}
		cout << "\n---------------------------------";
	}
	void printCalendar()
	{
		printCalendar(year, month, day);
	}

	static void printYearCalendar(unsigned short userYear)
	{
		cout << "\n---------------------------------" << endl;
		cout << "\n\tCalendar - " << userYear << endl;
		cout << "\n---------------------------------" << endl;

		for (short i = 1; i <= 12; i++)
		{
			printCalendar(userYear, i, 1);
		}
	}
	void printYearCalendar()
	{
		printYearCalendar(year);
	}

	// calculate Date
	static unsigned short calculateDaysFromSpecificDate(unsigned userYear, unsigned short userMonth, unsigned short userDay)
	{
		unsigned short totalDays = 0;

		short i = 1;
		while (i <= userMonth)
		{
			if (i == userMonth)
			{
				totalDays += userDay;
				break;
			}
			totalDays += calculateDaysInMonth(userYear, i);
			i++;
		}
		return totalDays;
	}
	static unsigned short calculateDaysFromSpecificDate(clsDate date)
	{
		unsigned short totalDays = 0;

		short i = 1;
		while (i <= date.month)
		{
			if (i == date.month)
			{
				totalDays += date.day;
				break;
			}
			totalDays += calculateDaysInMonth(date.year, i);
			i++;
		}
		return totalDays;
	}
	unsigned short calculateDaysFromSpecificDate()
	{
		return calculateDaysFromSpecificDate(year, month, day);
	}

	static clsDate calculateSpecificDateFromDays(unsigned short daysFromBeginning, unsigned short userYear)
	{
		unsigned short calculatedDay, calculatedMonth, calculatedYear;
		calculatedYear = userYear;
		calculatedMonth = 1;
		unsigned short remainingDays = daysFromBeginning;
		unsigned short monthDays = 0;

		while (true)
		{
			monthDays = calculateDaysInMonth(userYear, calculatedMonth);
			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				if (calculatedMonth == 12)
				{
					calculatedMonth = 1;
					calculatedYear++;
				}
				else
					calculatedMonth++;
			}
			else
			{
				calculatedDay = remainingDays;
				break;
			}
		}
		return clsDate(calculatedDay, calculatedMonth, calculatedYear);
	}

	void addDaysToSpecificDate(unsigned short daysToAdd)
	{
		unsigned short remainingDays = daysToAdd + calculateDaysFromSpecificDate(year, month, day);
		unsigned short monthDays = 0;
		month = 1;

		while (true)
		{
			monthDays = calculateDaysInMonth(year, month);
			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				month++;
				if (month > 12)
				{
					month = 1;
					year++;
				}
			}
			else
			{
				day = remainingDays;
				break;
			}
		}
	}

	static unsigned short daysUntilTheEndOfWeek(clsDate date)
	{
		unsigned short daysUntilTheEndOfWeek = 0;
		unsigned short todayOrderInWeek = calculateD(date);
		while (true)
		{
			if (todayOrderInWeek == 6)
				break;
			todayOrderInWeek++;
			daysUntilTheEndOfWeek++;
		}
		return daysUntilTheEndOfWeek;
	}
	unsigned short daysUntilTheEndOfWeek()
	{
		daysUntilTheEndOfWeek(*this);
	}

	static unsigned short daysUntilTheEndOfMonth(clsDate date)
	{
		unsigned short daysUntilTheEndOfMonth = 0;
		unsigned short totalDaysInMonth = calculateDaysInMonth(date.year, date.month);
		unsigned short i = date.day;

		while (true)
		{
			if (i == totalDaysInMonth)
				break;
			i++;
			daysUntilTheEndOfMonth++;
		}
		return daysUntilTheEndOfMonth;
	}
	unsigned short daysUntilTheEndOfMonth()
	{
		return daysUntilTheEndOfMonth(*this);
	}

	static unsigned short daysUntilTheEndOfYear(clsDate date)
	{
		//unsigned short daysUntilTheEndOfYear = 0;
		unsigned short totalDaysInYear = calculateDaysInYear(date.year);
		unsigned short i = calculateDaysFromSpecificDate(date);
		return totalDaysInYear - i;
		/*while (true)
		{
			if (i == totalDaysInYear)
				break;
			i++;
			daysUntilTheEndOfYear++;
		}
		return daysUntilTheEndOfYear;*/
	}
	unsigned short daysUntilTheEndOfYear()
	{
		return daysUntilTheEndOfYear(*this);
	}

	// date comparison
	static bool isBefore(clsDate date1, clsDate date2)
	{
		return (date1.year < date2.year) ? true :
			((date1.year == date2.year && date1.month < date2.month) ? true :
				((date1.year == date2.year && date1.month == date2.month && date1.day < date2.day) ? true : false));
	}
	bool isBefore(clsDate date2)
	{
		return isBefore(*this, date2);
	}

	static bool isEqual(clsDate date1, clsDate date2)
	{
		// mentor solution
		//		return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
		return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) ? true : false;
	}
	bool isEqual(clsDate date2)
	{
		return isEqual(*this, date2);
	}

	static bool isAfter(clsDate date1, clsDate date2)
	{
		return (date1.year > date2.year) ? true :
			((date1.year == date2.year && date1.month > date2.month) ? true :
				((date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) ? true : false));
	}
	bool isAfter(clsDate date2)
	{
		return isAfter(*this, date2);
	}

	static bool isFirstDay(unsigned short day)
	{
		return day == 1;
	}
	bool isFirstDay()
	{
		return isFirstDay(day);
	}

	static bool isFirstMonth(unsigned short month)
	{
		return (month == 1);
	}
	bool isFirstMonth()
	{
		return isFirstMonth(month);
	}

	static bool isLastDay(clsDate date)
	{
		return (date.day == calculateDaysInMonth(date.year, date.month));
	}
	bool isLastDay()
	{
		return isLastDay(*this);
	}

	static bool isLastMonth(unsigned short userMonth)
	{
		return (userMonth == 12);
	}
	bool isLastMonth()
	{
		return isLastMonth(month);
	}

	static clsDate increaseDateByOneDay(clsDate date)
	{
		if (isLastDay(date))
		{
			if (isLastMonth(date.month))
			{
				date.day = 1;
				date.month = 1;
				date.year++;
			}
			else
			{
				date.day = 1;
				date.month++;
			}
		}
		else
			date.day++;
		return date;
	}
	void increaseDateByOneDay()
	{
		*this = increaseDateByOneDay(*this);
	}

	static void swapDates(clsDate date1, clsDate date2)
	{
		clsDate tempDate;
		tempDate = date1;
		date1 = date2;
		date2 = tempDate;
	}
	void swap(clsDate date2)
	{
		clsDate tempDate;
		tempDate = *this;
		*this = date2;
		date2 = tempDate;
	}

	static short calculateDiffInDays(clsDate date1, clsDate date2, bool includeEndDate = false)
	{
		unsigned short diffInDays = 0;
		short swapFlagValue = 1;

		if (!isBefore(date1, date2))
		{
			swapDates(date1, date2);
			swapFlagValue = -1;
		}

		while (isBefore(date1, date2))
		{
			date1 = increaseDateByOneDay(date1);
			diffInDays++;
		}
		return (includeEndDate) ? ++diffInDays * swapFlagValue : diffInDays * swapFlagValue;
	}
	short calculateDiffInDays(clsDate date2, bool includeEndDate = false)
	{
		return calculateDiffInDays(*this, date2, includeEndDate);
	}

	static enCompareDatesCases compareDates(clsDate date1, clsDate date2)
	{
		return (isBefore(date1, date2)) ? enCompareDatesCases::before : (isEqual(date1, date2) ? enCompareDatesCases::equal : enCompareDatesCases::after);
	}
	enCompareDatesCases compareDates(clsDate date2)
	{
		compareDates(*this, date2);
	}

	//below no need to have non-static function for the object because it does not depend on any data from it.
	static short YourAge(clsDate birthDate)
	{
		return calculateDiffInDays(birthDate, getCurrentDate(), true);
	}

	// increase Date By
	static clsDate increaseDateByXDays(clsDate& date, unsigned short xDays = 10)
	{
		for (short i = 0; i < xDays; i++)
		{
			date = increaseDateByOneDay(date);
		}
		return date;
	}
	void increaseDateByXDays(unsigned short xDays = 10)
	{
		*this = increaseDateByXDays(*this, xDays);
	}

	static clsDate increaseDateByOneWeek(clsDate& date)
	{
		for (short i = 0; i < 7; i++)
		{
			date = increaseDateByOneDay(date);
		}
		return date;
	}
	void increaseDateByOneWeek()
	{
		increaseDateByOneWeek(*this);
	}

	static clsDate increaseDateByXWeeks(clsDate& date, unsigned short xWeeks = 10)
	{
		for (short i = 0; i < xWeeks; i++)
		{
			date = increaseDateByOneWeek(date);
		}
		return date;
	}
	void increaseDateByXWeeks(unsigned short xWeeks = 10)
	{
		increaseDateByXWeeks(*this, xWeeks);
	}

	static clsDate increaseDateByOneMonth(clsDate& date)
	{
		for (short i = 0; i < 1; i++)
		{
			if (isLastMonth(date.month))
			{
				date.month = 1;
				date.year++;
			}
			else
				date.month++;
		}

		// check if the date day is the allowed days for the month that has recently increased
		unsigned short numberOfDaysInMonth = calculateDaysInMonth(date.year, date.month);
		if (date.day > numberOfDaysInMonth)
			date.day = numberOfDaysInMonth;

		return date;
	}
	void increaseDateByOneMonth()
	{
		increaseDateByOneMonth(*this);
	}

	static clsDate increaseDateByXMonths(clsDate& date, unsigned short xMonths = 5)
	{
		for (short i = 0; i < xMonths; i++)
		{
			date = increaseDateByOneMonth(date);
		}
		return date;
	}
	void increaseDateByXMonths(unsigned short xMonths = 5)
	{
		increaseDateByXMonths(*this, xMonths);
	}

	static clsDate increaseDateByOneYear(clsDate& date)
	{
		for (short i = 0; i < 1; i++)
		{
			date.year++;
		}
		return date;
	}
	void increaseDateByOneYear()
	{
		increaseDateByOneYear(*this);
	}

	static clsDate increaseDateByXYears(clsDate& date, unsigned short xYears = 10)
	{
		for (short i = 0; i < xYears; i++)
		{
			date = increaseDateByOneYear(date);
		}
		return date;
	}
	void increaseDateByXYears(unsigned short xYears = 10)
	{
		increaseDateByXYears(*this, xYears);
	}

	static clsDate increaseDateByXYearsFaster(clsDate& date, unsigned short xYears = 10)
	{
		date.year += xYears;
		return date;
	}
	void increaseDateByXYearsFaster(unsigned short xYears = 10)
	{
		increaseDateByXYearsFaster(*this, xYears);
	}

	static clsDate increaseDateByOneDecade(clsDate& date)
	{
		for (short i = 0; i < 1; i++)
		{
			date = increaseDateByXYearsFaster(date);
		}
		return date;
	}
	void increaseDateByOneDecade()
	{
		increaseDateByOneDecade(*this);
	}

	static clsDate increaseDateByXDecades(clsDate& date, unsigned short xDecades = 10)
	{
		for (short i = 0; i < xDecades; i++)
		{
			date = increaseDateByOneDecade(date);
		}
		return date;
	}
	void increaseDateByXDecades(unsigned short xDecades = 10)
	{
		increaseDateByXDecades(*this, xDecades);
	}

	static clsDate increaseDateByXDecadesFaster(clsDate& date, unsigned short xDecades = 10)
	{
		date.year += (xDecades * 10);
		return date;
	}
	void increaseDateByXDecadesFaster(unsigned short xDecades = 10)
	{
		increaseDateByXDecadesFaster(*this, xDecades);
	}

	static clsDate increaseDateByOneCentury(clsDate& date)
	{
		date = increaseDateByXDecadesFaster(date);
		return date;
	}
	void increaseDateByOneCentury()
	{
		increaseDateByOneCentury(*this);
	}

	static clsDate increaseDateByOneMillennium(clsDate& date)
	{
		date.year += 1000;
		return date;
	}
	void increaseDateByOneMillennium()
	{
		increaseDateByOneMillennium(*this);
	}

	// decrease Date By
	static clsDate decreaseDateByOneDay(clsDate& date)
	{
		if (isFirstDay(date.day))
		{
			if (isFirstMonth(date.month))
			{
				date.day = 31;
				date.month = 12;
				date.year--;
			}
			else
			{
				date.month--;
				unsigned short numberOfDaysInMonth = calculateDaysInMonth(date.year, date.month);
				date.day = numberOfDaysInMonth;
			}
		}
		else
			date.day--;
		return date;
	}
	void decreaseDateByOneDay()
	{
		decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByXDays(clsDate& date, unsigned short xDays = 10)
	{
		for (short i = 0; i < xDays; i++)
		{
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	void decreaseDateByXDays(unsigned short xDays = 10)
	{
		decreaseDateByXDays(*this, xDays);
	}

	static clsDate decreaseDateByOneWeek(clsDate& date)
	{
		for (short i = 0; i < 7; i++)
		{
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	void decreaseDateByOneWeek()
	{
		decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(clsDate& date, unsigned short xWeeks = 10)
	{
		for (short i = 0; i < xWeeks; i++)
		{
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}
	void decreaseDateByXWeeks(unsigned short xWeeks = 10)
	{
		decreaseDateByXWeeks(*this, xWeeks);
	}

	static clsDate decreaseDateByOneMonth(clsDate& date)
	{
		for (short i = 0; i < 1; i++)
		{
			if (isFirstMonth(date.month))
			{
				date.month = 12;
				date.year--;
			}
			else
				date.month--;
		}

		// check if the date day is the allowed days for the month that has recently increased
		unsigned short numberOfDaysInMonth = calculateDaysInMonth(date.year, date.month);
		if (date.day > numberOfDaysInMonth)
			date.day = numberOfDaysInMonth;

		return date;
	}
	void decreaseDateByOneMonth()
	{
		decreaseDateByOneMonth(*this);
	}

	static clsDate decreaseDateByXMonths(clsDate& date, unsigned short xMonths = 5)
	{
		for (short i = 0; i < xMonths; i++)
		{
			date = decreaseDateByOneMonth(date);
		}
		return date;
	}
	void decreaseDateByXMonths(unsigned short xMonths = 5)
	{
		decreaseDateByXMonths(*this, xMonths);
	}

	static clsDate decreaseDateByOneYear(clsDate& date)
	{
		for (short i = 0; i < 1; i++)
		{
			date.year--;
		}
		return date;
	}
	void decreaseDateByOneYear()
	{
		decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByXYears(clsDate& date, unsigned short xYears = 10)
	{
		for (short i = 0; i < xYears; i++)
		{
			date = decreaseDateByOneYear(date);
		}
		return date;
	}
	void decreaseDateByXYears(unsigned short xYears = 10)
	{
		decreaseDateByXYears(*this, xYears);
	}

	static clsDate decreaseDateByXYearsFaster(clsDate& date, unsigned short xYears = 10)
	{
		date.year -= xYears;
		return date;
	}
	void decreaseDateByXYearsFaster(unsigned short xYears = 10)
	{
		decreaseDateByXYearsFaster(*this, xYears);
	}

	static clsDate decreaseDateByOneDecade(clsDate& date)
	{
		for (short i = 0; i < 1; i++)
		{
			date = decreaseDateByXYearsFaster(date);
		}
		return date;
	}
	void decreaseDateByOneDecade()
	{
		decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecades(clsDate& date, unsigned short xDecades = 10)
	{
		for (short i = 0; i < xDecades; i++)
		{
			date = decreaseDateByOneDecade(date);
		}
		return date;
	}
	void decreaseDateByXDecades(unsigned short xDecades = 10)
	{
		decreaseDateByXDecades(*this, xDecades);
	}

	static clsDate decreaseDateByXDecadesFaster(clsDate& date, unsigned short xDecades = 10)
	{
		date.year -= (xDecades * 10);
		return date;
	}
	void decreaseDateByXDecadesFaster(unsigned short xDecades = 10)
	{
		decreaseDateByXDecadesFaster(*this, xDecades);
	}

	static clsDate decreaseDateByOneCentury(clsDate& date)
	{
		date.year -= 100;
		return date;
	}
	void decreaseDateByOneCentury()
	{
		decreaseDateByOneCentury(*this);
	}

	static clsDate decreaseDateByOneMillennium(clsDate& date)
	{
		date.year -= 1000;
		return date;
	}
	void decreaseDateByOneMillennium()
	{
		decreaseDateByOneMillennium(*this);
	}

	// Business or WeekEnd
	static bool isEndOfWeek(clsDate date)
	{
		return (printDayShortName(calculateD(date)) == "Sat");
	}
	bool isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}

	static bool isWeekEnd(clsDate date)
	{
		string dayName = printDayShortName(calculateD(date));
		return (dayName == "Fri") || (dayName == "Sat");
	}
	bool isWeekEnd()
	{
		return isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date)
	{
		/*return (date.dayName != "Fri") && (date.dayName != "Sat");*/
		return !isWeekEnd(date);
	}
	bool isBusinessDay()
	{
		return isBusinessDay(*this);
	}

	static unsigned short calculateBusinessDays(clsDate date1, clsDate date2)
	{
		short totalDays = calculateDiffInDays(date1, date2);
		unsigned short VacationDays = 0;
		for (short i = 0; i < totalDays; i++)
		{
			if (isBusinessDay(date1))
				VacationDays++;
			date1 = increaseDateByOneDay(date1);
		}
		return VacationDays;
	}

	static unsigned short calculateVacationDays(clsDate date1, clsDate date2)
	{
		return calculateBusinessDays(date1, date2);
	}

	static clsDate calculateVacationReturnDate(clsDate date1, unsigned short vacationDays)
	{
		while (vacationDays != 0)
		{
			if (isBusinessDay(date1))
				vacationDays--;
			date1 = increaseDateByOneDay(date1);
		}
		date1 = increaseDateByOneDay(date1);
		// The Employee shout return the company in a business day
		while (isWeekEnd(date1))
			date1 = increaseDateByOneDay(date1);
		return date1;
	}

	static unsigned short calculateTotalHolidayPeriod(clsDate date1, clsDate returnDate)
	{
		return calculateDiffInDays(date1, returnDate);
	}
};