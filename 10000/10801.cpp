#include <iostream>
using namespace std;

int main()
{
	int A[10], B[10];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0)
				cin >> A[j];
			else
				cin >> B[j];
		}
	}

	int winA = 0, winB = 0;
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
			winA++;
		else if (A[i] < B[i])
			winB++;
	}

	if (winA > winB) cout << 'A';
	else if (winB > winA) cout << 'B';
	else cout << 'D';
	return 0;
}