#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		int numOfDoc, locOfDoc;
		cin >> numOfDoc >> locOfDoc;

		queue<int> printer;
		int* temp = new int[numOfDoc];//�߿䵵�� ���� ���� ���� ã�Ƴ��� ����

		for (int j = 0; j < numOfDoc; j++)
			cin >> temp[j];
		for (int j = 0; j < numOfDoc; j++)//�迭�� �Է¹��� ���� �״�� ť���� ����
			printer.push(temp[j]);

		sort(temp, temp + numOfDoc);//�����Ͽ� ���� ���� �߿䵵�� ã�Ƴ���

		int max = temp[numOfDoc - 1], max_index = numOfDoc - 1, num = 0;
		//���⼭ num ������ ���߿� �� ��°�� ��µǴ��� ���� ����

		while (!printer.empty())
		{
			if (printer.front() < max)//�߿䵵�� ���� ������ �ڿ� �ִٴ� ��
			{
				printer.push(printer.front());
				printer.pop();//front�� ��ġ�� ������ ���� �ڷ� ����
				if (locOfDoc == 0)//�ñ��� ��ġ�� ������ ���
					locOfDoc = printer.size() - 1;//�ڷ� �������� ���� ��ġ�� ��������
				else//�ñ��� ��ġ�� ������ ������� ������ �ڷ� ������ ���
					locOfDoc--;//�ñ��� ��ġ�� ������ �մ����
			}
			else//�߿䵵�� ���� ���� ������ ���� �տ� �ִٴ� ��
			{
				printer.pop();
				max = temp[--max_index];//�� �������� �߿䵵�� ���� ���� ��������
				num++;//���ݱ��� ��µ� ������ ��
				if (locOfDoc == 0)//�ñ��� ��ġ�� ������ pop�� ����
				{
					cout << num << "\n";
					break;//�� �̻� �ݺ����� �� �ʿ䰡 �����Ƿ� ���´�
				}
				else //���� �ñ��� ��ġ�� ������ ť�� �����ִٴ� ��
					locOfDoc--;//pop �Ǿ����Ƿ� �մ������
			}
		}
	}

	return 0;
}