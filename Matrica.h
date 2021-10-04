#pragma once
#include "Header.h"

using matrix = std::vector<std::vector<double>>;

class Matrica
{
	matrix data;

	double getUpValue(int x, int y);

	double getDownValue(int x, int y);

public:
	Matrica(int x);

	double getDeterminant();

	friend std::ostream& operator << (std::ostream& os, const Matrica& matrica);
};
