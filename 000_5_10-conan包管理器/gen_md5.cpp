#include <iostream>

#include "Poco/DigestStream.h"
#include "Poco/MD5Engine.h"

using namespace std;

int main() {
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();

    cout << "md5 -> :" << Poco::DigestEngine::digestToHex(md5.digest()) << endl;
    return 0;
}