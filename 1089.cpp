#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100 + 5;
bool isSame(int a[], int b[], int len);
bool insertSort(int temp[], int target[], int len);
bool mergeSort(int temp[], int target[], int len);


int main()
{
	int origin[maxn];
	int temp[maxn];
	int target[maxn];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &origin[i]);
		temp[i] = origin[i];
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &target[i]);
	}

	if (insertSort(temp, target, n))
	{
		printf("Insertion Sort\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d", temp[i]);
			if (i < n - 1)
				printf(" ");
		}
	}
	else
	{
		// 恢复 temp 序列
		for (int i = 0; i < n; i++)
		{
			temp[i] = origin[i];
		}
		mergeSort(temp, target, n);
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d", temp[i]);
			if (i < n - 1)
				printf(" ");
		}

	}
	return 0;
}

// 判断数组a和b是否相同
bool isSame(int a[], int b[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}


bool insertSort(int temp[],int target[], int len)
{
	bool flag = false; // 记录是否存在排序的中间步骤与target数组相同
	for (int i = 1; i < len; i++)
	{
		if (i != 1 && isSame(temp, target, len)) // 中间步骤与目标序列相同，且不是初始序列
		{
			flag = true;
		}

		// 以下为插入部分
		int t = temp[i];
		int j = i;
		while (j > 0 && temp[j - 1] > t)
		{
			temp[j] = temp[j - 1];
			j--; 
		}
		temp[j] = t;
		if (flag == true)
			return true; // 说明找到了目标序列
	}

	return false;  // 没有找到目标序列
}


bool mergeSort(int temp[], int target[], int len)
{
	bool flag = false;
	for (int step = 2; step / 2 < len; step *= 2)
	{
		if (step != 2 && isSame(temp, target, len))
		{
			flag = true;  // 中间步骤与目标序列相同，且不是初始序列
		}
		for (int i = 0; i < len; i += step)
		{
			sort(temp + i, temp + min(i + step, len));
		}
		if (flag == true)
		{
			return true;
		}
	}
	return false;
}
