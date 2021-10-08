#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long solution(long long cur)
{
	if (cur == 0) return 1;

	if (m.find(cur) != m.end()) return m[cur];

	return m[cur] = solution(cur / P) + solution(cur / Q);
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> Q;
}
int main()
{
	init();
	cout << solution(N);

	return 0;
}
