#include "selection.h"
#include <iostream>

/*Implementacao dos metodos da classe Planeta.*/
Planeta::Planeta()
{
    nome = " ";
    distancia = -1;
    populacao = -1;
}
Planeta::Planeta(std::string n, int d, int p)
{
    nome = n;
    distancia = d;
    populacao = p;
}
std::string Planeta::GetNome()
{
    return nome;
}
int Planeta::GetDistancia()
{
    return distancia;
}
int Planeta::GetPopulacao()
{
    return populacao;
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
    if(tamanho == MAXTAM)
        throw std::invalid_argument("ERRO: Lista cheia!");
    planetas[tamanho] = p;
    tamanho++;
}
void ArranjoPlanetas::Imprime()
{
    for(int i = 0; i < tamanho; i++)
        planetas[i].Imprime();
}
void ArranjoPlanetas::Limpa()
{
    tamanho = 0;
}
void ArranjoPlanetas::Troca(int i, int j)
{
    Planeta aux = planetas[i];
    planetas[i] = planetas[j];
    planetas[j] = aux;
    //Imprime();
}
void ArranjoPlanetas::SelectionSort()
{
    int min;
    for(int i = 0; i < tamanho - 1; i++)
    {
        min = i;
        for(int j = i + 1 ; j < tamanho; j++)
            if(planetas[j].GetDistancia() < planetas[min].GetDistancia())
                min = j;
            else if(planetas[j].GetDistancia() == planetas[min].GetDistancia() && planetas[j].GetPopulacao() > planetas[min].GetPopulacao())
                min = j;
        Troca(i, min);
    }
}