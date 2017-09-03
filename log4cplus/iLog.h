/*************************************************************************
	> File Name: log.h
	> Author: zhongxin.cao
	> Mail: zhongxin.cao@pt.sony.cn 
	> Created Time: 2016年05月17日 星期二 14时38分08秒
 ************************************************************************/
#ifndef _AFX_LOG4CPLUS_  
#define _AFX_LOG4CPLUS_ 
#include<iostream>
#include<string.h> 
#include <iomanip>
#include "log4cplus/logger.h"
#include "log4cplus/configurator.h"
#include "log4cplus/fileappender.h"
#include "log4cplus/consoleappender.h"
#include "log4cplus/loggingmacros.h"
#include "log4cplus/layout.h"
enum LOG_LEVEL
{
	TRACE = 0,
	DEBUG,
	INFO,
	WARN,
	ERROR,
	FATAL
};
using namespace log4cplus;
using namespace log4cplus::helpers;
class Log  
{  
public:  
    // 打开日志  
    // 获得日志实例  
    static Log& instance();
    ~Log(); 
private:  
    Log();
	Logger _logger;
public:
	void writeLog(int level,char* info);
}; 
#endif // _AFX_LOG4CPLUS_
