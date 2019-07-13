#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	double sum = 0;
    double v =0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &v);
		sum += v * i*(n + 1 - i);
    //sum += i*(n + 1 - i) * v; // 错误， 整数相乘可能溢出
	}

	printf("%.2f", sum);
	return 0;
}
