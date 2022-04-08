#include <fstream>
#include <sstream>
#include "NNeighbor.h"
#include <iostream>

void parseLine(std::stringstream&, std::string&, std::string&, std::string&);

int main(void) {

	NNeighbor model;
	std::string inFile = "data.txt";
	std::ifstream fin;
	std::string fileLine;
	std::string x, y, z;

	fin.open(inFile);
	if (fin.is_open()) {
		while (!fin.eof()) {

			Data newData;
			std::getline(fin, fileLine);
			std::stringstream rawLine(fileLine);

			parseLine(rawLine, x, y, z);
			newData.setX(std::stoi(x));
			newData.setY(std::stoi(y));
			newData.setZ(std::stoi(z));

			model.train(newData);
		}
	}

	std::string userCoord;
	std::string outFile = "output.txt";
	std::ofstream fout;
	std::stringstream rawLine;
	Data userData;

	std::cout << "Enter user coordinates [x,y,z] : " << std::endl;
	std::getline(std::cin, z, '\n');

	parseLine(rawLine, x, y, z);
	userData.setX(std::stoi(x));
	userData.setY(std::stoi(y));
	userData.setZ(std::stoi(z));

	userData.setLabel(model.predict(userData));
	model.addData(userData);

	//print dataset. add function.
	
	//override << operator for vector to output to file
	

	return 0;
}

void parseLine(std::stringstream& rawLine, std::string& x, std::string& y, std::string& z) {
	
	std::getline(rawLine, x, ',');
	std::getline(rawLine, y, ',');
	std::getline(rawLine, z, '\n');

	//check all function declared with &s for by-ref passing. make sure the definitions parameters have &s
}