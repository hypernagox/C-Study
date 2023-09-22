#include "CppStudyClient.h"
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <ranges>
#include <algorithm>
#include <random>
#include "String.h"
#include <map>
using namespace std;

// 포인터와 레퍼런스

// C++ 포인터사용이유: 메모리를 직접 조작하기위해서
// 레퍼런스: 포인터와 99프로 똑같음
// 레퍼런스의 사용이유:
// 1. 복사를 피하기위해서
// 2. 데이터에 직접 접근하기위해서 

// 포인터와 레퍼런스의 차이

// 1. 포인터는 배열을 만들 수 있지만, 레퍼런스는 못함
// 2. 포인터는 그냥 선언하고 나중에 값 할당하고 써도 되지만, 레퍼런스는 선언과 동시에 초기화 되어야함
// 3. 포인터는 nullptr이 들어올수있지만 null자체가 들어올수가없음
// 4. 포인터는 주소를담는 자료형이기때문에 반드시 8바이트 먹음
// 레퍼런스는 대부분 8바이트지만 간혹 메모리아에 안차지하는경우가있음


// 사용자 정의 자료형
// 스트럭트, 클래스
// 데이터랑 함수를 하나의 단위로묶은것

struct a
{
	double b;
	int a;
};

struct Test
{
	a t;
	char h;
	void foo() {

	}
	void foo1() {

	}
	void foo2() {

	}
	void foo3() {

	}
};

int main()
{
	

	cout << sizeof(Test) << endl;
	
	
}