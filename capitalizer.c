#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Deven Bernard - 10099810
//Marissa Huang - 10179169
//Kevin Zuern - 10134425
//Quentin Petraroia - 10145835


int main(int argc, char const *argv[]) {
  FILE *fp;
  FILE *tmpFile;
  char buff[500];
  char dest[500];
  fp = fopen(argv[1], "r+");
  tmpFile = fopen("temp.txt", "w");
  int toCapital = 0;
  char *token;
  while (!feof(fp)) {
    fgets(buff, 500, fp);

    //if (feof(fp)) {
      //break; }
    //printf("%s", buff);
    //puts(buff);
    token = strtok(buff," ");
    while (token != NULL) {
      if (toCapital == 0) {
        char c = toupper(token[0]);
        token[0] = c;
        toCapital = 1;
    } else {
      toCapital = 0;
    }
    fprintf(tmpFile, "%s ", token);
    token = strtok(NULL, " ");
    //strcat(dest, buff);
  }
    fprintf(tmpFile, "\n");
    //strcat(dest, buff);
    //char c = toupper(buff[0]);
    //printf("%c\n", c);
    //puts(dest);
  }


  fclose(fp);
  fclose(tmpFile);
  char tempArray[100] = "cat temp.txt >";
  strcat(tempArray,argv[1]);
  system(tempArray);
  return 0;
}







