#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//File reading
char* readtxt()
{
    FILE *fp;
	char buff[2000];
	static char line[2000];
	//read from the txt file
    fp=fopen("G:\\Y4\\ES\\ES_CW\\C\\data textfile.txt","r");
	if(fp==NULL)
    {
        printf("Open Failed\n");
        exit(1);
    }
    //write the file information to buffer
	while(fgets(buff,2000,(FILE*)fp)!=NULL)
    //get the number of lines
	strcat(line,buff);

	return line;
}

struct Weather
{
	int date;
	int humidity;
	int pressure;
	int rainfall;
	int temperature;
 	int windspeed;
};

int main()
{
	char line[2000];
	struct Weather Wea[30];

	strcpy(line,readtxt());

    //read txt file line by line
	int i,j,n=strlen(line),curWea=-1;
	int humiditySum=0,pressureSum=0,rainfallSum=0,temperatureSum=0,windspeedSum=0;
	int humidityCount=0,pressureCount=0,rainfallCount=0,temperatureCount=0,windspeedCount=0;
	char date[20],humidity[20],pressure[20],rainfall[20],temperature[20],windspeed[20];

	for(i=0;i<n;i++){
		if(line[i]=='D'){
			j=0;
			i++;
			curWea++;

			strcpy(date,"");
			strcpy(humidity,"");
			strcpy(pressure,"");
			strcpy(rainfall,"");
			strcpy(temperature,"");
			strcpy(windspeed,"");


			while(line[i]!='D'&&line[i]!='H'&&line[i]!='P'&&line[i]!='R'&&line[i]!='T'&&line[i]!='W'){
				if(line[i]>='0'&&line[i]<='9'){
					date[j]=line[i];
					date[j+1]=' ';
					j++;
				}
				i++;
			}
		}
		if(line[i]=='H'){
			j=0;
			i++;
			while(line[i]!='D'&&line[i]!='H'&&line[i]!='P'&&line[i]!='R'&&line[i]!='T'&&line[i]!='W'){
				if(line[i]>='0'&&line[i]<='9'){
					humidity[j]=line[i];
					humidity[j+1]=' ';
					j++;
				}
				i++;
			}
		}

		if(line[i]=='P'){
			j=0;
			i++;
			while(line[i]!='D'&&line[i]!='H'&&line[i]!='P'&&line[i]!='R'&&line[i]!='T'&&line[i]!='W'){
				if(line[i]>='0'&&line[i]<='9'){
					pressure[j]=line[i];
					pressure[j+1]=' ';
					j++;
				}
				i++;
			}
		}

		if(line[i]=='R'){
			j=0;
			i++;
			while(line[i]!='D'&&line[i]!='H'&&line[i]!='P'&&line[i]!='R'&&line[i]!='T'&&line[i]!='W'){
				if(line[i]>='0'&&line[i]<='9'){
					rainfall[j]=line[i];
					rainfall[j+1]=' ';
					j++;
				}
				i++;
			}
		}

		if(line[i]=='T'){
			j=0;
			i++;
			while(line[i]!='D'&&line[i]!='H'&&line[i]!='P'&&line[i]!='R'&&line[i]!='T'&&line[i]!='W'){
				if(line[i]>='0'&&line[i]<='9'){
					temperature[j]=line[i];
					temperature[j+1]=' ';
					j++;
				}

				i++;
			}
		}

		if(line[i]=='W'){
			j=0;
			i++;
			while(line[i]!='D'&&line[i]!='H'&&line[i]!='P'&&line[i]!='R'&&line[i]!='T'&&line[i]!='W'){
				if(line[i]>='0'&&line[i]<='9'){
					windspeed[j]=line[i];
					windspeed[j+1]=' ';
					j++;
				}
				i++;
			}
		}

		//ascii to integer, change char type into int type
		Wea[curWea].date=atoi(date);
		Wea[curWea].humidity=atoi(humidity);
		Wea[curWea].pressure=atoi(pressure);
		Wea[curWea].rainfall=atoi(rainfall);
		Wea[curWea].temperature=atoi(temperature);
		Wea[curWea].windspeed=atoi(windspeed);

		//sum all values and count values appearance times
		if(Wea[curWea].humidity!=0){humiditySum=humiditySum+Wea[curWea].humidity;humidityCount++;}
		if(Wea[curWea].pressure!=0){pressureSum=pressureSum+Wea[curWea].pressure;pressureCount++;}
		if(Wea[curWea].rainfall!=0){rainfallSum=rainfallSum+Wea[curWea].rainfall;rainfallCount++;}
		if(Wea[curWea].temperature!=0){temperatureSum=temperatureSum+Wea[curWea].temperature;temperatureCount++;}
		if(Wea[curWea].windspeed!=0){windspeedSum=windspeedSum+Wea[curWea].windspeed;windspeedCount++;}

		i--;

	}

	//calculate average values
	float averHumidity, averPressure, averRainfall, averTemperature, averWindspeed;
	averHumidity=(float)humiditySum/humidityCount;
	averPressure=(float)pressureSum/pressureCount;
	averRainfall=(float)rainfallSum/rainfallCount;
	averTemperature=(float)temperatureSum/temperatureCount;
	averWindspeed=(float)windspeedSum/windspeedCount;

	//display average values
	printf("Average Humidity of the month:%.2f\nAverage Pressure of the month:%.2f\nAverage Rainfall of the month:%.2f\nAverage Temperature of the month:%.2f\nAverage Windspeed of the month:%.2f\n\n",
		averHumidity,
		averPressure,
		averRainfall,
		averTemperature,
		averWindspeed
	);



	//save in xls

	FILE *fp2 = fopen("G:\\Y4\\ES\\ES_CW\\C\\data textfile.xls","w+");
	fprintf(fp2,"Date\tHumidity\tPressure\tRainfall\tTemperature\tWindspeed\n");
	for(i=0;i<30;i++){
		fprintf(fp2,"%d\t%d\t%d\t%d\t%d\t%d\n",Wea[i].date,Wea[i].humidity,Wea[i].pressure,Wea[i].rainfall,Wea[i].temperature,Wea[i].windspeed);
	}
		fprintf(fp2,"\tAverage Humidity\tAverage Pressure\tAverage Rainfall\tAverage Temperature\tAverage Windspeed\n");
		fprintf(fp2,"\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
			averHumidity,
			averPressure,
			averRainfall,
			averTemperature,
			averWindspeed
	);
	printf("Save xls Successfully\n");
}
