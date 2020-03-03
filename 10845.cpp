#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; //��ɾ �Է¹��� ����
	int n,size = 0,front = 0,back = 0; //��ɾ��� ����,ť�� ũ��,ó���� �� �ε���
	cin >>n;
	int queue[10000];//���� ���ǿ� �°� ����

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		
		if (size == 0) //ũ�Ⱑ 0�� ��� �ε������� 0���� �ʱ�ȭ
		{ 
			front = 0;
			back = 0;
		}

		if (s == "push")
		{
			int x;
			cin >> x;

			queue[back] = x;//�� �ε����� �Է� �� �߰�
			size++;//ũ��� �� �ε����� 1 ����
			back++;
		}
		if (s == "pop")
		{
			if (size == 0)//ũ�Ⱑ 0�� ���
				cout << -1<<"\n";
			else
			{
				cout << queue[front] << "\n";
				front++;//�� �ε����� 1 ������Ű�� ũ�⸦ 1 ���ҽ��� ���� ȿ���� ��
				size--;
			}
		}
		if (s == "size")
			cout << size << "\n";
		if (s == "empty")
		{
			if (size == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		if (s == "front")
		{
			if (size == 0)
				cout << -1 << "\n";
			else
				cout << queue[front] << "\n";
		}
		if(s=="back")
		{
			if (size == 0)
				cout << -1 << "\n";
			else
				cout << queue[back-1] << "\n";
		}

		//�ڵ带 �������鼭 ť�� ��Ȳ�� ���� ���� �ڵ�

		//cout << front << " " << back << " " << size << endl;
		//for (int i = 0; i < 10; i++)
		//	cout << queue[i] << " ";
		//cout << endl;
	}
	
	return 0;
}