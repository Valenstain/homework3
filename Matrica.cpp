#include "Matrica.h"

double Matrica::getUpValue(int x, int y)
{
	return data.at((y + x) % data.size()).at(y);
}

double Matrica::getDownValue(int x, int y)
{
	return data.at(std::abs(static_cast<int>((y + x) % data.size() - (data.size() - 1)))).at(y);
}

Matrica::Matrica(int x)
{
	std::srand(time(NULL));

	for (size_t i = 0; i < x; i++)
	{
		data.push_back(std::vector<double>{});

		for (size_t z = 0; z < x; z++)
			data.at(i).push_back(static_cast<double>(std::rand()) / 100);
	}
}

double Matrica::getDeterminant()
{
	if (data.size() > 2)
	{
		double d{};

		std::string s1{}, s2{}, sEnd{"0 "};

		for (int i = 0; i < data.size(); i++)
		{
			double m1 = getUpValue(i, 0);
			double m2 = getDownValue(i, 0);

			s1 = std::to_string(getUpValue(i, 0));
			s2 = std::to_string(getDownValue(i, 0));

			for (int z = 1; z < data.size(); z++)
			{
				m1 *= getUpValue(i, z);
				m2 *= getDownValue(i, z);

				s1 += " * " + std::to_string(getUpValue(i, z));
				s2 += " * " + std::to_string(getDownValue(i, z));
			}

			sEnd += " + " + s1 + " - " + s2;
			d += m1 - m2;
		}

		std::cout << sEnd << " = " << d << "\n\n";

		return d;
	}
	else if (data.size() == 2)
	{
		return (data.at(0).at(0) * data.at(1).at(1) - data.at(1).at(0) * data.at(0).at(1));
	}
	else if (data.size() == 1)
	{
		return data.at(0).at(0);
	}

	throw std::invalid_argument("It's impossible to calculate the determinant.");

	return 0;
}

std::ostream& operator << (std::ostream& os, const Matrica& matrica)
{
	for (auto v1 : matrica.data)
	{
		for (auto v2 : v1)
			os << v2 << '\t';

		os << std::endl;
	}

	return os;
}
