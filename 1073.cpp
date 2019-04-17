#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string data;
	getline(cin, data);

	int len = data.length();
	vector<char> res;

	// 确定 E 的位置
	int ePos = 0;
	for (int i = 0; i < len; i++)
	{
		if (data[i] == 'E')
		{
			ePos = i;
			break;
		}
	}

	// 判断正负
	bool isP = false;
	if (data[0] == '+')
		isP = true; // 正数


	// 记录 number
	vector<int> num;
	for (int i = 1; i < ePos; i++)
	{
		if (data[i] != '.')
			num.push_back(data[i] - '0');
	}
	int numSize = num.size();

	// 判断指数正负
	bool isEP = false;
	if (data[ePos + 1] == '+')
		isEP = true; // 指数为正

	// 记录指数
	int index = 0;
	for (int i = ePos + 2; i < len; i++)
		index = index * 10 + data[i] - '0';

	if (!isP)
		printf("-");

	if (isEP) // 指数为正
	{
		if (index < numSize - 1)
		{
			for (int i = 0; i < numSize; i++)
			{
				printf("%d", num[i]);
				if (i == index)
					printf(".");
			}
		}
		else
		{
			for (int i = 0; i < numSize; i++)
			{
				printf("%d", num[i]);
			}
			for (int i = 0; i < index - numSize + 1; i++)
			{
				printf("0");
			}
		}
	}
	else // 指数为负
	{
		if (index < 1)  // 指数为0
		{
			for (int i = 0; i < numSize; i++)
			{
				printf("%d", num[i]);
				if (i == 0)
					printf(".");

			}
		}
		else
		{
			printf("0.");
			for (int i = 0; i < index - 1; i++)
				printf("0");
			for (int i = 0; i < numSize; i++)
				printf("%d", num[i]);
		}
	}


	return 0;
}
