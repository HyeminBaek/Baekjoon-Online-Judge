#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int mon, day; cin >> mon >> day;
	if (mon == 1 )	cout << "Before";
	else if (mon == 2 && day < 18) cout << "Before";
	else if (mon == 2 && day == 18) cout << "Special";
	else cout << "After";

	return 0;
}