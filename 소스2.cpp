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
		cout << "������Ʈ" << endl;
	}
};

int main()
{
	int** p = new int * [10];

	for (int i = 0; i < 10; ++i)
	{
		p[i] = new int;
	}

	// �� �������� �޸𸮰� �� 1����Ʈ�� ���� ���� �ʵ��� �ڵ带 �����϶�

	// ù��° , [] <<< ���޸𸮿� ������ 10��
	// �ι�°, p[0] << int�Ѱ� ���޸𸮿� �Ҵ�

	

	for (int i = 0; i < 10; ++i)
	{
		delete p[i];
	}

	delete[]p;
}





