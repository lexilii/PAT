/*
1017. Queueing at Bank (25)
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
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.
Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.
Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.
Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
*/



#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


struct Customer {
	int hour; // arrive at h:m:s
	int minute;
	int second;
	int processingTime; // in minutes
	int arrivingTime; // in seconds
};

struct Window {
	int hour = 8;
	int minute = 0;
	int second = 0;
	int availableTime = 8 * 60 * 60; // in seconds
};

bool sortCustomer(const Customer& cus1, const Customer& cus2)
{
	return cus1.arrivingTime < cus2.arrivingTime; // 升序排列
}
bool sortWindow(const Window& win1, const Window& win2)
{
	return win1.availableTime < win2.availableTime; // 升序排列
}

int main()
{
	/*----------------------------- 输入数据 ---------------------------------*/
	int N; // number of customers
	int k; // number of windows
	scanf("%d %d", &N, &k);
	vector<Window> windows(k);
	vector<Customer> customers;
	Customer tempCus;
	int closeTime = 17 * 60 * 60 + 1; // 换算至秒 17：00：01
	for (int i = 0; i < N; i++)
	{
		scanf("%d:%d:%d %d", &tempCus.hour, &tempCus.minute, &tempCus.second, &tempCus.processingTime);
		tempCus.arrivingTime = tempCus.hour * 60 * 60 + tempCus.minute * 60 + tempCus.second;
		if (tempCus.arrivingTime < closeTime)
			customers.push_back(tempCus);
	}

	/*----------------------------- 对customer按照到达时间进行排序 ---------------------------------*/
	sort(customers.begin(), customers.end(), sortCustomer);

	/*----------------------------- 计算处理用户业务时长 ---------------------------------*/
	double waitingTime = 0; // in seconds
	for (int i = 0; i < customers.size(); i++)
	{
		sort(windows.begin(), windows.end(), sortWindow); // 对窗口按照availableTime进行排序，时间最小的优先访问
		if (windows[0].availableTime >= customers[i].arrivingTime)
		{
			// 如果客户到达时，无窗口空闲，则需要等待
			waitingTime += windows[0].availableTime - customers[i].arrivingTime;
			windows[0].availableTime += customers[i].processingTime * 60; // 更新窗口信息
		}
		else
		{
			// 如果客户到达时，窗口空闲，则无需等待
			windows[0].availableTime = customers[i].arrivingTime + customers[i].processingTime * 60; // 更新窗口信息
		}
	}
	double averageTime; // in minutes
	averageTime = waitingTime / customers.size() / 60;

	printf("%.1f", averageTime);

	return 0;
}

