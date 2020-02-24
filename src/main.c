#include "bf.h"
#include "stack.h"

int main(int argc, char **argv){

  char *input = NULL;

  if(argc != 2){
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    fprintf(stderr, "     : %s script\n", argv[0]);
    exit(1);
  }

  // Read *.bf.
  FILE *fp;
  char buf[READ_SIZE];

  if((fp = fopen(argv[1], "r")) != NULL){
    fscanf(fp, "%s", buf);
    input = buf;
    fclose(fp);
  }
  else{
    // when *.bf nou found, file name uses as script.
    input = argv[1];
  }

  brainfuck(input, 0);

  return 0;
}

