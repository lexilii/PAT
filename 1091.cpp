#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int pixel[60][1286][128]; // 三维01矩阵
bool inq[60][1286][128] = { false };
struct Node
{
	int x, y, z; // 位置(x,y,z)
};

int X[6] = { 0,0,0,0,1,-1 };
int Y[6] = { 0,0,1,-1,0,0 };
int Z[6] = { 1,-1,0,0,0,0 };

bool jude(int x, int y, int z, const int& n, const int& m, const int& l); // 判断坐标（x,y,z）是否需要访问
int bfs(int x, int y, int z, const int& n, const int& m, const int& l, const int& t);

int main()
{
	int m, n, l, t;
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (int z = 0; z < l; z++)  // 切片层
	{
		for (int y = 0; y<m; y++)  // 行
		{
			for (int x = 0; x < n; x++) // 列
			{
				scanf("%d", &pixel[z][y][x]);
			}
		}
	}

	int ans = 0; // 记录卒中核心区中 1 的总个数
	for (int z = 0; z < l; z++)  // 切片层
	{
		for (int x = 0; x < n; x++) // 列
		{
			for (int y = 0; y < m; y++)  // 行
			{
				if (pixel[z][y][x] == 1 && inq[z][y][x] == false) // 当前点为 1 且未被访问
				{
					ans += bfs(x, y, z, n, m, l, t);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

bool jude(int x, int y, int z, const int& n, const int& m, const int& l) // 判断坐标（x,y,z）是否需要访问
{
	//越界
	if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= l)
		return false;

	// 为0 或 已入队
	if (pixel[z][y][x] == 0 || inq[z][y][x] == true)
		return false;

	return true;
}

// 访问（x,y,z）所在的块，将其中的1 对应的访问量都置为true
int bfs(int x,int y, int z, const int& n, const int& m, const int& l, const int& t)
{
	int total = 0;  // 计数当前块中1的个数
	queue<Node> q; // 定义节点队列

	Node node;
	node.x = x;
	node.y = y;
	node.z = z;
	q.push(node);
	inq[z][y][x] = true;

	while (!q.empty()) // 当队列不为空
	{
		Node top = q.front(); // 取出队首元素
		q.pop();
		total++;
		for (int i = 0; i < 6; i++)
		{
			int newx = X[i] + top.x;
			int newy = Y[i] + top.y;
			int newz = Z[i] + top.z;

			if (jude(newx, newy, newz, n, m, l))
			{
				node.x = newx;
				node.y = newy;
				node.z = newz;
				q.push(node);
				inq[newz][newy][newx] = true; // 设置当前点已入队
			}
		}
	}
	if (total >= t)
		return total; // 超过阈值，有效
	else
		return 0; // 否则该块不计数

}




