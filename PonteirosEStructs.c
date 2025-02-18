#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    float y = 20.50;
    char z = 'a';

    int *pX;
    pX = &x;
    float *pY = &y;
    char *pZ = &z;

    int *resultado = &x;
    //int *resultado = 6422012;




    printf("%d", resultado);

}



/* 
    struct Aluno{
        int matricula;
        int idade;
        float nota1;
        float nota2;
    };

    struct Aluno aluno;

    aluno.matricula = 20133056;
    aluno.idade = 28;
    aluno.nota1 = 10;
    aluno.nota2 = 10;


    printf("AlunoMat: %d\nIdade: %d\nNota1: %.2f\n Nota2: %.2f", aluno.matricula, aluno.idade, aluno.nota1, aluno.nota2 );


    ETAPA 2:
     int x;
   x = 10;

   // imprimir o x e mostrar que assim imprime o X e para imprimir printf("%d", &x)
    int *ponteiro; //criou o ponteiro mas ainda não está apontando;

    ponteiro = &x;

    printf("%d\n", *ponteiro); //imprimindo com asteristco valor, sem * endereço




    ETAPA 3

        int x;
    x = 10;
    int y = x;

    x = 20;

    printf("%i %i\n", x, y);


    ETAPA 4:
     int x = 10;
    int *ponteiro;
    ponteiro = &x;
    int y = 20;
    *ponteiro = y;

    printf("%i %i\n", x, y);



    ETAPA 5

      int x = 10;
    float y = 20.50;
    char z = 'a';

    int *pX;
    pX = &x;
    double *pY = &y;
    char *pZ = &z;


    printf("Endereço X = %d - Valor X = %i", pX, *pX);
    printf("Endereço Y = %f - Valor Y = %f", pY, *pY);
    printf("Endereço Z = %C - Valor Z = %C", pZ, *pZ);

    ETAPA 6:
        int x = 10;
    float y = 20.50;
    char z = 'a';

    int *pX;
    pX = &x;
    float *pY = &y;
    char *pZ = &z;

    float soma = *pX + *pY;

    printf("%f", soma);


ETAPA 7
int main()
{
    int x = 10;
    float y = 20.50;
    char z = 'a';

    int *pX;
    pX = &x;
    float *pY = &y;
    char *pZ = &z;

    int *resultado = &x;
    //int *resultado = 6422012;




    printf("%d", resultado);

}



ETAPA 8


int main()
{
    int x = 10;
    float y = 20.50;
    char z = 'a';

    int *pX;
    pX = &x;
    float *pY = &y;
    char *pZ = &z;

   // int *resultado = &x;
    int *resultado = 6422012;



		printf("%d", resultado);
    //printf("%d", *resultado);
	

}








*/

