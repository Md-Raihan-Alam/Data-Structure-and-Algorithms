#include<stdio.h>
#include<string.h>
int main()
{
    char txt[]="aabcdfaabfefffgdfbgsdfgdfdewedaabcdercd";
    char pat[100];
    scanf("%s",pat);
    int i;
    for(i=0;i<=strlen(txt)-strlen(pat);i++)
    {
        int j;
        for(j=0;j<strlen(pat);j++)
        {
            if(txt[i+j]!=pat[j])
                break;       
        }
        if(j==strlen(pat))
        {
            printf("pattern matche at index %d\n",i);
        }
    }
    return 0;
}