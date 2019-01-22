/*
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	struct Register{
		string ID;
		int signIn[3];
		int signOut[3];
	};

	int recordNum;
	cin >> recordNum;

	vector<Register> recordList;
	Register currentRecord;
	string tempID;
	string signIn;
	string signOut;
	int hour = 0;
	int minute = 0;
	int second = 0;
	for (int i = 0; i < recordNum; i++)
	{
		cin >> tempID >> signIn >> signOut;

		currentRecord.ID = tempID;

		hour = (signIn[0] - '0') * 10 + (signIn[1] - '0');
		minute = (signIn[3] - '0') * 10 + (signIn[4] - '0');
		second = (signIn[6] - '0') * 10 + (signIn[7] - '0');
		currentRecord.signIn[0] = hour;//小时
		currentRecord.signIn[1] = minute;//分钟
		currentRecord.signIn[2] = second;

		hour = (signOut[0] - '0') * 10 + (signOut[1] - '0');
		minute = (signOut[3] - '0') * 10 + (signOut[4] - '0');
		second = (signOut[6] - '0') * 10 + (signOut[7] - '0');
		currentRecord.signOut[0] = hour;
		currentRecord.signOut[1] = minute;
		currentRecord.signOut[2] = second;

		recordList.push_back(currentRecord);
	}

	int indexIN = 0;
	string first = recordList[indexIN].ID;
	int indexOUT = 0;
	string last = recordList[indexOUT].ID;
	for (int i = 1; i < recordNum; i++)
	{
		if ((recordList[i].signIn[0] < recordList[indexIN].signIn[0]) || (recordList[i].signIn[0] == recordList[indexIN].signIn[0] && recordList[i].signIn[1] < recordList[indexIN].signIn[1])
			|| (recordList[i].signIn[0] == recordList[indexIN].signIn[0] && recordList[i].signIn[1] == recordList[indexIN].signIn[1] && recordList[i].signIn[2] < recordList[indexIN].signIn[2]))
		{
			indexIN = i;
			first = recordList[indexIN].ID;
		}
		if ((recordList[i].signOut[0] > recordList[indexOUT].signOut[0]) || (recordList[i].signOut[0] == recordList[indexOUT].signOut[0] && recordList[i].signOut[1] > recordList[indexOUT].signOut[1])
			|| (recordList[i].signOut[0] == recordList[indexOUT].signOut[0] && recordList[i].signOut[1] == recordList[indexOUT].signOut[1] && recordList[i].signOut[2] > recordList[indexOUT].signOut[2]))
		{
			indexOUT = i;
			last = recordList[indexOUT].ID;
		}
	}

	cout << first << " " << last << endl;

	return 0;
}
