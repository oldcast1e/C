#pragma warning(disable : 4996) // 'gets': This function or variable may be unsafe.

#include <stdio.h>
#include <string.h>

int main() {
    int auth = 0;
    char passwd[20];
    printf("패스워드: ");
    gets(passwd);  
    if (strcmp(passwd, "passkey") == 0 || passwd[20] != 0 ) auth = 1;
    if (auth) printf("인증 성공!\n");
    else printf("인증 실패!\n");
    return 0;
}


/*
111111111111111111111
*/