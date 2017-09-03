#include <stdio.h>
#include "iLog.h"
int main(void)
{
	log_init();
	void* lpLogCategory = log_open("mycat");
	LOG_TRACE(lpLogCategory,"trace:%d",123);
	LOG_ERROR(lpLogCategory,"error");
	LOG_WARN(lpLogCategory,"warn");
	LOG_NOTICE(lpLogCategory,"notice");
	LOG_DEBUG(lpLogCategory,"hello log4c!");
	void* lpLogCategory2 = log_open("iTest");
	LOG_TRACE(lpLogCategory2,"trace:%d",123);
	LOG_ERROR(lpLogCategory2,"error");
	LOG_WARN(lpLogCategory2,"warn");
	LOG_NOTICE(lpLogCategory2,"notice");
	LOG_DEBUG(lpLogCategory2,"hello log4c!");
	log_close();
	return 0;
}