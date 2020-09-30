#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int V, E; cin >> V >> E;
		int temp = 2 - V + E;
		cout << temp << "\n";
	}
	return 0;
}