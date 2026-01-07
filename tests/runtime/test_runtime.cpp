#include <iostream>
#include "runtime_dummy.h"

int main() {
    runtime::init();
    std::cout << "[runtime] init passed\n";
    return 0;   // 返回 0 = 测试通过
}
