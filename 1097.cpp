#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
	int address, data, next;
	int order;
};
const int maxn = 100005;
const int table = 1000010;
Node node[maxn];
bool isExist[10005] = { false }; // 标记该绝对值是否已经出现 key<=10000

bool cmp(Node n1, Node n2);

int main()
{
	fill(isExist, isExist + 10005, false); // 初始化 isExist
	for (int i = 0; i < maxn; i++)
	{
		node[i].order = 2 * maxn; // 表示初始时均为无效结点
	}
	int n, begin, address;
	scanf("%d%d",&begin, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	// 统计未删除的结点个数 和 已删除的节点个数
	int cntValid = 0;
	int cntRemoved = 0; 
	int p = begin;
	while (p != -1)
	{
		if (isExist[abs(node[p].data)] == false) // 如果这个绝对值不存在
		{
			isExist[abs(node[p].data)] = true; // 标为已存在
			node[p].order = cntValid++;  // 不删除，编号从0开始
		}
		else
		{
			node[p].order = maxn + cntRemoved++; // 被删除，编号从maxn开始
		}
		p = node[p].next;
	}
	sort(node, node + maxn, cmp); // 按照order从小到大排序
	// 输出结果
	int cnt = cntValid + cntRemoved; // 有效结点个数
	for (int i = 0; i < cnt; i++)
	{
		if (i != cntValid - 1 && i != cnt - 1) // 非最后一个结点
		{
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		}
		else // 最后一个结点
		{
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}

bool cmp(Node n1, Node n2)
{
	return n1.order < n2.order;
}
