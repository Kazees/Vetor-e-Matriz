#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>

using namespace std;

template <typename T>
class Matriz
{
private:
    int linha;
    int coluna;
    T **mat; //Ponteiro para ponteiro

public:
    Matriz();
    Matriz(int linha,int coluna):linha(0),coluna(0),mat(0)
    {
        if(linha<=0 && coluna<=0)
        {
            throw string("Linhas ou colunas inválidas.");
        }

        try
        {
            this->linha=linha;
            this->coluna=coluna;

            mat=new T*[linha];

            for(int i=0;i<linha;i++) // Alocação dinâmica da matriz
            {
                mat[i]=new T[coluna];
            }
        }

        catch (bad_alloc &erro)
        {
            throw string("Não foi possível criar matriz.");
        }
    }

    Matriz(const Matriz<T>& copia);//Construtor de cópia

    ~Matriz()
    {
        if(mat)
        {
            for(int i=0;i<coluna;i++)
            {
                delete []mat[i];
            }

            delete []mat;
        }
    }

    int getLinha()const {return linha;}
    int getColuna()const {return coluna;}

    Matriz& operator = (const Matriz<T>& n2)
    {
        if(this!=&n2) //ponteiro implícito que aponta para a instância atual do objeto no qual um método está sendo chamado e acessar membros do objeto atual ajudando a evitar ambiguidades
        {
            if(linha!=n2.linha && coluna!=n2.coluna)
            {
                throw string("Matrizes diferentes.");
            }
        }

        for(int i=0;i<linha;i++)
        {
            for(int j=0;j<coluna;j++)
            {
                mat[i][j]=n2[i][j];
            }
        }

        return *this; //referenciar o próprio objeto,convertendo ele de um ponteiro para um objeto real permitimdo o encadeamento de operações como: como objeto.setValor(10).setOutroValor(20);
    }

    Matriz operator + (const Matriz<T>& n2)const
    {
        if(linha!=n2.linha && coluna!=n2.coluna)
        {
            throw string("Matrizes de ordens diferente.");
        }

        Matriz resultado(linha,coluna);

        for(int i=0;i<linha;i++)
        {
            for(int j=0;j<coluna;j++)
            {
                resultado[i][j]=mat[i][j]+n2[i][j];
            }
        }

        return resultado;
    }

    Matriz operator - (const Matriz<T>& n2)const
    {
        if(linha!=n2.linha && coluna!=n2.coluna)
        {
            throw string("Matrizes de ordens diferente.");
        }

        Matriz resultado(linha,coluna);

        for(int i=0;i<linha;i++)
        {
            for(int j=0;j<coluna;j++)
            {
                resultado[i][j]=mat[i][j]-n2[i][j];
            }
        }

        return resultado;
    }

    Matriz operator * (const Matriz<T>& n2)const
    {
        if(coluna!=n2.linha)
        {
            throw string("Matrizes de ordens diferente.");
        }

        Matriz resultado(linha,n2.coluna);

        for(int i=0;i<linha;i++)
        {
            for(int j=0;j<n2.coluna;j++)
            {
                resultado[i][j]=0;

                for(int k=0;k<coluna;k++)
                {
                    resultado[i][j]+=mat[i][k]*n2[k][j];
                }
            }
        }

        return resultado;
    }

    Matriz operator * (int num)const
    {
        Matriz resultado(linha,coluna);

        for(int i=0;i<linha;i++)
        {
            for(int j=0;j<coluna;j++)
            {
                resultado[i][j]=mat[i][j]*num;
            }
        }

        return resultado;
    }

    T* operator [](int indice)const
    {
        if(indice<0||indice>=linha)
        {
            throw string("Posição inválida.");
        }

        return mat[indice];
    }

    friend ostream& operator << (ostream& out,const Matriz& n1)
    {
        for(int i=0;i<n1.getLinha();i++)
        {
            for(int j=0;j<n1.getColuna();j++)
            {
                out<<n1[i][j]<<" ";
            }

            out<<endl;
        }

        return out;
    }

    friend istream& operator >> (istream& in,const Matriz& n1)
    {
        for(int i=0;i<n1.getLinha();i++)
        {
            for(int j=0;j<n1.getColuna();j++)
            {
                in>>n1[i][j];
            }
        }

        return in;
    }


};
#endif // MATRIZ_H
