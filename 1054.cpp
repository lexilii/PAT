#include  <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<int, int> pic;  // 2^24 在 int 的表示范围内 （2^31）

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int data;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &data);
			if (pic.find(data) == pic.end())  // 如果当前map中不存在 data
				pic[data] = 1;
			else   // 如果已经存在，则自增
				pic[data]++;
		}
	}

	int k = 0;  //  dominant color
	int max = 0; //  dominant color 出现的次数

	for (map<int, int>::iterator it = pic.begin(); it != pic.end(); it++)
	{
		if (it->second > max)
		{
			max = it->second;
			k = it->first;
		}
	}
	printf("%d", k);
	return 0;
}
