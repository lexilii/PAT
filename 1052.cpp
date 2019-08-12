#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;
struct Node {
	int address, data, next;
	bool flag; // 节点是否在链表上
};

Node node[maxn];

bool cmp(Node n1, Node n2);

int main()
{
	// 初始化静态链表
	for (int i = 0; i < maxn; i++)
	{
		node[i].flag = false;
	}

	int n, begin, address;
	scanf("%d%d", &n, &begin);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address] .address = address;
	}

	int cnt = 0, p = begin;
	// 枚举链表，对flag进行标记，同时统计有效结点个数
	while (p != -1)
	{
		node[p].flag = true;
		cnt++;
		p = node[p].next;
	}

	if (cnt == 0)
	{
		printf("0 -1\n"); // 特判，链表中没有结点
	}
	else
	{
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", cnt, node[0].address);
		for (int i = 0; i < cnt; i++)
		{
			if (i != cnt - 1) // 没到最后一个结点
			{
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
			}
			else
			{
				printf("%05d %d -1\n", node[i].address, node[i].data);
			}
		}
	}
	return 0;
}

bool cmp(Node n1, Node n2)
{
	if (n1.flag == true && n2.flag == true) 
		return n1.data < n2.data;  // 如果都是有效结点，就按 data 从小到大排序
	else        
		return n1.flag > n2.flag;  // 只要有一个是无效结点，就把它放到后面
}
