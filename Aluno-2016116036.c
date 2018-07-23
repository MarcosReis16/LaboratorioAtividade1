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
    char dia[3], mes[3], ano[5];
    int cont,i,j;
    cont = i = j = 0;
    int iDia, iMes, iAno;

    while (data[i]!='\0'){
        if(data[i]=='/'){
            cont++;
            j=0;

        }
        else{
            if (cont == 0){
                dia[j]=data[i];
                j++;
                if (j=2){
                    dia[j]='\0';
                }
            }
            else if (cont == 1){
                mes[j]=data[i];
                j++;
                if (j=2){
                    dia[j]='\0';
                }
            }
            else if (cont == 2){
                ano[j]=data[i];
                j++;
            }
        }
    }

    ano[j]=='\0';

    iDia=atoi(dia);
    iMes=atoi(mes);
    iAno=atoi(ano);

    if (iAno>=0 && iAno<=18){
        iAno += 2000;
    }
    else if (iAno>=19 && iAno<=99){
        iAno += 1900;
    }

    datavalida = validaData(iDia,iMes,iAno);




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
    int nDias, nMeses, nAnos;

    nDias = nDias;
    nMeses = nMeses;
    nAnos = nAnos;

    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

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
int q3(char *texto, char c, int caseSensitive){
    int qtdOcorrencias = 0;
    int i = 0;

    while(texto[i]!='\0'){

        if (caseSensitive == 0){
            if (converteMaiusculo(texto[i])==converteMaiusculo(c)){
                qtdOcorrencias += 1;
            }
        }
        else{

            if (texto[i]==c){
                qtdOcorrencias += 1;
            }
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
    int qtdOcorrencias = -1;


    return qtdOcorrencias;

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
    int qtdOcorrencias;
    return qtdOcorrencias;
}
