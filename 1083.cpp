#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
	char name[11];
	char id[11];
	int grade; //[0,100]
};

bool cmp(const Student& s1, const Student& s2)
{
	return s1.grade > s2.grade;
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<Student> stu(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%d", stu[i].name, stu[i].id, &(stu[i].grade));
	}

	sort(stu.begin(), stu.end(), cmp);

	int glow, ghigh;
	scanf("%d%d", &glow, &ghigh);

	bool output = false;

	for (int i = 0; i < n; i++)
	{
		if (stu[i].grade >= glow && stu[i].grade <= ghigh)
		{
			output = true;
			printf("%s %s\n", stu[i].name, stu[i].id);
		}
	}
	if (output == false)
		printf("NONE");

	return 0;
}
