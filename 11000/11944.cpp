#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	
	string s; s = "";
	for (int i = 0; i < N; i++)
		s += to_string(N);

	M = (s.length() < M) ? s.length() : M;
	for (int i = 0; i < M; i++)
		cout << s[i];

	return 0;
}