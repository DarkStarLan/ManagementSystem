#pragma once
#include <iostream>
using namespace std;
#include <string>
#include<stdlib.h>  //rand头文件 
#include<ctime>  //srand头文件 
#include<Windows.h>
#include<fstream>  //读写文件
#include<cmath>
#include<cstdio>

class sai {
public:
	string m_Name = "DefaultName";
	int m_Id = 0;
	void reName(const string& name);
	void reId(const int& id);
	sai();
	sai(const string& name, const int& id);
	sai(const sai& sai);
	sai& operator+(const sai& sai_first);
	sai& operator-(const sai& sai_first);
	sai& operator*(const sai& sai_first);
	sai& operator/(const sai& sai_first);
	sai& operator%(const sai& sai_first);
	sai& operator++();
	sai operator++(int);
	sai& operator--();
	sai operator--(int);
	sai& operator=(sai& sai);
	bool operator==(sai& sai);
	bool operator!=(sai& sai);
};
ostream& operator<<(ostream& cout, sai& sai);

string ssg(const string& str, const int& st, const int& en);
string sj(const string& str, const string& st, const string& en);
void syso(const string& str);
void syso(const string& str, const bool& mode);
void syso(const int& str);
void syso(const int& str, const bool& mode);
string ss_add(const string& str1, const string& str2);
void siof(const string& str, const string& goal, int& name);
void siof(const string& str, const string& goal, const int& add, int& name);
int siof(const string& str, const string& goal);
int siof(const string& str, const string& goal, const int& add);
int* sl(const string& str, const string& goal);
int slg(const string& str);
void slg(const string& str, int& name);
string strim(const string& str);
void sr(string str, const char& cha1, const char& cha2, string& name);
string sr(string str, const char& cha1, const char& cha2);
void sr(string& str, const char& cha1, const char& cha2);
int sran(const int& first, const int& last);
void sran(const int& first, const int& last, int& name);
void sranh();
void stop(const int& time);
void forsyso(const string& str);
void forsyso(const string& str, const bool& mode);
void isystem(const string& str_first, const string& str_last);
short numb(int num, const int& bit);
void HideWindow();
void BubbleSort(int* p, const int& len);
void PrintArray(const int* p, const int& len);
bool ifin(const string& str, const string& goal);
bool isInRange(const float& flo1, const float& flo2, const float& range);
float isInRange(const float& flo1, const float& flo2);
float isInRange(const float& flo1, const float& flo2, const bool& mode);
void fct(const string& load);
bool fct(const bool& mode, const string& load);
void fw(const string& load, const string& str);
bool fw(const bool& mode, const string& load, const string& str);
void fr(const string& load, string& name);
bool fr(const bool& mode, const string& load, string& name);
string fr(const string& load);
void fd(const string& load);
bool fd(const bool& mode, const string& load);
void fn(const string& name_first, const string& name_last);
bool fn(const bool& mode, const string& name_first, const string& name_last);
void fe(const string& load, bool& result);
bool fe(const string& load);
void fc(const string& load_first, const string& load_last);
void fc(const string& load_first, const string& load_last, const bool& mode);
bool fc(const bool& isReturn, const string& load_first, const string& load_last);
bool fc(const bool& isReturn, const string& load_first, const string& load_last, const bool& mode);
void fm(const string& load_first, const string& load_last);
bool fm(const bool& mode, const string& load_first, const string& load_last);
void capl(string& str);
void capl(string& str, const bool& mode);
void autoCapl(string & str);
bool equation2(const double& a, const double& b, const double& c, double& x1, double& x2);