#include <iostream>
#include <string>
using namespace std;

void find(string& s, int& min, int& max)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '5' || s[i] == '6')
		{
			min *= 10; min += 5; max *= 10; max += 6;
		}
		else
		{
			min *= 10; min += s[i] - '0'; max *= 10; max += s[i] - '0';
		}
	}
}
int main()
{
	string A, B; cin >> A >> B;

	int minA = 0, maxA = 0; int minB = 0, maxB = 0;
	find(A, minA, maxA); find(B, minB, maxB);
	cout << minA+ minB << " " << maxA + maxB;

	return 0;
}