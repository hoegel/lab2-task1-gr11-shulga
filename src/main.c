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
        return 0;
    }

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