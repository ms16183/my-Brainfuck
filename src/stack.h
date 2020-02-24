#ifndef _STACK_H_
#define _STACK_H_
// for "[" and "]"
typedef struct{
  // pointer to "["
  char *arr[STK_SIZE];
  int top;
} STACK;

void stkinit(STACK*);
void push(STACK*, char*);
char *pop(STACK*);

#endif
