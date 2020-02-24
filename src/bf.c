#include "bf.h"
#include "stack.h"

void brainfuck(char *input, int show_arr){

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
  if(show_arr){
    printf("\n");
    for(int i = 0; i < ARR_SIZE; i++){
      printf("|%03d", arr[i]);
      if((i+1) % 16 == 0){
        printf("|\n");
      }
    }
  }
  return;
}

