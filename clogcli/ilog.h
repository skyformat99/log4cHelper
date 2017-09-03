/*************************************************************************
	> File Name: ilog.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年05月27日 星期三 16时22分57秒
 ************************************************************************/

#ifndef _COMMON_LOG_
#define _COMMON_LOG_ 

#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <time.h>
typedef enum bool
{
	true=1,
	false=0
}bool;
int initlog(int nLev,char* szDir);
void writelog(int nLev,bool bShow,char* szfileinfo,int nLine,const char* szFunc,char* szformat,...);
void logclose();
#endif
