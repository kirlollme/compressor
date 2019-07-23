#include <vector>
#include <algorithm>
#include "distribution.h"
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

bool cmp(const Node &a, const Node &b);
vector <Node> GetStartTree(const vector <DistributionItem>&);
void FillTree(vector <Node> &tree);


vector <Node> Tree(vector <DistributionItem> &alph)
{
	vector <Node> tree = GetStartTree(alph);
	FillTree(tree);
	return tree;
}

bool cmp(const Node & a, const Node & b)
{
	if (a.weight > b.weight)
	{
		return true;
	}
	return false;
}

vector<Node> GetStartTree(const vector <DistributionItem> &alph)
{
	vector <Node> tree;

	for (auto now: alph)
	{
		Node temp;
		temp.value = now.weight;
		temp.weight = now.value;
		temp.level = 0;
		tree.push_back(temp);
	}
	sort(tree.begin(), tree.end(), cmp);
	for (int i = 0; i < tree.size(); i++) 
	{
		tree[i].pos = i;
	}

	return tree;
}

void FillTree(vector <Node> &tree)
{
	vector <Node> temptree = tree;
	while (temptree.size() != 1)
	{
		int last = temptree.size() - 1;
		Node TempLeft = temptree[last - 1];
		Node TempRight = temptree[last];
		Node Temp;
		Temp.left = TempLeft.pos;
		Temp.right = TempRight.pos;
		Temp.weight = TempRight.weight + TempLeft.weight;
		Temp.level = TempRight.level + 1;
		Temp.pos = tree.size();
		tree.push_back(Temp);
		temptree.pop_back();
		temptree.pop_back();
		temptree.push_back(Temp);
		sort(temptree.begin(), temptree.end(), cmp);

	
	}
	return;
}
