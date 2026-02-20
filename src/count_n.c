#include "count_n.h"

int count_n(const wchar_t *s) {
    int cnt = 0;
    while (*s) {
        if (*s == L'н')
            cnt++;
        s++;
    }
    return cnt;
}