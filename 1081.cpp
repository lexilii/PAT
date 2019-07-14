#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long  ll;
struct Fraction
{
	ll up;
	ll down;
};

Fraction f[100];

Fraction add(const Fraction &f1, const Fraction &f2);
ll gcd(ll a, ll b);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &f[i].up, &f[i].down);
	}
	Fraction ans;
	ans.up = 0;
	ans.down = 1;
	int d;
	for (int i = 0; i < n; i++)
	{
		ans =  add(ans, f[i]);

		if (ans.up == 0)
		{
			ans.down = 1;
		}
		else
		{
			// 计算最大公约数进行约分
			d = gcd(abs(ans.down), abs(ans.up));
			ans.up /= d;
			ans.down /= d;
		}
	}

	if (ans.down == 1) //整数
	{
		printf("%lld", ans.up);
	}
	else if (ans.up > ans.down)  //假分数
	{
		printf("%lld %lld/%lld", ans.up / ans.down, abs(ans.up%ans.down), ans.down);
	}
	else // 真分数
	{
		printf("%lld/%lld", ans.up, ans.down);
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

ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	gcd(b, a%b);
}
