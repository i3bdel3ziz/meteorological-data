#include "data.hpp"
#include <iostream>
#include <string>

void usage(void);

void usage(void)
{
	std::cout<<"Intermediate Help "<<std::endl;
	std::cout<<"synopsis: "<<std::endl;
	std::cout<<"./intermediate --file data-file-name"<<std::endl;
	std::cout<<"Where data-file-name is the file containing meteorological data"<<std::endl;
	std::cout<<"accordingly formated"<<std::endl;
	return;
}


int main(int argc, char **argv)
{
	std::string filename;//data file 
	if(argc < 2)
	{
		usage();
		return 1;
	}
	else
	{
		bool ok = false;
		for(int i =1; i< argc; i++)
		{
			std::string value(argv[i]);
			if(value == std::string("--file"))
			{
				if(argv[i+1] )		
				{		
					filename=std::string(argv[i+1]);
					ok = true;
					std::cout<<filename<<std::endl;
					break;
				}
			}
			else if( value == std::string("--help"))
			{
				ok=false;
				break;
			}

		}

		if(ok == false)
		{
			usage();
			return 1;
		}
	}	
	int minTempYear,minTempMonth;
	Dataset data = Dataset(filename);
	data.lowestMinTempMonthYear(minTempYear,minTempMonth);
	std::cout<<"The year with lowest minimum temperature is "<<minTempYear<<std::endl;
	std::cout<<"The month with lowest minimum temperature is "<<minTempMonth<<std::endl;
	std::cout<<"The year with highest rainfall was year: "<<data.highestRainfallYear()<<std::endl;
	std::cout<<"Exiting..\nGood Bye"<<std::endl;
	return 0;
	
}
