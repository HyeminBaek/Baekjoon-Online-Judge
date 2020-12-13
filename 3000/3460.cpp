#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;

		string temp = "";
		while (n > 0)
		{
			temp += to_string(n % 2);
			n /= 2;
		}
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '1')
				cout << i << " ";
		}
	}

	return 0;
}