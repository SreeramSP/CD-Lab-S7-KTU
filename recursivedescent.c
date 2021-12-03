//Recursive Descent Parser
// E->TE'  
// E'->+TE'
// T->FT'
// T'-> *FT' 
// F->(E)|i
// By Sreeram S P

#include <stdio.h>
#include <string.h>

int pointer=0;
int error=0;
char input[30];

void Edash();
void T();
void Tdash();
void F();
void E();

void E(){
    T();
    Edash();
}

void Edash(){
    if(input[pointer]=='+'){
        pointer++;
        T();
        Edash();
    }
}

void T(){
    F();
    Tdash();
}

void Tdash(){
    if(input[pointer]=='*'){
        pointer++;
        F();
        Tdash();
    }
}

void F(){
    if(input[pointer]=='('){
        error++;
        pointer++;
        E();
        if(input[pointer]==')'){
            error--;
            pointer++;
        }
    }
    else if(input[pointer]=='i')
        pointer++;
    else
        error++;
}

int main(){
  printf("Enter the input = ");
  scanf("%s",input);
  input[strlen(input)]='$'; 
  E();
  if(input[pointer]=='$' && error==0)
        printf("Accepted\n");
    else
        printf("Not Accepted\n");
    return 0;
}























































////Changing the last character to $ sign
