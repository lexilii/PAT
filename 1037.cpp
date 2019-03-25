#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool psort(const int& p1, const int& p2)
{
	return p1 > p2; //正数从大到小排列
}
bool nsort(const int& n1, const int& n2)
{
	return n1 < n2; //负数从小到大排列
}
int main()
{
	int nc, np;
	vector<int> coupon_p;
	vector<int> coupon_n;
	vector<int> value_p;
	vector<int> value_n;
	int x;

	scanf("%d", &nc);
	for (int i = 0; i < nc; i++)
	{
		scanf("%d", &x);
		if (x >= 0)
			coupon_p.push_back(x);
		else
			coupon_n.push_back(x);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &x);
		if (x >= 0)
			value_p.push_back(x);
		else
			value_n.push_back(x);
	}
	sort(coupon_p.begin(), coupon_p.end(), psort);
	sort(coupon_n.begin(), coupon_n.end(), nsort);
	sort(value_p.begin(), value_p.end(), psort);
	sort(value_n.begin(), value_n.end(), nsort);

	int sum = 0;

	int size = min(coupon_p.size(), value_p.size());
	for (int i = 0; i < size; i++)
	{
		sum = sum + coupon_p[i] * value_p[i];
	}
	size = min(coupon_n.size(), value_n.size());
	for (int i = 0; i < size; i++)
	{
		sum = sum + coupon_n[i] * value_n[i];
	}
	printf("%d", sum);

	return 0;
}
