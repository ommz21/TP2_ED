#include "quick.h"
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
void ArranjoPlanetas::ParticaoQuick(int esq, int dir, int &i, int &j)
{
    Planeta x("", -1, -1);
    Planeta w("", -1, -1);
    i = esq;
    j = dir;
    //Obtem o pivo x
    x = planetas[(i + j)/2]; 
    do
    {
        //Adaptacao para incluir na logica do quick sort o fato de que dois planetas com a mesma
        //distancia mas o que possuir a menor populacao deve ficar mais a direita na lista
        while(x.distancia >= planetas[i].distancia)
        {
            if(x.distancia == planetas[i].distancia && x.populacao >= planetas[i].populacao)
                break;
            i++;
        }
        while(x.distancia <= planetas[j].distancia)
        {
            if(x.distancia == planetas[j].distancia && x.populacao <= planetas[j].populacao)
                break;
            j--;
        }
        if(i <= j)
        {
            //Troca os planetas toda vez que for necessario a partir das comparacoes com o pivo
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
    //Particiona o vetor atual
    ParticaoQuick(esq, dir, i, j);
    //Faz as chamadas recursivas para os subvetores a esquerda e a direita da particao
    if (esq < j)
        Quick(esq, j);
    if (i < dir)
        Quick(i, dir);
}
void ArranjoPlanetas::QuickSort()
{
    //Chamada necessaria para que se inicie a ordenacao e quando todas as chamadas recursivas
    //terminarem o vetor estara ordenado
    Quick(0, tamanho - 1);
}