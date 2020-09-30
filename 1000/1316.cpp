#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, num = 0; //num은 그룹 단어를 세기 위한 변수
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		bool alpha[26] = { false }, tf = false; 
		//alpha는 for문을 돌면서 앞에서 알파벳이 나왔는지 알기위한 배열
		for (int j = 0; j < s.length(); j++)
		{
			if (!alpha[s[j] - 97])
				alpha[s[j] - 97] = true; //해당 알파벳 인덱스에 나왔음을 표시
			else
				if (s[j] != s[j - 1])
				{//만약 앞에서 나왔는데 바로 직전 알파벳이랑 다르면 그룹단어가 아닌것
					tf = true; //도중에 빠져나왔음을 표시하는 변수
					break;
				}
		}
		if (!tf)
			num++;
	}
	cout << num;
	
	return 0;
}