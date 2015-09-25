#include "data.hpp"


void usage(void);

void usage(void)
{
	std::cout<<"advanced Help "<<std::endl;
	std::cout<<"synopsis: "<<std::endl;
	std::cout<<"advanced --file data-file-name"<<std::endl;
	std::cout<<"Where \"data-file-name\" is the file containing the apropriately formated"<<std::endl;
	std::cout<<"meteorological data"<<std::endl;
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
	int tempYear,tempMonth;
	Dataset data = Dataset(filename);
	data.lowestMinTempMonthYear(tempYear,tempMonth);
	std::cout<<"Lowest temperature was in year "<<tempYear<<" and month "<<tempMonth<<std::endl;
    data.highestRainfallYear();
	std::cout<<"The year with highest rainfall was "<<data.highestRainfallYear()<<std::endl;
	int value=0;
	
	
	std::cout<<"Enter 1 to choose a plot of maximum temperature vs time"<<std::endl;
	std::cout<<"Enter 2 to choose a plot of manuximum temperature vs sunshine hours"<<std::endl;
	std::cout<<"Enter 3 to choose a scatter plot of sunshine hours vs time"<<std::endl;
	std::cout<<"Enter any other value to exit"<<std::endl;
	std::cin>>value;
	switch(value)
	{
		case 1:				
			data.plotMaxTempVsTime();
		break;
		case 2:
			data.plotMaxTempVsSunshine();
		break;
		case 3:
			data.plotSunshineVsTime();
		break;
		default:
			std::cout<<"Invalid value, exiting.."<<std::endl;			
		break;

	}
	
	
   std::cout<<"Goodbye :-)"<<std::endl;    
   return 0;
	
}

