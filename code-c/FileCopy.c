#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpSrc,*fpDest; /*分别定义已存在文件和复制所得文件*/
    char ch;
    char name_Src[20],name_Dest[20]; /*定义数组存放文件名*/
    printf("Please input the existing file name:\n");
    scanf(" %s",name_Src);             /*由用户输入已存在文件名*/
    printf("Please input the new file name:\n");
    scanf(" %s",name_Dest);             /*由用户输入新文件名*/
    if((fpSrc=fopen(name_Src,"r"))==NULL)
    {
        printf("Failure to open %s!\n",name_Src);
        exit(0);
    }
    if((fpDest=fopen(name_Dest,"w"))==NULL)
    {
        printf("Failure to open %s!\n",name_Dest);
        exit(0);
    }
    while((ch=fgetc(fpSrc))!=EOF)
    {
        fputc(ch,fpDest);
    }                               /*复制文件*/
    fclose(fpSrc);
    fclose(fpDest);
    return 0;
}
