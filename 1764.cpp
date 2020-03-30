#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string s;
	vector<string> dntlook;
	vector<string> dnthear;
	vector<string> temp;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		dntlook.push_back(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		dnthear.push_back(s);
	}

	sort(dntlook.begin(), dntlook.end()); //빠른 탐색을 위해 정렬해줌
	sort(dnthear.begin(), dnthear.end());

	int tmp = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = tmp; j < m; j++)
		{
			if (dntlook[i] < dnthear[j])
				break;
			if (dntlook[i] == dnthear[j])
			{
				temp.push_back(dntlook[i]);
				tmp = j + 1;
				break;
			}
		}
	}

	cout << temp.size() << "\n";
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << "\n";
	
	return 0;
}