#pragma once
#include "Classifier.h"
#include <iostream>

class OtherModel : protected Classifier
{


public:

	void train(Data&);
	std::string predict(Data&);
	friend std::ostream& operator<<(std::ostream&, OtherModel& model);

};

