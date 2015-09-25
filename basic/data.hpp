#include <istream>

class MonthData
{
    public:
  //  protected:
	float tmin;
	float tmax;
	int   frost_days;
	float sun_hours;
	int   year;
	int   month;
	float rain;


   // public:
	friend MonthData& operator>>(std::istream&,MonthData&);
	float getMinTemp();
	float getMaxTemp();
	int   getFrostDays();
	int   getYear();
	int   getMonth();
	float getSunHours();
	float getRain();
};


