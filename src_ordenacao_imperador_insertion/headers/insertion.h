#ifndef INSERTION_H
#define INSERTION_H
#include <string>

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
        static const int MAXTAM = 200;
        Planeta planetas[MAXTAM];
        int tamanho;
};

#endif /* INSERTION_H */