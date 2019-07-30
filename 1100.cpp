#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

// [0,12] 的火星文
string unitDigit[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string tenDigit[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

// 映射表
string numToStr[170]; // 数字-》火星文
map<string, int> strToNum; // 火星文-》数字
int main()
{
	// 打表
	for (int i = 0; i < 13; i++)
	{
		numToStr[i] = unitDigit[i];  // 个位为【0,12】，十位为0
		strToNum[unitDigit[i]] = i;

		numToStr[i * 13] = tenDigit[i];  // 十位为【0,12】，个位为0
		strToNum[tenDigit[i]] = i * 13;
	}

	for (int i = 1; i < 13; i++) // 十位
	{
		for (int j = 1; j < 13; j++) // 个位
		{
			string str = tenDigit[i] + " " + unitDigit[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}

	int n;
	cin >> n;
	getchar(); // gets() 或 getline() 前都需要用 getchar 吸收整数后的换行符
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		if (str[0] <= '9'&& str[0] >= '0')
		{
			int num = 0;
			for (int j = 0; j < str.size(); j++)
				num = num * 10 + (str[j] - '0');
			cout << numToStr[num] << endl;
		}
		else
			cout << strToNum[str] << endl;
	}
	return 0;
}
