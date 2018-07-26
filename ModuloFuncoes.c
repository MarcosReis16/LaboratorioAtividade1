#include <stdio.h>
#include <stdlib.h>
#include "ModuloFuncoes.h"

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
        if (verificaBissexto(ano)){
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



	return validado;
}

Date quebraData(char *data){
    char dia[3];
	char mes[3];
	char ano[5];
	int barra=0, k=0, i=0;

	Date datainteira;

	while(data[i]!='\0'){
        if(data[i]=='/'){
            barra++;
            k=0;
        }
        if(barra==0){
            dia[k]=data[i];
            dia[k+1]='\0';
            k++;
        }
        else if(barra == 1){
            if(data[i]=='/'){
                i++;
            }
            mes[k]=data[i];
            mes[k+1]='\0';
            k++;
        }
        else if(barra == 2){
            if(data[i]=='/'){
                i++;
            }
            ano[k]=data[i];
            ano[k+1]='\0';
            k++;
        }
        i++;
    }

	datainteira.dia=atoi(dia);
	datainteira.mes=atoi(mes);
	datainteira.ano=atoi(ano);

    if (datainteira.ano>=0 && datainteira.ano<=18){
        datainteira.ano += 2000;
    }
    else if (datainteira.ano>=19 && datainteira.ano<=99){
        datainteira.ano += 1900;
    }


    return datainteira;

}

int verificaBissexto(int ano){

        if (ano%4==0){
            if (ano%100==0){
                if(ano%400==0){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 1;
            }

        }
        return 0;

}

