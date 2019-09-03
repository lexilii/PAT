#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 110;
vector<int> Node[maxn]; // 静态树，Node[i]存放节点i的孩子id
int hashTable[maxn] = { 0 }; // 记录每一层的结点个数
int level[maxn] = { 0 }; // 记录每一个节点数所在层数

void bfs();

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int id, k, child;
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			Node[id].push_back(child);
		}
	}
	bfs();

	int maxnum = 0, maxlevel = 1;
	for (int i = 0; i < maxn; i++)
	{
		if (hashTable[i] > maxnum)
		{
			maxnum = hashTable[i];
			maxlevel = i;
		}
	}

	printf("%d %d", maxnum, maxlevel);
	return 0;
}

void bfs()
{
	queue<int> q;
	q.push(1);
	level[1] = 1;
	while (!q.empty())
	{
		int index = q.front();
		q.pop();
		hashTable[level[index]]++; // 对应层的节点数+1
		for (int i = 0; i < Node[index].size(); i++)
		{
			level[Node[index][i]] = level[index] + 1;
			q.push(Node[index][i]);
		}
	}
}
