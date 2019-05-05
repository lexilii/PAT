#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
	int pos[100000];

	int n;
	scanf("%d", &n);
	int num;
	int left = n - 1; // 存放除 0 以外不在本位的数
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		pos[num] = i;
		if (pos[num] == num && num != 0) // 如果除 0 以外有在本位的数
			left--;
	}

	int k = 1;  // k 存放除 0  以外当前不在本位的最小的数
	int ans = 0;
	while (left > 0) // 只要还有数不在本位上
	{
		// 如果 0  在本位上，则选取一个当前不在本位上的数与之交换
		if (pos[0] == 0)
		{
			while (k < n)
			{
				if (pos[k] != k) 
				{
					swap(pos[0], pos[k]);  // 将 0 与 k 交换位置
					ans++;
					break;
				}
				k++;  // 判断 k+1是否在本位
			}
		}
		else  // 如果 0 不在本位，则将 0 所在位置的数的当前所处位置与 0 的位置交换
		{
			swap(pos[0], pos[pos[0]]);  // 将 0 与 pos[0] 交换位置
			ans++;
			left--;
		}

	}

	printf("%d\n", ans);

	return 0;
}
