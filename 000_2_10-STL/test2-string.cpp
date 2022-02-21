#include <iostream>
#include <string>

using namespace std;
#define DESC "string demo ... "

/*
1: string 是c++风格的字符串，而string本质上是一个class;

2: string 和char*的区别;
    (1) char* 是一个指针;
    (2) string是一个class，类内部封装了char*，管理这个字符串，是一个char*型的容器;

3: string 的特点:
    (1) string 类内部封装了很多成员方法,查找 find，拷贝 copy，删除 delete，替换 replace，插入 insert
    (2) string 管理 char *所分配的内存，不用担心复制越界和取值越界等，有类内部进行负责;




*/

void test01();  // string  初始化，构造函数
void test02();  // string赋值操作
void test03();  // string 字符串拼接

//
int main() {
    // test01();
    // test02();
    test03();
    return 0;
}

void test01() {
    // 4 : string 构造函数原型
    //     (1) string() 创建一个空字符串，例如 : string str;
    //     (2) string(const char* s) 使用字符串s初始化;
    //     (3) string(string string & str) 使用一个string对象初始化另一个string对象;
    //     (4) string(int n, char c) 使用n个字符c初始化;

    string str1;
    cout << "str1 = " << str1 << endl;

    const char* str2 = "hello world";
    cout << "str2 = " << str2 << endl;

    string str3(str2);
    cout << "str3 = " << str3 << endl;

    string str4(str3);
    cout << "str4 = " << str4 << endl;

    string str5(10, 'x');
    cout << "str5 = " << str5 << endl;
}

void test02() {
    // 5 : string 赋值操作
    //      string& operator=(const char* s);         // char* 类型字符串 赋值给当前的字符串
    //      string& operator=(const string& s);       //把字符串 s 赋给当前的字符串
    //      string& operator(char c);                 //字符赋值给当前的字符串
    //      string& assign = (const char* s);         //把字符串 s 赋给当前的字符串
    //      string& assign = (const char* s, int n);  //吧字符串 s 的前 n 个字符赋给当前的字符串
    //      string& assign = (const string& s);       //把字符串 s 赋给当前字符串
    //      string& assign(int n, char c);            //用 n 个字符 c 赋给当前字符串

    string str1;
    str1 = "hello world";
    cout << "str1=" << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2=" << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3=" << str3 << endl;

    string str4;
    str4.assign("hello C++");
    cout << "str4=" << str4 << endl;

    string str5;
    str5.assign("hello C++", 5);
    cout << "str5=" << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6=" << str6 << endl;

    string str7;
    str7.assign(10, 'w');
    cout << "str7=" << str7 << endl;
}

void test03() {
    // string  字符串拼接
    //     string& operator+=(const char* str);              //重载+=操作符
    //     string& operator+=(const char c);                 //重载+=操作符
    //     string& operator+=(const string& str);            //重载+=操作符
    //     string& append(const char* s);                    //把字符串 s 连接到当前字符串结尾
    //     string& append(const char* s, int n);             //把字符串 s 的前 n 个字符串连接到当前字符串结尾
    //     string& append(const string& s);                  //同 operator+=(const string & str)
    //     string& append(const string& s, int pos, int n);  //字符串 s 中从 pos 开始的 n 个字符连接到字符串结尾
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << str1 << endl;

    str1 += ":";
    cout << str1 << endl;
    string str2 = "LOL DNF";
    str1 += str2;
    cout << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << str3 << endl;

    str3.append("game abcde", 4);
    cout << str3 << endl;

    str3.append(str2);
    cout << str3 << endl;

    str3.append(str2, 4, 3);
    cout << str3 << endl;
}

/*

6: string  查找和替换
    功能描述：
        查找：查找指定字符串是否存放
        替换：在指定的位置替换字符串
    函数原型：
        int find(const string& str,int pos=0) const;//查找 str 第一次出现文职，从 pos 开始查找
        int find(const char* s,int pos=0) const;//查找 s 第一次出现位置，从 pos 开始查找
        int find(const char*s,int pos,int n) const;//从 pos 位置查找 s 的前 n 个字符第一次位置
        int find(const char c,int pos=0) const;//查找字符 c 第一次出现位置
        int rfind(const string& str,int pos=npos) const;//查找 str 最后一次位置，从 pos 开始查找
        int rfind(const char* s,int pos=npos) const;//查找 s 最后一次出现位置，从 pos 开始查找
        int rfind(const char *s ,int pos,int n) const;//从 pos 查找 s 的前 n 个字符最后一次位置
        int rfind(const char c,int pos=0) const;//查找字符 c 最后一次出现位置
        string & replace(int pos,int n, const string& str);//替换从 pos 开始 n 个字符为字符串 str
        string& replace(int pos,int n,const char*s);//替换从 pos 开始的 n 个字符为字符串 s

7: string 字符串比较
    比较方式：字符串比较是按字符的 ASCII 码进行对比
        =返回 0
        ＞返回 1
        < 返回 -1
    函数原型：
        int compare(const string &s) const;//与字符串 s 比较
        int compare(const char *s) const;//与字符串 s 比较

8: string 字符提取
    string 中单个字符存取方式有两种
        char& operator[](int n); //通过[]方式取字符
        char& at(int n); //通过 at 方法获取字符
 */