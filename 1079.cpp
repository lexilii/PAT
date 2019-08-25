#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 100010; // 结点数少于10^5
struct node
{
	double data; // 数据域
	vector<int> child; // 指针域
};

node nodes[maxn];
double ans = 0;
int n;
double p, r;
void dfs(int index, int depth);

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	int k, child;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if (k == 0) // 叶节点标志
		{
			scanf("%lf", &nodes[i].data); // 叶节点货物量
		}
		else
		{
			for (int j = 0; j < k; j++)
			{
				scanf("%d", &child);
				nodes[i].child.push_back(child); // child为结点i的子节点
			}
		}
	}
	dfs(0, 0);
	printf("%.1f", ans);
	return 0;
}

void dfs(int index, int depth)
{
	if (nodes[index].child.size() == 0) // 到达叶节点
	{
		ans += nodes[index].data*pow(1 + r, depth+0.0)*p; // 累加叶节点货物价格
		return;
	}
	for (int i = 0; i < nodes[index].child.size(); i++)
	{
		dfs(nodes[index].child[i], depth + 1); // 递归访问子节点
	}
}
