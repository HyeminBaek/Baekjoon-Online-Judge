#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; cin >> s;

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B; cin >> A >> B;

		char temp = s[A];
		s[A] = s[B]; s[B] = temp;
	}
	cout << s;

	return 0;
}