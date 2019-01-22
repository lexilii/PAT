/*
1012 The Best Rank （25 分）

Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string ID;
	double grade[4] = { 0 };// A C M E
	int rank[4] = { 1,1,1,1 };
	int best = 0;//默认最好成绩为Average
	void calculateA();
	void bestGrade();
};
void Student::calculateA()
{
	grade[0] = (grade[1] + grade[2] + grade[3]) / 3;
}
void Student::bestGrade()
{
	int temp = 0;
	for (size_t i = 1; i < 4; i++)
	{
		if (rank[i] < rank[temp])
		{
			temp = i;
		}
	}
	best = temp;
}

int main()
{
	char table[4] = { 'A','C','M','E' };
	int n = 0; //students number
	int m = 0; //number need to check
	cin >> n >> m;
	vector<Student> students;
	Student stu;
	for (size_t i = 0; i < n; i++)
	{
		cin >> stu.ID >> stu.grade[1] >> stu.grade[2] >> stu.grade[3];
		stu.calculateA();
		students.push_back(stu);
	}
	string id;
	vector<string> query;
	for (size_t j = 0; j < m; j++)
	{
		cin >> id;
		query.push_back(id);
	}
	int rank = 1;
	for (size_t j = 0; j < m; j++)
	{
		id=query[j];
		rank = 1;
		size_t i;
		for (i=0; i < n; i++)
		{
			if (students[i].ID == id)
			{
				for (size_t k = 0; k < n; k++)
				{
					if (students[k].grade[0] > students[i].grade[0]) //A
						students[i].rank[0]++; //初始默认该生该门成绩排名为1 ，出现一个人成绩高于它，则排名+1后移，和他成绩相同，则不影响他的排名
					if (students[k].grade[1] > students[i].grade[1]) //C
						students[i].rank[1]++;
					if (students[k].grade[2] > students[i].grade[2]) //M
						students[i].rank[2]++;
					if (students[k].grade[3] > students[i].grade[3]) //E
						students[i].rank[3]++;
				}
				students[i].bestGrade(); //找出最好的排名
				cout << students[i].rank[students[i].best] << " " << table[students[i].best] << endl;
				break;
			}
		}
		if (i == n) //哪怕找到student[n-1]才是对应的ID，那么执行break后i不会再自增，到不了n。只有找过所有的都没有查到对应id，由于循环增量自增跳出循环的情况才会出现 i=n
			cout << "N/A" << endl;
	}
	return 0;
}
