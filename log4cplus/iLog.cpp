/*************************************************************************
	> File Name: log.cpp
	> Author: zhongxin.cao
	> Mail: zhongxin.cao@pt.sony.cn 
	> Created Time: 2016年05月17日 星期二 14时45分12秒
 ************************************************************************/

#include "iLog.h"
ConfigureAndWatchThread ConfigureThread("log4cplus.cfg", 5 * 1000);;
Log::Log()
{
	PropertyConfigurator::doConfigure("log4cplus.cfg");
	_logger = Logger::getRoot(); 
}  
  
Log::~Log()  
{
}  
  
Log& Log::instance()  
{  
    static Log log; 
    return log;  
}

void Log::writeLog(int level,char* info)
{
	switch(level)
	{
		case 0:
		LOG4CPLUS_TRACE(_logger,info);
		break;
		case 1:
		LOG4CPLUS_DEBUG(_logger,info);
		break;
		case 2:
		LOG4CPLUS_INFO(_logger,info);
		break;
		case 3:
		LOG4CPLUS_WARN(_logger,info);
		break;
		case 4:
		LOG4CPLUS_ERROR(_logger,info);
		break;
		case 5:
		LOG4CPLUS_FATAL(_logger,info);
		break;
		default:
		break;
	}
}