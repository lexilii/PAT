#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct Score
{
	int location;  //考试地点编号 1~N
	string registration;  // 注册号
	int score; //成绩

	int final_rank = 0;
	int local_rank = 0;
};

bool localSort(const Score& t1, const Score& t2)
{
	return t1.score > t2.score;
}
bool finalSort(const Score& t1, const Score& t2)
{
	if (t1.score != t2.score)
		return t1.score > t2.score;
	else
		return t1.registration < t2.registration;
}

int main()
{
	int N; // 考场数
	scanf("%d", &N);
	vector<vector<Score>> testees(N);
	Score temp;

	/*   数据录入   */
	for (int i = 0; i < N; i++)
	{
		int K; //该考场考生数
		scanf("%d", &K);
		for (int j = 0; j < K; j++)
		{
			cin >> temp.registration;
			cin >> temp.score;
			temp.location = i + 1; //编号从1开始
			testees[i].push_back(temp);
		}
	}

	/*   局部排名   */
	int start = 0;
	for (int i = 0; i < N; i++)
	{
		//依据成绩从大到小排列
		sort(testees[i].begin(), testees[i].end(), localSort);
		int rank = 0;
		int lastScore = 1000000;
		int count = 0;
		for (int j = 0; j < testees[i].size(); j++)
		{
			if (testees[i][j].score != lastScore) // 和上一个人成绩不同
			{
				rank = rank + count + 1;
				testees[i][j].local_rank = rank;
				lastScore = testees[i][j].score;

				count = 0; //累计数清零
			}
			else // 和上一个人成绩相同
			{
				count++;
				testees[i][j].local_rank = rank;
			}

		}
	}

	/*   最终排名   */

	vector<Score> totalTestee;
	for (int i = 0; i < N; i++)
	{
		totalTestee.insert(totalTestee.end(), testees[i].begin(), testees[i].end());
	}
	
	//依据成绩从大到小排列
	sort(totalTestee.begin(), totalTestee.end(), finalSort);

	int rank = 0;
	int lastScore = 1000000;
	int count = 0;
	for (int i = 0; i < totalTestee.size(); i++)
	{
		if (totalTestee[i].score != lastScore) // 和上一个人成绩不同
		{
			rank = rank + count + 1;
			totalTestee[i].final_rank = rank;
			lastScore = totalTestee[i].score;

			count = 0; //累计数清零
		}
		else // 和上一个人成绩相同
		{
			count++;
			totalTestee[i].final_rank = rank;
		}
		//cout <<"score = " << totalTestee[i].score << "        rank = " << rank << "    count = " << count << endl;
	}

	cout << totalTestee.size() << endl;
	for (int i = 0; i < totalTestee.size(); i++)
	{
		cout << totalTestee[i].registration << " " << totalTestee[i].final_rank << " " << totalTestee[i].location << " " << totalTestee[i].local_rank << endl;
	}

	return 0;
}
