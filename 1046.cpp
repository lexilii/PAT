#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> dist(n+1,0);
	int totalDist = 0;
	for (int i = 1; i < n+1; i++)
	{
		scanf("%d", &(dist[i]));
		totalDist += dist[i];
	}

	int m;
	scanf("%d", &m);


	while (m--)
	{
		int s = 0;
		int e = 0;
		int res = 0;
		scanf("%d%d", &s, &e);

		//将起点设置为较小的那个
		if (s > e)
		{
			int temp = s;
			s = e;
			e = temp;
		}

		for (int i = s; i < e; i++)
		{
			res += dist[i];
		}

		if (res < totalDist - res)
			printf("%d", res);
		else
			printf("%d", totalDist - res);

		if (m) //如果不是最后一个则输出换行
			printf("\n");
	}
	
	return 0;
}
