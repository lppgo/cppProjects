#include <exception>
#include <iostream>

using namespace std;

struct CustomException : public exception {
    const char* what() const throw() {
        return "C++ customException";
    };
};

int main() {
    try {
        throw CustomException();

    } catch (CustomException& e1) {
        cout << "CustomException caught ... " << endl;
        cout << "e1 : " << e1.what() << endl;
    } catch (const std::exception& e2) {
        std::cerr << "e2 : " << e2.what() << std::endl;
    }

    return 0;
}