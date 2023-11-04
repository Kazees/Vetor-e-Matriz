#include "matriz.h"

template <typename T>
Matriz<T>::Matriz():linha(0),coluna(0),mat(0)
{

}

template <typename T>
Matriz<T>::Matriz(const Matriz<T>& copia):linha(copia.linha),coluna(copia.coluna)
{
    mat=new T*[linha];

    for(int i=0;i<linha;i++) // Alocação dinâmica da matriz
    {
        mat[i]=new T[coluna];

        for(int j=0;j<coluna;j++)
        {
            mat[i][j]=copia.mat[i][j];
        }
    }
}
