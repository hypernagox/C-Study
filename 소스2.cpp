#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <iomanip>
#include <fstream>
using namespace std;

class Test
{
private:
	int n = 10;
public:
	void update() {
		this->n = 100;
		cout << "업데이트" << endl;
	}
};

int main()
{
	int** p = new int * [10];

	for (int i = 0; i < 10; ++i)
	{
		p[i] = new int;
	}

	// 이 예제에서 메모리가 단 1바이트도 누수 되지 않도록 코드를 수정하라

	// 첫번째 , [] <<< 힙메모리에 포인터 10개
	// 두번째, p[0] << int한개 힙메모리에 할당

	

	for (int i = 0; i < 10; ++i)
	{
		delete p[i];
	}

	delete[]p;
}





