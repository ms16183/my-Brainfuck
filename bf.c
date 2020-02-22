#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

  if(argc != 2){
    fprintf(stderr, "Usage: %s <program>\n", argv[0]);
    exit(1);
  }

  char *input = argv[1];

  char arr[32] = {};
  char *current = arr;

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
          p = strchr(input, ']');
        }
        break;

      case ']':
        if(*current != 0){
          p = strchr(input, '[');
        }
        break;

      default:
        break;

    }
  }
  return 0;
}

