#include <cstdio>

using namespace std;

int HashTable[1001] = { 0 };

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int cur;
		scanf("%d", &cur);
		HashTable[cur]++;
	}

	int v1 = -1;
	int v2 = -1;
	bool flag = false;
	for (int i = 0; i <= 500; i++)
	{
		if (HashTable[i] != 0)
		{
			v2 = m - i;
			if((i == v2 && HashTable[v2]-1 > 0)|| (i != v2 && HashTable[v2] > 0))
			{
				v1 = i;
				v2 = m - i;
				flag = true;
				break;
			}
		}
	}
	if (!flag)
	{
		printf("No Solution\n");
	}
	else
	{
		printf("%d %d\n", v1, v2);
	}

	return 0;
}
