#pragma once

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef __FILENAME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

extern int __log_level;

#define LEVEL_DEBUG 3
#define LEVEL_INFO 2
#define LEVEL_WARN 1
#define LEVEL_ERROR 0

// Default to log level info
int __log_level = LEVEL_INFO;

#define LOG_DEBUG(fmt, ...) \
    __LOG(LEVEL_DEBUG, fmt, ##__VA_ARGS__)

#define LOG_INFO(fmt, ...) \
    __LOG(LEVEL_INFO, fmt, ##__VA_ARGS__)

#define LOG_WARN(fmt, ...) \
    __LOG(LEVEL_WARN, fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
    __LOG(LEVEL_ERROR, fmt, ##__VA_ARGS__)

#define __LOG(level, fmt, ...)                                                                                                    \
    do                                                                                                                            \
    {                                                                                                                             \
        if (__builtin_expect(((level) <= __log_level), 0))                                                                        \
            fprintf(stderr, "%s[%s:%d](%s): " fmt "\n", getLogLevel(level), __FILENAME__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
    } while (0)

    const char *getLogLevel(int level)
    {
        switch (level)
        {
        case LEVEL_DEBUG:
            return "[DBG]";
        case LEVEL_INFO:
            return "[NFO]";
        case LEVEL_WARN:
            return "[WRN]";
        case LEVEL_ERROR:
            return "[ERR]";
        default:
            return "";
        }
    }

#ifdef __cplusplus
}
#endif
