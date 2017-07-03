//
//  main.c
//  GPS
//
//  Created by 20161104614 on 2017/7/3.
//  Copyright © 2017年 20161104614. All rights reserved.
///Users/a20161104614/Desktop/GPS20161104614/GPS170510.log
#include <stdio.h>
int main()
{
    FILE *fp=fopen("//Users//a20161104614//Desktop//GPS20161104614//GPS170510.log", "r");
    FILE *fp1=fopen("//Users//a20161104614/Desktop//GPS20161104614//biaodan.csv", "r+");
    int i;
    char g1[63];
    char g2[70];
    char lat[9];               //纬度
    char lng[10];              //经度
    char height[5];            //海拔
    char day[3],month[3],year[3];
    char s[3],m[3],h[3];
    
    
    
    
    
    
    
    
    if(fp==NULL)
    {
        printf("文件读取错误，请检查文件GPS170510.log是否存在!");
    }
    else
    {
        while(fscanf(fp,"%s%s",g1,g2)!=EOF)
        {
            printf("%s\n%s\n",g1,g2);
            for(i=0;i<8;i++)
                lat[i]=g1[i+16];
            lat[8]='\0';
            printf("纬度：%s\n",lat);
            fprintf(fp1,"纬度：%s",lat);
            
            
            for(i=0;i<9;i++)
                lng[i]=g1[i+27];
            lng[9]='\0';
            printf("经度：%s\n",lng);
            fprintf(fp1,"经度：%s",lng);
            
            
            
            
            
            
            
            
            for(i=0;i<2;i++)
                day[i]=g1[i+51];
            day[2]='\0';
            
            for(i=0;i<2;i++)
                month[i]=g1[i+53];
            month[2]='\0';
            
            
            for(i=0;i<2;i++)
                year[i]=g1[i+55];
            year[2]='\0';
            
            printf("日期：%s年%s月%s日\n",year,month,day);
            fprintf(fp1,"日期：%s年%s月%s日",year,month,day);
            
            
            
            
            
            
            for(i=0;i<2;i++)
                s[i]=g1[i+7];
            s[2]='\0';
            
            for(i=0;i<2;i++)
                m[i]=g1[i+9];
            m[2]='\0';
            
            for(i=0;i<2;i++)
                h[i]=g1[i+11];
            h[2]='\0';
            
            printf("时间：%s时%s分%s秒\n",s,m,h);
            fprintf(fp1,"时间：%s时%s分%s秒",s,m,h);
            
            
            
            
            
            for(i=0;i<4;i++)
                height[i]=g2[i+43];
            height[4]='\0';
            printf("海拔：%s\n",height);
            fprintf(fp1,"海拔：%s米\n",height);
        }
    }
    fclose(fp);
    return 0;
}
