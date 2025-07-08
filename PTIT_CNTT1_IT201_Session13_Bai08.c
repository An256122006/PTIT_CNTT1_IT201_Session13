#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
typedef struct stack {
   int arr[100];
   int top;
}stack;
stack *create_stack() {
   stack *s;
   s = (stack *)malloc(sizeof(stack));
   s->top=-1;
   return s;
}
void push(stack *s,int x) {
   s->arr[++(s->top)]=x;
}
int pop(stack *s) {
   return s->arr[s->top--];
}
int check(stack *s,char *str) {
   for(int i=0;i<strlen(str);i++) {
      if (isdigit(str[i])) {
         push(s,str[i]-'0');
      }else {
         int b=pop(s);
         int a=pop(s);
         int sum;
         switch (str[i]) {
            case '+':
               sum=a+b;
               break;
            case '-':
               sum=a-b;
               break;
            case '*':
               sum=a*b;
               break;
            case '/':
               sum=a/b;
               break;
            default:
               return 0;
         }
         push(s,sum);
      }
   }
   return pop(s);
}
int main(){
   char str[100];
   fgets(str,100,stdin);
   str[strlen(str)-1]='\0';
   stack *s = create_stack();
   int sum=check(s,str);
   printf("%d\n",sum);
   return 0;
}