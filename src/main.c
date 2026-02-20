/* hello.c */
/* Author: hoegel */
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int count_n(const wchar_t *s);

void main (void)
{
  //setlocale(LC_ALL, "");
  const wchar_t *str = L"привеннн, мир";
  printf("%d\n", count_n(str));
}

int count_n(const wchar_t *s) {
    int cnt = 0;
    while (*s) {
        if (*s == L'н') ++cnt;
        ++s;
    }
    return cnt;
}