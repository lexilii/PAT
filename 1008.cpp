/*
1008. Elevator (20)

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
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:

For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<int> floors;
	int tempNum;
	for (size_t i = 0; i < num; i++)
	{
		cin >> tempNum;
		floors.push_back(tempNum);
	}

	int up = 6;
	int down = 4;
	int stop = 5;

	int totalTime = 0;
	int start = 0;
	int end = 0;
	for (size_t i = 0; i < num; i++)
	{
		start = end;
		end = floors[i];
		if (end - start > 0)
		{
			totalTime += (end - start)*up + stop;
		}
		else
		{
			totalTime += (start - end)*down + stop;
		}
	}

	cout << totalTime << endl;
	return 0;
}
