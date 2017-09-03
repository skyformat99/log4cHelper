/*************************************************************************
  > File Name: iLog.cpp
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年05月27日 星期三 10时36分34秒
 ************************************************************************/

#include "iLog.h"
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
// #define PRT_LOG(nLev,fmt, ...) WriteLog(nLev,true, "[BWS] File:"__FILE__" Fun:"__FUNCTION__"();",__LINE__, "Info:"fmt, ##__VA_ARGS__)
// #include<locale.h>

CiLog::CiLog(void)
	: m_nLev(2)
	,m_pf(NULL)
	, m_curHour(0)
	  , m_nDay(0)
{
	//setlocale(LC_ALL,"chs");
	getcwd(m_szDir,260);
	strcat(m_szDir,"/log");
	mkdir(m_szDir,S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
}

CiLog::~CiLog(void)
{
	if (m_pf)
	{
		fclose(m_pf);
	}
}

int CiLog::SetLev(int nLev)
{
	m_nLev=nLev;
	return m_nLev;
}

void CiLog::WriteLog(int nLev,bool bShow,char* szFileInfo,int nLine,const char* szFunc, char* szLog,...)
{
	if (nLev>m_nLev)
	{
		return;
	}
	time_t ntm;
	time(&ntm);
	struct tm* itm;
	itm=localtime(&ntm);
#define LogFileName "%s/%d-%02d-%02d %02d.log",m_szDir,1900+itm->tm_year,itm->tm_mon,itm->tm_mday,itm->tm_hour
	if (m_nDay!=itm->tm_yday||m_curHour!=itm->tm_hour)
	{
		if (m_pf)
		{
			fclose(m_pf);
			char szLogName[260];
			sprintf(szLogName,LogFileName);
			m_pf=fopen(szLogName,"a");
			m_nDay=itm->tm_yday;
			m_curHour=itm->tm_hour;
			if (!m_pf)
			{
				return;
			}
		}
	}
#define PREFIX "%d-%02d-%02d %02d:%02d:%02d Lev:[%d] %s Line:<%d> func:%s(); Info:",1900+itm->tm_year,itm->tm_mon,itm->tm_mday,itm->tm_hour,itm->tm_min,itm->tm_sec, nLev, szFileInfo , nLine,szFunc
	if (!m_pf)
	{
		char szLogName[260];
		sprintf(szLogName,LogFileName);
		m_pf=fopen(szLogName,"a");
		m_nDay=itm->tm_yday;
		m_curHour=itm->tm_hour;
		if (!m_pf)
		{
			return;
		}
	}
	fprintf(m_pf, PREFIX);
	va_list args;
	va_start(args, szLog);
	int nLen=vfprintf(m_pf, szLog, args);
	if (fwrite("\n",1,1,m_pf)>0&&bShow)
	{
		printf(PREFIX);
		char* buff=(char*)malloc(nLen+2);
		va_end(args);
		va_start(args, szLog);
		vsnprintf(buff, nLen+2, szLog, args);
		buff[nLen++]='\n';
		buff[nLen]='\0';
		printf(buff);
		free(buff);
	}
	va_end(args);
}
