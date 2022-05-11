#include "Logger.h"

int main(int argc, char const *argv[])
{
    __log_level = LEVEL_WARN;
    LOG_DEBUG("Debug level message: %d %d", 123, 345);
    LOG_INFO("Info level message");
    LOG_WARN("Warning message");
    LOG_ERROR("Error message!");
    return 0;
}
