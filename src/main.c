/* Author: hoegel */

/* main.c */
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "count_n.h"

int main (int argc, char *argv[])
{
  if(argc != 3) {
    printf("error: invalid arguments\nusage: <string1> <string2>\n");
    return 0;
  }

  printf("first string: %s\n", argv[1]);
  printf("second string: %s\n", argv[2]);
  
  return 0; 
}