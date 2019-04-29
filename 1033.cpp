#include <cstdio>
#include <algorithm>

using namespace std;

struct Station
{
	double p; //the unit gas price
	double dis; //distance between this station and Hangzhou
}stations[501];

bool cmp(Station &s1, Station &s2)
{
	return s1.dis < s2.dis; //由近及远排列
}

int main()
{
	double c_max;  //maximum capacity of the tank
	double d; //the distance between Hangzhou and the destination city
	double d_avg; //the average distance per unit gas that the car can run
	int n; //the total number of gas stations

	scanf("%lf%lf%lf%d", &c_max, &d, &d_avg, &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &stations[i].p, &stations[i].dis);
	}

	// 将终点也视作加油站
	stations[n].dis = d;
	stations[n].p = 0;

	// 按照距起点的距离，由近及远进行排序
	sort(stations, stations + n, cmp);

	////// 分情况讨论

	// 因为油箱初始为空，此时无法出发
	if (stations[0].dis != 0)  
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}

	// 能够出发
	double max_run = c_max*d_avg;

	int now = 0;  // 当前所处加油站的编号
	double nowTank = 0; // 当前油箱剩余油量

	double cost = 0.0;
	while (now < n)
	{
		int next = -1;  // 最低油价对应加油站的编号
		int minPrice = 10000000; // 最低油价

		for (int i = now + 1; i <= n && stations[now].dis + max_run >= stations[i].dis; i++)
		{
			// 如果油价比最低油价更低
			if (stations[i].p < minPrice)
			{
				// 更新最低油价
				minPrice = stations[i].p;
				next = i;
			}
			//如果找到第一个油价比当前油价低，直接中断循环
			if (minPrice < stations[now].p)
			{
				break;
			}
		}

		// 在有效距离内不存在可用加油站
		if (next == -1)
			break;

		// 为能找到可到达的加油站next计算花费
		double need = (stations[next].dis - stations[now].dis) / d_avg;  		//从now到next需要的油量

		// 如果存在油价低于当前油价,只买足够到达加油站next的油
		if (minPrice < stations[now].p)
		{
			// 当前油量不足need
			if (nowTank < need)
			{
				cost += stations[now].p*(need - nowTank); //补足need
				nowTank = 0; // 到达next后油量为0
			}
			else //当前油量超过need
			{
				nowTank -= need; // 不需加油，直接到达加油站
			}
		}
		else // 不存在油价低于当前油价 则加满
		{
			cost += stations[now].p*(c_max - nowTank);
			nowTank = c_max - need; // 到达加油站next之后的油量
		}
		now = next; // 到达下一站

	}

	if (now == n)
	{
		printf("%.2f\n", cost);
	}
	else
	{
		printf("The maximum travel distance = %.2f\n", stations[now].dis + max_run);
	}
		
}
