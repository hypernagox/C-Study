#include "CppStudyClient.h"
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <ranges>
#include <algorithm>
#include "String.h"

using namespace std;

int main()
{
	String str = "helLo";
	String str2 = "world";
	
	cout<<*std::find_if(str.begin(), str.end(), isupper);
	cout<<std::all_of(str.begin(), str.end(), islower);
	
	for(int i=0;i<10;++i)
		Send_Code("192.168.0.43", L"¼Ò½º1.cpp",L"ÃÖÀçÇõ");
	
}