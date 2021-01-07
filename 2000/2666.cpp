#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int M;
vector<int> v;
int dp[20][20][20];
int door(int n, int one, int two)
{
	if (n == M) return 0;
	int temp = dp[n][one][two];

	if (temp != -1) return temp;

	if (v[n] <= one) return temp = door(n + 1, v[n], two) + (one-v[n]);
	else if(v[n]>one&&v[n]<two) 
		return temp = min(door(n + 1, v[n], two) + (v[n] - one), door(n + 1, one, v[n]) + two-v[n]);
	else if (v[n] >= two) return temp = door(n + 1, one, v[n]) + (v[n] - two);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int one, two; cin >> one >> two; //문 2개의 위치
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	memset(dp, -1, sizeof(dp));
	cout << door(0, one, two);

	return 0;
}