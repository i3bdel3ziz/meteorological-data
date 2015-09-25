#include "data.hpp"


float MonthData::getMinTemp()
{
	return this->tmin;
}
float MonthData::getMaxTemp()
{
	return this->tmax;
}
int MonthData::getFrostDays()
{
	return this->frost_days;
}
int MonthData::getMonth()
{
	return this->month;
}
int MonthData::getYear()
{
	return this->year;
}
float MonthData::getSunHours()
{
	return this->sun_hours;
}
float MonthData::getRain()
{
	return this->rain;
}

MonthData& operator>>(std::istream& in ,MonthData& data)
{
	in>>data.year>>data.month>>data.tmax>>data.tmin>>data.frost_days>>data.rain>>data.sun_hours;
	return data;
}
