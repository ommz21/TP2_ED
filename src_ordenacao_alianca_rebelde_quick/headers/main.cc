#include <iostream>
#include "quick.h"

int main()
{
    int num_planetas, distancia, populacao;
    std::string nome;
    ArranjoPlanetas lista;
    //Leitura da quantidade de planetas e dos suas respectivas caracteristicas
    scanf("%d",&num_planetas);
    for(int i = 0; i < num_planetas; i++)
    {
        std::cin >> nome;
        std::cin >> distancia;
        std::cin >> populacao;
        //Armazena os planetas na lista por arranjos implementada pela classe ArranjoPlanetas
        Planeta p(nome, distancia, populacao);
        lista.InsereFinal(p);
    }
    lista.QuickSort();
    printf("\n");
    lista.Imprime();
    return 0;
}