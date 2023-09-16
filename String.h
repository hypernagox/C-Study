#pragma once
#include <iostream>
using namespace std;
class String
{
private:
	char* m_pStr = nullptr;
	size_t m_len = 0;
public:
	bool bDebug = true;
	String() = default;
	~String() {
		delete m_pStr;
	}
	String(const char* pStr_) {
		m_len = strlen(pStr_);
		m_pStr = new char[m_len];
		memcpy(m_pStr, pStr_, m_len);
	}
	friend std::ostream& operator << (std::ostream& os, const String& str) {
		for (int i = 0; i < str.m_len; ++i)
		{
			os << str.m_pStr[i];
		}
		return os;
	}
	String(const String& other) {
		m_len = other.m_len;
		m_pStr = new char[m_len];
		memcpy(m_pStr, other.m_pStr, m_len);
		if (bDebug)cout << "복사생성자" << endl;
	}
	String& operator = (const String& other) {
		if (this != &other) {
			delete m_pStr;
			m_len = other.m_len;
			m_pStr = new char[m_len];
			memcpy(m_pStr, other.m_pStr, m_len);
		}
		if (bDebug)cout << "복사대입연산자" << endl;
		return *this;
	}
	String(String&& other)noexcept {
		m_pStr = other.m_pStr;
		m_len = other.m_len;
		other.m_pStr = nullptr;
		other.m_len = 0;
		if (bDebug)cout << "이동생성자" << endl;
	}
	String& operator = (String&& other)noexcept {
		if (this != &other) {
			delete m_pStr;
			m_pStr = other.m_pStr;
			m_len = other.m_len;
			other.m_pStr = nullptr;
			other.m_len = 0;
		}
		if (bDebug)cout << "이동대입연산자" << endl;
		return *this;
	}
	String operator + (const String& other) {
		String temp;
		temp.m_pStr = new char[m_len + other.m_len];
		temp.m_len = m_len + other.m_len;
		memcpy(temp.m_pStr, m_pStr, m_len);
		memcpy(temp.m_pStr + m_len, other.m_pStr, other.m_len);
		return temp;
	}
	String& operator += (const String& other) {
		*this = *this + other;
		return *this;
	}
	char& operator[](const int idx) { return m_pStr[idx]; }
public:
	class iterator
	{
	private:
		char* m_pCursor = nullptr;
		size_t m_iCurPos = 0;
	public:
		iterator() = default;
		iterator(char* pStr_):m_pCursor{ pStr_ }{}
		char& operator*() { return *(m_pCursor + m_iCurPos); }
		char* operator ->() { return m_pCursor + m_iCurPos; }
		iterator& operator ++() {
			++m_iCurPos;
			return *this;
		}
		iterator operator ++(int) {
			iterator temp = *this;
			++m_iCurPos;
			return temp;
		}
		iterator& operator --() {
			--m_iCurPos;
			return *this;
		}
		iterator operator --(int) {
			iterator temp = *this;
			--m_iCurPos;
			return temp;
		}
		bool operator != (const iterator& other) { return *(m_pCursor + m_iCurPos) != *(other.m_pCursor + other.m_iCurPos); }
		bool operator == (const iterator& other) { return *(m_pCursor + m_iCurPos) == *(other.m_pCursor + other.m_iCurPos); }
	};
	iterator begin()const {return iterator{m_pStr}; }
	iterator end() const{ return iterator{ m_pStr + m_len }; }
};

