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
    char hour[8],min[8],seconds[8],year[8],month[8],day[8];
    char str2[80],alt[5];
    int i,j;
    ft2=fopen("//Users//a20161104582//Desktop//GPS//GPS//output.csv","w");
    ft=fopen("//Users//a20161104582//Desktop//GPS170510.log","r+");
    if(ft==NULL)
    {
        printf("文件打开错误，要打开的文件可能不存在\n");
    }
    else
    {
        printf("日期，时间，纬度，纬度方向，经度，经度方向，地面速率，航向，海拔\n");
        fprintf(ft2,"日期，时间，纬度，纬度方向，经度，经度方向，地面速率，航向，海拔\n");
        while(fscanf(ft,"%s %s",str1,str2)!=EOF)
        {
            for(i=0;i<2;i++)
            {
                year[i]=str1[i+55];
            }
            year[2]='\0';
            for(i=0;i<2;i++)
            {
                month[i]=str1[i+53];
            }
            month[2]='\0';
            for(i=0;i<2;i++)
            {
                day[i]=str1[i+51];
            }
            day[2]='\0';
            for(i=0;i<2;i++)
            {
                hour[i]=str1[i+7];
            }
            hour[2]='\0';
            for(i=0;i<2;i++)
            {
                min[i]=str1[i+9];
            }
            min[2]='\0';
            for(i=0;i<2;i++)
            {
                seconds[i]=str1[i+11];
            }
            seconds[2]='\0';
            for(i=0;i<8;i++)
                lat[i]=str1[i+16];
            lat[8]='\0';
            switch(str1[25]){
                case('N'):
                    printf("北纬\n");
                    break;
                case('S'):
                    printf("南纬\n");
                    break;
            }
            for(i=0;i<9;i++)
                lon[i]=str1[i+27];
            lon[9]='\0';
            switch(str1[37]){
                case('W'):
                    printf("西经\n");
                    break;
                case('E'):
                    printf("东经\n");
                    break;
            }
             for(i=0;i<6;i++)
                speed[i]=str1[i+39];
            speed[5]='\0';
            for(i=0;i<6;i++)
                dire[i]=str1[i+45];
            dire[5]='\0';
            for(j=0;j<4;j++)
                alt[j]=str2[j+43];
            alt[4]='\0';
            printf("20%s年%s月%s日,%s时%s分%s秒,%s,%c,%s,%c,%s公里／小时,%s,%sft\n",year,month,day,hour,min,seconds,lat,str1[25],lon,str1[37],speed,dire,alt);
            fprintf(ft2,"20%s年%s月%s日,%s时%s分%s秒,%s,%c,%s,%c,%s公里／小时,%s,%sft\n",year,month,day,hour,min,seconds,lat,str1[25],lon,str1[37],speed,dire,alt);
        }
        fclose(ft);
        fclose(ft2);
    }
    return 0;
}
