#include "headers/heap.h"
#include <iostream>
#include <bits/stdc++.h> 

int main()
{
	//Inicia a contagem do tempo de execucao do programa
    clock_t start, end;
    start = clock(); 

    //Declaracao das variaveis utilizadas para leitura e armazenamento dos dados
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
        //Armazena os planetas na lista implementada pela classe ArranjoPlanetas
        Planeta p(nome, distancia, populacao);
        lista.InsereFinal(p);
    }
    //Ordena a lista e imprime na tela
    lista.HeapSort();
    lista.Imprime();
  
    //Termina a contagem do tempo de execucao do programa e imprime na tela o tempo total
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    std::cout << std::endl << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(5); 
    std::cout << " sec";

    return 0;
}