#pragma once
#include <math.h>
#include <string>
#include <vector>
#include <fstream>

#define FACTOR 10
#define DECIMALPLACES 5


class Data
{
	double x;
	double y;
	double z;
	std::string label;

public:

	Data();
	Data(const Data&);
	Data(double, double, double);
	Data(double, double, double, std::string);

	void setX(double);
	void setY(double);
	void setZ(double);
	double getX();
	double getY();
	double getZ();

	double getDistance(Data&);
	double getMeanDistance(std::vector<Data>, std::string, Data&);
	std::string getLabel();
	void setLabel(std::string);
	Data& operator=(Data& data);
	friend std::ofstream& operator<<(std::ofstream& fOut, std::vector<Data> set);
	friend std::ostream& operator<<(std::ostream& cout, Data& dataPoint);

};

