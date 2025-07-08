#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
   char open[100];
   char close[100];
   int top1;
   int top2;
} stack;

stack *create_stack() {
   stack *s = (stack *)malloc(sizeof(stack));
   s->top1 = -1;
   s->top2 = -1;
   return s;
}

void push_open(stack *s, char x) {
   s->open[++(s->top1)] = x;
}

void push_close(stack *s, char x) {
   s->close[++(s->top2)] = x;
}

int is_matching(char open, char close) {
   return (open == '(' && close == ')') ||
          (open == '[' && close == ']') ||
          (open == '{' && close == '}');
}

int check(stack *s) {
   if (s->top1 != s->top2) {
      return 0;
   }
   for (int i = 0; i <= s->top1; i++) {
      if (!is_matching(s->open[i], s->close[s->top1 - i])) {
         return 0;
      }
   }
   return 1;
}

int main() {
   char str[100];
   fgets(str, 100, stdin);
   str[strcspn(str, "\n")] = '\0';

   int len = strlen(str);
   stack *s = create_stack();

   for (int i = 0; i < len; i++) {
      if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
         push_open(s, str[i]);
      } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
         push_close(s, str[i]);
      }
   }

   if (check(s)) {
      printf("true\n");
   } else {
      printf("false\n");
   }

   return 0;
}
