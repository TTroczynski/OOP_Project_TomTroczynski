#pragma once
#include <math.h>
#include <string>
#include <vector>

class Data
{
	double x;
	double y;
	double z;
	std::string label;

public:

	Data();
	Data(double, double, double);

	void setX(double);
	void setY(double);
	void setZ(double);
	double getX();
	double getY();
	double getZ();

	double getDistance(Data&);
	double getMeanDistance(std::vector<Data>, std::string);
	std::string getLabel();
	void setLabel(std::string);
	Data& operator=(Data& data);

};

