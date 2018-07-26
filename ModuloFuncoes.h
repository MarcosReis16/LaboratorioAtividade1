typedef struct {
    int dia, mes, ano;

} Date;

char converteMaiusculo(char palavra);
char converteMinusculo(char palavra);
int validaData(int dia,int mes,int ano);
Date quebraData(char *data);
int verificaBissexto(int ano);
