#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char ch; cin >> ch;
	char pmz; cin >> pmz;

	switch (ch)
	{
	case 'A':
		if (pmz == '+')
			cout << 4.3;
		else if (pmz == '0')
			cout <<fixed<<setprecision(1)<< 4.0;
		else
			cout << 3.7;
		break;
	case 'B':
		if (pmz == '+')
			cout << 3.3;
		else if (pmz == '0')
			cout << fixed << setprecision(1) << 3.0;
		else
			cout << 2.7;
		break;
	case 'C':
		if (pmz == '+')
			cout << 2.3;
		else if (pmz == '0')
			cout << fixed << setprecision(1) << 2.0;
		else
			cout << 1.7;
		break;
	case 'D':
		if (pmz == '+')
			cout << 1.3;
		else if (pmz == '0')
			cout << fixed << setprecision(1) << 1.0;
		else
			cout << 0.7;
		break;
	default:
		cout << fixed << setprecision(1) << 0.0;
	}

	return 0;
}