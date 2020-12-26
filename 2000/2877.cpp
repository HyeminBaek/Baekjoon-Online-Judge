#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K; cin >> K;

	string binary = "";

	K++;

	while (K > 0)
	{
		binary = to_string(K % 2) + binary;
		K /= 2;
	}

	string answer = "";
	for (int i = 1; i < binary.length(); i++)
		answer += (binary[i] == '0') ? "4" : "7";

	cout << answer;

	return 0;
}