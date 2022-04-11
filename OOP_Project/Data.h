//! Data Class
/*!
* A class that defines objects with 3 type: double values and a string label.
* The label is the classifier of the Data object when training a machine learning algorithm. It
* is also the value retrieved when making predictions.
* The Data object packages a x, y, z coordinate with a classifier label for use by, and derived from, the Classifier class.
*/

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
	std::string getLabel();
	void setLabel(std::string);
	
	double getMeanDistance(std::vector<Data>, std::string);
	double getDistance(Data&);

	Data& operator=(Data& data);
	friend std::ofstream& operator<<(std::ofstream& fOut, std::vector<Data>& set);
	friend std::ostream& operator<<(std::ostream& cout, Data& dataPoint);

};

