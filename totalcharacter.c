//Read the number of characters, numbers, special characters, etc from a file
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char special[]="<>,./?'|\"[]{})(*&^%$#@!-_=+)";
char types[6][30]={"Upper case", "Lower case", "Numbers", "Special characters", "Spaces","Total characters"};
bool isSpecialChar(char ch)
{
    for(int i=0;i<strlen(special);i++)
        if(special[i]==ch)
            return true;
    return false;
}
void main()
{
    FILE *fpt;
    char ch;
    int count[6]={0,0,0,0,0,0};
    fpt=fopen("input.txt","r");
    while(fscanf(fpt,"%c",&ch)!=EOF)
    {
        if(ch>='A' && ch<='Z')
            count[0]=count[0]+1;

        else if((ch>='a' && ch<='z'))
            count[1]=count[1]+1;

        else if(ch>=48 && ch<=57)
            count[2]=count[2]+1;

        else if(isSpecialChar(ch))
            count[3]=count[3]+1;

        else if(ch==' ')
            count[4]=count[4]+1;

        count[5]=count[5]+1;
    }
    for(int i=0;i<6;i++)
        printf("%s: %d\n",types[i],count[i]);
    fclose(fpt);
}