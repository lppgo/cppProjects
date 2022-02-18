#include <iostream>

using namespace std;

/* namespace first_space {
void func() {
    cout << "inside first_space" << endl;
}
};  // namespace first_space

namespace seconds_space {
void func() {
    cout << "inside seconds_space" << endl;
}
};  // namespace seconds_space

int main() {
    // 调用第一个namespace空间的函数
    first_space::func();

    // 调用第二个namespace空间的函数
    seconds_space::func();
    return 0;
} */

// 第一个命名空间
namespace first_space {
void func() {
    cout << "Inside first_space" << endl;
}
// 第二个命名空间
namespace second_space {
void func() {
    cout << "Inside second_space" << endl;
}
};  // namespace second_space
};  // namespace first_space

using namespace first_space::second_space;
int main() {
    // 调用第二个命名空间中的函数
    func();

    return 0;
}