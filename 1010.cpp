#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int map[256]; // char 类型取值范围是 0~255  ，将 ‘0’~‘9’ ‘a’~‘z’ 与  0~35  对应
long long inf = (1LL << 63) - 1; // long long 的最大值 2^63-1


long long convertTen(char x[], long long radix);
int findLargestDigit(char n2[]);
long long findRadix(char n2[], long long t);

int main()
{
	char n1[11], n2[11], temp[11];
	int tag;
	long long radix;

	scanf("%s %s %d %d", n1, n2, &tag, &radix);

	// 交换顺序，使得 radix 始终对应 n1
	if (tag == 2)
	{
		strcpy(temp, n1);
		strcpy(n1, n2);
		strcpy(n2, temp);
	}

	for (char c = '0'; c <= '9'; c++)
	{
		map[c] = c - '0';  // 将 ‘0’~‘9’映射到0~9
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		map[c] = c - 'a' + 10;  // 将 'a'~'z'映射到10~35
	}

	long long t = convertTen(n1, radix); // 将 n1 从 radix 转换为十进制，方便后续比较
	long long result = findRadix(n2, t);
	if (result == -1)
		printf("Impossible");
	else
		printf("%lld", result);

	return 0;
}

// 进制转换过程中就可以判断 是否溢出 或 大于n1的十进制
long long convertTen(char x[], long long radix)
{
	long long ans = 0;
	int len = strlen(x);
	for (int i = 0; i < len; i++)
	{
		ans = ans*radix + map[x[i]];
	}
	return ans;
}

// 求最大位数
int findLargestDigit(char n2[])
{
	int ans = -1;
	int len = strlen(n2);
	for (int i = 0; i < len; i++)
	{
		if (map[n2[i]] > ans)
			ans = map[n2[i]];
	}
	return ans+1;  // 最大位数为ans，说明进制数的底线是 ans+1
}

long long findRadix(char n2[], long long t)
{
	// 确定二分查找上下界
	long long low = findLargestDigit(n2);
	long long high = max(low, t);

	// 二分查找
	long long mid, sum;
	while (low <= high)
	{
		mid = (low + high) / 2;
		sum = convertTen(n2, mid); // 将 n2 从 mid 进制转换为十进制
		if (sum<0 || sum>t) // 结果溢出 或 大于 n1 的十进制
			high = mid - 1;
		else if (sum < t) // 结果小于 n1 的十进制
			low = mid + 1;
		else
			return mid;
	}
	return -1; // 没有找到
}
