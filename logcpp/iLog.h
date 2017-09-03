/*************************************************************************
  > File Name: iLog.h
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年05月27日 星期三 10时31分30秒
 ************************************************************************/
#ifndef _COMMON_LOG_
#define _COMMON_LOG_ 


#include<iostream>
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <time.h>
using namespace std;
class CiLog
{
public:
		CiLog(void);
		~CiLog(void);
private:
		int snprintf(char *buff, int nLen, const char *format, ...)
		{
			va_list args;
			va_start(args, format);
			int nSize=vsnprintf(buff, nLen, format, args);
			va_end(args);
			return nSize;
		}
private:
		// log Level
		int m_nLev;
		FILE* m_pf;
		int m_curHour;
		int m_nDay;
		char m_szDir[260];
public:
		int SetLev(int nLev);
		void WriteLog(int nLev,bool bShow,char* szFileInfo,int nLine,const char* szFunc, char* szLog,...);
};



#endif

