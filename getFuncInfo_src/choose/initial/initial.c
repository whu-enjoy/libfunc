/*************************************************************************
    > Copyright (C), 2017-2018, enjoy5512
    > File Name       : initial.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2017年03月15日 星期三 16时38分19秒
    > Version         : 1.0
    > Description     : 
    > Function List   : 
    > History         : 
      <author>    <time>  <version>   <desc>
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <initial.h>
#include <funcNameArray.h>

/************************************************************************
    > Function       : int initial(char funcName[])
    > Description    : 这个函数会将函数名以首字母排序显示出来给用户选择
    > Input          : 
    >   char funcName[] : 用于保存函数名
    > Return         : 
    >   0   : 说明成功获取了函数名
    >   1   : 说明用户选择返回上一层,没有获取函数名
************************************************************************/
int initial(char funcName[])
{
    int i = 0;
    int choice = 0;
    char tmp = '\0';

    if (-1 == system("clear"))
    {
        perror("systm(\"clear\"):");
        exit(1);
    }

    while (1)
    {
        fprintf(stdout, "\n****************************************\n");
        fprintf(stdout, "*************** 欢迎使用 ***************\n");
        fprintf(stdout, "****************************************\n");
        for (i = 1; i <= FUNCNAMEARRSIZE; i++)
        {
        fprintf(stdout, "** 输入%2d,%-*s                **\n", i,FUNCNAMESIZE, funcNameArray[i-1]);
        }
        fprintf(stdout, "** 输入%2d,返回上一层                  **\n", i);
        fprintf(stdout, "** 输入0,退出程序                     **\n");
        fprintf(stdout, "****************************************\n");

        if (1 != fscanf(stdin, "%d", &choice))
        {
            if (-1 == system("clear"))
            {
                perror("systm(\"clear\"):");
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
            if (choice < 0 ||  choice > 3)
            {
                if (-1 == system("clear"))
                {
                    perror("systm(\"clear\"):");
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
        case 3:
            {
                return 1;
            }
        case 0:
            {
                exit(0);
            }
        default:
            {
                if (0 < choice && choice < 3)
                {
                    strcpy(funcName, funcNameArray[choice-1]);
                    return 0;
                }
                else
                {
                    fprintf(stderr, "error!\n");
                    exit(2);
                }
            }
    }
}
