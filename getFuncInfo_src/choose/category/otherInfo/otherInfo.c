/*************************************************************************
    > Copyright (C), 2017-2018, enjoy5512
    > File Name       : other.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2017年03月15日 星期三 10时12分51秒
    > Version         : 1.0
    > Description     : 
    > Function List   : 
    > History         : 
      <author>    <time>  <version>   <desc>
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <otherInfo.h>
#include <getRandData.h>

/************************************************************************
    > Function       : int otherInfo(char funcName[])
    > Description    : 这个函数用于获取其他代码文件里中相关函数的函数名
    > Input          : 
    >   char funcName[] : 用于保存函数名
    > Return         : 
    >   0   : 说明成功获取了函数名
    >   1   : 说明用户选择返回上一层,没有获取函数名
************************************************************************/
int otherInfo(char funcName[])
{
    int ret = 1;
    int choice = 0;
    char tmp = '\0';

    while (ret)
    {
        if (-1 == system("clear"))
        {
            perror("system(\"clear\")");
            exit(1);
        }

        while (1)
        {
            fprintf(stdout, "\n****************************************\n");
            fprintf(stdout, "*************** 欢迎使用 ***************\n");
            fprintf(stdout, "****************************************\n");
            fprintf(stdout, "** 输入1,获取随机序列                 **\n");
            fprintf(stdout, "** 输入2,返回上一层                   **\n");
            fprintf(stdout, "** 输入0,退出程序                     **\n");
            fprintf(stdout, "****************************************\n");

            if (1 != fscanf(stdin, "%d", &choice))
            {
                if (-1 == system("clear"))
                {
                    perror("system(\"clear\")");
                    exit(1);
                }
                
                fprintf(stderr, "\n您输入的是");
                while(fscanf(stdin, "%c", &tmp) && tmp != '\n' && tmp != EOF)
                {
                    fprintf(stderr, "%c", tmp);
                }
                fprintf(stderr, "\n输入有误,请检查后重新输入!\n\n");
            }
            else
            {
                if (choice < 0 ||  choice > 2)
                {
                    if (-1 == system("clear"))
                    {
                        perror("system(\"clear\")");
                        exit(1);
                    }

                    fprintf(stderr, "\n您输入的数字是%d\n", choice);
                    fprintf(stderr, "输入有误,请检查后重新输入!\n\n");
                }
                else
                {
                    break;;
                }
            }
        }

        switch(choice)
        {
            case 1:
                {
                    ret = getRandData(funcName);
                    break;
                }
            case 2:
                {
                    return 1;
                }
            case 0:
                {
                    exit(0);
                }
            default:
                {
                    fprintf(stderr, "error!\n");
                    exit(2);
                }
        }
    }

    return 0;
}
