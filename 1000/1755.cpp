#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string eng(int i)
{
	if (i == 0) return "zero";
	else if (i == 1) return "one";
	else if (i == 2) return "two";
	else if (i == 3) return "three";
	else if (i == 4) return "four";
	else if (i == 5) return "five";
	else if (i == 6) return "six";
	else if (i == 7) return "seven";
	else if (i == 8) return "eight";
	else return "nine";
}
int num(string c)
{
	if (c == "ze") return 0;
	else if (c == "on") return 1;
	else if (c == "tw") return 2;
	else if (c == "th") return 3;
	else if (c == "fo") return 4;
	else if (c == "fi") return 5;
	else if (c == "si") return 6;
	else if (c == "se") return 7;
	else if (c == "ei") return 8;
	else return 9;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;
	vector<string> v;
	for (int i = M; i <= N; i++)
	{
		string temp = "";
		if (i >= 10)
			temp = eng(i / 10) + " ";
		temp += eng(i % 10);

		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++)
	{
		
		if (i > 0 && i % 10 == 0) cout << "\n";
		
		int answer = 0;
		string temp = v[i].substr(0, 2);
		answer += num(temp);
		
		if (v[i].length() >= 6)
		{
			if (temp == "on" || temp == "tw" || temp == "si")
				temp = v[i].substr(4, 2);
			else if (temp == "th" || temp == "se" || temp == "ei")
				temp = v[i].substr(6, 2);
			else if (temp == "fo" || temp == "fi" || temp == "ni"||temp=="ze")
				temp = v[i].substr(5, 2);

			//cout << temp << endl;
			answer *= 10;
			answer += num(temp);
		}
		
		cout << answer << " ";
		
	}

	return 0;
}