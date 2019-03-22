#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string ID;
	string name;
	int grade;
};

bool sortByID(const Student& s1, const Student& s2)
{
	return s1.ID < s2.ID; // in increasing order
}
bool sortByName(const Student& s1, const Student& s2)
{
	if (s1.name != s2.name)
		return s1.name < s2.name; // in non-decreasing order
	else
		return s1.ID < s2.ID;

}
bool sortByGrade(const Student& s1, const Student& s2)
{
	if(s1.grade!=s2.grade)
		return s1.grade < s2.grade; // in non-decreasing order
	else
		return s1.ID < s2.ID;
}


int main()
{
	int N; // the number of records
	int C; // the column that you are sopposed to sort the records with
	cin >> N >> C;

	vector<Student> students;
	Student temp;
	for (int i = 0; i < N; i++)
	{
		char id[7];
		char name[9];
		int grade;
		scanf("%s %s %d", id, name, &grade);
		temp.ID = id;
		temp.name = name;
		temp.grade = grade;
		students.push_back(temp);
	}

	switch (C)
	{
	case 1:
		sort(students.begin(), students.end(), sortByID);
		break;
	case 2:
		sort(students.begin(), students.end(), sortByName);
		break;
	case 3:
		sort(students.begin(), students.end(), sortByGrade);
		break;
	}

	for (int i = 0; i < N; i++)
	{
		printf("%s %s %d\n", students[i].ID.c_str(), students[i].name.c_str(), students[i].grade);
	}

	return 0;
}
