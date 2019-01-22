/*
1003 Emergency （25 分）

Sample Input:

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
 
Sample Output:

2 4
*/

#include <iostream>
#include <cstdio>

using namespace std;

//题目所需常量与变量
const int INF = 10000000; //注意这个值不要超过int的表示范围！！！！太大变成负值就会出错
const int maxn = 510;
int N, M, C1, C2, L;  //城市数，道路数，所在城市，目标城市，每条道路长度

					  //关于边的变量，存储边权（此处为城市间的距离）
int map[maxn][maxn];

//关于点的变量，存储点权
int resc[maxn]; //每个城市的救援队数量
int visit[maxn];//标志该城市是否访问过 0未访问 1已访问

//关于路径的变量
int dist[maxn]; //所在城市到其余各个城市的最短路径长度
int sum[maxn];  //所在城市到其余各个城市的最短路径条数
int num[maxn];  //所在城市到其余各个城市的最短路径上所能召集的最大救援队数量

//函数声明
void Dijkstra();

int main()
{
	/*读取数据*/
	scanf("%d %d %d %d", &N, &M, &C1, &C2);

	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			map[i][j] = INF;

	for (int i = 0; i < N; i++)
		scanf("%d", &resc[i]);
	for (int i = 0; i < M; i++)
	{
		int c1, c2;
		scanf("%d %d %d", &c1, &c2, &L);
		map[c1][c2] = L;
		map[c2][c1] = L;
	}


	/*用 Dijkstra 算法求源点到各个目标点的最短距离*/
	Dijkstra();

	/*输出起点到目标城市的最短路径数目，及能召集的最大救援队数*/
	printf("%d %d", sum[C2], num[C2]);
	//cout << sum[1];
	return 0;
}

void Dijkstra()
{
	/*初始化*/
	//其余节点初始化
	for (int i = 0; i < N; i++)
	{
		visit[i] = 0; //访问标记 0 表示未访问 1 表示已访问
		dist[i] = INF;//起点到其余各点的最短距离
		sum[i] = 0;   //起点到各点最短路径的数目
		num[i] = 0;   //起点到各点所有最短路径中能召集的最大救援人数
	}
	//起点初始化
	dist[C1] = 0;
	sum[C1] = 1;
	num[C1] = resc[C1];


	while (1)
	{
		int min = INF;
		int index = -1;

		//在 未访问过 的所有节点中找到距离 起点 最近的节点
		for (int i = 0; i < N; i++)
		{
			if (visit[i] == 0 && dist[i] < min)
			{
				min = dist[i];
				index = i;
			}
		}

		if (min == INF || index == C2)
			break; //若所有节点已访问或当前搜索到的最近节点就是要到达的目标节点则跳出循环

		visit[index] = 1; //更新找到的最近节点状态


		//对 未访问过 的所有节点进行遍历  若 dist[index]+map[index][j]<dist[j] 则更新dist[j]
		for (int j = 0; j < N; j++)
		{
			int tempDist = map[index][j] + dist[index];
			int tempNum = num[index] + resc[j];
			
			//若当前城市已访问过 或 城市index 和 城市j 之间不连通 则跳过
			if (visit[j] == 1 || map[index][j] == INF)
				continue;
			//若 从起点经过城市index到达城市j的路径 比 起点直达城市j的路径 更短，则更新所有属性
			if (tempDist < dist[j])
			{
				dist[j] = tempDist;
				sum[j] = sum[index];
				num[j] = tempNum;
			}
			//若 从起点经过城市index到达城市j的路径 与 起点直达城市j的路径 相等，则更新最短路径数
			else if (tempDist == dist[j])
			{
				sum[j] = sum[index] + sum[j];
				//若新经过index的路径上能够召集的人手数更多（点权更大），则更新最大人手数
				if (tempNum > num[j])
				{
					num[j] = tempNum;
				}
			}
		}
	}
}
