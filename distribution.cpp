#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct DistributionItem
{
	//DistributionItem(uint8_t);
	uint8_t value;
	size_t weight;
};
int Find(uint8_t ch, vector <DistributionItem>&);



vector <DistributionItem> Distribution(const vector<uint8_t>& data)
{	
	vector <DistributionItem> distrib;
	for(auto symbol: data)
	{
		int pos = Find(symbol, distrib);
		if (pos == -1)
		{
			//DistributionItem temp(symbol);
			//distrib.push_back(temp);
			distrib.push_back({ symbol,1 });
		}
		else {
			distrib[pos].weight++;
		}
	}
	sort(distrib.begin(), distrib.end(),[](const auto const & a, const auto const & b) {
		return a.weight > b.weight ? true : false;
	});
	return distrib;
}

vector <uint8_t> Read(string &path) 
{
	ifstream file;
	file.open(path);
	vector <uint8_t> data;
	if (!file.is_open())
	{
		cout << "Îøèáêà";
	}
	else
	{
		char ch;
		while(file.get(ch))
		{
			uint8_t temp = ch;
			data.push_back(temp);

		}
	}
	file.close();
	return data;


}

vector <DistributionItem> GetDistribution()
{
	string path = "file.txt";
	auto data = Read(path);
	auto distribution = Distribution(data);
	return distribution;

}


int Find(uint8_t ch,vector <DistributionItem> &distrib)
{
	int i = 0;
	for (auto now : distrib) {
		if (now.value == ch)
		{
			return i;
		}
		i++;
	}
	return -1;
}


/*
DistributionItem::DistributionItem(uint8_t ch)
{
	value = ch;
	weight = 1;

}
*/
