#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

bool check(char c);

int main()
{
	string str;
	getline(cin, str); // 读取整行字符串
	map<string, int> scount;

	int i = 0; // 定义下标
	while (i < str.length())  // 索引整个字符串
	{
		string word;
		while (i < str.length() && check(str[i]))
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
				str[i] = str[i] + ('a' - 'A');
			word += str[i];
			i++;
		}

		// 单词非空，则计数加一  eg: "a"
		if (word != "") 
		{
			if (scount.find(word) == scount.end())
				scount[word] = 1;
			else
				scount[word]++;
		}

		// 跳过非单词字符
		while (i < str.length() && !check(str[i]))
		{
			i++;
		}
	}

	int maxN = -1;
	string minS;
	for (map<string, int>::iterator it = scount.begin(); it != scount.end(); it++)
	{
		if (it->second > maxN)
		{
			maxN = it->second;
			minS = it->first;
		}
		else if (it->second == maxN && it->first <minS)
		{
			minS = it->first;
		}
	}

	cout << minS << " " << maxN;
	return 0;
}

bool check(char c)
{
	if (c >= 'A'&& c <= 'Z')
		return true;
	if (c >= 'a'&&c <= 'z')
		return true;
	if (c >= '0'&&c <= '9')
		return true;

	return false;
}
