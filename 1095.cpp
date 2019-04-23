#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct Car
{
	string plate;
	int h;
	int m;
	int s;
	int time; // 以s为单位
	string status; 
};


bool cmp(Car& c1, Car& c2)
{
	if (c1.plate != c2.plate)
		return c1.plate < c2.plate;
	else
		return c1.time < c2.time;
}

bool cmp2(Car& c1, Car& c2)
{
	return c1.time < c2.time;
}

int main()
{
	int n;  //the number of records  ≤10^4
	int k;  //the number of queries  ≤8×10^​4
	scanf("%d%d", &n, &k);

	vector<Car> cars(n);
	for (int i = 0; i < n; i++)
	{
		char plate[8];
		char status[4];
		scanf("%s %d:%d:%d %s", plate, &cars[i].h, &cars[i].m, &cars[i].s, status);
		cars[i].plate = plate;
		cars[i].status = status;
		cars[i].time = cars[i].h * 60 * 60 + cars[i].m * 60 + cars[i].s;
	}

	sort(cars.begin(), cars.end(), cmp);

	vector<Car> valid;
	map<string, int> parkTime;
	int inTime;
	int maxTime = 0;
	for (int i = 0; i < n;)
	{
		if (cars[i].plate == cars[i + 1].plate && cars[i].status == "in" && cars[i + 1].status == "out")
		{
			valid.push_back(cars[i]);
			valid.push_back(cars[i + 1]);
			inTime = cars[i + 1].time - cars[i].time;

			// 如果map中还未保存这个车牌号的信息，置零
			if (parkTime.count(cars[i].plate) == 0)
			{
				parkTime[cars[i].plate] = 0;
			}

			// 更新相应车牌的停留时间
			parkTime[cars[i].plate] += inTime;

			// 更新最大停留时长
			if (maxTime < parkTime[cars[i].plate])
				maxTime = parkTime[cars[i].plate];

			i = i + 2;
		}
		else
		{
			i++;
		}
	}

	//按时间从小到大重新排序
	sort(valid.begin(), valid.end(), cmp2);

	int numCar = 0;
	int now = 0; // 处理至当前查询时间
	for (int i = 0; i < k; i++)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int qTime = h * 60 * 60 + m * 60 + s;

		while (now < valid.size() && valid[now].time <= qTime)
		{
			if (valid[now].status == "in")
				numCar++; // 车辆进入
			else
				numCar--; // 车辆离开
			now++;
		}

		printf("%d\n", numCar);
	}

	map<string, int>::iterator it;
	for (it = parkTime.begin();it != parkTime.end();it++)
	{
		// 输出所有最长停留时间的车牌 按照字典顺序输出（map 会按照 键 从小到大自动排序）
		if (it->second == maxTime)
		{
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxTime / 3600, (maxTime % 3600) / 60, maxTime % 60);
	return 0;
}
