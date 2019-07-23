#include <vector>
#include <string>
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

struct TableItem 
{
	string code;
	uint8_t value;
};
void GetCode(vector <Node> &Current, vector<TableItem> &table, int pos, string code);



vector<TableItem> GetTable(vector <Node> tree)
{
	vector<TableItem> table;
	GetCode(tree, table, tree.size() - 1,"");
	return table;

}

void GetCode(vector <Node> &Current, vector<TableItem> &table,int pos, string code)
{
	if (Current[pos].level == 0)
	{
		TableItem temp;
		temp.code = code;
		temp.value = Current[pos].weight;
		table.push_back(temp);
		return;
	}
	else
	{
		string left = code + "1";
		GetCode(Current, table, Current[pos].left, left);
		string right = code + "0";
		GetCode(Current, table, Current[pos].right, right);
	}


}