#pragma once

#ifndef distribution
#define distribution
using namespace std;
struct DistributionItem
{
	DistributionItem(uint8_t);
	uint8_t value;
	size_t weight;
};

vector <DistributionItem> GetDistribution();
#endif // !1
