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
	cout << "¦��: " << odd << endl;
	cout << "Ȧ��: " << even << endl;
	cout << "��: " << cnt << endl;*/

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

	// 1. ������ �ڷ���
	// ������? �޸𸮿� ������ ũ�⸸ŭ �Ҵ��ϰ� �� ��ġ�� �̸��� ���ΰ�
	// �ڷ���? 1. �������� ũ��
	//		   2. �������� �ؼ����
	//

	// 2. ���α׷� ���� �� �߻� �ϴ� ��
	// 1. �ڵ念��
	// ���ͷ�, �Լ���
	//2. �����Ϳ���
	// ��������, ��������,
	// �ʱ�ȭ�� �������� vs �ʱ�ȭ�ȵ� ��������
	// �ʱ�ȭ�� ���������� ���������� ũ�⸦ �ø���
	// ����: main �Լ� �������� ��� ���� �ش��ϴ� ������ �ʱ�ȭ �Ǿ�� �ϹǷ� �������� ��ü�� �ش� ������ ������ ���Ե�
	// �ʱ�ȭ �ȵ� ���������� ������ �ʱ�ȭ�� ����Ʈ�� �ɰ��� ����Ǿ������ϱ� �� �������� ũ�� ������ �����

	// 3. ������
	// ��Ÿ�ӿ� new�� malloc���� �����Ҵ���� �������� ����Ǵ°�
	// ���α׷��Ӵ� �ü������ �̰��� �޸𸮸� �Ҵ��ش޶�� ��û�ϰ� �Ҵ���� ��ġ�� �ּ�(������)�� �޾Ƽ� ����Ѵ�
	// �Ҵ�� ������ å���� ���α׷��ӿ��� ����
	// �������� delete ���� ����ϴ°� ������ ���������� �� ����
	
	// 4. ���ÿ���
	// �Լ��� �Ű����� �� ������������ ��� ��
	// �Լ� ȣ���Ҷ� ���ƿ� �ּҸ� �����ϱ� ���ؼ��� ����.
	// �Լ�, ������ ������ �ڵ����� ��ȯ��. �׷��⿡ �ڵ� ����� ��� �Ҹ�
	// [����] ������ 1õ���� ���� �� �� �ִ� �迭�� �Ҵ��϶�
	
//int b = 10;
//for (auto& a : arr) {
//	a = 10;
//	b += a;
//
//}
//cout << b;

	// �Լ���?
	// �ᱹ ���α׷��Ӱ� �ۼ��� �Լ��� �� ��� ��
	// �Լ����� ���� �ڵ念���ӿ� ����
	// �Լ��� �̸��� ��Ȯ�� �ڵ念���� �Լ��� �����ּҿ� ���� (��ġ �迭�� �̸�����)
	// �̰� ������ ó�� �� �� ����
	// ȣ�� �� �߻��ϴ� �������?
	// 1. �ϴ� ���� ���ƿ� ���� �ּҸ� ���ÿ��ְ�
	// 2. �Ű��������� ���ÿ� �ְ�
	// 3. �Լ��� ���� ���ÿ����� ������������ ���
	// 4. �����ϰ� ������������ ö���ϰ� ���ƿ´�
	// ��¥�� �ƴ�

	// int�ڷ��� �����Ͻ� ����
	// 1. cppref�� ������.
	// 2. �ڷ���ũ��� �÷������� �ٸ��� ������ sizeof�� �Ἥ �Ǽ��� ������ ������ ����

	// ���Ͻ�Ʈ�� is open�� in����
	// [����] ������ �о, �ش� ���Ͽ� 1,2,3 ... ���� ������ ������ �� �����, Ȧ���� �����, ¦���� ����� �����
	// 2. ���Ͽ��� ��� ���� ���ؼ� �� ���� ����϶�



	// const�� ����ϴ� ���� (������ �����Ϸ� ����ȭ)
	
	//

	// qsort �Ұ�
	// [����] qsort�� �̿��ؼ� �ش� ���ڿ��� ���������� �����϶�
	//
	// char str[] = "C++Study";
//qsort(str, sizeof(str) / sizeof(char) - 1, sizeof(char), [](const void* a, const void* b) {
//	return *(const char*)(a)-*(const char*)(b);
//	});
//cout << str << endl;
	//�������� �Ұ�
	// [����] �ֻ���
}