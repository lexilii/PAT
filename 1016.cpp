/*
1016. Phone Bills (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B

A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.
Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.
Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.
Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/


#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int HOURS = 24;

struct Record {
	string name;
	int month;
	int day;
	int hour;
	int minute;
	string status;
};

bool mySort(const Record& r1, const Record& r2)
{
	if (r1.name != r2.name) //如果两条记录不是一个人的，则按照姓名拼音排列
	{
		return r1.name < r2.name; //升序排列
	}
	else //是同一个人的通话记录
	{
		int total1 = r1.day * 24 * 60 + r1.hour * 60 + r1.minute;
		int total2 = r2.day * 24 * 60 + r2.hour * 60 + r2.minute;
		return total1 < total2;
	}
}

double charge(const Record &start, const Record &end, const int chargetable[HOURS])
{
	int fee = 0;
	int d_fee = 0;
	int h_fee = 0;
	int m_fee = 0;

	for (int i = 0; i < 24; i++)
	{
		d_fee += chargetable[i] * 60;
	}
	for (int i = 0; i < start.hour; i++)
		h_fee -= chargetable[i] * 60;
	for (int i = 0; i < end.hour; i++)
		h_fee += chargetable[i] * 60;
	
	m_fee = end.minute*chargetable[end.hour] - start.minute*chargetable[start.hour];

	fee = (end.day - start.day)*d_fee + h_fee + m_fee;
	double doller = fee / 100.0;
	return doller;
}

int lastingTime(const Record &start, const Record &end)
{
	int timeS = 0;
	int timeE = 0;

	timeS = start.day * 24 * 60 + start.hour * 60 + start.minute;
	timeE = end.day * 24 * 60 + end.hour * 60 + end.minute;

	return timeE - timeS;
}

int main()
{
	/*-------------------------录入数据---------------------------*/
	int chargeTable[HOURS] = { 0 }; 
	for (int i = 0; i < HOURS; i++)
	{
		scanf("%d", &chargeTable[i]);
	}
	int N;
	scanf("%d", &N);

	vector<Record> bills(N);
	for (int i = 0; i < N; i++)
	{
		char name[21];//人名最多有20个字母 '\0'末尾有空字符
		char status[9];
		scanf("%s %d:%d:%d:%d %s", name, &bills[i].month, &bills[i].day, &bills[i].hour, &bills[i].minute, status);
		bills[i].name = name;
		bills[i].status = status;
	}
	sort(bills.begin(), bills.end(), mySort);

	vector<Record> useful; //存储有用的record信息

	vector<Record> ::iterator itr;
	bool have_online = false; //true表示已经读入一条online记录
	string current_name = "none"; //上一条压入 on_line 记录的人名，如果这条是off，且人名与上一条压入的相同，才构成一条通话记录
	for (itr = bills.begin(); itr != bills.end(); itr++)
	{
		if ((*itr).status == "on-line" && have_online == false) //第一次遇到 on_line ，直接压入
		{
			useful.push_back(*itr);
			have_online = true;
			current_name = (*itr).name;
		}
		else if ((*itr).status == "on-line" && have_online == true) //第二次遇到 on_line（上一次也是on_line) ,弹出上条，压入新的一条记录
		{
			useful.pop_back();
			useful.push_back(*itr);
			have_online = true;
			current_name = (*itr).name;

		}
		else if ((*itr).status == "off-line" && have_online == true && current_name == (*itr).name) //匹配成功，压入off
		{
			useful.push_back(*itr);
			have_online = false;
		}
	}
	if (have_online == true) //最后一条信息必须是 off_line
		useful.pop_back();
	double totalAmount = 0;
	double curAmount = 0;
	string curName = "none";
	for (itr = useful.begin(); itr < useful.end(); )
	{

		if ((*itr).name != curName) //当前读入的是 新客户的bill
		{
			
			cout << (*itr).name << " ";
			printf("%02d\n", itr->month);
			printf("%02d:%02d:%02d ", (*itr).day, (*itr).hour, (*itr).minute);
			printf("%02d:%02d:%02d ", (*(itr+1)).day, (*(itr+1)).hour, (*(itr+1)).minute);
			printf("%d ", lastingTime(*itr, *(itr + 1)));
			curAmount = charge(*itr, *(itr + 1), chargeTable);
			printf("$%.2f\n", curAmount);

			curName = (*itr).name;
			totalAmount = curAmount;
		}
		else if ((*itr).name == curName) //当前读入的 与前一条bill是相同客户
		{
			printf("%02d:%02d:%02d ", (*itr).day, (*itr).hour, (*itr).minute);
			printf("%02d:%02d:%02d ", (*(itr + 1)).day, (*(itr + 1)).hour, (*(itr + 1)).minute);
			printf("%d ", lastingTime(*itr, *(itr + 1)));
			curAmount = charge(*itr, *(itr + 1), chargeTable);
			printf("$%.2f\n", curAmount);

			totalAmount += curAmount;
		}
		if ((itr+2) == useful.end()|| (itr + 2)->name != curName) //这里注意顺序，||的话，左边的条件满足就不计算右边了，到换位置就会报错，因为到达末尾的话直接索引后两个超出了范围
		{
			printf("Total amount: $%.2f\n", totalAmount);
			totalAmount = 0;
		}
		
		itr += 2;
	}

	return 0;
}

