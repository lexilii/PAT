/*
1013. Battle Over Cities (25)

It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
*/

#include <cstdio>
#include <iostream>

void Dfs(int j, int n);

int map[1001][1001] = { 0 }; //因为n<1000
bool visit[1001] = { 0 };

int main()
{
	int n, m, k; //总的城市数 连通道路数 需要核对的城市数
	int count = 0;//标记连通分量的数目
	scanf("%d %d %d", &n, &m, &k);

	int a, b;//道路连通的两个城市

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b); //注意城市标号从1到n
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 0; i < k; i++) //需要分别考虑 k 个城市被攻占的情况
	{
		std::fill(visit, visit + 1001, false);//所有节点初始化为未访问状态
		int city;
		scanf("%d", &city);
		count = 0;
		visit[city] = true; //被攻占的城市标记为true
		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == false)
			{
				Dfs(j, n); //调用一次就把一个连通路上的所有点标记为 已访问 ，然后这些点可以看做一个独立顶点
				count++;
			}
		}
		printf("%d\n", count-1);//n 个独立顶点的图只需要 n-1 条边即可连通
	}
}

void Dfs(int j, int n)
{
	visit[j] = true;//标为已访问
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false && map[j][i] == 1) //连通且未访问的子节点
		{
			Dfs(i, n);
		}
	}
}
