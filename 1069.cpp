#include <cstdio>
#include <algorithm>

using namespace std;

void toArray(int n, int arr[]);
int toNumber(int arr[]);
bool mysort(const int& i1, const int& i2);

int main()
{
	int n;
	scanf("%04d", &n);

	int arr[4];
	while (1)
	{
		toArray(n, arr);

		// 递增排序
		sort(arr, arr + 4);
		int min = toNumber(arr);

		// 递减排序
		sort(arr, arr + 4, mysort);
		int max = toNumber(arr);

		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);

		if (n == 0 || n == 6174)
		{
			break;
		}
	}

	return 0;
}

void toArray(int n, int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		arr[i] = n % 10;
		n = n / 10;
	}
	return;
}

int toNumber(int arr[])
{
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		ans = ans * 10 + arr[i];
	}
	return ans;
}

// 降序排列
bool mysort(const int& i1, const int& i2)
{
	return i1 > i2;
}
