#pragma once
#include "Header.h"

class AverageList
{
	std::vector<double> listValues;
public:
    AverageList(std::vector<double> listValues);
    void addValue();
    friend std::ostream& operator << (std::ostream& os, const AverageList& av);
};


