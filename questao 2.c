#include <stdio.h>
#include <math.h>

struct investimentos {
    int meses;
    double investimento;
    double juros;
};

int main() {
    struct investimentos dados;

    scanf("%d",&dados.meses);
    scanf("%lf",&dados.investimento);
    scanf("%lf",&dados.juros);

    for(int i = 1; i <= dados.meses; i++){
        double retorno = dados.investimento*(1+dados.juros)*(((pow((1+dados.juros), i))-1)/dados.juros);
        printf("Montante ao fim do mes %d: R$ %.2f\n",i,retorno);

    }
    return 0;
}