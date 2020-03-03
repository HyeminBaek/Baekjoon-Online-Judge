#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; //명령어를 입력받을 변수
	int n,size = 0,front = 0,back = 0; //명령어의 갯수,큐의 크기,처음과 끝 인덱스
	cin >>n;
	int queue[10000];//문제 조건에 맞게 설정

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		
		if (size == 0) //크기가 0인 경우 인덱스들을 0으로 초기화
		{ 
			front = 0;
			back = 0;
		}

		if (s == "push")
		{
			int x;
			cin >> x;

			queue[back] = x;//끝 인덱스에 입력 값 추가
			size++;//크기와 끝 인덱스를 1 증가
			back++;
		}
		if (s == "pop")
		{
			if (size == 0)//크기가 0인 경우
				cout << -1<<"\n";
			else
			{
				cout << queue[front] << "\n";
				front++;//앞 인덱스를 1 증가시키고 크기를 1 감소시켜 삭제 효과를 냄
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

		//코드를 돌려가면서 큐의 현황을 보기 위한 코드

		//cout << front << " " << back << " " << size << endl;
		//for (int i = 0; i < 10; i++)
		//	cout << queue[i] << " ";
		//cout << endl;
	}
	
	return 0;
}