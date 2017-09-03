#include <log4c.h>
#include <assert.h>
#include "iLog.h"
int log_init()
{
	if (log4c_init() == 1)
    {
        return -1;
    }
	return 0;
}

void* log_open(const char *category)
{
    
    log4c_category_t* log_category = log4c_category_get(category);
    return log_category;
}

void log_message(void* lpLogCategory, int priority , const char *fmt , ...)
{
	va_list ap;
	
	assert(lpLogCategory != NULL);

	va_start(ap, fmt);
	log4c_category_vlog((log4c_category_t*)lpLogCategory , priority , fmt , ap);
	va_end(ap);
}

void log_trace(void* lpLogCategory, const char *file, int line, const char *fun, 
			const char *fmt , ...)
{
	char new_fmt[2048];
	const char *head_fmt = "[file:%s, line:%d, function:%s]"; 
	va_list ap;
	int n;
	
	assert(lpLogCategory != NULL);
	n = sprintf(new_fmt, head_fmt , file , line , fun);
	strcat(new_fmt + n , fmt);

	va_start(ap , fmt);
	log4c_category_vlog((log4c_category_t*)lpLogCategory , LOG4C_PRIORITY_TRACE, new_fmt , ap);
	va_end(ap);
}


int log_close()
{
    return (log4c_fini());
}