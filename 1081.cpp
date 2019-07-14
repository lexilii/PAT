#include <cstdio>

struct Fraction
{
	int up;
	int down;
};

Fraction f[100];

Fraction add(const Fraction &f1, const Fraction &f2);
int gcd(long long a, long long b);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d/%d", &f[i].up, &f[i].down);
	}
	Fraction ans;
	ans.up = 0;
	ans.down = 1;
	int d;
	for (int i = 0; i < n; i++)
	{
		ans =  add(ans, f[i]);

		// 计算最大公约数进行约分
		if (ans.up > ans.down)
		{
			d = gcd(ans.up, ans.down);
		}
		else
		{
			d = gcd(ans.down, ans.up);
		}

		ans.up /= d;
		ans.down /= d;

	}

	if (ans.up == 0)
	{
		printf("0");
		return 0;
	}
	else if (ans.up < ans.down)
	{
		printf("%d/%d", ans.up, ans.down);
	}
	else
	{
		if(ans.up%ans.down != 0)
			printf("%d %d/%d", ans.up / ans.down, ans.up%ans.down, ans.down);
		else
			printf("%d", ans.up / ans.down);
	}

	return 0;
}

Fraction add(const Fraction &f1, const Fraction &f2)
{
	Fraction ans;
	ans.down = f1.down*f2.down;
	ans.up = f1.up*f2.down + f1.down*f2.up;

	return ans;
}

int gcd(long long a, long long b)
{
	if (b == 0)return a;
	gcd(b, a%b);
}
