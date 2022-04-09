#include <fstream>
#include <sstream>
#include "NNeighbor.h"
#include <iostream>

/*! \brief Nearest Neighbor ML Algorithm
* 
* Training a model with data and later supplying unlabeled data to the model to predictively assign a label
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
		std::cout << model;
	}
	//CHECK THAT ALL DATA IS PROPERLY HIDDEN
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
