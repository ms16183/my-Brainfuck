#include "bf.h"
#include "stack.h"

void stkinit(STACK *stk){
  for(int i = 0; i < STK_SIZE; i++){
    stk->arr[i] = NULL;
  }
  stk->top = 0;
  return;
}

void push(STACK *stk, char *p){
  if(stk->top <= STK_SIZE){
    stk->arr[++stk->top] = p;
    return;
  }
  fprintf(stderr, "STACK is refered out of range.\n");
  exit(1);
}

char *pop(STACK *stk){
  if(stk->top != 0){
    return stk->arr[stk->top--];
  }
  fprintf(stderr, "STACK is empty.\n");
  exit(1);
}

