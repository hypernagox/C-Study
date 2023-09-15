#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <ranges>
#include <vector>
#include <numeric>
using namespace std;

int cmp(const int* a, const int* b)
{
	return *a - *b;
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

void foo()
{
	cout << "hello world" << endl;
}

int main()
{
	//int arr[10]{ 1,3,5,7,9,2,4,6,8,10 };
	//::qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), reinterpret_cast<int(*)(const void*, const void*)>(cmp));
	//::qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp);
	/*ifstream in{ "data.txt" };
	int n;
	in >> n;
	if (!in)
	{
		cout << "in" << endl;
	}
	if (in.is_open())
	{
		cout << "open" << endl;
	}*/
	//ifstream in{ "cpp_study.txt" };
	///*unsigned long long sum = 0;
	//int n;
	//while (in >> n) {
	//	sum += n;
	//}
	//cout << sum << endl;*/
	/*string temp;
	int cnt = 0;
	vector<string> vec;
	while (in >> temp) {
		if (std::ranges::all_of(temp, [](char ch) {return (int)(ch - '0') & 1; })) {
			++cnt;
			vec.emplace_back(std::move(temp));
		}
	}
	cout << cnt << endl;
	for(auto& s:vec)
		cout<<s<<endl;*/
	
	/*const char* p = "hi";
	const char* p2 = "hi";
	int a;*/
	/*int a = 1200;
	int* pa = &a;
	int& ra = a;
	cout << a;
	int b = 10;*/
	
	/*ifstream in{ "cpp_study_short.txt" };
	istream_iterator<string> file_begin{ in };
	vector<string> strVec{ file_begin,istream_iterator<string>{} };
	string temp;
	for (auto& str : strVec)
	{
		cout << str << endl;
	}
	int odd = 0;
	int even = 0;
	int cnt = 0;
	while (in >> temp) {
		ranges::for_each(temp, [&](char ch) {
			const int num = (int)(ch - '0');
			if (num & 1)++even;
			else ++odd;
			++cnt;
			});
	}
	cout << "짝수: " << odd << endl;
	cout << "홀수: " << even << endl;
	cout << "수: " << cnt << endl;*/

	//int n = 1;
	//float f;
	//memcpy(&f, &n, sizeof(n));
	//cout << n << endl;
	//cout << f << endl;
	////
	//cout << endl;

	//cout << *reinterpret_cast<float*>(&n) << endl;
	//cout << *reinterpret_cast<int*>(&f) << endl;
	//int a;

	/*const int a = 3;
	const int b = 4;
	const int c = a + b;
	printf("%d", c);
	return 0;*/

	// 1. 변수와 자료형
	// 변수란? 메모리에 변수의 크기만큼 할당하고 그 위치에 이름을 붙인것
	// 자료형? 1. 데이터의 크기
	//		   2. 데이터의 해석방법
	//

	// 2. 프로그램 실행 시 발생 하는 일
	// 1. 코드영역
	// 리터럴, 함수들
	//2. 데이터영역
	// 전역변수, 정적변수,
	// 초기화된 전역변수 vs 초기화안된 전역변수
	// 초기화된 전역변수는 실행파일의 크기를 늘린다
	// 이유: main 함수 시작전에 모든 값이 해당하는 값으로 초기화 되어야 하므로 실행파일 자체에 해당 값들이 실제로 포함됨
	// 초기화 안된 전역변수는 어차피 초기화는 디폴트로 될것이 보장되어있으니까 그 데이터의 크기 정보만 저장됨

	// 3. 힙영역
	// 런타임에 new나 malloc으로 동적할당받은 변수들이 저장되는곳
	// 프로그래머는 운영체제에게 이곳에 메모리를 할당해달라고 요청하고 할당받은 위치의 주소(포인터)를 받아서 사용한다
	// 할당과 해제의 책임이 프로그래머에게 있음
	// 생각보다 delete 이후 사용하는거 은근히 안잡힐때가 꽤 있음
	
	// 4. 스택영역
	// 함수의 매개변수 및 지역변수들이 사는 곳
	// 함수 호출할때 돌아올 주소를 저장하기 위해서도 쓴다.
	// 함수, 지역이 끝나면 자동으로 반환됨. 그렇기에 자동 저장소 라고도 불림
	// [문제] 정수를 1천만개 저장 할 수 있는 배열을 할당하라
	
//int b = 10;
//for (auto& a : arr) {
//	a = 10;
//	b += a;
//
//}
//cout << b;

	// 함수란?
	// 결국 프로그래머가 작성한 함수는 다 기계어가 됨
	// 함수들은 전부 코드영역속에 있음
	// 함수의 이름은 정확히 코드영역의 함수의 시작주소와 같음 (마치 배열의 이름같음)
	// 이거 포인터 처럼 쓸 수 있음
	// 호출 시 발생하는 오버헤드?
	// 1. 일단 내가 돌아올 곳의 주소를 스택에넣고
	// 2. 매개변수들을 스택에 넣고
	// 3. 함수에 사용될 스택영역에 스택프레임을 잡고
	// 4. 일을하고 스택프레임을 철거하고 돌아온다
	// 공짜가 아님

	// int자료형 말씀하신 이유
	// 1. cppref가 진리다.
	// 2. 자료형크기는 플랫폼마다 다를수 있으니 sizeof를 써서 실수의 여지를 만들지 말자

	// 파일스트림 is open과 in차이
	// [문제] 파일을 읽어서, 해당 파일에 1,2,3 ... 같은 숫자의 갯수는 총 몇개인지, 홀수는 몇개인지, 짝수는 몇개인지 세어라
	// 2. 파일에서 모든 값을 더해서 그 값을 출력하라



	// const를 써야하는 이유 (간단한 컴파일러 최적화)
	
	//

	// qsort 소개
	// [문제] qsort를 이용해서 해당 문자열을 사전순으로 정렬하라
	//
	// char str[] = "C++Study";
//qsort(str, sizeof(str) / sizeof(char) - 1, sizeof(char), [](const void* a, const void* b) {
//	return *(const char*)(a)-*(const char*)(b);
//	});
//cout << str << endl;
	//랜덤엔진 소개
	// [문제] 주사위
}