/*
1021. Deepest Root (25)
时间限制
1500 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/

#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int maxHeight = 0; // 最大深度
vector<vector<int>> v; // 保存各个顶点之间的联系
bool visit[10010];  // 保存顶点的访问状态
set<int> s; // 保存深度最大的根节点集合
vector<int> temp; //临时存储深度最大顶点的向量

/*深度优先遍历搜索*/
void dfs(int node, int height) 
{
	if (height > maxHeight) /* 如果当前节点的深度比最大深度还要大，则更新 临时存储深度最大顶点的向量 以及 最大深度 */
	{
		temp.clear();
		temp.push_back(node);
		maxHeight = height;
	}
	else if (height == maxHeight) /* 如果深度相同 ，则将相同深度的节点存入 temp */
	{
		temp.push_back(node);
	}

	visit[node] = true;  /* 置当前节点为已访问状态 */

	for (int i = 0; i < v[node].size(); i++) /* 遍历 v[]node] 即 当前节点 的所有孩子*/
	{
		if (visit[v[node][i]] == false)
			dfs(v[node][i], height + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n + 1); // 如果设为n，下面的循环会导致索引越界 
	int a, b, cnt = 0, s1 = 0;
	for (int i = 0; i < n - 1; i++) /* 输入父节点和子节点的联系 */
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	fill(visit, visit + 10010, false); /* 初始化visit */
	for (int i = 1; i <= n; i++) /* 节点编号从1到n */
	{
		if (visit[i] == false) /* 如果节点还未访问过 */
		{
			dfs(i, 1);
			if (i == 1) 
			{
				if (temp.size() != 0) 
					s1 = temp[0];
				for (int j = 0; j < temp.size(); j++)
					s.insert(temp[j]);
			}
			cnt++;
		}
	}
	if (cnt >= 2) 
	{
		printf("Error: %d components", cnt);
	}
	else 
	{
		temp.clear();
		maxHeight = 0;
		fill(visit, visit + 10010, false);
		dfs(s1, 1);
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}
