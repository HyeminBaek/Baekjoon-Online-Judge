#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
void back(string x, int num, int M, int N)
{
	if (num == N)
	{
		cout << x << "\n"; return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		back(x + to_string(v[i]) + " ", num + 1, M, N);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;
	for (int i = 1; i <= M; i++)
		v.push_back(i);

	back("", 0, M, N);
	return 0;
}