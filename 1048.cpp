// ====================== 哈希表 ==========================


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


//========================== 二分法 ===============================

#include <cstdio>
#include <algorithm>

using namespace std;

int coin[100001];

int findIndx(int left, int right, int key);

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}

	sort(coin, coin + n); // 默认升序排列
	int i;
	for (i = 0; i < n; i++)
	{
		int pos = findIndx(0, n - 1, m - coin[i]);  // 寻找 m - coin[i]
		if (pos != -1 && pos != i) // 找到且不为coin[i]
		{
			printf("%d %d\n", coin[i], coin[pos]);
			break;
		}
	}
	if (i == n)
		printf("No Solution\n");
	
	return 0;
}

int findIndx(int left, int right, int key)
{
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (coin[mid] > key)
			right = mid - 1;
		else if (coin[mid] < key)
			left = mid + 1;
		else
			return mid;
	}
	return -1; // 没有找到
}
