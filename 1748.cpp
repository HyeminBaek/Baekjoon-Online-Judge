#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n; 
	cin >> n;

	long long d[10] = { 0, };
	d[1] = 9;

	for (int i = 2; i < 10; i++)
		d[i] = d[i - 1] + 9 * pow(10, i - 1)*i;
	
	if (n < 10)
		cout << n;
	else if (n < 100)
		cout << d[1] + (n - 9) * 2;
	else if (n < 1000)
		cout << d[2] + (n - 99) * 3;
	else if (n < 10000)
		cout << d[3] + (n - 999) * 4;
	else if (n < 100000)//5
		cout << d[4] + (n - 9999) * 5;
	else if (n < 1000000)
		cout << d[5] + (n - 99999) * 6;
	else if (n < 10000000)//7
		cout << d[6] + (n - 999999) * 7;
	else if (n < 100000000)//8
		cout << d[7] + (n - 9999999) * 8;
	else if (n == 100000000)
		cout << d[8] + 9;

	return 0;
}
