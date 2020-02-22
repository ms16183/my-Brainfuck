#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STK_SIZE (32)
#define ARR_SIZE (64)

// for "[" and "]"
typedef struct{
  // pointer to "["
  char *arr[STK_SIZE];
  int top;
} STACK;

void stkinit(STACK*);
void push(STACK*, char*);
char *pop(STACK*);

int main(int argc, char **argv){

  if(argc != 2){
    fprintf(stderr, "Usage: %s <program>\n", argv[0]);
    exit(1);
  }

  char *input = argv[1];

  // array of Brainfuck.
  unsigned char arr[ARR_SIZE] = {};
  // current cell.
  unsigned char *current = arr;

  // A stack for mapping "[" and "]".
  STACK bracket;
  // Initialize a stack.
  stkinit(&bracket);
  // pairs[i][0] = pointer of "["
  // pairs[i][1] = pointer of "]".
  int i = 0;
  char *pairs[STK_SIZE][2] = {};

  // Make "[" and "]" pairs.
  for(char *p = input; *p != '\0'; p++){
    if(*p == '['){
      push(&bracket, p);
    }
    if(*p == ']'){
      pairs[i][0] = pop(&bracket); // [
      pairs[i][1] = p;             // ]
      i++;
    }
  }

  // Execute.
  for(char *p = input; *p != '\0'; p++){

    switch(*p){
      case '>':
        current++;
        break;

      case '<':
        current--;
        break;

      case '+':
        (*current)++;
        break;

      case '-':
        (*current)--;
        break;

      case '.':
        putchar(*current);
        break;

      case ',':
        *current = getchar();
        break;

      case '[':
        if(*current == 0){
          // Find yourself.
          for(int i = 0; i < STK_SIZE; i++){
            if(pairs[i][0] == p){
              // Seek my pair "]"
              p = pairs[i][1];
              break;
            }
          }
        }
        break;

      case ']':
        if(*current != 0){
          // Find yourself.
          for(int i = 0; i < STK_SIZE; i++){
            if(pairs[i][1] == p){
              // Seek my pair "["
              p = pairs[i][0];
              break;
            }
          }
        }
        break;

      default:
        break;
    }
  }

  // visualize array.
  for(int i = 0; i < ARR_SIZE; i++){
    printf("|%03d", arr[i]);
    if((i+1) % 16 == 0){
      printf("|\n");
    }
  }
  return 0;
}


void stkinit(STACK *stk){
  for(int i = 0; i < STK_SIZE; i++){
    stk->arr[i] = NULL;
  }
  stk->top = 0;
  return;
}

void push(STACK *stk, char *p){
  if(stk->top <= STK_SIZE){
    stk->top++;
    stk->arr[stk->top] = p;
  }
  else{
    fprintf(stderr, "STACK out of range.\n");
    exit(1);
  }
  return;
}

char *pop(STACK *stk){
  int tmp;
  if(stk->top != 0){
    tmp = stk->top;
    stk->top--;
  }
  else{
    fprintf(stderr, "STACK is empty.\n");
    exit(1);
  }
  return stk->arr[tmp];
}

