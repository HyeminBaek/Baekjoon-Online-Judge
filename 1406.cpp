#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n;//명령어 개수를 받을 변수
	cin >> n;

	vector<char> stack_L;//커서의 왼쪽
	vector<char> queue_R;//커서의 오른쪽

	for (int i = 0; i < s.length(); i++)
	{ 
		//커서가 맨 뒤에 위치하므로 스택에 전부 넣어줌
		stack_L.push_back(s[i]);
	}

	for (int i = 0; i < n; i++)
	{
		char c;//명령어 입력
		cin >> c;

		if (c == 'L')
		{
			if (!stack_L.empty())//커서가 문장의 맨 앞이 아니라면
			{
				queue_R.push_back(stack_L.back());
				stack_L.pop_back();
			}
		}
		else if (c == 'D')
		{
			if (!queue_R.empty())//커서가 문장의 맨 뒤가 아니라면
			{
				stack_L.push_back(queue_R.back());
				queue_R.pop_back();
			}
		}
		else if (c == 'B')
		{
			if (!stack_L.empty())//커서가 문장의 맨 앞이 아니라면
				stack_L.pop_back();
		}
		else if (c == 'P')
		{
			char x;
			cin >> x;

			stack_L.push_back(x);
		}
	}

	for (int i = 0; i < stack_L.size(); i++)
		cout << stack_L[i];
	for (int i = queue_R.size()-1; i >= 0; i--)
		cout << queue_R[i];

	return 0;
}