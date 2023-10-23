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
// 동적배열
// 크기가 제한되지 않은 배열(메모리가 허용하는 한 계속 늘릴 수 있음)
// 일반 배열과 비슷하지만 컴파일타임에 배열의 크기가 결정되야하는 배열과는 달리
// 런타임에 크기가 계속 바뀔 수 있다.

// 장점
// 메모리에서 연속적이다 (캐시적중 좋음 순회속도빠름)
// 그렇기때문에 배열 위치에 임의접근이 가능하다 ( std::sort, binary_search, n번째원소 참조할때 바로가능)
// 원소뒤에서의 삽입삭제가 O(1)

// 단점
// 정해진 용량의 한계에 도달하면 배열의 모든 내용을 다른 메모리로 전부다 복사 한후
// 기존 쓰던 메모리 영역을 전부 해제하고 이사 간 주소를 시작주소로 다시지정
// 이 과정의 오버헤드가 상당히 비쌈
// 원소의 맨끝에서의 삽입삭제는빠르지만 배열 중간에서의 삽입삭제가 아주 느리다
// 원소를 밀고 당기는 과정이있음

// 포인터같은거 쓸때 벡터의 특정원소의 주소를 가리키고있다가
// 재할당이 일어나서 벡터가 이사를가버리면 그 메모리주소는 철거된주소임 (반복자무효화)

// 배열의 시작주소, 원소의갯수(size), 수용가능한 용량(capacity)를 가지는 클래스

// 메서드들
// push_back   << 배열의 맨뒤에 원소를 추가한다

// pop_back << 배열의 맨뒤의 원소를 제거한다

// [] << 연산자 오버로딩

// reserve 벡터의 용량을 예약한다

// capacity가 한계에 다다르면 기존 capacity의 1.5배 ~ 2배만큼 재할당한다

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
		capacity = n; // 새로운 캐퍼시티
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
		// 아예 싹 날리고 한개 줄일수도있음
		--size;
	}
	int Size() { return size; }
	int& operator[](int idx) { return arr[idx]; }
	int* begin() { return arr; }
	int* end() { return arr + size; }
	void insert(int pos, int n) { // pos라는 인덱스위치에 n을 삽입하고 기존의 n부터 마지막까지의 원소를 한칸씩 뒤로밀어야함
		if (size + 1 >= capacity) {
			reserve(n * 2);
		}
		::memmove(arr + pos + 1, arr + pos, sizeof(int) * (size - pos));
		arr[pos] = n;
		++size;
	}
	void erase(int pos) { // pos라는 인덱스위치의 원소를 지우고 뒤에있는애를 앞으로하나씩 당긴다
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