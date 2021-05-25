
#include <stdio.h>
#include <stdlib.h>
#include <defs.h>

int isspace(char ch){
    if(ch == ' ' || ch == '\n' || ch == '\r'|| ch == '\t' || ch == '\v'){
        return 1;
    }
    return 0;
}
int atoi(char s[])
{
    if(s == NULL)
    {
        printf("");
        return -1;
    }
    int index = 0;  //记录数组下标
    int res = 0;    //存放最终要返回的值
    int is_neg = 0;
        
    while(isspace(*s))
    {
        s++;
    }
    if(*s == '-')
    {
        is_neg = -1;    //负数
        s++;
    }
    else if(*s == '+')
    {
        s++;
    }

    while(*s >= '0' && *s <= '9')//遇到非数字直接退出
    {
        res = (res<<3) + (res<<1) + (*s - '0');
        s++;
    }
    if(is_neg){
        res = ~res + 1;
    }
    return res;
}