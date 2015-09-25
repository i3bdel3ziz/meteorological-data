#ifndef DATA_HPP_
#define DATA_HPP_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class MonthData
{
    
    protected:
	float tmin;
	float tmax;
	int   frost_days;
	float sun_hours;
	int   year;
	int   month;
	float rain;


    public:

	friend MonthData& operator>>(std::istream&,MonthData&);
	float getMinTemp();
	float getMaxTemp();
	int   getFrostDays();
	int   getYear();
	int   getMonth();
	float getSunHours();
	float getRain();
};


class Dataset
{
	private:
	std::vector<MonthData> meteorologicalData;
	public:
	Dataset(std::string datafile);
	/*
	*void lowestMinTempMonthYear(int &year,int &month)
	*This function sets the year and month of that year that
	*has had the lowest minimum temperature in the meteorological data;
	*/
	void lowestMinTempMonthYear(int &year,int &month);
	/*
	*int highestRainfallYear()
	*Returns the year that had the highest total rainfall in the entire meteorological data
	*/
	int  highestRainfallYear();
	/*
	*	void plotMaxTempVsTime();
	* Plots a line graph of  maximum temperature vs time for the entire meteorological data.
	*/
	void plotMaxTempVsTime();
	/*
	*	void plotSunshineVsTime()
	* Plots a line graph of sunshine hours vs time for the entire meteorological data.
	*/
	void plotSunshineVsTime();
	/*
	* void plotMaxTempvsSunshine();
	* Scatter plot of maximum temperatur vs sunhours for the entire meteorological data
	*/
	void plotMaxTempVsSunshine();
};

#endif DATA_HPP_
