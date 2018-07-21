#include <stdio.h>
#include <stdlib.h>

char* converteMaiusculo(char *palavra){
    int i;

    for (i=0;palavra[i]!='\0';i++){
        if (palavra[i] >= 97 && palavra[i] <= 122) {
            palavra[i] = palavra[i]-32;
        }
    }

    return *palavra;
}

char* converteMinusculo(char *palavra){
    int i;

    for (i=0;palavra[i]!='\0';i++){
        if (palavra[i] >= 65 && palavra[i] <= 90) {
            palavra[i] = palavra[i]+32;
        }
    }

    return *palavra;
}

int validaData(int dia, int mes, int ano){
    int validado = 1;
	if (mes > 12 || mes < 1 || dia < 1 || dia > 31){
		validado = 0;
	}
	else if (mes % 2 == 0 && mes != 2 && dia > 30) {
		validado = 0;
	}
	else if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) {
		if (mes == 2 && dia > 29) {
			validado = 0;
		}
	}
	else if (mes == 2 && dia > 28) {
		validado = 0;
	}

	return validado;
}
