#include <iostream>
using namespace std;

int Rev(int x)
{
	if (x < 10)
		return x;
	int temp = 0, X = x;
	while(X>=10)
	{
		temp *= 10;
		temp += X % 10;
		X /= 10;
	}
	temp *= 10; temp += X;

	return temp;
}
int main()
{
	int X, Y; cin >> X >> Y;
	cout << Rev(Rev(X) + Rev(Y));
	return 0;
}