#pragma once
#ifndef dfs
#define dfs
#include <vector>

using namespace std;
struct TableItem
{
	string code;
	uint8_t value;
};
vector <TableItem> GetTable(vector <Node>);
#endif // !dfs
