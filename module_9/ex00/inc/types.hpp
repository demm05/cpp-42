#pragma once

#include <aio.h>
#include <map>
#include <string>
#include <vector>

typedef std::map<time_t, double> PriceMap;
typedef std::pair<time_t, double> PricePair;
typedef std::vector<PricePair> PriceVector;
