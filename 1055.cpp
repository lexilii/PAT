#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Info
{
	char name[10];
	int age;
	int nworth;
};

bool cmp(const Info& in1, const Info& in2)
{
	if (in1.nworth != in2.nworth)
		return in1.nworth > in2.nworth;
	else if (in1.age != in2.age)
		return in1.age < in2.age;
	else
		return strcmp(in1.name, in2.name) < 0;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vector<Info> richests(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d", richests[i].name, &(richests[i].age), &(richests[i].nworth));
	}

	sort(richests.begin(), richests.end(), cmp);

	int validNum = 0;
	int ageNum[201] = { 0 }; //某年龄的人数
	vector<Info> valid;
	for (int i = 0; i < N; i++)
	{
		if (ageNum[richests[i].age] < 100)
		{
			ageNum[richests[i].age]++;
			valid.push_back(richests[i]);
		}
	}

	for (int i = 0; i < K; i++)
	{
		int m;
		int amin, amax;
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i+1);

		int cnt = 0; // 已输出的人数
		for (int j = 0; j < valid.size() && cnt < m; j++)
		{
			if (valid[j].age >= amin&&valid[j].age <= amax)
			{
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].nworth);
				cnt++;
			}
		}
		if (cnt == 0)
			printf("None\n");
	}

	return 0;
}
