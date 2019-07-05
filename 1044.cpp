#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int sum[100001];

struct Pair
{
	int i;
	int j;

	Pair(int I, int J) :i(I), j(J) {};
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	// 录入的同时求和
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] = sum[i - 1] + sum[i];
	}

	vector<Pair> res;
	int minSum = 1000000000;
	// 对序列起点进行枚举
	for (int i = 1; i <= n; i++)
	{
		int begin = i;
		int end = n;
		int mid;
		int sumSeq;

		// 二分法寻找
		while (begin < end)  // 因为现在找的是 >= m 的数
		{
			mid = (begin + end) / 2;
			sumSeq = sum[mid] - sum[i - 1];
			if (sumSeq >= m)
				end = mid;
			else
				begin = mid + 1;
		}
		// 循环退出的条件是 begin = end
		sumSeq = sum[end] - sum[i - 1];
		if (sumSeq >= m)
		{
			if (sumSeq < minSum)
			{
				res.clear();
				res.push_back(Pair(i, end));
				minSum = sumSeq;
			}
			else if (sumSeq == minSum)
			{
				res.push_back(Pair(i, end));
			}
		}
		else
		{
			break; // 当前起点找不到 >= m 的序列，再往后也不可能了
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		printf("%d-%d\n", res[i].i, res[i].j);
	}
	return 0;
}
