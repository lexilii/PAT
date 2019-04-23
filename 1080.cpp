#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	int ge;  // the national entrance exam grade
	int gi;  // the interview grade
	int gf;  // the final grade
	int id;
	int rank;
	int choice[5] = { -1,-1,-1,-1,-1 };
};

struct School
{
	int quota;
	int lastRank;
	//int charge[40010]; // 招收学生的编号
	vector<int> charge;
};

bool cmp(const Student& s1, const Student& s2)
{
	if (s1.gf != s2.gf)
		return s1.gf > s2.gf;
	else
		return s1.ge > s2.ge;
}

int main()
{
	int n; // the total number of applicants  <= 40,000
	int m; // the total number of graduate schools  <= 100  
	int k; // he number of choices an applicant may have  <= 5
	scanf("%d%d%d", &n, &m, &k);

	vector<School> schools(m);
	for (int i = 0; i < m; i++)  //numbered from 0 to M−1
	{
		scanf("%d", &schools[i].quota);
	}

	vector<Student> stu(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		stu[i].gf = stu[i].ge + stu[i].gi; // 作排名用，不需要除2
		stu[i].id = i;
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &(stu[i].choice[j]));
		}
	}


	sort(stu.begin(), stu.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && stu[i].gf == stu[i - 1].gf&&stu[i].ge == stu[i - 1].ge)
		{
			stu[i].rank = stu[i - 1].rank;
		}
		else
		{
			stu[i].rank = i;
		}

		for (int j = 0; j < k; j++)
		{
			int choice = stu[i].choice[j];
			if (schools[choice].quota > 0)
			{
				schools[choice].charge.push_back(stu[i].id);
				schools[choice].quota--;
				schools[choice].lastRank = stu[i].rank;
				break;
			}
			else  // schools[choice].quota = 0 
			{
				if (stu[i].rank == schools[choice].lastRank)
				{
					schools[choice].charge.push_back(stu[i].id);
					break;
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		sort(schools[i].charge.begin(), schools[i].charge.end());
		if (schools[i].charge.size() != 0)
		{
			int j;
			for (j = 0; j < schools[i].charge.size() - 1; j++)
			{
				printf("%d ", schools[i].charge[j]);
			}
			printf("%d\n", schools[i].charge[j]);
		}
		else
		{
			printf("\n");
		}
	}



	return 0;
}
