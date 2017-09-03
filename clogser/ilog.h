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

typedef enum fontcolor
{
	none=0,     // 默认
	black=30,   // 黑色
	red=31,     // 红色
	green=32,   // 绿色
	yellow=33,  // 黄色
	blue=34,    // 蓝色
	purple=35,  // 紫红色
	cyanine=36, // 青蓝色
	white=37	// 白色
}fontcolor;
int initlog(int nLev,char* szDir);
void writelog(int nLev,bool bShow,int nColor,char* szfileinfo,int nLine,const char* szFunc,char* szformat,...);
void logclose();
#endif
