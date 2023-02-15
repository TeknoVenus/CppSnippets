#pragma once

#include <string.h>
#include <cstdio>
#include <cstring>

#ifndef __FILE_NAME__
#define __FILE_NAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define Log(fmt, ...)                                                                                   \
    do {                                                                                                \
        fprintf(stderr, "[%s:%d](%s): " fmt "\n", __FILE_NAME__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
        fflush(stderr);                                                                                 \
    } while (0)