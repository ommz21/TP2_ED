#include "insertion.h"
#include <iostream>

/*Implementacao dos metodos da classe Planeta.*/
Planeta::Planeta(std::string n, int d, int p)
{
    nome = n;
    distancia = d;
    populacao = p;
}
void Planeta::Imprime()
{
    std::cout << nome << " " << distancia << " " << populacao << std::endl;
}

/*Implementacao dos metodos da classe ArranjoPlanetas.*/
ArranjoPlanetas::ArranjoPlanetas()
{
    tamanho = 0;
}
void ArranjoPlanetas::InsereFinal(Planeta p)
{
    planetas.push_back(p);
    tamanho++;
}
void ArranjoPlanetas::Imprime()
{
    for(int i = 0; i < tamanho; i++)
        planetas[i].Imprime();
}
void ArranjoPlanetas::InsertionSort()
{
    int j;
    Planeta aux("", -1, -1);
    for (int i = 1; i < tamanho; i++)
    {
        aux = planetas[i];
        j = i - 1;
        while(( j >= 0 ) && (aux.distancia <= planetas[j].distancia))
        {
            //Verifica o caso de distancias iguais caso o planeta que estamos querendo inserir
            //no vetor possua a mesma distancia que um outro planeta, porem sua populacao eh menor
            //entao achamos a posicao dele a direita do que possui a populacoa maior
            if(aux.distancia == planetas[j].distancia && aux.populacao < planetas[j].populacao)
                break;
            planetas[j + 1] = planetas[j];
            j--;
        }
        planetas[j + 1] =aux;
    }
}