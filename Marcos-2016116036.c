// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marcos Vinícius Pereira dos Reis
//  email: marcossummers@gmail.com
//  Matrícula: 2016116036
//  Semestre: 5

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 24/06/2018 - 20/07/2018

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ModuloFuncoes.h"
#include <ctype.h>

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    int datavalida = 1;

    Date dataquebrada = quebraData(data);
    datavalida = validaData(dataquebrada.dia,dataquebrada.mes,dataquebrada.ano);

    return (datavalida);

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int nDias, nMeses, nAnos, validainicio, validafim;

    Date datainicio, datafim;

    *qtdDias = 0;
    *qtdAnos = 0;
    *qtdMeses = 0;

    datainicio = quebraData(datainicial);
    datafim = quebraData(datafinal);
    validainicio = validaData(datainicio.dia,datainicio.mes,datainicio.ano);
    validafim = validaData(datafim.dia,datafim.mes,datafim.ano);

    if (validainicio && validafim){
        *qtdAnos = datafim.ano - datainicio.ano;
        *qtdMeses = datafim.mes - datainicio.mes;
        *qtdDias = datafim.dia - datainicio.dia;

        if(datafim.ano - datainicio.ano >= 0 && datafim.mes - datainicio.mes < 0){
			*qtdAnos = *qtdAnos - 1;
			*qtdMeses = 12 - (datainicio.mes - datafim.mes);
		}
		if(datafim.dia - datainicio.dia < 0){
			if(*qtdMeses == 0){
				if(datafim.dia == 28 && datainicio.dia == 29 && datafim.mes == 2 && datainicio.mes == 2 && verificaBissexto(datainicio.ano) && !verificaBissexto(datafim.ano)){
					*qtdDias = 0;
					*qtdMeses = 0;
				} else{
					*qtdAnos = *qtdAnos - 1;
					*qtdMeses = 11;
					*qtdDias = datafim.dia;
				}
			}else{
				*qtdMeses = *qtdMeses - 1;
				if(datainicio.mes == 1 || datainicio.mes == 3 || datainicio.mes == 5 || datainicio.mes == 7 || datainicio.mes == 8 || datainicio.mes == 10 || datainicio.mes == 12){
					*qtdDias = (31 - datainicio.dia) + datafim.dia;
				} else if(datainicio.mes == 4 || datainicio.mes == 6 || datainicio.mes == 9 || datainicio.mes == 11){ // Validando os meses de 30 dias
					*qtdDias = (30 - datainicio.dia) + datafim.dia;
				} else if(datainicio.mes == 2 && !verificaBissexto(datainicio.ano)){ // Validando o mês de fevereiro em ano não bissexto
					if(!verificaBissexto(datafim.ano)){
						*qtdDias = (28 - datainicio.dia) + datafim.dia;
					} else {
						*qtdDias = (28 - datainicio.dia) + datafim.dia + 1;
					}
				} else if(datainicio.mes == 2 && verificaBissexto(datainicio.ano)){ // Validando o mês de fevereiro em ano bissexto
					if(datafim.mes == 2){
						if(verificaBissexto(datafim.ano)){
							*qtdDias = 29 - datainicio.dia + datafim.dia;
						}else{
							*qtdDias = 28 - datainicio.dia + datafim.dia;
						}
					} else{
						*qtdDias = (29 - datainicio.dia) + datafim.dia;
					}
				}
			}
    	}
return 1;



    }
    else{
        return -1;
    }

    //printf("%s\n", datainicial);
    //printf("%s\n", datafinal);

    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    	int cont=0, tam=0;
	int qtdOcorrencias = 0;
	tam=strlen(texto);

	if (isCaseSensitive == 1){
		cont=0;
		while(cont <= tam){
			if(c == texto[cont]){
				qtdOcorrencias++;

			}
		cont++;
 		}
	}

	else if (isCaseSensitive != 1){
				cont=0;
		while(cont <= tam){
			if(texto[cont] == toupper(c) || texto[cont] == tolower(c)){
				qtdOcorrencias++;
			}
		    	cont++;
 			}
	}
    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){

    int i,var3,var4,var1,var2,cont,cont2,cont3;
    var1=var2=var3=var4=cont=cont2=cont3=0;

    if(strlen(strBusca)==1){
        for(i=0;strTexto[i]!='\0';i++){
            if(strTexto[i]==strBusca[0])
                cont++;
        }
        return cont;
    }

    for(i = 0;strTexto[i]!='\0'; i++){
        cont=0;
    if(strTexto[i]==-95 || strTexto[i]==-87 || strTexto[i]==-83 || strTexto[i]==-77 || strTexto[i]==-70 || strTexto[i]==-93 || strTexto[i]==-89)
       cont3++;
        if(strTexto[i] == strBusca[var3]){
            for(var1=i+1,var4=var3+1;strBusca[var4]==strTexto[var1];var1++,var4++)
                cont++;
        }
        if(cont==strlen(strBusca)-1){
            posicoes[var2++]=(i+1)-cont3;
            posicoes[var2++]=var1-cont3;
            cont2++;
        }
    }
    return cont2;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int n){
    int retorno = 0;
    int i = 1;

    while (i<=n)
    {
        retorno *= 10;
        retorno +=(n%(i*10)-n%i)/i;
        i*=10;

    }

    return retorno;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0;
    int vetBase[300];
    int vetBusca[300];
    int contBase=0, i=0, j=0, control=0;
    int contBusca=0;


	while(numerobase>=0){//preenchendo vetor de int numerobase
		if(numerobase < 10 && numerobase >= 0 ){
			vetBase[contBase]=numerobase;
			break;
		}
		else{
			vetBase[contBase]=numerobase%10;
			numerobase=numerobase/10;
			contBase++;
		}
	}
	while(numerobusca>=0){//preenchendo vetor de int numerobusca
		if(numerobusca < 10 && numerobase >= 0){
			vetBusca[contBusca]=numerobusca;
			break;
		}
		else{
			vetBusca[contBusca]=numerobusca%10;
			numerobusca=numerobusca/10;
			contBusca++;
		}
	}
	//buscando ocorrencias no vetor
	for (int i = 0; i <= contBase; ++i){
		if(contBusca == 0){
			if (vetBusca[0] == vetBase[i]){
				qtdOcorrencias++;
			}
		}
		else{
			if(vetBusca[j] == vetBase[i]){
				control=1;
				j++;
			}
			else if (vetBusca[j] != vetBase[i]){
				control=0;
				j=0;
			}
			if(control == 1 && j == contBusca){
				control=0;
				j=0;
				qtdOcorrencias++;
			}
		}
	}
    return qtdOcorrencias;
}

