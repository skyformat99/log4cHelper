#ifndef _LOG_H_
#define _LOG_H_

#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include "log4c.h"

#ifdef __cplusplus
}
#endif

#define LOG_PRI_ERROR 		LOG4C_PRIORITY_ERROR
#define LOG_PRI_WARN 		LOG4C_PRIORITY_WARN
#define LOG_PRI_NOTICE 		LOG4C_PRIORITY_NOTICE
#define LOG_PRI_DEBUG 		LOG4C_PRIORITY_DEBUG
#define LOG_PRI_TRACE 		LOG4C_PRIORITY_TRACE

extern int log_init();
extern void* log_open(const char *category);
extern void log_message(void* lpLogCategory,int priority ,const char* fmt, ...);
extern void log_trace(void* lpLogCategory,const char *file , int line , const char *func, const char *fmt ,...);
extern int log_close();

#define LOG_ERROR(lpLogCategory,fmt , args...)	\
	log_message(lpLogCategory,LOG_PRI_ERROR, fmt, ##args)
#define LOG_WARN(lpLogCategory,fmt, args...)		\
	log_message(lpLogCategory,LOG_PRI_WARN, fmt , ##args)
#define LOG_NOTICE(lpLogCategory,fmt , args...)	\
	log_message(lpLogCategory,LOG_PRI_NOTICE, fmt , ##args)
#define LOG_DEBUG(lpLogCategory,fmt , args...)	\
	log_message(lpLogCategory,LOG_PRI_DEBUG, fmt , ##args)
#define LOG_TRACE(lpLogCategory,fmt,args...) 		\
	log_trace(lpLogCategory,__FILE__ , __LINE__ , __FUNCTION__ , fmt ,## args)


#endif