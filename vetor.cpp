#include "vetor.h"

template <typename T>
Vetor<T>::Vetor():tamanho(0),array(0)
{

}

template <typename T>
Vetor<T>::Vetor(const Vetor<T>& copia):tamanho(0),array(0)
{
    tamanho=copia.tamanho;
    array=new T[tamanho];

    for (int i=0; i<tamanho;i++)
    {
        array[i] = copia.array[i];
    }
}



