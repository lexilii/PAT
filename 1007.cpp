/*
1007. Maximum Subsequence Sum (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size;
	int tempdata;
	bool flag = true;//标志所有输入是否全为负值的标识符 true表示全为负值
	vector<int> data;

	cin >> size;
	for (size_t i = 0; i < size; i++)
	{
		cin >> tempdata;
		if (tempdata >= 0)
			flag = false;
		data.push_back(tempdata);
	}
	//cout << "flag = " << flag << endl;
	int start = 0;
	int end = 0;
	int tempSum = 0;
	int finalSum = -1;
	if (flag == true) //所有数据均为负值
	{
		cout << 0 << " " << data[0] << " " << data[size - 1] << endl;
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] >= 0) //开始肯定从正数开始加会值更大，存在中间有负值的可能性
			{
				tempSum = 0;
				size_t j;
				for (j = i; j < size; j++)
				{
					tempSum += data[j];
					if (tempSum > finalSum)
					{
						finalSum = tempSum;
						start = i;
						end = j;
					}
				}
		
			}
		}
		cout << finalSum << " " << data[start] << " " << data[end] << endl;
	}

	return 0;
}
