#include "heap.h"
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
void ArranjoPlanetas::RefazHeap(int Esq, int Dir)
{
    int i, j;
    Planeta x(" ", -1, -1);
    i = Esq;
    //Adaptacao da conta vista em aula para considerar o vetor comecando da posicao 0
    j = ((i + 1) * 2) - 1;
    x = planetas[i];
    while (j <= Dir)
    {
        if(j < Dir)
        {
            if(planetas[j].distancia < planetas[j + 1].distancia)
                j++;
            //Possui essa comparacao extra para verificar se quando os filhos possuem a mesma distancia,
            //deve ser o candidato a ser trocado com o pai o que possuir a menor populacao 
            else if(planetas[j].distancia == planetas[j + 1].distancia && planetas[j].populacao > planetas[j + 1].populacao)
                j++;
        }
        //Alem de verificar que nao se deve trocar o pai caso ele possua maior distancia
        //do que seus filhos, o segundo break é para quando a distancia for igual mas o pai
        //possuir uma populacao menor, pois ao final da ordenacao esse pai ira ficar maiis a
        //direita dos seus filhos.
        if(x.distancia > planetas[j].distancia)
            break;
        else if(x.distancia == planetas[j].distancia && x.populacao <= planetas[j].populacao)
            break;
        planetas[i] = planetas[j];
        i = j;
        //Adaptacao da conta vista em aula para considerar o vetor comecando da posicao 0
        j = ((i + 1) * 2) - 1;
    }
    planetas[i] = x;
}
void ArranjoPlanetas::ConstroiHeap()
{
    int Esq;
    //Constroi o heap utilizando o vetor todo e considerando como posicao inicial o 0
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
    Planeta x(" ", -1, -1);
    ConstroiHeap(); 
    Esq = 0;
    Dir = tamanho - 1;
    //Utiliza a funcao refaz para sempre que colocar o primeiro elemento da lista na posicao
    //correta correspondente a ordenacao, considera o heap uma posicao menor assim ordenando 
    //o vetor por completo
    while(Dir > 0) 
    { 
        x = planetas[0];
        planetas[0] = planetas[Dir];
        planetas[Dir] = x;
        Dir--;
        RefazHeap(Esq, Dir);
    }
}