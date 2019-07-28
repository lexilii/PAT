#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> course[2501]; // course[i]存放选择第i门课的所有学生编号
char stu[40001][5]; // 最多有40000个学生

bool cmp(int i1, int i2)
{
	return(strcmp(stu[i1], stu[i2]) < 0); // <0 表示 c1<c2
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int c;
		scanf("%s %d", stu[i], &c); // 学生姓名及选课数
		for (int j = 0; j < c; j++)
		{
			int courseID;
			scanf("%d", &courseID);
			course[courseID].push_back(i);  // 将学生 i 加入第courseID门课中
		}
	}
	for (int i = 1; i <= k; i++)  // 总共k门课
	{
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++)
			printf("%s\n", stu[course[i][j]]);
	}

	return 0;
}
