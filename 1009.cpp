/*
1009. Product of Polynomials (25)
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
This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct Polynomial
{
	int exponent; //指数
	double coefficient; //系数

	Polynomial(int exp = 0, double coeff = 0) :exponent(exp), coefficient(coeff) {}
};

int main()
{
	int size1;
	int size2;
	int tempExp;
	double tempCoeff;
	vector<Polynomial> p1;
	vector<Polynomial> p2;

	cin >> size1;
	for (size_t i = 0; i < size1; i++)
	{
		cin >> tempExp >> tempCoeff;
		p1.push_back(Polynomial(tempExp, tempCoeff));
	}
	cin >> size2;
	for (size_t i = 0; i < size2; i++)
	{
		cin >> tempExp >> tempCoeff;
		p2.push_back(Polynomial(tempExp, tempCoeff));
	}
	double result[2001] = { 0 };

	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			tempCoeff = p1[i].coefficient*p2[j].coefficient;
			tempExp = p1[i].exponent + p2[j].exponent;
			result[tempExp] += tempCoeff;
		}
	}
	int count = 0;
	for (int i = 2000; i >= 0; i--)
	{
		if (abs(result[i]) > 1e-8)
		{
			count++;
		}
	}
	cout << count;
	cout.setf(ios::fixed); //不足位补零
	for (int i = 2000; i >= 0; i--)
	{
		if (abs(result[i]) > 1e-8)
		{
			cout << " " << i << " " << setprecision(1) << result[i];
		}
	}

	return 0;
}
