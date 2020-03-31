#include <iostream>
#include <string>
using namespace std;

string findOdd(int n)
{
	string odd;

	if (n % 2 == 0)
		n--;

	if (n == 1)
	{
		odd = "* "; return odd;
	}
	else
	{
		odd = findOdd(n - 2) + "* "; return odd;
	}
}
string findEven(int n)
{
	string even;

	if (n % 2 == 1)
		n--;

	if (n == 2)
	{
		even = " *"; return even;
	}
	else
	{
		even = findEven(n - 2) + " *"; return even;
	}
}
int main()
{
	int n;
	cin >> n;

	if (n == 1)
		cout << findOdd(n);
	else
	{
		for (int i = 0; i < n; i++)
			cout << findOdd(n) << "\n" << findEven(n) << "\n";
	}

	return 0;
}