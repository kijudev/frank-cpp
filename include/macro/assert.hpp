#pragma once

#include <cassert>

#ifdef NDEBUG
#define FRANK_ASSERT
#else
#define FRANK_ASSERT(cond) assert(cond)
#endif
