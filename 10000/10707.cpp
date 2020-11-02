#include <iostream>
using namespace std;

int main()
{
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	int X, Y;
	X = A * E;
	Y = (E > C) ? B + ((E - C)*D) : B;

	X = (X > Y) ? Y : X;
	cout << X;

	return 0;
}