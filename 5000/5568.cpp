#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string arr[11];
bool visited[11];

vector<string> v;
void dfs(int num, string sum)
{
	if (num == k)
	{
		if (find(v.begin(), v.end(), sum) == v.end())
		{
			v.push_back(sum);
			return;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(num + 1, sum + arr[i]);
			visited[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dfs(0, "");
	cout << v.size();

	return 0;
}