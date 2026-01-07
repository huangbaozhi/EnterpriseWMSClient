#include "domain_dummy.h"
#include "runtime_dummy.h"

namespace domain {

    void bootstrap() {
        // 调用 runtime，验证依赖链
        runtime::init();
    }

}