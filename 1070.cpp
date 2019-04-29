#include <cstdio>
#include <algorithm>

using namespace std;

struct moonCake
{
	double storage; // 库存量
	double sell; // 总售价
	double price;// 单价
};

moonCake cakes[1001];

bool cmp(moonCake &c1, moonCake &c2)
{
	return c1.price > c2.price;
}

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf",&cakes[i].storage);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &cakes[i].sell);
		cakes[i].price = cakes[i].sell / cakes[i].storage;
	}

	sort(cakes, cakes + n, cmp);

	double profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (cakes[i].storage <= d)
		{
			profit += cakes[i].sell;
			d = d - cakes[i].storage;
			//if (d == 0)
			//	break;
		}
		else  //cakes[i].storage > d
		{
			profit += d*cakes[i].price;
			break;
		}
	}

	printf("%.2f", profit);

	return 0;
}
