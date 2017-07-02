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
    char str1[80],lata[8],latb[10],lona[8],lonb[10],speed[6],dire[6];
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
        printf("日期,时间,纬度,纬度方向,经度,经度方向,地面速率,航向,海拔\n");
        fprintf(ft2,"日期,时间,纬度,纬度方向,经度,经度方向,地面速率,航向,海拔\n");
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
            printf("20%s年%s月%s日,",year,month,day);
            fprintf(ft2,"20%s年%s月%s日,",year,month,day);
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
            printf("%s时%s分%s秒,",hour,min,seconds);
            fprintf(ft2,"%s时%s分%s秒,",hour,min,seconds);
            for(i=0;i<2;i++)
                lata[i]=str1[i+16];
            lata[2]='\0';
            for(i=0;i<7;i++)
            {
                latb[i]=str1[i+18];
            }
            latb[6]='\0';
            printf("%s'%s,",lata,latb);
            fprintf(ft2,"%s'%s,",lata,latb);
            switch(str1[25]){
                case 'N' :
                    printf("北纬,");
                    fprintf(ft2,"北纬,");
                    break;
                case 'S' :
                    printf("南纬,");
                    fprintf(ft2,"南纬,");
                    break;
            }
            for(i=0;i<3;i++)
            {
                lona[i]=str1[i+27];
            }
            lona[3]='\0';
            for(i=0;i<6;i++)
            {
                lonb[i]=str1[i+30];
            }
            lonb[6]='\0';
            printf("%s'%s,",lona,lonb);
            fprintf(ft2,"%s'%s,",lona,lonb);
            switch(str1[37]){
                case 'W' :
                    printf("西经,");
                    fprintf(ft2,"西经,");
                    break;
                case 'E' :
                    printf("东经,");
                    fprintf(ft2,"东经,");
                    break;
            }
             for(i=0;i<6;i++)
                speed[i]=str1[i+39];
            speed[5]='\0';
            printf("%s,",speed);
            fprintf(ft2,"%s,",speed);
            for(i=0;i<6;i++)
                dire[i]=str1[i+45];
            dire[5]='\0';
            printf("%s,",dire);
            fprintf(ft2,"%s,",dire);
            for(j=0;j<4;j++)
                alt[j]=str2[j+43];
            alt[4]='\0';
            printf("%sft\n",alt);
            fprintf(ft2,"%sft\n",alt);
        }
        fclose(ft);
        fclose(ft2);
    }
    return 0;
}
