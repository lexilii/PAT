#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int tcase = 1;
	while (T--)
	{
		long long A;
		long long B;
		long long C;
		scanf("%lld%lld%lld", &A, &B, &C);

		long long res = A + B;
		bool flag = false;
		if (A > 0 && B > 0 && res < 0)  //正溢出
		{
			flag = true;  //A+B>C
		}
		else if (A < 0 && B < 0 && res >= 0)  //负溢出
		{
			flag = false; //A+B<C
		}
		else  //无溢出 
		{
			if (res > C)
				flag = true;
			else
				flag = false;
		}

		if (flag)
		{
			printf("Case #%d: true\n", tcase++);
		}
		else
		{
			printf("Case #%d: false\n", tcase++);
		}
	}

}
