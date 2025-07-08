#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack {
   int *arr;
   int top;
   int cap;
}stack;
stack*creative(int cap) {
   stack *s=(stack*)malloc(sizeof(stack));
   s->arr = (int *)malloc(sizeof(int) * cap);
   s->cap=cap;
   s->top=-1;
   return s;
}
stack *push(stack *s, int x) {
   s->top++;
   s->arr[s->top]=x;
   return s;
}
void print_stack(stack *s) {
   for(int i=s->top;i>=0;i--) {
      printf("%d ",s->arr[i]);
   }
   printf("\n");
   printf("%d\n",s->top);
   printf("%d\n",s->cap);
}

int main(){
   stack *s=creative(5);
   int data;
   for(int i=0;i<5;i++) {
      scanf("%d",&data);
      push(s,data);
   }
   print_stack(s);
   return 0;
}