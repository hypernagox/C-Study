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
	String str1 = "helLo";
	String str2 = "world";
	
	cout<<*std::find_if(str1.begin(), str1.end(), isupper);
	cout<<std::all_of(str2.begin(), str2.end(), islower);
	
	for(int i=0;i<10;++i)
		Send_Code(L"¼Ò½º1.cpp",L"ÃÖÀçÇõ");
	
}