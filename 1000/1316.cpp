#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, num = 0; //num�� �׷� �ܾ ���� ���� ����
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		bool alpha[26] = { false }, tf = false; 
		//alpha�� for���� ���鼭 �տ��� ���ĺ��� ���Դ��� �˱����� �迭
		for (int j = 0; j < s.length(); j++)
		{
			if (!alpha[s[j] - 97])
				alpha[s[j] - 97] = true; //�ش� ���ĺ� �ε����� �������� ǥ��
			else
				if (s[j] != s[j - 1])
				{//���� �տ��� ���Դµ� �ٷ� ���� ���ĺ��̶� �ٸ��� �׷�ܾ �ƴѰ�
					tf = true; //���߿� ������������ ǥ���ϴ� ����
					break;
				}
		}
		if (!tf)
			num++;
	}
	cout << num;
	
	return 0;
}