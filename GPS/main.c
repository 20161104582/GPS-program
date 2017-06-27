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
    char str1[80],lat[9],lon[10],speed[6],dire[6];
    int time[7],hour,min,seconds,date[7],year,month,day;
    char str2[80],alt[5];
    int i,j;
    int count=0;
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
    /*for(i=0;i<7;i++)
        time[i]=str1[i+7];
    time[6]='\0';
    printf("时间（hhmmss)：%d\n",time);
    fprintf(ft2,"时间（hhmmss)：%d\n",time);*/
    for(i=0;i<7;i++){
        if(i<6)
            time[i]=str1[i+7]-48;
    }
    hour=time[0]*10+time[1];
    min=time[2]*10+time[3];
    seconds=time[4]*10+time[5];
    if(hour<16)
        hour=8+hour;
    else{
        count++;
        hour=hour-16;
    }
    printf("时间：%d时%d分%d秒\n",hour,min,seconds);
    fprintf(ft2,"时间：%d时%d分%d秒\n",hour,min,seconds);
    for(i=0;i<6;i++)
        speed[i]=str1[i+39];
    speed[5]='\0';
    printf("地面速率：%s\n",speed);
    fprintf(ft2,"地面速率：%s\n",speed);
    /*for(i=0;i<7;i++)
        date[i]=str1[i+51];
    date[6]='\0';
    printf("日期（ddmmyy）：%s\n",date);
    fprintf(ft2,"日期（ddmmyy）：%s\n",date);*/
    for(i=0;i<7;i++){
        if(i<6)
            date[i]=str1[i+51]-48;
    }
    day=date[0]*10+date[1];
    month=date[2]*10+date[3];
    year=date[4]*10+date[5];
    if(count!= 0) {
        day++;
    }
    printf("日期为：20%d年%d月%d日\n",year,month,day);
    fprintf(ft2,"日期为：20%d年%d月%d日\n",year,month,day);
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
