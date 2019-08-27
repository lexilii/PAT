#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void dfs(int root, int depth);

vector<int> child[100005]; // 存放树

double p, r;
int n, maxDepth = 0, num = 0; // 最大深度，最大深度的叶节点个数
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r = r / 100;
	int father, root;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &father);
		if (father != -1)
			child[father].push_back(i);
		else
			root = i;
	}

	dfs(root, 0);

	printf("%.2f %d\n", p*pow((1 + r), maxDepth), num);
	return 0;
}


void dfs(int root, int depth)
{
	if (child[root].size() == 0) // 到达叶节点
	{
		if (depth > maxDepth)
		{
			maxDepth = depth;
			num = 1;
		}
		else if (depth == maxDepth)
			num++;

		return;
	}

	for (int i = 0; i < child[root].size(); i++)
		dfs(child[root][i], depth + 1); // 递归访问节点 root 的子节点
}
