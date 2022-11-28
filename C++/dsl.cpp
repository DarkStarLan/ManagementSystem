#include"dsl.h"

//class sai
void sai::reName(const string& name) {
    m_Name = name;
}
void sai::reId(const int& id) {
    m_Id = id;
}
sai::sai() {}
sai::sai(const string& name, const int& id) {
    m_Name = name;
    m_Id = id;
}
sai::sai(const sai& sai) {
    this->m_Name = sai.m_Name;
    this->m_Id = sai.m_Id;
}
sai& sai::operator+(const sai& sai_first){
    this->m_Id += sai_first.m_Id;
    return *this;
}
sai& sai::operator-(const sai& sai_first) {
    this->m_Id -= sai_first.m_Id;
    return *this;
}
sai& sai::operator*(const sai& sai_first) {
    this->m_Id *= sai_first.m_Id;
    return *this;
}
sai& sai::operator/(const sai& sai_first) {
    this->m_Id /= sai_first.m_Id;
    return *this;
}
sai& sai::operator%(const sai& sai_first) {
    this->m_Id %= sai_first.m_Id;
    return *this;
}
sai& sai::operator++() {
    m_Id++;
    return *this;
}
sai sai::operator++(int) {
    sai temp = *this;
    m_Id++;
    return temp;
}
sai& sai::operator--() {
    m_Id--;
    return *this;
}
sai sai::operator--(int) {
    sai temp = *this;
    m_Id--;
    return temp;
}
ostream& operator<<(ostream& cout, sai& sai) {
    cout << "Name: " << sai.m_Name << " Id: " << sai.m_Id;
    return cout;
}
sai& sai::operator=(sai& sai) {
    this->m_Id = sai.m_Id;
    this->m_Name = sai.m_Name;
    return *this;
}
bool sai::operator==(sai& sai) {
    if (this->m_Id == sai.m_Id && this->m_Name == sai.m_Name)
        return true;
    return false;
}
bool sai::operator!=(sai& sai) {
    if (this->m_Id == sai.m_Id && this->m_Name == sai.m_Name)
        return false;
    return true;
}

