#include <iostream>
#include <string>
using namespace std;

int main()
{
	int month, date;
	cin >> month >> date;

	int last[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

	int sum = 0;

	if (month > 1)
	{
		for (int i = month-1; i > 0; i--)
			sum += last[i - 1];
		sum += date;
	}
	else
		sum += date;
	
	cout << day[sum % 7];

	return 0;
}
