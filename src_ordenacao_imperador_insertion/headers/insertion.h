#ifndef INSERTION_H
#define INSERTION_H
#include <string>
#include <vector>

typedef int TipoChave; //TipoChave é um inteiro

/*Assinatura dos atributos e metodos da classe Planeta*/
class Planeta
{
    public:
        Planeta();
        Planeta(std::string n, int d, int p);
        std::string GetNome();
        int GetDistancia();
        int GetPopulacao();
        void Imprime();
    
    private:
        std::string nome;
        int distancia;
        int populacao;
};

/*Assinatura dos atributos e metodos da classe ArranjoPlanetas*/
class ArranjoPlanetas
{
    public:
        ArranjoPlanetas();
        void InsereFinal(Planeta p);
        void Imprime();
        void Limpa();
        void InsertionSort();

    private:
        std::vector<Planeta> planetas;
        int tamanho;
};

#endif /* INSERTION_H */