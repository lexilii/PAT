/*
1015. Reversible Primes (20)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime.
For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases.
Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/


#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

bool WhetherPrime(int n);

int main()
{
	int N;
	int D;
	int index = 0;
	while (1)
	{
		scanf("%d", &N);
		if (N < 0)
			break;
		scanf("%d", &D);
		index++;

		if (WhetherPrime(N))
		{
			int tempN = N;
			int remainder = 0;
			int result = 0;
			while (tempN != 0) //这里出错导致编译一直不通过！！！！！ 应该用 商 判断而不是余数
			{
				remainder = tempN%D;
				result = result*D + remainder;
				tempN = tempN / D;
			}
			if (WhetherPrime(result))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			printf("No\n");
		}

	}
	return 0;
}

//判断输入 n 是否为素数 
bool WhetherPrime(int n)
{
	if (n == 1 || n==0) //1不是素数
		return false;

	int sqrts = sqrt(n*1.0);
	for (int i = 2; i <= sqrts; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

