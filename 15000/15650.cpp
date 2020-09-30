#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void com(int M,int N)
{
	vector<int> v;
	for (int i = 1; i <= M; i++)
		v.push_back(i);
	vector<int> t;
	for (int i = 0; i < M - N; i++)
		t.push_back(0);
	for (int i = 0; i < N; i++)
		t.push_back(1);

	vector<string> answer;
	do
	{
		string s;
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i] == 1)
				s += to_string(v[i]) + " ";
		}
		answer.push_back(s);
	} while (next_permutation(t.begin(), t.end()));
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}
int main()
{
	int M, N; cin >> M >> N;
	com(M, N);

	return 0;
}