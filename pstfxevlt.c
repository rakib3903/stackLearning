#include<stdio.h>
#define capacity 50


int arr[capacity];
int index = -1;

void push(int x) {
    index ++;
    if(index < capacity) {
        arr[index] = x;
    } else {
        printf("over flow!");
    }
}

 int pop() {

    if(index >= 0) {
    index--;
        return arr[index+1];

    } else {
        printf("under flow!");
        return -1;
    }
}


int main() {

    char  postfix[100];
    gets(postfix);
    int len = strlen(postfix);
    postfix[len+1] = ")";
    len++;

    for(int i=0; i<len; i++) {
        int x =0;
        if(isdigit(postfix[i])) {
            char s[50]="0/";

            while((postfix[i]) != ',') {
                s[x]=postfix[i];
                x++;
                i++;
            }
            int number = atoi(s);
            push(number);
        } else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' ) {
            int A = pop();
            int B = pop();
            int number;
            if(postfix[i] == '+')
                number = B + A;
            else if(postfix[i] == '-')
                number = B- A;
            else if(postfix[i] == '*')
                number = B* A;
            else
                number = B/ A;
            push(number);
            i++;
        } else break;
    }

    int result = pop();
    printf("the result is : %d\n",result);

    return 0;
}
