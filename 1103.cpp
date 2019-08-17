#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

void init();
void DFS(int index, int cur_k, int cur_sum, int cur_facSum); 

int n, k, p;
int maxFacSum = -1; // 记录最大底数之和
vector<int> fac;
vector<int> ans;
vector<int> temp;
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	init();
	int index = fac.size() - 1;

	DFS(index, 0, 0, 0); // 从fac的最后一位开始往前搜索

	if (maxFacSum == -1)
		printf("Impossible\n"); // 没有找到合适序列
	else
	{
		printf("%d = %d^%d", n, ans[0],p);
		for (int i = 1; i < ans.size(); i++)
		{
			printf(" + %d^%d", ans[i], p);
		}
	}
	
	return 0;
}

void init()
{
	int i = 0;
	int temp = 0;
	while (temp <= n)
	{
		fac.push_back(temp); // 先把0加入队列，即 0^p 次方
		temp = pow(++i, p);
	}
}

void DFS(int index, int cur_k, int cur_sum, int cur_facSum)
{
	if (cur_sum == n && cur_k == k) // 找到一个满足的序列
	{
		if (cur_facSum > maxFacSum) // 底数之和更优
		{
			maxFacSum = cur_facSum; // 更新最大底数之和
			ans = temp; // 用一个vector覆盖另一个，且是深复制
		}
		return; 
	}
	else if (cur_sum > n || cur_k > k) // 这种情况下不会有答案
		return; 
	else
	{
		if (index >= 1) // fac[0] = 0 不需要选择
		{
			// “选”的分支
			temp.push_back(index); // 将底数index加入临时序列
			DFS(index, cur_k + 1, cur_sum + fac[index], cur_facSum + index);
			temp.pop_back();
			// “不选”的分支
			DFS(index - 1, cur_k, cur_sum, cur_facSum);
		}
	}
}



