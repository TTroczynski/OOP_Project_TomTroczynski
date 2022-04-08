#include "Data.h"

Data::Data():x(0), y(0), z(0) {}

Data::Data(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Data::setX(double)
{
}

void Data::setY(double)
{
}

void Data::setZ(double)
{
}

double Data::getDistance(Data& dataPoint)
{
    return (double)sqrtl(pow(dataPoint.getX() - this->x, dataPoint.getX() - this->x) + pow(dataPoint.getY() - this->y, dataPoint.getY() - this->y) + pow(dataPoint.getZ() - this->z, dataPoint.getZ() - this->z));
}

double Data::getMeanDistance(std::vector<Data> dataSet, std::string side)
{
    double mean = 0;
    for (Data data : dataSet) {
        if (data.getLabel() == side) {
            mean += data.getDistance(data);
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
    Data newData(data.getX(), data.getY(), data.getZ());
    return newData;
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
        fOut << std::to_string(element.getY());
        fOut << std::to_string(element.getZ());
        fOut << element.getLabel();
    }
}
