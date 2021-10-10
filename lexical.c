#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int i; 
char keyword(char buf[30])
{
    char key[][10]={"void","int","char","return"};
    for(i=0;i<sizeof(key)/10;i++)
    {
        if(strcmp(key[i],buf)==0)
        {
            return 1;
        }
    }

}
int function(char* buf)
{
    i=strlen(buf);
    if(buf[i-1]==')' && buf[i-2]=='(')
        return 1;
    return 0;
}
void main()
{
    char ch,buf[20];
    char operator[]={"+-*/%^="};
    FILE *ptr;
    ptr=fopen("input.txt","r");
    while(fscanf(ptr,"%s",buf)!=EOF)
    {
        if(keyword(buf)==1)
            printf("\n%s IS A KEYWORD",buf);
        else if(function(buf)==1) 
            printf("\n%s IS A FUNCTION",buf);
        else
            printf("\n%s IS A IDENTIFIER",buf);    

        
    }
}