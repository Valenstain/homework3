#include "AverageList.h"

AverageList::AverageList(std::vector<double> listValues) :
    listValues{ listValues }
{
}

void AverageList::addValue()
{
    double sum{};

    for (auto v : listValues)
    {
        sum += v;
    }

    listValues.push_back(sum / listValues.size());
}

std::ostream& operator << (std::ostream& os, const AverageList& av)
{
    for (auto val : av.listValues)
        os << val << " ";

    return os;
}
