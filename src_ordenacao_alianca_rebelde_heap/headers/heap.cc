#include "heap.h"
#include <iostream>

/*Implementacao dos metodos da classe Planeta.*/
Planeta::Planeta()
{
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
    printf("%s ", nome);
    printf("%d ", distancia);
    printf("%d\n", populacao);
}

/*Implementacao dos metodos da classe ArranjoPlanetas.*/
ArranjoPlanetas::ArranjoPlanetas()
{
    tamanho = 0;
}
ArranjoPlanetas::~ArranjoPlanetas()
{
    for(int i = 0; i < tamanho; i++)
        delete planetas[i];
}
void ArranjoPlanetas::InsereFinal(Planeta p)
{
    Planeta *novo = new Planeta(p.GetNome(), p.GetDistancia(), p.GetPopulacao());
    planetas.push_back(novo);
    tamanho++;
}
void ArranjoPlanetas::Imprime()
{
    for(int i = 0; i < tamanho; i++)
        planetas[i]->Imprime();
}
void ArranjoPlanetas::Limpa()
{
    tamanho = 0;
}
void ArranjoPlanetas::RefazHeap(int Esq, int Dir)
{
    int i, j;
    Planeta *x;
    i = Esq;
    j = ((i + 1) * 2) - 1;
    x = planetas[i];
    while (j <= Dir)
    {
        if(j < Dir)
        {
            if(planetas[j]->GetDistancia() < planetas[j + 1]->GetDistancia())
                j++;
            else if(planetas[j]->GetDistancia() == planetas[j + 1]->GetDistancia() && planetas[j]->GetPopulacao() > planetas[j + 1]->GetPopulacao())
                j++;
        }
        if(x->GetDistancia() > planetas[j]->GetDistancia())
            break;
        else if(x->GetDistancia() == planetas[j]->GetDistancia() && x->GetPopulacao() <= planetas[j]->GetPopulacao())
            break;
        planetas[i] = planetas[j];
        i = j;
        j = ((i + 1) * 2) - 1;
    }
    planetas[i] = x;
}
void ArranjoPlanetas::ConstroiHeap()
{
    int Esq;
    Esq = (tamanho / 2);
    while(Esq > 0)
    {
        Esq--;
        RefazHeap(Esq, tamanho-1);
    }
}
void ArranjoPlanetas::HeapSort()
{
    int Esq, Dir;
    Planeta *x;
    ConstroiHeap(); // constroi o heap 
    Esq = 0;
    Dir = tamanho - 1;
    while(Dir > 0) // ordena o vetor 
    { 
        x = planetas[0];
        planetas[0] = planetas[Dir];
        planetas[Dir] = x;
        //Imprime();
        Dir--;
        RefazHeap(Esq, Dir);
    }
}