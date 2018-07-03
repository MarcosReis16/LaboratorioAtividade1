#include <stdio.h>
#include <stdlib.h>

char* converteMaiusculo(char *palavra){
    int i;

    for (i=0;i!="O/";i++){
        if palavra[i] >= 97 && palavra[i] <= 122 {
            palavra[i] = palavra[i]-32
        }
    }

    return palavra
}

char* converteMinusculo(char *palavra){
    int i

    for (i=0;i!="O/";i++){
        if palavra[i] >= 65 && palavra[i] <= 90 {
            palavra[i] = palavra[i]+32;
        }
    }

    return palavra
}
