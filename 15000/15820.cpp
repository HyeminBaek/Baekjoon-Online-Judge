#include <iostream>
using namespace std;

int main()
{
	int S1, S2; cin >> S1 >> S2;

	int answer = 0;
	for (int i = 0; i < S1; i++)
	{
		long long test, manyoung; cin >> test >> manyoung;
		if (test == manyoung) answer++;
	}
	if (answer < S1)
	{
		cout << "Wrong Answer\n"; return 0;
	}
	for (int i = 0; i < S2; i++)
	{
		long long system, manyoung; cin >> system >> manyoung;
		if (system == manyoung) answer++;
	}
	if (answer == S1 + S2) cout << "Accepted\n";
	else cout << "Why Wrong!!!\n";

	return 0;
}