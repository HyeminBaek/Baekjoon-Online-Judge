#include <iostream>
#include <string>
using namespace std;

int main()
{
	string binary; cin >> binary;
	string eight = "";

	while (binary.length() % 3 != 0)
	{
		binary = "0" + binary;
	}
	for (int i = binary.length() - 1; i >= 2; i -= 3)
	{
		string temp = binary.substr(i - 2, 3);
		if (temp == "000") eight = "0" + eight;
		else if (temp == "001") eight = "1" + eight;
		else if (temp == "010") eight = "2" + eight;
		else if (temp == "011") eight = "3" + eight;
		else if (temp == "100") eight = "4" + eight;
		else if (temp == "101") eight = "5" + eight;
		else if (temp == "110") eight = "6" + eight;
		else if (temp == "111") eight = "7" + eight;
	}

	cout << eight;

	return 0;
}