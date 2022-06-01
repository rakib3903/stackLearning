#include<stdio.h>
#define capacity 3

int arr[capacity];
int index = -1;

void push(int x) {
    index ++;
    if(index < capacity) {
        arr[index] = x;
    } else {
        printf("index exceeds the limit!");
    }
}

int pop() {
    if(index>=0) {
        index--;
        return arr[index+1];
    }
    return -1;
}

int peek() {
    if(index>=0) {
        return arr[index];
    }
    return -1;
}

int main() {
push(12);
push(13);
push(14);
//push(15);
int x = pop();
printf("\n%d ",x);
x = peek();
printf("%d ",x);
}
