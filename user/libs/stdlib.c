
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

//convert integer to string
char *itoa(int value, char *buf, int radix){
    int r;
    char *p = buf;
    int is_neg = 0;
    int length;

    if(value==0){
        *buf++ = '0';
        *buf = '\0';
        return buf;
    }
    if(value<0){
        is_neg = 1;
        value = ~value + 1; //get absolute value
    }

    if(radix==10){
        while(value){
            r = value%radix;
            value /= radix;
            *p++ = r + '0';
        }
    }else if(radix==16){
        while(value){
            r = value & 0xf;
            value >>= 4;
            *p++ = (r<10) ? r + '0' : r - 10 + 'a';
        }
    }else{
        return NULL;    //not supported radix
    }

    length = p - buf;   //the length of string

    //reverse the string
    int i, j, tmp;
    int offset = is_neg ? 1 : 0;
    for(i=0, j=length-1; i<j; i++, j--){
        tmp = buf[i];
        buf[i + offset] = buf[j];
        buf[j + offset] = tmp;
    }

    if(is_neg){
        buf[0] = '-';
    }
    buf[length+offset] = '\0';

    return buf;
}