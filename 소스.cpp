#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <ranges>
#include <vector>
using namespace std;

int cmp(const int* a, const int* b)
{
	return *a - *b;
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
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
	cout << "Â¦¼ö: " << odd << endl;
	cout << "È¦¼ö: " << even << endl;
	cout << "¼ö: " << cnt << endl;*/
}