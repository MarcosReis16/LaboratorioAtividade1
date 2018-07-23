#include <stdio.h>
#include <stdlib.h>

char converteMaiusculo(char palavra){
    int i;

    //for (i=0;palavra[i]!='\0';i++){
        if (palavra >= 97 && palavra <= 122) {
            palavra = palavra-32;
        }
    //}

    return palavra;
}

char converteMinusculo(char palavra){
    int i;

    //for (i=0;palavra[i]!='\0';i++){
        if (palavra >= 65 && palavra <= 90) {
            palavra = palavra+32;
        }
    //}

    return palavra;
}

int validaData(int dia, int mes, int ano){
    int validado = 1;
	if (dia<1 || dia>31){
		validado = 0;
	}
	else if (mes % 2 == 0 && mes != 2) {
        if (dia>30){
            validado = 0;
        }
	}
	else if (mes == 2) {
		if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) {
            if (dia>29){
                validado = 0;
            }
        else{
            if (dia>28){
                validado = 0;
            }
        }
		}
	}

	return validado;
}


