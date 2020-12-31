#include <iostream>
using namespace std;

void Star(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) // 좌표에 따른 규칙성 파악
	{
		cout << " ";
	}
	else
	{
		if (n / 3 == 0)
		{
			cout << "*";
		}
		else
		{
			Star(i, j, n / 3); // 모든 3의 거듭제곱 N에 대한 NxN 사각형의 가운데에 속하지 않으면 * 출력
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			Star(i, j, n);
		cout << endl;
	}

}

