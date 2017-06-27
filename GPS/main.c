//
//  main.c
//  GPS
//
//  Created by a20161104582 on 17/6/19.
//  Copyright © 2017年 a20161104582. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
int main(int argc, const char * argv[]) {
    //insert code here...
    FILE *ft;
    FILE *ft2;
    char str1[80],lat[9],lon[10],time[7],speed[6],date[7],dire[6];
    char str2[80],alt[5];
    int i,j;
    ft=fopen("//Users//a20161104582//Desktop//GPS170510.log","r+");
    ft2=fopen("//Users//a20161104582//Desktop//GPS//GPS//output.txt","w+");
    fscanf(ft,"%s%s",str1,str2);
    printf("结果：%s\n%s\n",str1,str2);
    fprintf(ft2,"结果：%s\n%s\n",str1,str2);
    for(i=0;i<8;i++)
        lat[i]=str1[i+16];
    lat[8]='\0';
    printf("纬度：%s\n",lat);
    fprintf(ft2,"纬度：%s\n",lat);
    switch(str1[25]){
        case('N'):
            printf("北纬\n");
            fprintf(ft2,"北纬\n");
            break;
        case('S'):
            printf("南纬\n");
            fprintf(ft2,"南纬\n");
            break;
    }
    for(i=0;i<9;i++)
        lon[i]=str1[i+27];
    lon[9]='\0';
    printf("经度：%s\n",lon);
    fprintf(ft2,"经度：%s\n",lon);
    switch(str1[37]){
        case('W'):
            printf("西经\n");
            fprintf(ft2,"西经\n");
            break;
        case('E'):
            printf("东经\n");
            fprintf(ft2,"东经\n");
            break;
    }
    for(i=0;i<7;i++)
        time[i]=str1[i+7];
    time[6]='\0';
    printf("时间（hhmmss)：%s\n",time);
    fprintf(ft2,"时间（hhmmss)：%s\n",time);
    for(i=0;i<6;i++)
        speed[i]=str1[i+39];
    speed[5]='\0';
    printf("地面速率：%s\n",speed);
    fprintf(ft2,"地面速率：%s\n",speed);
    for(i=0;i<7;i++)
        date[i]=str1[i+51];
    date[6]='\0';
    printf("日期（ddmmyy）：%s\n",date);
    fprintf(ft2,"日期（ddmmyy）：%s\n",date);
    for(i=0;i<6;i++)
        dire[i]=str1[i+45];
    dire[5]='\0';
    printf("航向：%s\n",dire);
    fprintf(ft2,"航向：%s\n",dire);
    for(j=0;j<4;j++)
        alt[j]=str2[j+43];
    alt[4]='\0';
    printf("海拔：%sft\n",alt);
    fprintf(ft2,"海拔：%sft\n",alt);
    fclose(ft);
    fclose(ft2);
    return 0;
}
