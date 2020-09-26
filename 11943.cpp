#include <iostream>
using namespace std;

int main()
{
	int A, B, C, D; 
	cin >> A >> B >> C >> D;

	int temp = (A + D > B + C) ? B + C : A + D;
	cout << temp;

	return 0;
}