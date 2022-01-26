#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//edge case z
#define MAX_LEN 256 // maximum length of a single word
char rotate(char c, int n){
    //rotate only alphate
    if(isalpha(c)){
      //rotate lowercase
      if(c>=97){
        char insideLower= 'a'+(c-'a'+n)%26;
        char outsideLower= 'a'+(c-'a'+n)%26-26;
        //inside the alphate
        if(isalpha(insideLower)){
            return insideLower;
        }
        //outside
        else{
          return outsideLower;
        }
      }
      //rotate uppercase
      else{
        char insideUpper= 'A'+(c-'A'+n)%26;
        char outsideUpper= 'A'+(c-'A'+n)%26-26;
        if(isalpha(insideUpper)){
          return insideUpper;
        }
        else{
          return outsideUpper;
        }
      }
    }
    //non-alphateic then return itself
    else{
       return c;
    }
}
int main(int argc, char* argv[]) {
  if(argc != 3){
    fprintf(stderr, "wrong number of arguments\n");
    return 1;
  }
  char word[MAX_LEN];
  //memset(word,'\0',MAX_LEN);

  FILE* fin = fopen(argv[1],"r");

  if(fin == NULL) {
    perror("Could not open input file.");
    return 1;
  }

  // TODO: Write your code here to implement the encryption.
int cin;
int i = 0;
int count;
int num;
sscanf (argv[2],"%d",&num);
while((cin = fgetc(fin))!= EOF){
  if(cin == ' ' || cin =='\n' ||'\0'){
    for(count=strlen(word)-1;count>=0;count--){
      printf("%c",rotate(word[count],num)); 
    }
    if(cin==' '){
      printf(" ");
    }
    else if(cin=='\n'){
      printf("\n");
    }
    memset(word,'\0',strlen(word));
    i = 0;
    continue;
  }
  word[i] = cin;
  i++;
}
  // clean up gracefully
  fclose(fin);

  return 0;
}
