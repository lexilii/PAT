#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct Node
{
	int address, data, next;
	int order; // 结点在链表上的序号，无效结点记为maxn
};

bool cmp(Node a, Node b)
{
	return a.order < b.order;  // 按order从小到大排序
}

Node nodes[maxn];
int main()
{
	for (int i = 0; i < maxn; i++)
	{
		nodes[i].order = maxn; // 初始化全部为无效结点
	}

	int begin, n, k, address;
	scanf("%d%d%d", &begin, &n, &k); // 起始地址、结点个数、步长
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &nodes[address].data, &nodes[address].next);
		nodes[address].address = address;
	}

	int p = begin, count = 0; // count 计数有效结点数目
	while (p != -1) // 遍历链表，找出单链表的所有有效结点
	{
		nodes[p].order = count++;
		p = nodes[p].next;
	}

	sort(nodes, nodes + maxn, cmp); // 按照order顺序从小到大排列 ，有效结点为前 count 个
	n = count; 

	// 至此单链表已经形成，接下来按照题目顺序输出
	for (int i = 0; i < n / k; i++) // 枚举完整的 n/k 块
	{
		for (int j = (i + 1)*k - 1; j > i*k; j--) // 第 i 块倒着输出
		{
			printf("%05d %d %05d\n", nodes[j].address, nodes[j].data, nodes[j - 1].address);
		}
		// 接下来处理每个块的最后一个结点
		printf("%05d %d ", nodes[i*k].address, nodes[i*k].data);
		if (i < n / k - 1) // 如果不是最后一个块，就指向下一块的最后一个结点
		{
			printf("%05d\n", nodes[(i + 2)*k - 1].address);
		}
		else // 如果是最后一块
		{
			if (n%k == 0) // 恰好是最后一个结点
			{
				printf("-1\n");
			}
			else // 剩下的不完整块 按顺序输出
			{
				printf("%05d\n", nodes[(i + 1)*k].address);
				for (int i = n / k*k; i < n; i++)
				{
					printf("%05d %d ", nodes[i].address, nodes[i].data);
					if (i < n - 1)
						printf("%05d\n", nodes[i + 1].address);
					else
						printf("-1\n");
				}
			}
		}
	}

	return 0;
}
