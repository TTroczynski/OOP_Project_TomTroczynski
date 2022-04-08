#pragma once
#include "Data.h"

class Classifier : public Data
{

protected:
	virtual void train(Data&) = 0;
	virtual std::string predict(Data&) = 0;
};

