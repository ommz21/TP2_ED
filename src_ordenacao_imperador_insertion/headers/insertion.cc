#include "insertion.h"
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
    planetas.push_back(p);
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
void ArranjoPlanetas::InsertionSort()
{
    int j;
    Planeta aux;
    for (int i = 1; i < tamanho; i++)
    {
        aux = planetas[i];
        j = i - 1;
        while(( j >= 0 ) && (aux.GetDistancia() <= planetas[j].GetDistancia()))
        {
            if(aux.GetDistancia() == planetas[j].GetDistancia() && aux.GetPopulacao() < planetas[j].GetPopulacao())
                break;
            planetas[j + 1] = planetas[j];
            j--;
        }
        planetas[j + 1] =aux;
        //Imprime();
    }
}