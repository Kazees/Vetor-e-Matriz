#ifndef VETOR_H
#define VETOR_H
#include <iostream>
using namespace std;

template <typename T>
class Vetor
{
private:
    int tamanho;
    T *array;

public:
    Vetor();
    Vetor(int tamanho):tamanho(0),array(0)
    {
        if(tamanho<=0)
        {
            throw string("Tamanho inválido.");
        }

        try
        {
            this->tamanho=tamanho;
            array=new T[tamanho];
        }

        catch (bad_alloc &erro)
        {
            throw string("Não foi possível criar vetor.");
        }
    }

    Vetor(const Vetor<T>& copia); //Construtor de cópia

    ~Vetor()
    {
        if(array)
        {
            delete []array;
        }
    }

    int getTamanho()const {return tamanho;}

    T setElementos(int indice,int num)
    {
        if(indice<0||indice>=tamanho)
        {
            throw string("Posição inválida.");
        }

        return *(array+indice)=num;
    }

    Vetor& operator = (const Vetor<T>& n2)
    {
        if(this!=&n2) //ponteiro implícito que aponta para a instância atual do objeto no qual um método está sendo chamado e acessar membros do objeto atual ajudando a evitar ambiguidades
        {
            if(tamanho!=n2.getTamanho())
            {
                throw string("Tamanho diferente.");
            }
        }

        for (int i = 0;i<tamanho; ++i)
        {
            array[i]=n2.array[i];
        }

        return *this; //referenciar o próprio objeto,convertendo ele de um ponteiro para um objeto real permitimdo o encadeamento de operações como: como objeto.setValor(10).setOutroValor(20);
    }

    Vetor operator + (const Vetor<T>& n2)const
    {
        if(tamanho!=n2.tamanho)
        {
            throw string("Tamanho diferente.");
        }

        Vetor<T> resultado(tamanho);

        for (int i=0;i<tamanho; ++i)
        {
            resultado.array[i]=*(array+i)+n2.array[i];
        }

        return resultado;
    }

    Vetor operator - (const Vetor<T>& n2)const
    {
        if(tamanho!=n2.getTamanho())
        {
            throw string("Tamanho diferente.");
        }

        Vetor resultado(tamanho);

        for (int i = 0;i<tamanho; ++i)
        {
            resultado.array[i]=*(array+i)-n2.array[i];
        }

        return resultado;
    }

    Vetor operator * (const Vetor<T>& n2)const
    {
        if(tamanho!=n2.getTamanho())
        {
            throw string("Tamanho diferente.");
        }

        Vetor<T> resultado(tamanho);

        for (int i = 0;i<tamanho; ++i)
        {
            resultado.array[i]=*(array+i)*n2.array[i];
        }

        return resultado;
    }

    Vetor operator * (int num)const
    {
        Vetor<T> resultado(tamanho);

        for (int i = 0; i<tamanho; ++i)
        {
            resultado.array[i]=*(array+i)*num;
        }

        return resultado;
    }

    T operator [](int indice)const
    {
        if(indice<0||indice>=tamanho)
        {
            throw string("Posição inválida.");
        }

        return *(array+indice);
    }


    friend ostream& operator << (ostream& out,const Vetor<T> &n1)
    {

        for(int i=0;i<n1.getTamanho();i++)
        {
            out<<n1.array[i]<<" ";
        }

        return out;

    }
    friend istream& operator >> (istream& in,Vetor<T> &n1)
    {

        for(int i=0;i<n1.getTamanho();i++)
        {
            in>>n1.array[i];
        }

        return in;

    }
};

#endif // VETOR_H
