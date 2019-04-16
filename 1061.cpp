#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char day[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };


int main()
{
	string str1, str2, str3, str4;
	int d, h, m;
	 
	//数据录入
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, str3);
	getline(cin, str4);

	int len1 = str1.length();
	int len2 = str2.length();
	int len3 = str3.length();
	int len4 = str4.length();

	int i = 0;

	// 寻找 str1 和 str2 中第一对相同位置的 A~G 的大写字母
	for (  ; i < len1 && i < len2; i++)
	{
		if (str1[i] == str2[i] && str1[i] >= 'A'&&str1[i] <= 'G')
		{
			d = str1[i] - 'A';
			break;
		}
	}

	i++; //因为是break跳出的，需要自增向后挪一位

	// 在前面的基础上继续搜索，寻找之后的相同位置的 0~9 或 A~N 字符
	for (; i < len1 && i < len2; i++)
	{
		if (str1[i] == str2[i])
		{
			if (str1[i] >= '0'&&str1[i] <= '9')
			{
				h = str1[i] - '0';
				break;
			}
			else if (str1[i] >= 'A' && str1[i] <= 'N')
			{
				h = 10 + str1[i] - 'A';
				break;
			}
		}
	}

	// 寻找 str3 和 str4 中第一队相同位置的 A~Z 或 a~z 的英文字母
	for (int i = 0; i < len3 && i < len4; i++)
	{
		if (str3[i] == str4[i])
		{
			if ((str3[i] >= 'a'&&str3[i] <= 'z') || (str3[i] >= 'A'&&str3[i] <= 'Z'))
			{
				m = i;
				break;
			}
		}
	}

	printf("%s %02d:%02d", day[d], h, m);

	return 0;
}
