#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool find(string a, string b)
{
	for (int i = 0; i < b.length(); i+=a.length())
	{
		if (i + a.length()<b.length())
		{
			string temp = b.substr(i, a.length());
			if (temp == a)
				return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		string* arr = new string[n];
		for (int j = 0; j < n; j++)
			cin >> arr[j];

		sort(arr, arr + n); //포인트 1: 두 개씩만 비교하여 N번만 돌기 위해 정렬
		
		bool flag = true; //일관성?

		for (int j = 0; j < n-1; j++)
		{
			if (arr[j].length() < arr[j+1].length()) //포인트 2: 앞 인덱스가 뒤 인덱스길이보다 작다면 확인
			{
				if (!find(arr[j], arr[j+1]))
				{
					flag = false; break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}