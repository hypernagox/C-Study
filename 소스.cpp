#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <ranges>
#include <vector>
#include <numeric>
#include <memory>
#include <Windows.h>
using namespace std;

// vector
// �����迭
// ũ�Ⱑ ���ѵ��� ���� �迭(�޸𸮰� ����ϴ� �� ��� �ø� �� ����)
// �Ϲ� �迭�� ��������� ������Ÿ�ӿ� �迭�� ũ�Ⱑ �����Ǿ��ϴ� �迭���� �޸�
// ��Ÿ�ӿ� ũ�Ⱑ ��� �ٲ� �� �ִ�.

// ����
// �޸𸮿��� �������̴� (ĳ������ ���� ��ȸ�ӵ�����)
// �׷��⶧���� �迭 ��ġ�� ���������� �����ϴ� ( std::sort, binary_search, n��°���� �����Ҷ� �ٷΰ���)
// ���ҵڿ����� ���Ի����� O(1)

// ����
// ������ �뷮�� �Ѱ迡 �����ϸ� �迭�� ��� ������ �ٸ� �޸𸮷� ���δ� ���� ����
// ���� ���� �޸� ������ ���� �����ϰ� �̻� �� �ּҸ� �����ּҷ� �ٽ�����
// �� ������ ������尡 ����� ���
// ������ �ǳ������� ���Ի����º������� �迭 �߰������� ���Ի����� ���� ������
// ���Ҹ� �а� ���� ����������

// �����Ͱ����� ���� ������ Ư�������� �ּҸ� ����Ű���ִٰ�
// ���Ҵ��� �Ͼ�� ���Ͱ� �̻縦�������� �� �޸��ּҴ� ö�ŵ��ּ��� (�ݺ��ڹ�ȿȭ)

// �迭�� �����ּ�, �����ǰ���(size), ���밡���� �뷮(capacity)�� ������ Ŭ����

// �޼����
// push_back   << �迭�� �ǵڿ� ���Ҹ� �߰��Ѵ�

// pop_back << �迭�� �ǵ��� ���Ҹ� �����Ѵ�

// [] << ������ �����ε�

// reserve ������ �뷮�� �����Ѵ�

// capacity�� �Ѱ迡 �ٴٸ��� ���� capacity�� 1.5�� ~ 2�踸ŭ ���Ҵ��Ѵ�

class Vector
{
private:
	int* arr = nullptr;
	int size = 0;
	int capacity = 1;
public:
	Vector() {
		arr = new int[capacity];
	}
	~Vector() {
		delete[]arr;
	}
	void reserve(int n) {
		if (capacity >= n)
			return;
		capacity = n; // ���ο� ĳ�۽�Ƽ
		int* temp = new int[capacity];
		::memcpy(temp, arr, sizeof(int) * size);
		delete[]arr;
		arr = temp;
	}

	void push_back(int n) {
		if (size == capacity) {
			reserve(n * 2);
		}
		arr[size++] = n;
	}
	void pop_back() {
		// �ƿ� �� ������ �Ѱ� ���ϼ�������
		--size;
	}
	int Size() { return size; }
	int& operator[](int idx) { return arr[idx]; }
	int* begin() { return arr; }
	int* end() { return arr + size; }
	void insert(int pos, int n) { // pos��� �ε�����ġ�� n�� �����ϰ� ������ n���� ������������ ���Ҹ� ��ĭ�� �ڷιо����
		if (size + 1 >= capacity) {
			reserve(n * 2);
		}
		::memmove(arr + pos + 1, arr + pos, sizeof(int) * (size - pos));
		arr[pos] = n;
		++size;
	}
	void erase(int pos) { // pos��� �ε�����ġ�� ���Ҹ� ����� �ڿ��ִ¾ָ� �������ϳ��� ����
		::memmove(arr + pos, arr + pos + 1, sizeof(int) * (size - pos));
		--size;
	}
};
int main()
{
	Vector v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	for (int i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << endl;
	}
	v.insert(3, 100);
	v.insert(3, 11);
	for (int i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << endl;
	}
	Sleep(100);
	v.erase(3);
	v.erase(3);
	cout << endl;
	for (int i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << endl;
	}
	int num = v.Size();
	for (int i = 0; i < num; ++i)
	{
		v.erase(0);
	}

	for (int i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << endl;
	}

	Sleep(100);
}