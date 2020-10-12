#ifndef INSERTION_H
#define INSERTION_H
#include <string>
#include <vector>

/*Assinatura dos atributos e metodos da classe Planeta*/
class Planeta
{
    public:
        Planeta(std::string n, int d, int p);
        void Imprime();
    
    private:
        std::string nome;
        int distancia;
        int populacao;

    //Permite que a lista de planetas possa acessar os atributos privados de Planeta
    friend class ArranjoPlanetas;
};

/*Assinatura dos atributos e metodos da classe ArranjoPlanetas*/
class ArranjoPlanetas
{
    public:
        ArranjoPlanetas();
        void InsereFinal(Planeta p);
        void Imprime();
        void InsertionSort();

    private:
        //Utiliza vector para nao ocorrer erros ao alocar muita memória(9.in = 2000000 posicoes)
        std::vector<Planeta> planetas;
        int tamanho;
};

#endif /* HEAP_H */