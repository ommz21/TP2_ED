#include "selection.h"
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
void ArranjoPlanetas::Troca(int i, int j)
{
    //Troca de posicao de dois planetas presentes no vetor 
    Planeta aux = planetas[i];
    planetas[i] = planetas[j];
    planetas[j] = aux;
}
void ArranjoPlanetas::SelectionSort()
{
    int min;
    for(int i = 0; i < tamanho - 1; i++)
    {
        min = i;
        for(int j = i + 1 ; j < tamanho; j++)
            //Descobre o planeta a ser trocado na atual instancia da ordenacao, sera o planeta
            //com a menor distancia e caso dois planetas possuam a mesma distancia o que possuir
            //a maior populacao sera selecionado para ficar mais a esquerda ao final da ordenacao
            if(planetas[j].distancia < planetas[min].distancia)
                min = j;
            else if(planetas[j].distancia == planetas[min].distancia && planetas[j].populacao > planetas[min].populacao)
                min = j;
        Troca(i, min);
    }
}