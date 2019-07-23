#pragma once

#ifndef tree
#define tree
using namespace std;
struct Node
{
	int pos;
	int left;
	int right;
	int value;
	int weight;
	int level;
	bool visited = false;

};

vector <Node> Tree(vector <DistributionItem>&);
#endif // !tree

