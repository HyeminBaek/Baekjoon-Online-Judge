#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int A, B; cin >> A >> B;
	double answer = 1 + pow(10.0, (B-A) /(double)400);
	cout << 1 / answer;

	return 0;
}