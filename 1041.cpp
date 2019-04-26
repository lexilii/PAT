#include <cstdio>
#include <iostream>

using namespace std;

struct Hash
{
	int count = 0;
	int order = 0;
};

Hash hashTable[10001];

int main()
{
	int n;
	scanf("%d", &n);

	int order = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		// 第一次读入则记录读取顺序
		if (hashTable[num].count == 0)
		{
			order++;
			hashTable[num].order = order;
			hashTable[num].count++;
		}
		else
		{
			hashTable[num].count++;
		}
	}

	bool flag = false;
	int minOrder = 10000000;
	int result = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (hashTable[i].count == 1)
		{
			flag = true;
			if (hashTable[i].order < minOrder)
			{
				minOrder = hashTable[i].order;
				result = i;
			}
		}
	}

	if (flag == false)
	{
		printf("None\n");
	}
	else
	{
		printf("%d\n", result);

	}

	return 0;
}
