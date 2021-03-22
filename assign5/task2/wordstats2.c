#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i;
  char buf[MAX_BUF];
  int charCount = -1;
  int numWords = 0;
  int numLines  = -1;
  int numUpper = 0;
  int numLower = 0;
  int numDigit = 0;
  int numSpaces = 0;

  do {
    if (fgets(buf, MAX_BUF, stdin) == NULL)
      break;
    len = strlen(buf) - 1;
    for (i = 0; i < len; i++){
      if ((buf[i] >= 'A' && buf[i] <= 'Z')) {
        letter_frequency[buf[i]-65]++;
        
        numUpper += 1;
      } else if ((buf[i] >= 'a' && buf[i] <= 'z')) {
        letter_frequency[buf[i]-97]++;
        numLower += 1;
      }
      else if (buf[i] == ' ') {
        numWords += 1;
        numSpaces += 1;
      }
      else if (buf[i] >= '0' && buf[i] <= '9') {
        numDigit += 1;
      }
      
    }
    charCount += (len + 1);
    numLines += 1;
  } while (len > 1);

  if (numWords != 0) {
    numWords += (numLines + 1);
    charCount += 1;
    numLines += 1;
  }

  printf("%d %d %d %d %d %d %d\n", charCount, numWords, numLines, numSpaces, numUpper, numLower, numDigit);
}