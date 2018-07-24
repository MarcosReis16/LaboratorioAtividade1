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
	int i = 0;

    if (mes<1 || mes>12){
        validado = 0;
    }
	else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        if(dia<1 || dia>31){
            validado = 0;
        }
	}
	else if (mes==4 || mes==6 || mes==9 || mes==11){
        if(dia<1 || dia>30){
            validado = 0;
        }

	}
	else if (mes==2){
        if (ano%4==0){
            if (ano%100==0){
                if(ano%400==0){
                    if(dia<1 || dia>29){
                        validado = 0;
                    }
                }
                else{
                    if(dia<1 || dia>28){
                        validado = 0;
                    }
                }
            }
            else{
                if(dia<1 || dia>29){
                    validado = 0;
                }
            }

        }
        else{
            if(dia<1 || dia>28){
                validado = 0;
            }

        }

	}



	return validado;
}


