#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> num;
	string x;
	cin >> x;

	for (int i = 0; i < x.length(); i++)
		num.push_back(x[i] - '0');
	
	/* 计算double之后的结果 */
	deque<int> num_d;
	int temp;
	int carry = 0;
	for (int i = num.size()-1; i >=0; --i)
	{
		temp = num[i] * 2;
		num_d.push_front(temp % 10 + carry);

		carry = temp / 10;
	}
	if (carry != 0)
		num_d.push_front(carry);

	int numCount[10] = { 0 };
	int numdCount[10] = { 0 };

	if (num_d.size() != num.size()) //两个数数位不同，输出no
		cout << "No" << endl;
	else //数位相同的情况下判断内容是否相同
	{
		for (int i = 0; i < num.size(); i++)
		{
			numCount[num[i]]++;
			numdCount[num_d[i]]++;
		}
		int j;
		for (j = 0; j < 10; j++)
		{
			if (numCount[j] != numdCount[j])
			{
				cout << "No" << endl;
				break;
			}
		}
		if (j == 10)
			cout << "Yes" << endl;
	}
	for (int i = 0; i < num_d.size(); i++)
		cout << num_d[i];

	return 0;
}
