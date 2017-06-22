//
//  main.c
//  GPS
//
//  Created by a20161104582 on 17/6/19.
//  Copyright © 2017年 a20161104582. All rights reserved.
//
#include<stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *ft;
    char str1[80];
    char str2[80];
    char lat[9];
    char lon[10];
    int i,j;
    ft=fopen("//Users//a20161104582//Desktop//GPS170510.log","r+");
    fscanf(ft,"%s%s",str1,str2);
    printf("结果：%s\n%s\n",str1,str2);
    for(i=0;i<8;i++)
        lat[i]=str1[i+16];
    for(j=0;j<9;j++)
        lon[j]=str1[j+27];
    lat[8]='\0';
    lon[9]='\0';
    printf("纬度：%s\n",lat);
    printf("经度：%s\n",lon);
    fclose(ft);
    return 0;
}
