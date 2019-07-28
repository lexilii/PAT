#include <set>
#include <cstdio>

using namespace std;

set<int> sets[55];
double calSimi(const set<int> &s1, const set<int> &s2);

int main()
{
	int n;
	scanf("%d", &n); // 总的 set 数
	for (int i = 1; i <= n; i++)
	{
		int num; // 当前set中的元素个数
		scanf("%d", &num);

		int memb;
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &memb);
			sets[i].insert(memb);
		}
	}

	int k; 
	scanf("%d", &k); // 查询数
	int s1, s2;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &s1, &s2);
		printf("%.1f%%\n", calSimi(sets[s1], sets[s2]));
	}
	return 0;
}


double calSimi(const set<int> &s1, const set<int> &s2)
{
	int nc = 0;
	int nt = s2.size();
	
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		if (s2.find(*it) != s2.end())
			nc++;
		else
			nt++;
	}
	return (nc*100.0 / nt);
}
