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
		int* temp = new int[numOfDoc];//중요도가 높은 것을 쉽게 찾아내기 위함

		for (int j = 0; j < numOfDoc; j++)
			cin >> temp[j];
		for (int j = 0; j < numOfDoc; j++)//배열에 입력받은 것을 그대로 큐에도 복사
			printer.push(temp[j]);

		sort(temp, temp + numOfDoc);//정렬하여 제일 높은 중요도를 찾아낸다

		int max = temp[numOfDoc - 1], max_index = numOfDoc - 1, num = 0;
		//여기서 num 변수는 나중에 몇 번째로 출력되는지 세기 위함

		while (!printer.empty())
		{
			if (printer.front() < max)//중요도가 높은 문서가 뒤에 있다는 것
			{
				printer.push(printer.front());
				printer.pop();//front에 위치한 문서를 빼고 뒤로 보냄
				if (locOfDoc == 0)//궁금한 위치의 문서의 경우
					locOfDoc = printer.size() - 1;//뒤로 보내질때 현재 위치도 변경해줌
				else//궁금한 위치의 문서와 관계없는 문서가 뒤로 보내진 경우
					locOfDoc--;//궁금한 위치의 문서가 앞당겨짐
			}
			else//중요도가 제일 높은 문서가 제일 앞에 있다는 것
			{
				printer.pop();
				max = temp[--max_index];//그 다음으로 중요도가 높은 수로 갱신해줌
				num++;//지금까지 출력된 문서의 수
				if (locOfDoc == 0)//궁금한 위치의 문서가 pop할 차례
				{
					cout << num << "\n";
					break;//더 이상 반복문을 돌 필요가 없으므로 나온다
				}
				else //아직 궁금한 위치의 문서가 큐에 남아있다는 것
					locOfDoc--;//pop 되었으므로 앞당겨진다
			}
		}
	}

	return 0;
}