#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n;//��ɾ� ������ ���� ����
	cin >> n;

	vector<char> stack_L;//Ŀ���� ����
	vector<char> queue_R;//Ŀ���� ������

	for (int i = 0; i < s.length(); i++)
	{ 
		//Ŀ���� �� �ڿ� ��ġ�ϹǷ� ���ÿ� ���� �־���
		stack_L.push_back(s[i]);
	}

	for (int i = 0; i < n; i++)
	{
		char c;//��ɾ� �Է�
		cin >> c;

		if (c == 'L')
		{
			if (!stack_L.empty())//Ŀ���� ������ �� ���� �ƴ϶��
			{
				queue_R.push_back(stack_L.back());
				stack_L.pop_back();
			}
		}
		else if (c == 'D')
		{
			if (!queue_R.empty())//Ŀ���� ������ �� �ڰ� �ƴ϶��
			{
				stack_L.push_back(queue_R.back());
				queue_R.pop_back();
			}
		}
		else if (c == 'B')
		{
			if (!stack_L.empty())//Ŀ���� ������ �� ���� �ƴ϶��
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