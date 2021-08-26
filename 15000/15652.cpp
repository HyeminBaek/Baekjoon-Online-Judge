#include <iostream>
#include <string>
#include <vector>
using namespace std;

void back(string x, int num, int M, int N)
{
	if (num == N)
	{
		cout << x << "\n"; return;
	}
	for (int i = x[x.length() - 1]-'0'; i <= M; i++)
	{
		back(x + " " + to_string(i), num + 1, M, N);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;
	for (int i = 1; i <= M; i++)
		back(to_string(i), 1, M, N);
	
	return 0;
}
