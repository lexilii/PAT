#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int binaruSearch(int i, int n, long long x);

vector<int> seque(100001);

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &seque[i]);
	}

	sort(seque.begin(), seque.begin() + n);
	int ans = 1; // 最大长度
	for (int i = 0; i < n; i++)
	{
		// 在 a[i+1]~a[n-1] 中寻找第一个 > a[i]*p 的数，返回其位置
		int j = binaruSearch(i, n, (long long)seque[i] * p);
		ans = max(ans, j - i);
	}

	printf("%d", ans);
	return 0;
}

// 在 [i+1,n-1] 的范围内查找第一个大于x的数的位置
int binaruSearch(int i,int n, long long x)
{
	// 如果所有数都<=x，则返回n
	if (seque[n - 1] <= x)
		return n;
	int left = i + 1;
	int right = n - 1;
	int mid; // 在[i+1,n-1]范围内查找
	while (left < right)
	{
		mid = (left + right) / 2;
		if (seque[mid] > x)
		{
			right = mid;
		}
		else //seque[mid] <= x
		{
			left = mid + 1;
		}
	}

	return left; // while 结束时 left == right，返回任意一个均可
}
