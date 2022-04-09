#pragma once
#include "Data.h"

class Classifier : public Data
{

protected:
/*! \brief Virtual function for Training models 
*
*  Trains the model with data points consisting of an x,y,z value
* 
* @param Data object reference
*/
	virtual void train(Data&) = 0;

/*! \brief Virtual function for predicting labels
*
* predicts label based on the supplied Data point by comapring against the entire set
* 
* @param Data object reference
* 
* @return predicted label of new data point
*/
	virtual std::string predict(Data&) = 0;
};

