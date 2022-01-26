#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256 // maximum length of a single word
//char rotate(char c, int n);

int main(int argc, char* argv[]) {
  if(argc != 3){
    fprintf(stderr, "wrong number of arguments\n");
    return 1;
  }
  //char word[MAX_LEN];

  FILE* fin = fopen(argv[1],"r");

  if(fin == NULL) {
    perror("Could not open input file.");
    return 1;
  }

  // TODO: Write your code here to implement the encryption.
int cin;
int i = 0;
int file[100];
while((cin = fgetc(fin))!= EOF){
  file[i] = cin;
  i++;
}
for(int i = 0;i<100;i++){
  printf("%d",file[i]);
}
  // clean up gracefully
  fclose(fin);

  return 0;
}
