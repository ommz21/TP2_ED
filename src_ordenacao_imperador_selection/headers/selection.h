#ifndef SELECTION_H
#define SELECTION_H
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
        void Troca(int i, int j);
        void SelectionSort();

    private:
        //static const int MAXTAM = 200;
        std::vector<Planeta> planetas;
        int tamanho;
};

#endif /* SELECTION_H */