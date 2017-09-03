/*************************************************************************
  > File Name: main.cpp
  > Author: zhongxin.cao
  > Mail: zhongxin.cao@pt.sony.cn 
  > Created Time: 2016年05月13日 星期五 13时34分47秒
 ************************************************************************/

#include<iostream>
#include <logger.h>
#include <configurator.h>
#include <iomanip>
#include <fileappender.h>
#include <consoleappender.h>
#include <loggingmacros.h>
#include <layout.h>
#include <time.h>
#include <string.h>
#define INIT_LOG(filePath) log4cplus::PropertyConfigurator::doConfigure(filePath)
using namespace std;
using namespace log4cplus;
Logger logger;
void writelog(char* leval,char* info)
{
	struct tm *p;
	time_t lt=time(NULL);
	p=localtime(&lt);
	char* timetemp=ctime(&lt);
	*(timetemp+strlen(timetemp)-1)='\0';
	char temp[10000];
	sprintf(temp,"[%s] %s",timetemp,info);
	printf("temp==%s",temp);
	printf("leval====%s ",leval);
	if(memcmp(leval,"TRACE",5)==0)
		printf("%d===%d",memcmp("TRACE","TRAC1E",5),memcmp(leval,"TRACE",5));
	LOG4CPLUS_TRACE(logger,temp);
	if(memcmp(leval,"DEBUG",5)==0)
		LOG4CPLUS_DEBUG(logger,temp);
	if(memcmp(leval,"INFO",4)==0)
		LOG4CPLUS_INFO(logger,temp);
	if(memcmp(leval,"WARN",4)==0)
		LOG4CPLUS_WARN(logger,temp);
	if(memcmp(leval,"ERROR",5)==0)
		LOG4CPLUS_ERROR(logger,temp);
	if(memcmp(leval,"FATAL",5)==0)
		LOG4CPLUS_FATAL(logger,temp);
}
int main()
{
	INIT_LOG(LOG4CPLUS_TEXT("./log4cplus.properties"));
	char* info="you have a iuns...";
	char filename[50];
	struct tm *p;
	time_t lt=time(NULL);
	p=localtime(&lt);
	sprintf(filename,"%d-%d-%d.txt",(1900+p->tm_year), (1+p->tm_mon),p->tm_mday);
	// FILE* stream=fopen(filename,"wb");
	// SharedAppenderPtr pFileAppender(new FileAppender((filename)));
	logger = Logger::getRoot();
	// logger.addAppender(pFileAppender);
	char temp[10000];
	sprintf(temp,"%s",info);
	LOG4CPLUS_TRACE(logger,temp);
	for(int i = 0;i<10000;i++)
	{
		LOG4CPLUS_DEBUG(logger,temp);
		LOG4CPLUS_INFO(logger,temp);
	}
	LOG4CPLUS_WARN(logger,temp);
	LOG4CPLUS_ERROR(logger,temp);
	LOG4CPLUS_FATAL(logger,temp);
	return 0;
}
