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
int function(char buf[30])
{
    
    i=strlen(buf);
    
    if((buf[i-1]==')') && (buf[i-2]=='('))
      return 1;  
    return 0;  
}
int operator(char buf[30])
{
    char OPERATOR[][10]={"<",">","/","*","%","+","-","^","=","==","&&","||"};
    for(i=0;i<sizeof(OPERATOR)/10;i++)
       if(strcmp(OPERATOR[i],buf)==0)
          return 1;
       return 0;   
}
int delimiter(char buf[30])
{
    char DELIMITER[][10]={"{","}",",",";","'","|"};
    for(i=0;i<sizeof(DELIMITER)/10;i++)
       if(strcmp(DELIMITER[i],buf)==0)
          return 1;
       return 0;   
}
void main()
{
    char ch,buf[20];    
    int j=0;
    FILE *ptr;
    ptr=fopen("input.txt","r");
    while(fscanf(ptr,"%s",buf)!=EOF)
    {        
            if(keyword(buf)==1)
                printf("\n%s IS A KEYWORD",buf);
            else if(function(buf)==1) 
                printf("\n%s IS A FUNCTION",buf);
            else if(operator(buf)==1)
                printf("\n%s IS A OPERATOR",buf);   
            else if(delimiter(buf)==1)
                printf("\n%s IS A DELIMITER",buf);  
            else
                printf("\n%s IS A IDENTIFIER",buf);            
    }
}
