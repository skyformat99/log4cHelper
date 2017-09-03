/*************************************************************************
  > File Name: main.cpp
  > Author: zhongxin.cao
  > Mail: zhongxin.cao@pt.sony.cn 
  > Created Time: 2016年05月13日 星期五 13时34分47秒
 ************************************************************************/

#include<iostream>
#include <time.h>
#include <string.h>
#include<unistd.h>
#include "iLog.h"
int main()
{
	Log logger = Log::instance();
	for(int i = 0 ;i < 100000 ; i++)
	{
		logger.writeLog(DEBUG,(char*)"My is Log...");
		logger.writeLog(ERROR,(char*)"My is Log...");
		usleep(10);
	}
	return 0;
}
