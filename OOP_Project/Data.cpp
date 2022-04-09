#include "Data.h"
#include <cmath>

/*! \brief Default constructor
*
* initializes x, y, z values to 0
*/
Data::Data():x(0), y(0), z(0) {}

/*! \brief Copy contructor
*
* Copies values of one Data object to this one
*/
Data::Data(const Data& copy)
{
    this->setX(copy.x);
    this->setY(copy.y);
    this->setZ(copy.z);
    this->setLabel(copy.label);

}

/*! \brief Parameterized constructor
*
* initializes x, y, z values to those passed as arguments
*/
Data::Data(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

/*! \brief Parameterized constructor
*
* initializes x, y, z and label values to those passed as arguments
*/
Data::Data(double x, double y, double z, std::string label)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setLabel(label);
}

/*! \brief Set the Data object's X value
*
* Sets the Data objects X value to the one passed as an argument
*/
void Data::setX(double x)
{
    this->x = x;
}

/*! \brief Set the Data object's Y value
*
* Sets the Data objects Y value to the one passed as an argument
*/
void Data::setY(double y)
{
    this->y = y;
}


/*! \brief Set the Data object's Z value
*
* Sets the Data objects Z value to the one passed as an argument
*/
void Data::setZ(double z)
{
    this->z = z;
}

/*! \brief Retrieves distance from a point
*
* Evaluates the distance between a point and this Data point
*/
double Data::getDistance(Data& dataPoint)
{
    double factor = pow(FACTOR, DECIMALPLACES);
    double distance = sqrtl(pow(dataPoint.getX() - this->x, 2) + pow(dataPoint.getY() - this->y, 2) + pow(dataPoint.getZ() - this->z, 2));
    distance = ceil(distance * factor) / factor;
    return distance;
}

/*! \brief Retrieves mean distance from a point
*
* Evaluates the distance between a point and this Data point
*/
double Data::getMeanDistance(std::vector<Data> dataSet, std::string side)
{
    double mean = 0;
    for (Data data : dataSet) {
        if (data.getLabel() == side) {
            mean += data.getDistance(*this);
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
