/*
1002. A+B for Polynomials (25)
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
This time, you are supposed to find A+B where A and B are two polynomials.
Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.
Output
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/

#include <iostream>
#include <vector>
#include<iomanip>
#include<cmath>

using namespace std;

struct Polynomials
{
	int exponents;
	double coefficients;
	Polynomials(int e = 0, double c = 0) :exponents(e), coefficients(c) {}
};

int main()
{
	int size1 = 0;
	int size2 = 0;
	vector<Polynomials> a;
	vector<Polynomials> b;
	double tempcoeff = 0;
	int tempexp = 0;

	cin >> size1; // 第一个多项式项数
	for (int i = 0; i < size1; i++)
	{
		cin >> tempexp >> tempcoeff;
		a.push_back(Polynomials(tempexp, tempcoeff));
	}

	cin >> size2;// 第二个多项式项数
	for (int i = 0; i < size2; i++)
	{
		cin >> tempexp >> tempcoeff;
		b.push_back(Polynomials(tempexp, tempcoeff));
	}

	if (size1 == 0 && size2 == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<Polynomials> sum;
	int i = 0;
	int j = 0;
	do {

		if (size1 == i) //a 已经遍历 b还有剩余
		{
			sum.push_back(Polynomials(b[j].exponents,b[j].coefficients));
			j++;
		}
		else if (size2 == j) //b 已经遍历 a还有剩余
		{
			sum.push_back(Polynomials(a[i].exponents, a[i].coefficients));
			i++;
		}
		else //a b都有剩余
		{
			if (a[i].exponents > b[j].exponents)
			{
				sum.push_back(Polynomials(a[i].exponents, a[i].coefficients));
				i++;
			}
			else if (a[i].exponents < b[j].exponents)
			{
				sum.push_back(Polynomials(b[j].exponents, b[j].coefficients));
				j++;
			}
			else
			{
				if (fabs(b[j].coefficients + a[i].coefficients) > 1e-8)  //当前项 系数和不为0
					sum.push_back(Polynomials(b[j].exponents, b[j].coefficients + a[i].coefficients));
				i++;
				j++;
			}
		}

	} while (i < size1 || j < size2);
	
	cout << sum.size();
	cout.setf(ios::fixed);//不足位补零
	cout << setprecision(1);
	for (int k = 0; k < sum.size(); k++)
		cout << " " << sum[k].exponents << " " << sum[k].coefficients;
	cout << endl;
	return 0;
}

