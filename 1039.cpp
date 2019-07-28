#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int m = 26 * 26 * 26 * 10+1;
vector<int> selectCourse[m];

int calIdx(char name[4])
{
	int res = 0;
	for (int i = 0; i < 3; i++)
	{
		res = res*26 + (name[i] - 'A');
	}
	res = res * 10 + (name[3] - '0');
	return res;
}
int main()
{
	int n, k;
	char name[5]; // 读入有"\0"

	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		int course;
		int s_num;
		scanf("%d%d", &course, &s_num);
		for (int i = 0; i < s_num; i++)
		{
			scanf("%s", name); 
			int id = calIdx(name);
			selectCourse[id].push_back(course);
		}
	}

	for (int j = 0; j<n; j++)
	{

		scanf("%s", name);
		int id = calIdx(name);
		int size = selectCourse[id].size();
		printf("%s %d", name, size);
		sort(selectCourse[id].begin(), selectCourse[id].end());

		for (int i = 0; i < size; i++)
		{
			printf(" %d", selectCourse[id][i]);
		}
		printf("\n");
	}
	return 0;
}
