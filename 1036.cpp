#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
	string name;
	string ID;
	int grade;
};

bool higher(const Info& f1, const Info& f2)
{
	return f1.grade > f2.grade;  //降序排列
}

bool lower(const Info& m1, const Info& m2)
{
	return m1.grade < m2.grade; // 升序排列
}
int main()
{
	int N;
	scanf("%d", &N);

	vector<Info> female;
	vector<Info> male;
	char name[11];
	char ID[11];
	char gender;
	int grade;
	Info temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %c %s %d", name, &gender, ID, &grade);
		temp.name = name;
		temp.ID = ID;
		temp.grade = grade;
		if (gender == 'F')
			female.push_back(temp);
		else if(gender == 'M')
			male.push_back(temp);
	}
	sort(female.begin(), female.end(), higher);
	sort(male.begin(), male.end(), lower);

	bool flag = false;
	if (female.size() == 0)
	{
		printf("Absent\n");
		flag = true;
	}
	else
		printf("%s %s\n", female[0].name.c_str(), female[0].ID.c_str());
	if (male.size() == 0)
	{
		printf("Absent\n");
		flag = true;
	}
	else
		printf("%s %s\n", male[0].name.c_str(), male[0].ID.c_str());

	if (flag == true)
		printf("NA\n");
	else
		printf("%d", female[0].grade - male[0].grade);

	return 0;
}
