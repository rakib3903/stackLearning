#include<stdio.h>
#include<stdlib.h>
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




float arr1[capacity];
int index1 = -1;

 void push1(float x) {
    index1 ++;
    if(index1 < capacity) {
        arr1[index1] = x;
    } else {
        printf("over flow!");
    }
}

    double pop1() {
    if(index1 >= 0) {
    index1--;
    return arr1[index1 + 1];

    } else {
        printf("under flow!");
        return -1;
    }
}

double peek1() {
    if(index1>=0) {
        return arr1[index];
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

        else if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]>='Z')){
        printf("assign the value of %c : ",infix[i]);
        char ch;
        scanf(" %c",&ch);
        infix[i] = ch;
                     postfix[x]=infix[i];
             x++;
            postfix[x]=' ';
                x++;

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



     len = strlen(postfix);
    postfix[len] = ')';
    len++;

    for(int i=0; i<len; i++) {
       int x=0;
        if(isdigit(postfix[i])) {
          char s[50]="";
           char *ptr;
            while((postfix[i]) != ' ') {
                s[x]=postfix[i];
                x++;
                i++;
            }
            i--;
            float num = strtod(s,&ptr);
            push1(num);
        } else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' ) {
            float A = pop1();
            float B = pop1();
            float number;
            if(postfix[i] == '+')
                number = B + A;
            else if(postfix[i] == '-')
                number = B- A;
            else if(postfix[i] == '*')
                number = B * A;
            else
                number = B / A;
            push1(number);
        }
        else if(postfix[i] == ' '){
        }
        else break;
    }

    float result = pop1();
    printf("the result is : %f\n",result);

    return 0;
}

