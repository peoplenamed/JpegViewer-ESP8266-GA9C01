#ifndef _LOG_SERVICE_H_
#define _LOG_SERVICE_H_

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/
#define LOG_LEVEL_TRACE 0 /**< A lot of logs to give detailed information*/
#define LOG_LEVEL_INFO 1  /**< Log important events*/
#define LOG_LEVEL_WARN 2  /**< Log if something unwanted happened but didn't caused problem*/
#define LOG_LEVEL_ERROR 3 /**< Only critical issue, when the system may fail*/
#define LOG_LEVEL_USER 4  /**< Custom logs from the user*/
#define LOG_LEVEL_NONE 5  /**< Do not log anything*/
#define LOG_LEVEL_NUM 6   /**< Number of log levels*/

LV_EXPORT_CONST_INT(LV_LOG_LEVEL_TRACE);
LV_EXPORT_CONST_INT(LV_LOG_LEVEL_INFO);
LV_EXPORT_CONST_INT(LV_LOG_LEVEL_WARN);
LV_EXPORT_CONST_INT(LV_LOG_LEVEL_ERROR);
LV_EXPORT_CONST_INT(LV_LOG_LEVEL_USER);
LV_EXPORT_CONST_INT(LV_LOG_LEVEL_NONE);

#if USE_LOG

/**********************
 *      MACROS
 **********************/
#ifndef LV_LOG_TRACE
#if LV_LOG_LEVEL <= LV_LOG_LEVEL_TRACE
#define LV_LOG_TRACE(...) _lv_log_add(LV_LOG_LEVEL_TRACE, __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define LV_LOG_TRACE(...) \
    do                    \
    {                     \
    } while (0)
#endif
#endif

#ifndef LV_LOG_INFO
#if LV_LOG_LEVEL <= LV_LOG_LEVEL_INFO
#define LV_LOG_INFO(...) _lv_log_add(LV_LOG_LEVEL_INFO, __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define LV_LOG_INFO(...) \
    do                   \
    {                    \
    } while (0)
#endif
#endif

#ifndef LV_LOG_WARN
#if LV_LOG_LEVEL <= LV_LOG_LEVEL_WARN
#define LV_LOG_WARN(...) _lv_log_add(LV_LOG_LEVEL_WARN, __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define LV_LOG_WARN(...) \
    do                   \
    {                    \
    } while (0)
#endif
#endif

#ifndef LV_LOG_ERROR
#if LV_LOG_LEVEL <= LV_LOG_LEVEL_ERROR
#define LV_LOG_ERROR(...) _lv_log_add(LV_LOG_LEVEL_ERROR, __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define LV_LOG_ERROR(...) \
    do                    \
    {                     \
    } while (0)
#endif
#endif

#ifndef LV_LOG_USER
#if LV_LOG_LEVEL <= LV_LOG_LEVEL_USER
#define LV_LOG_USER(...) _lv_log_add(LV_LOG_LEVEL_USER, __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define LV_LOG_USER(...) \
    do                   \
    {                    \
    } while (0)
#endif
#endif

#ifndef LV_LOG
#if LV_LOG_LEVEL < LV_LOG_LEVEL_NONE
#define LV_LOG(...) lv_log(__VA_ARGS__)
#else
#define LV_LOG(...) \
    do              \
    {               \
    } while (0)
#endif
#endif

#else /*USE_LOG*/

/*Do nothing if `LV_USE_LOG 0`*/
#define _lv_log_add(level, file, line, ...)
#define LV_LOG_TRACE(...) \
    do                    \
    {                     \
    } while (0)
#define LV_LOG_INFO(...) \
    do                   \
    {                    \
    } while (0)
#define LV_LOG_WARN(...) \
    do                   \
    {                    \
    } while (0)
#define LV_LOG_ERROR(...) \
    do                    \
    {                     \
    } while (0)
#define LV_LOG_USER(...) \
    do                   \
    {                    \
    } while (0)
#define LV_LOG(...) \
    do              \
    {               \
    } while (0)

#endif /*USE_LOG*/
#endif