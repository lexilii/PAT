#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int INF = (1 << 31) - 1;
const int maxn = 100000 + 5;

int a[maxn];
int leftMax[maxn];
int rightMin[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	// 统计每个数字左侧最大的数值
	leftMax[0] = 0; 
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] > leftMax[i - 1])
			leftMax[i] = a[i - 1];
		else
			leftMax[i] = leftMax[i - 1];
	}
	// 统计每个数字右边最小的数值
	rightMin[n - 1] = INF;
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i + 1] < rightMin[i + 1])
			rightMin[i] = a[i + 1];
		else
			rightMin[i] = rightMin[i + 1];
	}

	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		// 某位数 左侧最大的数值 <= 它  右侧最小的数值 >= 它 ，那么就符合快排的排序要求
		if (leftMax[i] <= a[i] && rightMin[i] >= a[i])
			ans.push_back(a[i]);
	}

	sort(ans.begin(), ans.end());

	int cnt = ans.size();

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d", ans[i]);
		if (i < cnt - 1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
