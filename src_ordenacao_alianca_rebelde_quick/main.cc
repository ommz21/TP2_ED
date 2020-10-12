#include <iostream>
#include "headers/quick.h"
#include <bits/stdc++.h> 

int main()
{
    /* clock_t clock(void) returns the number of clock ticks 
       elapsed since the program was launched.To get the number  
       of seconds used by the CPU, you will need to divide by  
       CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical 
       32 bit system.  */
    clock_t start, end;   
    /* Recording the starting clock tick.*/
    start = clock(); 

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
    lista.Imprime();

    // Recording the end clock tick. 
    end = clock(); 
    // Calculating total time taken by the program. 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    std::cout << std::endl << "Time taken by program is : " << std::fixed << time_taken << std::setprecision(5); 
    std::cout << " sec"; 

    return 0;
}