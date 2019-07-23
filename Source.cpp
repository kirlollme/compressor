#include <iostream> 
#include <vector>
#include "distribution.h"
#include "tree.h"
#include "dfs.h"

using namespace std;

int main(){
	vector <DistributionItem> distrib = GetDistribution();
	vector <Node> a = Tree(distrib);
	vector<TableItem> table = GetTable(a);
	return 0;
}