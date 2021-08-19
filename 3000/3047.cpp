#include <iostream>
using namespace std;

int main()
{
	int a, b, c; cin >> a >> b >> c;
	char s[3];
	for (int i = 0; i < 3; i++)
		cin >> s[i];

	if (a > b)
	{
		int temp = b;
		b = a;
		a = temp;
	}
	if (a > c)
	{
		int temp = c;
		c = a;
		a = temp;
	}
	if (b > c)
	{
		int temp = b;
		b = c;
		c = temp;
	}

	for (int i = 0; i < 3; i++)
	{
		if (s[i] == 'A') cout << a << " ";
		else if (s[i] == 'B') cout << b << " ";
		else    cout << c << " ";
	}

	return 0;
}
