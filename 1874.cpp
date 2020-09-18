#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> arr; vector<char> answer; vector<int> st;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		arr.push_back(x);
	}
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		if (st.empty() || st.back() < arr[i])
		{
			if (idx > arr[i])
			{
				cout << "NO"; return 0;
			}
			for (int j = idx + 1; j <= arr[i]; j++)
			{
				st.push_back(j); answer.push_back('+');
			}
			idx = arr[i];
		}
		if (st.back() >= arr[i])
		{
			for (int j = st.back(); j >= arr[i]; j--)
			{
				st.pop_back(); answer.push_back('-');
			}
		}
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";

	return 0;
}