//封装函数和方法(非成员函数)
string ssg(const string& str, const int& st, const int& en)
{
    string a;
    if (en - st < 2)
    {
        return "";
    }
    else if (en < str.length())
    {
        for (int i = 1; i < (en - st); ++i)
        {
            a += str[st + i];
        }
        cout << "ok" << endl;
    }
    else
    {
        return "";
    }
    return a;
}
string sj(const string& str, const string& st, const string& en)
{
    if (st == en) return "";
    int first = str.find_first_of(st);
    int last = str.find_last_of(en);
    if (last > first) return "";
    string a;
    for (int i = 1; i < (last - first); ++i)
    {
        a += str[first + i];
    }
    return a;
}
void syso(const string& str){
    cout << str << endl;
}
void syso(const string& str, const bool& mode) {
    if (mode) cout << str << endl;
    else cout << str;
}
void syso(const int& str) {
    cout << str << endl;
}
void syso(const int& str, const bool& mode) {
    if (mode) cout << str << endl;
    else cout << str;
}
string ss_add(const string& str1, const string& str2)
{
    return str1 + str2;
}
void siof(const string& str, const string& goal, int& name) {
    name = str.find(goal);
}
void siof(const string& str, const string& goal, const int& add, int& name) {
    if (str.find(goal) - add < 0) name = -1;
    name = str.find(goal) - add;
}
int siof(const string& str, const string& goal) {
    return str.find(goal);
}
int siof(const string& str, const string& goal, const int& add) {
    if (str.find(goal) - add < 0) return -1;
    return str.find(goal) - add;
}
int* sl(const string& str, const string& goal)
{
    int num = 0, i = 0;
    while (true)
    {
        num = str.find(goal, num + 1);
        if (num == -1) break;
        i++;
    }
    int* a = new int[str.length() - i];
    num = 0;
    while (true)
    {
        int temp = num;
        num = str.find(goal, num + 1);
        if (num == -1) break;
        for (int k = 0; k < temp - num; ++k)
        {
            *(a + i) = str[num * 2 - temp + k];
        }
    }
    return a;
}
int slg(const string& str) {
    return str.length();
}
void slg(const string& str, int& name) {
    name = str.length();
}
string strim(const string& str) {
    int i = 0, k = 0;
    for (; i < str.length(); ++i)
    {
        if (str[i] != ' ') break;
    }
    for (; k < str.length(); ++k)
    {
        if (str[str.length() - 1 - k] != ' ') break;
    }
    string a;
    cout << "ok" << i << k << endl;
    for (int j = 0; j < str.length() - k - i; ++j)
    {
        a += str[i + j];
    }
    return a;
}
void sr(string str, const char& cha1, const char& cha2, string& name) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == cha1) str[i] = cha2;
    }
    name = str;
}
string sr(string str, const char& cha1, const char& cha2) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == cha1) str[i] = cha2;
    }
    return str;
}
void sr(string& str, const char& cha1, const char& cha2) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == cha1) str[i] = cha2;
    }
}
int sran(const int& first, const int& last) {
    return rand() % last + 1 + first;
}
void sran(const int& first, const int& last, int& name) {
    name = rand() % last + 1 + first;
}
void sranh() {
    srand((unsigned int)time(NULL));
}
void stop(const int& time) {
    Sleep(time);
}
void forsyso(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        cout << str[i] << endl;
    }
}
void forsyso(const string& str, const bool& mode) {
    int len = str.length();
    if (mode) {
        for (int i = 0; i < len; ++i) {
            cout << str[i] << endl;
        }
    }
    else {
        for (int i = 0; i < len; ++i) {
            cout << str[len - 1 - i] << endl;
        }
    }
}
void isystem(const string& str_first, const string& str_last) {
    system((str_first + str_last).c_str());
}
short numb(int num, const int& bit) {
    int temp = num, len = 0;
    while (temp > 0) {
        temp /= 10;
        ++len;
    }
    if (len < bit) return -1;
    return num / short(pow(10, len - bit)) % 10;
}
void HideWindow() {
    HWND hwnd = GetForegroundWindow();
    if (hwnd) ShowWindow(hwnd, SW_HIDE);
    //#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
}
void BubbleSort(int * p, const int& len) {
    for (int i = 0; i < len; ++i) {
        for (int k = 0; k < len - i - 1; ++k) {
            if (*(p + k) > *(p + k + 1)) {
                int temp = *(p + k);
                *(p + k) = *(p + k + 1);
                *(p + k + 1) = temp;
            }
        }
    }
}
void PrintArray(const int* p, const int& len) {
    for (int i = 0; i < len; ++i) {
        cout << *p << endl;
        p++;
    }
}
bool ifin(const string& str, const string& goal) {
    if (str.find(goal) >= str.length()) return false;
    return true;
}
bool isInRange(const float& flo1, const float& flo2, const float& range) {
    if (flo1 - flo2 < 0 && flo2 - flo1 <= range + 0.00000005f) return true;
    else if (flo1 - flo2 > 0 && flo1 - flo2 <= range + 0.00000005f) return true;
    return false;
}
float isInRange(const float& flo1, const float& flo2) {
    if (flo1 - flo2 < 0) return flo2 - flo1 - 0.00000005f;
    return flo1 - flo2 - 0.00000005f;
}
float isInRange(const float& flo1, const float& flo2, const bool& mode) {
    if (flo1 - flo2 < 0) return flo2 - flo1 - mode * 0.00000005f;
    return flo1 - flo2 - mode * 0.00000005f;
}
void fct(const string& load) {
    fstream ifs;
    ifs.open(load, ios::out | ios::app);
    ifs.close();
}
bool fct(const bool& mode, const string& load) {
    fstream ifs;
    ifs.open(load, ios::out | ios::app);
    if (!ifs.is_open()) return false;
    ifs.close();
    return true;
}
void fw(const string& load, const string& str) {
    fstream ifs;
    ifs.open(load, ios::out | ios::app);
    ifs << str << endl;
    ifs.close();
}
bool fw(const bool& mode, const string& load, const string& str) {
    fstream ifs;
    ifs.open(load, ios::out | ios::app);
    if (!ifs.is_open() && mode) return false;
    ifs << str << endl;
    ifs.close();
    if(mode) return true;
}
void fr(const string& load, string& name) {
    fstream ifs;
    ifs.open(load, ios::in);
    while (getline(ifs, name));
    ifs.close();
}
bool fr(const bool& mode, const string& load, string& name) {
    fstream ifs;
    ifs.open(load, ios::in);
    if (!ifs.is_open() && mode) return false;
    while (getline(ifs, name));
    ifs.close();
    if(mode) return true;
}
string fr(const string& load) {
    fstream ifs;
    string str;
    ifs.open(load, ios::in);
    while (getline(ifs, str));
    ifs.close();
    return str;
}
void fd(const string& load) {
    remove(load.c_str()); 
}
bool fd(const bool& mode, const string& load) {
    if (remove(load.c_str()) != -1 && mode) return true;
    return false;
}
void fn(const string& name_first, const string& name_last) {
    int* temp = new int;
    * temp = rename(name_first.c_str(), name_last.c_str());
    delete(temp);
}
bool fn(const bool& mode, const string& name_first, const string& name_last) {
    if(rename(name_first.c_str(), name_last.c_str()) != -1 && mode) return true;
    return false;
}
void fe(const string& load, bool& result) {
    fstream ifs;
    ifs.open(load, ios::in);
    if (!ifs) result = false;
    ifs.close();
    result = true;
}
bool fe(const string& load) {
    fstream ifs;
    ifs.open(load, ios::in);
    if (!ifs) return false;
    ifs.close();
    return true;
}
void fc(const string& load_first, const string& load_last) {
    CopyFile(load_first.c_str(), load_last.c_str(), false);
}
void fc(const string& load_first, const string& load_last, const bool& mode) {
    CopyFile(load_first.c_str(), load_last.c_str(), mode);
}
bool fc(const bool& isReturn, const string& load_first, const string& load_last) {
    if(CopyFile(load_first.c_str(), load_last.c_str(), false) != -1 && isReturn) return true;
    if(isReturn) return false;
}
bool fc(const bool& isReturn, const string& load_first, const string& load_last, const bool& mode) {
    if (CopyFile(load_first.c_str(), load_last.c_str(), mode) != -1 && isReturn) return true;
    if (isReturn) return false;
}
void fm(const string& load_first, const string& load_last) {
    MoveFile(load_first.c_str(), load_last.c_str());
}
bool fm(const bool& mode, const string& load_first, const string& load_last) {
    bool result = MoveFile(load_first.c_str(), load_last.c_str());
    if (mode) return result;
}
void capl(string& str) {
    int temp;
    for (int i = 0; i < str.length(); ++i) {
        temp = int(str[i]);
        if (temp >= 97 && temp <= 122) str[i] = (char)(temp - 32);
    }
}
void capl(string& str, const bool& mode) {
    int temp;
    if (mode) {
        for (int i = 0; i < str.length(); ++i) {
            temp = int(str[i]);
            if (temp >= 97 && temp <= 122) str[i] = (char)(temp - 32);
        }
    }
    else {
        for (int i = 0; i < str.length(); ++i) {
            temp = int(str[i]);
            if (temp >= 65 && temp <= 90) str[i] = (char)(temp + 32);
        }
    }
}
void autoCapl(string& str) {
    int temp;
    for (int i = 0; i < str.length(); ++i) {
        temp = int(str[i]);
        if (temp >= 97 && temp <= 122) str[i] = (char)(temp - 32);
        if (temp >= 65 && temp <= 90) str[i] = (char)(temp + 32);
    }
}
bool equation2(const double& a, const double& b, const double& c, double& x1, double& x2) {
    double delta = 1.0 * (b * b - 4 * a * c);
    if (delta < 0) return false;
    if (delta == 0) {
        x1 = (-1.0 * b) / (2.0 * a);
        x2 = x1;
    }
    else {
        x1 = (-1.0 * b + sqrt(delta)) / (2.0 * a);
        x2 = (-1.0 * b - sqrt(delta)) / (2.0 * a);
    }
    return true;
}