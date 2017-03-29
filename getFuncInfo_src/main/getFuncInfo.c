/*************************************************************************
    > Copyright (C), 2017-2018, enjoy5512
    > File Name       : getFuncInfo.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2017年03月14日 星期二 13时59分45秒
    > Version         : 1.0
    > Description     : 
    > Function List   : 
    > History         : 
      <author>    <time>  <version>   <desc>
 ************************************************************************/
#include <stdio.h>

#include <choose.h>

int main(int argc,char *argv[])
{
    char funcName[20] = {0};

    choose(funcName);
    fprintf(stdout, "%s\n", funcName);

     
    return 0;
}
