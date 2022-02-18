#include <fstream>
#include <iostream>

using namespace std;

int main() {
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("app.txt");

    cout << "write to the file ..." << endl;
    cout << "Input your name:" << endl;
    cin.getline(data, 100);  // 100-1

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Input your age:" << endl;
    cin >> data;
    cin.ignore();  // 它的一个常用功能就是用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响
    // 再次向用户写入输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("app.txt");

    cout << "Reading from the file" << endl;
    infile >> data;
    cout << data << endl;

    // 再次从文件读取数据，并显示
    infile >> data;
    cout << data << endl;

    infile.close();

    return 0;
}
