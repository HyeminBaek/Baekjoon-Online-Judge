#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
set<string> c;
vector<int> v;
bool visited[8];

void combination(int x)
{
	do
	{
		string s="";
		for (int i = x; i < M; i++)
			s += to_string(v[i]) + " ";
		c.insert(s);
	} while (next_permutation(v.begin(), v.end()));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	for(int i=0;i<N;i++)
		combination(i);

	for (set<string>::iterator ite = c.begin(); ite != c.end(); ite++)
		cout << *ite << "\n";

	return 0;
}