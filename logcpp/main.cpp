/*************************************************************************
  > File Name: main.cpp
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年05月27日 星期三 10时29分32秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include"iLog.h"
#include<sys/timeb.h>

#define PRT_INFO(nLev,fmt, ...) WriteLog(nLev,true, "[BWS] File:"__FILE__,__LINE__,__FUNCTION__, fmt, ##__VA_ARGS__)
#define PRT_LOG(nLev,fmt, ...) WriteLog(nLev,false, "[BWS] File:"__FILE__,__LINE__,__FUNCTION__, fmt, ##__VA_ARGS__)

int main()
{
	CiLog llog;
    struct timeb start,end;
	time_t t1,t2;
	ftime(&start);
	char* szLog="我是abcdefghijklmn log...:%d";
	for (int i=0;i<10000;i++)
	{
		llog.PRT_INFO(1,szLog,i);
	}
	ftime(&end);
	t1=start.time*1000+start.millitm;
	t2=end.time*1000+end.millitm;
	printf("耗时:%Id\n",t2-t1);

}
