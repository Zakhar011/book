#include <stdio.h>
#include "encrypt.h"  
#include "checksum.h"  


int main()
{
    char s[] = "sdda";
    encrypt(s);
    printf("Зашифровано в '%s'\n", s);
    printf("Контрольная сумма %i\n", checksum(s));
    encrypt(s);
    printf("Расшифровано обратно в '%s'\n", s);
    printf("Контрольная сумма %i\n", checksum(s));
    return 0;
}
