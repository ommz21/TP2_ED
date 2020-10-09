#include "quick.h"
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
void ArranjoPlanetas::ParticaoQuick(int esq, int dir, int &i, int &j)
{
    Planeta x, w;
    i = esq;
    j = dir;
    x = planetas[(i + j)/2]; //obtem o pivo x 
    do
    {
        while(x.GetDistancia() >= planetas[i].GetDistancia())
        {
            if(x.GetDistancia() == planetas[i].GetDistancia() && x.GetPopulacao() >= planetas[i].GetPopulacao())
                break;
            i++;
        }
        while(x.GetDistancia() <= planetas[j].GetDistancia())
        {
            if(x.GetDistancia() == planetas[j].GetDistancia() && x.GetPopulacao() <= planetas[j].GetPopulacao())
                break;
            j--;
        }
        if(i <= j)
        {
            w = planetas[i];
            planetas[i] = planetas[j];
            planetas[j] = w;
            i++;
            j--;
        }
    } while (i <= j);
}
void ArranjoPlanetas::Quick(int esq, int dir)
{
    int i, j;
    //Imprime();
    ParticaoQuick(esq, dir, i, j);
    if (esq < j)
        Quick(esq, j);
    if (i < dir)
        Quick(i, dir);
}
void ArranjoPlanetas::QuickSort()
{
    Quick(0, tamanho - 1);
}