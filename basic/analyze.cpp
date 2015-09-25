#include "data.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

struct annualRainfall
{
	int year;
	float total_rain;
};
	

int main(int argc,char **argv)
{
	std::vector<MonthData> metData; //vector to hold month specific weather info
	float minTemp;//lowest minimum temp
	int minTempYear, minTempMonth;//year and month with least temp
	int maxRainYear;//year with max rainfall
	std::string line;//to hold line reads
	std::ifstream datafile("./sheffield.data");//file should be in current directory
	//std::cout<<argc<<std::endl;	

	if(datafile.is_open() == false)	
	{
		std::cout<<"Error opening "<<"./sheffield.data"<<std::endl;
		return -1;
	}
	/*skip first four lines*/
	getline(datafile,line);	
	getline(datafile,line);	
	getline(datafile,line);	
	getline(datafile,line);
	
	
	/*read data into vector*/

	while(datafile.eof()==false)//read till the end
	{
		MonthData data;
		datafile>>data;
		metData.push_back(data);
	}
	datafile.close();
	

	/*find year & month with least temperature*/
	minTempYear = metData[0].getYear();
	minTempMonth = metData[0].getYear();
	minTemp = metData[0].getMinTemp();
	for(std::vector<MonthData>::iterator data = metData.begin(); data != metData.end(); ++data)
	{
		if(data->getMinTemp() < minTemp)
		{
			minTempYear = data->getYear();
			minTempMonth = data->getMonth();
			minTemp = data->getMinTemp();
		}
	}
	
	std::cout<<"The Year and Month With lowest minimum temperature were "<<std::endl;
	std::cout<<"Year"<<"\t"<<minTempYear<<std::endl;
	std::cout<<"Month"<<"\t"<<minTempMonth<<std::endl;
	std::cout<<"Value\t"<<minTemp<<std::endl<<std::endl;
	
	/* calculate and store annual rainfall for each year  */
	
	std::vector<struct annualRainfall> sheffieldAnnualRainfall;
	float tempTotalRain=0;
	int   tempYear = metData[0].getYear();
	for(std::vector<MonthData>::iterator data = metData.begin(); data != metData.end();)
	{	tempYear = data->getYear();		
		while(tempYear == data->getYear() && data != metData.end())
		{
			tempTotalRain += data->getRain();
			data++;			
		}
		struct annualRainfall ar;
		ar.total_rain = tempTotalRain;
		ar.year = tempYear;
		sheffieldAnnualRainfall.push_back(ar);
		tempTotalRain = 0;
	
	}
	
	/*find year with maximum total rainfall*/
	float maxRainfallVal = 0;
	maxRainYear = 0;
	
	for( std::vector<struct annualRainfall>::iterator ar = sheffieldAnnualRainfall.begin(); \
		ar != sheffieldAnnualRainfall.end(); ar++)
	{
		if( ar->total_rain > maxRainfallVal)
		{
			maxRainYear = ar->year;
			maxRainfallVal = ar->total_rain;
		}	
	}

	std::cout<<"Maximum rainfall was in "<<std::endl;
	std::cout<<"Year "<<maxRainYear<<"\tValue "<<maxRainfallVal<<"\n"<<std::endl;

	return 0;
		
}






