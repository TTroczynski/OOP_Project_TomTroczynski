

/*! \brief Nearest Neighbor ML Algorithm
* 
* Training a model with data and later supplying unlabeled data to the model to predictively assign a label
* 
* Shortest distance is used to evaluate points. If two trained points are equidistant to an unlabeled point,
* the mean distance of all classified points is calculated. The label/classification of the closest mean is chosen.
*/
/*! \file NNeighbor.h
	\brief Includes the model that will be used to make predicitions

	Using this class this program will train a model using the Nearest Neighbor algorithm. This class handles 
	equidistant points as an edge case which prevents scewing.
*/

/*! \file sstream.h
	\brief The sstream library

	This library provides simple functionality for reading and writing streams
*/

/*! \file iotream.h
	\brief The iostream library

	This library provides simple functionality for input/output to/from the user
*/

/*! \file trainingData.txt
	\brief The data set used for training

	This text file contains data as structureed text to train the algorithm with.
*/

/*! \file output.txt
	\brief The file the program writes to

	This file contains the data processed by the algorithm. Unknown points without classifier
	labels get assigned the predicted label returned by the algorithm.
*/

/*! \file unknownData.txt
	\brief The file containing all unclassified points

	The data set that needs to be processed formatted as structured text.
*/


#include <sstream>
#include "NNeighbor.h"
#include <iostream>

/*! \fn void parseLine(std::stringstream&, std::string& x, std::string& y, std::string& z)
	\brief The function decomposes a single line from a file into 3 strings (x, y, z)

	Passes to 
	@param x
	@param y
	@param z
	By reference
*/

void parseLine(std::stringstream&, std::string&, std::string&, std::string&);

int main(void) {

	NNeighbor model;
	std::string inFile = "trainingData.txt";
	std::ifstream fin;
	std::string fileLine;
	std::string x, y, z, label;

	fin.open(inFile);
	if (fin.is_open()) {
		while (!fin.eof()) {

			std::getline(fin, fileLine);
			std::stringstream rawLine(fileLine);

			parseLine(rawLine, x, y, z);
			std::getline(rawLine, label, '\n');
			Data newData(std::stod(x), std::stod(y), std::stod(z), label);

			model.train(newData);
		}
		fin.close();
	}

	std::string outFile = "output.txt";
	inFile = "unknownData.txt";
	std::ofstream fout;
	std::string testLine;
	std::vector<Data> predictions;

	fin.open(inFile);
	if (fin.is_open()) {
		while (!fin.eof()) {

			std::getline(fin, testLine);

			std::stringstream rawLine(testLine);
			parseLine(rawLine, x, y, z);

			Data userData(std::stod(x), std::stod(y), std::stod(z));
			userData.setLabel(model.predict(userData));

			predictions.push_back(userData);
		}
		fin.close();

		fout.open(outFile);

		if (fout.is_open()) {

			fout << predictions;
			fout.close();
		}
		for (Data element : predictions) {
			std::cout << element;
		}
	}
	//print side text not number
	return 0;
}

/*! \brief parseLine() extracts values from a string
*
* Converts  comma seperated values into type:double values
*/
void parseLine(std::stringstream& rawLine, std::string& x, std::string& y, std::string& z) {
	
	std::getline(rawLine, x, ',');
	std::getline(rawLine, y, ',');
	std::getline(rawLine, z, ',');
}
