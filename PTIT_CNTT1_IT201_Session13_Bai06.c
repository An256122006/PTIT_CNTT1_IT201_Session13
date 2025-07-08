#include <ctype.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack {
   char data[100];
   int top;
   int size;
}stack;
stack*create_stack(int len) {
   stack *s=(stack*)malloc(sizeof(stack));
   s->top=-1;
   s->size=len;
   return s;
}
void push(stack *s, char x) {
   s->data[++(s->top)] = x;
}
char pop(stack *s) {
   return s->data[s->top--];
}
int check_stack(stack *s,int len) {
   for(int i=0;i<len;i++) {
      if(s->data[i]!=pop(s)) {
         return 0;
      }
   }
   return 1;
}
int main(){
   char str[100];
   fgets(str,100,stdin);
   str[strcspn(str, "\n")] = '\0';
   int len=strlen(str);
   stack *s=create_stack(len);
   for(int i=0;i<len;i++) {
      push(s,str[i]);
   }
   if (check_stack(s,len)) {
      printf("True");
   }else {
      printf("False");
   }
   return 0;
}