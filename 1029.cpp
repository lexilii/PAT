//=============================== 自己的方法 =======================================

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;

int a[maxn];

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int i = 0;
	int j = 0;
	int medium = (n + m - 1) / 2;  // 向下取整，-1是因为序列下标从0开始
	int count = -1;
	int b;
	int temp;
	scanf("%d", &b);
	while (count < medium)
	{
		if (i < n&&j < m)
		{
			if (a[i] < b)
			{
				temp = a[i];
				i++;
				count++;
			}
			else
			{
				temp = b;
				j++;
				count++;
				if (j < m)
					scanf("%d", &b);
			}
		}
		else if (i == n)
		{
			temp = b;
			j++;
			count++;
			if (j < m)
				scanf("%d", &b);

		}
		else if (j == m)
		{
			temp = a[i];
			i++;
			count++;
		}
	}

	printf("%d", temp);
	return 0;
}


//=============================== 别人的方法 =======================================
#include<cstdio>
const int INF = 0x7fffffff;//最大的int值
//const int INF = (1 << 31) - 1;
const int maxn = 200005;
int a[maxn];
int b;//边输入边处理b
int main()
{
	int m, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[n] = INF; // 便于判断序列结束
	scanf("%d", &m);
	int mid = (m + n - 1) / 2;
	scanf("%d", &b);
	int count = 0, l = 0, k = 0;
	while (count < mid)
	{
		if (a[l] < b) l++;
		else
		{
			k++;
			if (k == m) b = INF;//注意这里的判断条件是==m而不是m-1
			else scanf("%d", &b);
		}
		count++;
	}
	printf("%d", b < a[l] ? b : a[l]);
	return 0;
}
