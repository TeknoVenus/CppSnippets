#pragma once

#include <string.h>
#include <cstdio>
#include <cstring>

#ifndef __FILENAME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define Log(fmt, ...)                                                                                   \
    do {                                                                                                \
        fprintf(stderr, "[%s:%d](%s): " fmt "\n", __FILENAME__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        fflush(stderr);                                                                                 \
    } while (0)