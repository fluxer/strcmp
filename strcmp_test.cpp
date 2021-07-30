#include <stdio.h>
#include <string.h>

// pure function call
int qqstrcmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

// copy of from musl standard C library:
// https://git.musl-libc.org/cgit/musl/plain/src/string/strcmp.c
int qqqstrcmp(const char *l, const char *r)
{
    for (; *l==*r && *l; l++, r++);
    return *(unsigned char *)l - *(unsigned char *)r;
}

// my implementation
int qqstrcmp_fixed(const char *l, const char *r)
{
    if (!l) {
        return -!r;
    }
    if (!r) {
        return !l;
    }
    for (int i = 0; l[i] && r[i]; i++) {
        if (l[i] < r[i]) {
            return -i;
        } else if (l[i] != r[i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    printf("qqstrcmp(%d)\n", qqstrcmp("asd", "asd"));
    printf("qqqstrcmp(%d)\n", qqqstrcmp("asd", "asd"));
    printf("qqstrcmp_fixed(%d)\n", qqstrcmp_fixed("asd", "asd"));
    printf("strcmp(%d)\n", strcmp("asd", "asd"));

    printf("qqstrcmp(%d)\n", qqstrcmp("asd das", "asd das"));
    printf("qqqstrcmp(%d)\n", qqqstrcmp("asd das", "asd das"));
    printf("qqstrcmp_fixed(%d)\n", qqstrcmp_fixed("asd das", "asd das"));
    printf("strcmp(%d)\n", strcmp("asd das", "asd das"));

    printf("qqstrcmp(%d)\n", qqstrcmp("asd 123", "asd das"));
    printf("qqqstrcmp(%d)\n", qqqstrcmp("asd 123", "asd das"));
    printf("qqstrcmp_fixed(%d)\n", qqstrcmp_fixed("asd 123", "asd das"));
    printf("strcmp(%d)\n", strcmp("asd 123", "asd das"));

    return 0;
}
