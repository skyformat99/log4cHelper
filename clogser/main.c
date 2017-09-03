/*************************************************************************
  > File Name: main.c
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年05月27日 星期三 16时20分51秒
 ************************************************************************/

#include<stdio.h>
#include"ilog.h"
#include<sys/timeb.h>
// nLev log level,bShow print log,nColor print log color:0(缺省)31(red),32(green),33(棕色)34(blue),35(紫色),36(青色)
#define PRT_INFO(nLev,bShow,nColor,fmt, ...) writelog(nLev,bShow,nColor, "[BWS] File:"__FILE__,__LINE__,__FUNCTION__, fmt, ##__VA_ARGS__)

int main()
{
	struct timeb start,end;
	time_t t1,t2;
	ftime(&start);
	initlog(2,NULL);
	char* szLog="我是abcdefghijklmn log...:%d";
	int i=0;
	for (i=0;i<10000;i++)
	{
		PRT_INFO(1,true,red,szLog,i);
	}
	ftime(&end);
	t1=start.time*1000+start.millitm;
	t2=end.time*1000+end.millitm;
	printf("耗时:%llu\n",(unsigned long long)(t2-t1));
	logclose();
	return 0;
}
