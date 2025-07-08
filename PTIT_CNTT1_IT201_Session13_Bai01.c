#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
    int *arr;
    int top;
    int cap;
}stack;
stack *create_stack(int cap) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->cap = cap;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * cap);
    return s;
}
void print_stack(stack *s) {
    if (s->top == -1) {
        printf("rong\n");
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
}
int main(void) {
    stack *s = create_stack(5);
    print_stack(s);
    return 0;
}