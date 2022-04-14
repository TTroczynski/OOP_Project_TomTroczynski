#pragma once
#include "OtherClassifier.h"
class OtherModel : protected OtherClassifier
{
public:

	void train(Data&);
	std::string predict(Data&);
	friend std::ostream& operator<<(std::ostream&, OtherModel& model);

};

