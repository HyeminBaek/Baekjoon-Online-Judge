#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	deque<int> d;
	for (int t = 0; t < T; t++)
	{
		int n;
		string s, arr; cin >> s >> n >> arr;
		
		d.clear();

		if (n != 0)
		{
			int arrlength = arr.length();
			int temp = 0;
			for (int i = 1; i < arrlength - 1; i++)
			{
				temp += arr[i] - '0';
				if (arr[i + 1] == ',' || arr[i + 1] == ']')
				{
					i++; d.push_back(temp);
					temp = 0;
				}
				else
					temp *= 10;
			}
		}
		bool err = false, rev = false;
		int slength = s.length();
		for (int i = 0; i < slength; i++)
		{
			if (s[i] == 'R')
			{
				if (!rev)
					rev = true;
				else
					rev = false;
			}
			else if (s[i] == 'D')
			{
				if (d.empty())
				{
					cout << "error\n";	err = true; break;
				}
				else
				{
					if (rev)
						d.pop_back();
					else
						d.pop_front();
				}
			}
		}
		if (!err)
		{
			if (!rev)
			{
				cout << '[';
				while (!d.empty())
				{
					cout << d.front();
					d.pop_front();
					if (!d.empty())
						cout << ",";
				}
				cout << "]\n";
			}
			else
			{
				cout << '[';
				while (!d.empty())
				{
					cout << d.back();
					d.pop_back();
					if (!d.empty())
						cout << ",";
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}