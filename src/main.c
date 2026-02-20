/* Author: hoegel */

/* main.c */
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "count_n.h"

wchar_t *GetWC(const char *c);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("error: invalid arguments\nusage: <string1> <string2>\n");
        return 1;
    }

  setlocale(LC_ALL, "");

  wchar_t *ws1 = GetWC(argv[1]);
  wchar_t *ws2 = GetWC(argv[2]);

  if (ws1 == NULL || ws2 == NULL) {
      printf("error converting string to wchar\n");
      free(ws1);
      free(ws2);
      return 1;
  }

  printf("\n### INPUT DATA ###\n");
  printf("first string: %s\n", argv[1]);
  printf("second string: %s\n", argv[2]);

  int first = count_n(ws1);
  int second = count_n(ws2);

  printf("\n### OUTPUT ###\n");
  printf("number of 'н' in both strings: %d\n", first + second);

  printf("\n### EXTRA OUTPUT ###\n");
  printf("number of 'н' in first string: %d\n", first);
  printf("number of 'н' in second string: %d\n", second);

  free(ws1);
  free(ws2);

  
    return 0;
}

wchar_t *GetWC(const char *c) {
    if (c == NULL) return NULL;
    size_t len = strlen(c) + 1;
    wchar_t *wc = malloc(len * sizeof(wchar_t));  // alloc mem for wchar
    if (wc == NULL) return NULL;                  // malloc failure
    size_t converted = mbstowcs(wc, c, len);      // convert multibyte string to wchar
    if (converted == (size_t)-1) {
        free(wc);
        return NULL;
    }
    return wc;
}