#include <iostream>
using namespace std;

int leftover(int, int);

int main()
{
	int n, sum = 0;
	cin >> n;

	int* school = new int[n];
	int* apple = new int[n];

	for (int i = 0; i < n; i++)
		cin >> school[i] >> apple[i];

	for (int i = 0; i < n; i++)
		sum += leftover(school[i], apple[i]);
	
	cout << sum;

	return 0;
}
int leftover(int school, int apple)
{
	int leftoverSum = 0;

	for (int i = 1; i * school <= apple; i++)
		leftoverSum = i;

	return apple - school * leftoverSum;
}