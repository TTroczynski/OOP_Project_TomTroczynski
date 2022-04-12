#include "Data.h"
#include <cmath>

/*! \brief Default constructor
*
* initializes x, y, z values to 0
* @return No return value
*/
Data::Data():x(0), y(0), z(0) {}

/*! \brief Copy contructor
*
* Copies values of one Data object to this one
* Calls setX(), setY(), setZ() and setLabel()
* @see setX()
* @see setY()
* @see setZ()
* @see setLabel()
* 
* @param Data object reference
* @return No return value
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
* @param X-value
* @param Y-value
* @param Z-value
* @return No return value
*/
Data::Data(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

/*! \brief Parameterized constructor
*
* initializes x, y, z and label values to those passed as arguments. Calls setX(), setY(), setZ() and setLabel()
* @see setX()
* @see setY()
* @see setZ()
* @see setLabel()
* 
* @param X-value
* @param Y-value
* @param Z-value
* @param Classification_label
* @return No return value
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
* @param X-Value
* @return No return value
*/
void Data::setX(double x)
{
    this->x = x;
}

/*! \brief Set the Data object's Y value
*
* Sets the Data objects Y value to the one passed as an argument
* 
* @param Y-Value
*/
void Data::setY(double y)
{
    this->y = y;
}


/*! \brief Set the Data object's Z value
*
* Sets the Data objects Z value to the one passed as an argument
* 
* @param Z-Value
*/
void Data::setZ(double z)
{
    this->z = z;
}

/*! \brief Retrieves distance from a point
*
* Evaluates the distance between a point and this Data point. Calls getX(), getY(), getZ() and makes use of the cmath library.
* @see ceil()
* @see pow()
* @see sqrtl()
* @see getX()
* @see getY()
* @see getZ()
* 
* @param Data object reference
* @return distance between two points
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
* Evaluates the distance between a point and this Data point. Calls getLabel(), getDistance()
* @see getLabel()
* @see getDistance()
* 
* @param vector<data> container object
* @param side specified
*/
double Data::getMeanDistance(std::vector<Data> dataSet, std::string side)
{
    double mean = 0;
    int count = 0;

    for (Data data : dataSet) {
        if (data.getLabel() == side) {
            mean += data.getDistance(*this);
            count++;
        }
    }
    mean /= count;
    return mean;
}

/*! \brief Returns the label of this Data point
*
* The label of this data point is returned to the caller
* 
* @return Data objects label
*/
std::string Data::getLabel()
{
    return this->label;
}

/*! \brief Sets the label of this Data point
*
* This data point's label is set the label passed as an argument
* 
* @param string label to set
* 
*/
void Data::setLabel(std::string label)
{
    this->label = label;
}

/*! \brief Overloads the = operator
*
* The = operator is overloaded to allow for assignments of Data to Data
* 
* @param Data object reference
* 
* @return new Data object
*/
Data& Data::operator=(Data& data)
{
    Data* newData = new Data(data);
    return *newData;
}

/*! \brief Returns the Y value of this data point
*
* This data points Y value is returned to the caller
* 
* @return this objects Y-value
*/
double Data::getY()
{
    return this->y;
}

/*! \brief Returns the Z value of this data point
*
* This data points Z value is returned to the caller
* 
* @return this objects Z-value
*/
double Data::getZ()
{
    return this->z;
}

/*! \brief Returns the X value of this data point
*
* This data points X value is returned to the caller
* 
* @return this objects X-value
*/
double Data::getX()
{
    return  this->x;
}

/*! \brief Overloads the << operator for ofstream objects
*
* Makes possible writing Data objects to file using the << operator. Makes use of string library and fstream library. Calls getX(), getY(), getZ() and getLabel()
* @see to_string()
* @see getX()
* @see getY()
* @see getZ()
* @see getLabel()
* 
* @param ofstream object reference
* @param vector<Data> container object
* 
* @return ofstream object
*/
std::ofstream& operator<<(std::ofstream& fOut, std::vector<Data>& dataSet)
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

/*! \brief Overloads the << operator for ostream objects
*
* Makes possible printing of Data objects using the << operator. Makes use of iostream library. Calls getX(), getY(), getZ() and getLabel()
* 
* @see getX()
* @see getY()
* @see getZ()
* @see getLabel()
* 
* @param ostream object reference
* @param Data object reference
*/
std::ostream& operator<<(std::ostream& cout, Data& dataPoint)
{
    cout << dataPoint.getX() << ", " << dataPoint.getY() << ", " << dataPoint.getZ() << ", ";
    
    std::string tempLabel = dataPoint.getLabel();
    int tempLabelValue = std::stoi(tempLabel);

    switch (tempLabelValue)
    {
    case 1:
        cout << "Face up" << std::endl;
        break;
    case 2:
        cout << "Face down" << std::endl;
        break;
    case 3:
        cout << "Portrait" << std::endl;
        break;
    case 4:
        cout << "Portrait upside down" << std::endl;
        break;
    case 5:
        cout << "Landscape left" << std::endl;
        break;
    case 6:
        cout << "Landscape right" << std::endl;
        break;
    default:
        break;
    }

    return cout;
}
