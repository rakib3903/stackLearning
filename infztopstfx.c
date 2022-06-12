#include<stdio.h>
#define capacity 100


char arr[capacity];
int index = -1;

void push(char x) {
    index ++;
    if(index < capacity) {
        arr[index] = x;
    } else {
        printf("over flow!");
    }
}

 char pop() {

    if(index >= 0) {
    index--;
        return arr[index+1];

    } else {
        printf("under flow!");
        return -1;
    }
}

char peek() {
    if(index>=0) {
        return arr[index];
    }
    return -1;
}

int main() {

    char  infix[100];
    char postfix[100];
    gets(infix);
    int len = strlen(infix);
    infix[len] = ')';
    len++;
    push('(');

   int x =0;
    for(int i=0; i<len; i++) {

        if(isdigit(infix[i]) ) {

            while(isdigit(infix[i]) ) {
                postfix[x]=infix[i];
                x++;
                i++;
            }

            postfix[x]=' ';
                x++;
            i--;
        }

        else if(infix[i] == '('){
        push('(');
           }

        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {

            while(1){

            if((infix[i] == '+' || infix[i] == '-') && ( peek()=='+' || peek()=='-' || peek()=='*' || peek()=='/' || peek() =='^')){
            postfix[x] =pop();
            x++;
             postfix[x] =' ';
            x++;
            }
            else if((infix[i] == '*' || infix[i] == '/') && ( peek()=='*'  || peek()=='/' || peek() =='^')){
           postfix[x] =pop();
            x++;
             postfix[x] =' ';
            x++;
            } else if((infix[i] == '^') && (peek() =='^')){
           postfix[x] =pop();
            x++;
             postfix[x] =' ';
            x++;
            }else{
            push(infix[i]);
            break;
            }
            }
        } else if(infix[i] == ')'){
         while(1){
         if(peek() != '('){
         postfix[x] = pop();
         x++;
         postfix[x] = ' ';
         x++;
         }else{
         char p = pop();
         break;
         }
         }

        }
    }
    for(int i=0;i<x-1;i++)
    printf("%c",postfix[i]);

    return 0;
}
