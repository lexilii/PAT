#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

struct User 
{
	int id;
	int par_score[6] = { -100,-100,-100,-100,-100,-100 }; //  −1 if the submission cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]
	int total_score = 0;
	int per_solved = 0;
	int rank;
	bool valid_solu = false;
} users[10001];


bool cmp(const User& u1, const User& u2)
{
	if (u1.total_score != u2.total_score)
		return u1.total_score > u2.total_score;
	else if (u1.per_solved != u2.per_solved)
		return u1.per_solved > u2.per_solved;
	else
		return u1.id < u2.id;
}

int main()
{
	int n;  //the total number of users  <=10^4
	int k;  //the total number of problems  <=5
	int m;  //the total number of submissions  <=10^5
	scanf("%d%d%d", &n, &k, &m);

	int score[6] = { 0 }; // 0~5
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &score[i]);
	}


	// 录入信息
	for (int i = 0; i < m; i++)
	{
		int id; // from 00001 to N
		scanf("%d", &id);
		users[id].id = id;  

		int prob_id;
		int partial_score;
		scanf("%d%d", &prob_id, &partial_score);
		 
		// 若不是编译错误，则该考生有能通过编译的提交
		if (partial_score != -1)
		{
			users[id].valid_solu = true;
		}

	    // 某题 第一次 获得满分，则完美解题数加 1
		if (score[prob_id] == partial_score && users[id].par_score[prob_id]<score[prob_id])
		{
			users[id].per_solved++;
		}
		// 获得更高分，则覆盖
		if (users[id].par_score[prob_id] < partial_score)
		{
			if(partial_score == -1)
				users[id].par_score[prob_id] = 0; // 编译错误，记为0分
			else
				users[id].par_score[prob_id] = partial_score;
		}
	}


	vector<User> valid;
	// 计算 total_score
	for (int i = 1; i <= n; i++)  // 00001 to n
	{
		for (int j = 1; j <= k; j++)  // 1 to k
		{
			if (users[i].par_score[j] >= 0)
			{
				// -100 无提交
				// -1 无法通过编译
				// [0, p[problem_id]] 有提交 且通过编译
				users[i].total_score += users[i].par_score[j];
			}
		}
		if (users[i].valid_solu == true)
		{
			valid.push_back(users[i]);
			//cout << users[i].id << endl;
		}
	}

	// 排序
	sort(valid.begin(), valid.end(), cmp);

	// 输出
	int last_id = -1;
	int last_score = -100;
	for (int i = 0; i < valid.size(); i++)
	{
		if (valid[i].total_score != last_score)
		{
			printf("%d ", i+1);
			last_id = i+1;
			last_score = valid[i].total_score;
		}
		else
		{
			printf("%d ", last_id);
		}

		printf("%05d %d", valid[i].id, valid[i].total_score);
		for (int j = 1; j <= k; j++)
		{
			if (valid[i].par_score[j] >= 0)
				printf(" %d", valid[i].par_score[j]);
			else
				printf(" -");
		}
		printf("\n");
	}


	return 0;
}
