#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpSrc,*fpDest; /*�ֱ����Ѵ����ļ��͸��������ļ�*/
    char ch;
    char name_Src[20],name_Dest[20]; /*�����������ļ���*/
    printf("Please input the existing file name:\n");
    scanf(" %s",name_Src);             /*���û������Ѵ����ļ���*/
    printf("Please input the new file name:\n");
    scanf(" %s",name_Dest);             /*���û��������ļ���*/
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
    }                               /*�����ļ�*/
    fclose(fpSrc);
    fclose(fpDest);
    return 0;
}
