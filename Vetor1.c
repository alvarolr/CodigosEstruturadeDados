#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idade;
    printf("Digite a sua idade\n");
    scanf("%d", &idade);

    if(idade >= 18){
        printf("Você é maior de idade, vai pagar as contas de casa!");
    }else{
        printf("Criança ainda...");
    }
}



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float notas[11];

    for (int i=0; i < 11; i++){
        printf("Digite o valor da nota[%d]", i);
        scanf("%f", &notas[i] );
    }

        for (int i=0; i < 11; i++){
        printf(" O valor da nota[%d] foi %.2f\n", i, notas[i]);
    }


}










  /*
    int vetor[5] = {10, 5, 12, 17, 10};

    printf("%d", vetor[4]);


      float notas[11] = {10, 5, 9, 2, 10, 5, 4, 4, 4, 8, 10};

    for (int i=0; i <= 10; i++){
        printf("O valor da nota [%d] é igual a %.2f \n", i, notas[i]);
    }

   */
