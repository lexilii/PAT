#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

char wei[5][10] = { "Shi","Bai","Qian","Wan","Yi" };
char num[10][10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };


int main()
{
	string str;
	getline(cin, str);

	int len = str.length(); // 字符串长度

	int left = 0; // left 与 right 分别指向字符串首尾元素
	int right = len - 1;

	// 如果是负数，则输出 Fu，并把left右移一位
	if (str[0] == '-')
	{
		printf("Fu");
		left++;
	}

	// 将right每次左移 4 位，直到left与right在同一节
	while (left <= right -  4)
	{
		right = right - 4;
	}

	// 循环 每次处理一个小节（4位或小于4位）
	while (left < len)
	{
		bool flag = false; // 表示没有累积的 0
		bool isPrint = false; // 表示该节没有输出过其中的位
		
		// 从左至右处理数字中的每一位
		while (left <= right)
		{
			// 当前位为0，标记 flag = true
			if (left > 0 && str[left] == '0')  // 考虑 0 的特殊情况 需要加上left>0
			{
				flag = true;
			}
			else
			{
				// 如果存在累积的 0
				if (flag == true)
				{
					printf(" ling");
					flag = false;
				}
				// 只要不是首位，前面就要加空格
				if (left > 0)
				{
					printf(" ");
				}
				// 输出当前位的数字
				printf("%s", num[str[left] - '0']);
				// 当前小节至少有一位被输出  1 0000 0001 一亿零一
				isPrint = true; 
				// 某节中除了个位，其余位都要带单位
				if (left != right)
				{
					printf(" %s", wei[right - left - 1]);
				}
			}
			// left 右移一位
			left++;
		}
		// 当前节有输出，且不是个位，就输出万或亿
		if (isPrint == true && right != len - 1)
		{
			printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		}

		right = right + 4; // right 右移4位
	}

	return 0;
}
