#pragma once

#define COMPILER_ASSERT(cond)                                              \
    struct T {                                                                 \
        char assert[(cond) ? 1 : -1];                                          \
    }
