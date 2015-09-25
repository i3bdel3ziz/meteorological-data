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


Dataset::Dataset(std::string datafile)
{
	std::string temp;
	std::ifstream file(datafile.data());
	if(file.is_open() == true)
	{
		for(int i=0 ; i<4;i++)
			getline(file,temp);
		while(file.eof() == false)
		{
			MonthData data;
			file>>data;
			this->meteorologicalData.push_back(data);
			
		}
		file.close();
	}
	else
		std::cout<<"Error opening file "<<datafile<<std::endl;
	
}

void Dataset::lowestMinTempMonthYear(int &y,int &m)
{
	int  month =this->meteorologicalData[0].getMonth();
	int  year = this->meteorologicalData[0].getYear();
	float temp=this->meteorologicalData[0].getMinTemp();
	/*step through the entire data set to find lowest mean temp, get its year and month*/
	for( std::vector<MonthData>::iterator ir=this->meteorologicalData.begin(); ir != meteorologicalData.end(); ir++)
	{
		if(ir->getMinTemp() < temp)
		{
			month = ir->getMonth();
			year = ir->getYear();
			temp = ir->getMinTemp();
		}		
		
	}
	//std::cout<<"\nYear and Month with least minimum temp is :"<<std::endl;
	//std::cout<<"Year\t"<<year<<"\tMonth\t"<<month<<"\tTemp\t\n"<<temp<<std::endl;
	y=year;
	m=month;
}
int Dataset::highestRainfallYear()
{
	std::vector<int> year;
	std::vector<float> annualRainfall;

	int tempYear;
	float tempTotal=0;
	tempYear = this->meteorologicalData[0].getYear();
	/*Calculate the total rainfall for each year snd store the values*/
	for(std::vector<MonthData>::iterator ir = this->meteorologicalData.begin(); ir != this->meteorologicalData.end(); ir++)
	{
		if(tempYear == ir->getYear()  )
		{
			tempTotal += ir->getRain();
		}
		else
		{
			year.push_back(tempYear);
			annualRainfall.push_back(tempTotal);
			tempTotal=0;
			tempTotal += ir->getRain();
			tempYear = ir->getYear();
		}
	}
	/*store the total for the last year*/
	year.push_back(tempYear);
	annualRainfall.push_back(tempTotal);
	
	
	/*Find the year with highest rainfall*/
	/*step through the entire data set looking for highest value*/
	tempTotal = annualRainfall[0];
	tempYear = year[0];
	std::vector<float>::iterator arir = annualRainfall.begin();
	std::vector<int>::iterator yir = year.begin();
	for(; arir != annualRainfall.end() && yir != year.end(); yir++,arir++)
	{
		if(tempTotal < *arir)
		{
			tempTotal = *arir;
			tempYear = *yir;
		}
	}
	//std::cout<<"Rainfall "<<tempTotal<<"\tyear\t"<<tempYear<<std::endl;
	return tempYear;
}

 
