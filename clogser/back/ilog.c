#include"ilog.h"
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
static char g_szDir[260]={0};
static int g_logday=0;
static int g_loghour=-1;
static int g_logLev=2;
static FILE* g_pf=NULL;
int initlog(int nLev,char* szDir)
{
	if(g_logLev!=nLev)
	{
		g_logLev=nLev;
	}
	if(szDir==NULL)
	{
		getcwd(g_szDir,260);
		strcat(g_szDir,"/log");
		mkdir(g_szDir,S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
	}
	else
	{
		strcpy(g_szDir,szDir);
	}
	return g_logLev;
}       
void writelog(int nLev,bool bShow,char* szfileinfo,int nLine,const char* szFunc,char* szformat,...)
{   
	if(nLev>g_logLev)
	{
		return;
	}
	time_t ntm;
	time(&ntm);
	struct tm* itm;
	itm=localtime(&ntm);
#define LogFileName "%s/%d-%02d-%02d %02d.log",g_szDir,1900+itm->tm_year,itm->tm_mon,itm->tm_mday,itm->tm_hour
	if(g_logday!=itm->tm_yday||g_loghour!=itm->tm_hour)
	{
		if(g_pf)
		{
			fclose(g_pf);
		}
		char szlogname[260];
		sprintf(szlogname,LogFileName);
		g_pf=fopen(szlogname,"a");
		if(!g_pf)
		{
			return;
		}
		g_logday=itm->tm_yday;
		g_loghour=itm->tm_hour;
	}
#define PREFIX "%d-%02d-%02d %02d:%02d:%02d Lev:[%d] %s Line:<%d> func:%s(); Info:",1900+itm->tm_year,itm->tm_mon,itm->tm_mday,itm->tm_hour,itm->tm_min,itm->tm_sec, nLev, szfileinfo , nLine,szFunc
	fprintf(g_pf, PREFIX);
	va_list args;
	va_start(args, szformat);
	int nLen=vfprintf(g_pf, szformat, args);
	if (fwrite("\n",1,1,g_pf)>0&&bShow)
	{
		printf(PREFIX);
		char* buff=(char*)malloc(nLen+2);
		va_end(args);
		va_start(args, szformat);
		vsnprintf(buff, nLen+2, szformat, args);
		buff[nLen++]='\n';
		buff[nLen]='\0';
		printf(buff);
		free(buff);
	}
	va_end(args);
}
void logclose()
{
	if(g_pf)
	{
		fclose(g_pf);
		g_pf=NULL;
		g_loghour=-1;
	}
}
