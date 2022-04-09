#include "Data.h"
#include <cmath>

Data::Data():x(0), y(0), z(0) {}

Data::Data(const Data& copy)
{
    this->setX(copy.x);
    this->setY(copy.y);
    this->setZ(copy.z);
    this->setLabel(copy.label);

}

Data::Data(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Data::Data(double x, double y, double z, std::string label)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLabel(label);
}

void Data::setX(double x)
{
    this->x = x;
}

void Data::setY(double y)
{
    this->y = y;
}

void Data::setZ(double z)
{
    this->z = z;
}

double Data::getDistance(Data& dataPoint)
{
    double factor = pow(FACTOR, DECIMALPLACES);
    double distance = sqrtl(pow(dataPoint.getX() - this->x, 2) + pow(dataPoint.getY() - this->y, 2) + pow(dataPoint.getZ() - this->z, 2));
    distance = ceil(distance * factor) / factor;
    return distance;
}

double Data::getMeanDistance(std::vector<Data> dataSet, std::string side, Data& newData)
{
    double mean = 0;
    for (Data data : dataSet) {
        if (data.getLabel() == side) {
            mean += data.getDistance(newData);
        }
    }
    mean /= (double)dataSet.size();
    return mean;
}

std::string Data::getLabel()
{
    return this->label;
}

void Data::setLabel(std::string label)
{
    this->label = label;
}

Data& Data::operator=(Data& data)
{
    Data* newData = new Data(data);
    return *newData;
}


double Data::getY()
{
    return this->y;
}

double Data::getZ()
{
    return this->z;
}

double Data::getX()
{
    return  this->x;
}

std::ofstream& operator<<(std::ofstream& fOut, std::vector<Data> dataSet)
{
    for (Data element : dataSet) {
        fOut << std::to_string(element.getX());
        fOut << ", ";
        fOut << std::to_string(element.getY());
        fOut << ", ";
        fOut << std::to_string(element.getZ());
        fOut << ", ";
        fOut << element.getLabel();
        fOut << std::endl;
    }
    return fOut;
}

std::ostream& operator<<(std::ostream& cout, Data& dataPoint)
{
    cout << dataPoint.getX() << ", " << dataPoint.getY() << ", " << dataPoint.getZ() << ", " << dataPoint.getLabel() << std::endl;

    return cout;
}
