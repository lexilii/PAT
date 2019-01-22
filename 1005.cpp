/*
1005. Spell It Right (20)

时间限制:400 ms
内存限制:65536 kB
代码长度限制:16000 B
判题程序:Standard
作者:CHEN, Yue

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string chart[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

	string number;
	cin >> number;

	int length = number.size();
	int sum = 0;
	for (size_t i = 0; i < length; i++)
		sum += (number[i] - '0');

	string result = to_string(sum);
	for (int i = 0; i < result.size(); i++)
	{
		cout << chart[result[i] - '0'];
		if (i != result.size()-1)
			cout << " ";
	}

	return 0;
}
