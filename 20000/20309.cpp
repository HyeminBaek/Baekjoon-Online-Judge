#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	bool flag = true; //���� üũ�ϱ� ���� �÷��� ����
	for (int i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0)//¦���̸�
		{
			if (i % 2 == 0)//�ε��� ��ġ 1�� ��츸 Ʈ���� ��Ʈ�� �������� ���� ����
			{
				flag = false;
				break;
			}
		}
		else
		{
			if (i % 2 == 1)//�ε��� ��ġ�� 1�� ��� ���� �Ұ�
			{
				flag = false;
				break;
			}
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}