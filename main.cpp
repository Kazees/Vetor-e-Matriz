#include <iostream>
#include <vetor.h>
#include <matriz.h>

using namespace std;

int main()
{
    int ok=1;

    while(ok!=0)
    {
        try
        {
            //Vetor:
            int num,vetam1,vetam2,resp;

            cout<<"Digite o tamanho do vetor 1: ";
            cin>>vetam1;

            cout<<"Digite o tamanho do vetor 2: ";
            cin>>vetam2;

            Vetor <int> n1(vetam1);
            Vetor <int> n2(vetam2);

            cout<<"Elementos do primeiro vetor: ";
            cin>>n1;

            cout<<"Elementos do segundo vetor: ";
            cin>>n2;

            cout<<"Numero para fazer o escalar: ";
            cin>>num;

            n1.setElementos(1,90);

            cout<<endl<<"Primeiro vetor:"<<n1<<endl;
            cout<<"Segundo vetor: "<<n2<<endl;

            cout<<"Digite 1 para multiplicar apenas um dos vetores pelo escalar "<<endl;
            cout<<"Digite 2 para multiplicar os dois vetores pelo escalar "<<endl;
            cin>>resp;

            cout<<endl<<"Adição: "<<n1+n2<<endl;
            cout<<"Subtração: "<<n1-n2<<endl;
            cout<<"Multiplicação de dois vetores: "<<n1*n2<<endl;

            if(resp==1)
            {
                cout<<endl<<"Digite 1 para multiplicar o primeiro vetor pelo escalar "<<endl;
                cout<<"Digite 2 para multiplicar o segundo vetor pelo escalar "<<endl;
                cin>>resp;

                if(resp==1)
                {
                    cout<<"Multiplicação escalar do primeiro vetor: "<<n1*num<<endl;
                }

                else
                {
                    cout<<"Multiplicação escalar do segundo vetor: "<<n2*num<<endl;
                }
            }

            else
            {
                cout<<"Multiplicação escalar do primeiro vetor: "<<n1*num<<endl;
                cout<<"Multiplicação escalar do segundo vetor: "<<n2*num<<endl;
            }

            cout<<endl<<"Digite 1 para fazer o primeiro veto receber os elementos do segundo vetor"<<endl;
            cout<<"Digite 2 para fazer o segundo vetor receber os elementos do primeiro vetor"<<endl;
            cin>>resp;

            if(resp==1)
            {
                n1=n2;
            }

            else
            {
                n2=n1;
            }

            cout<<endl<<"Primeiro vetor:"<<n1<<endl;
            cout<<"Segundo vetor: "<<n2<<endl;


            //Matriz:
            int linha1,coluna1,linha2,coluna2;
            num=resp=0;

            cout<<endl<<"Digite o numero de linhas da matriz 1: ";
            cin>>linha1;

            cout<<"Digite o numero de colunas da matriz 1: ";
            cin>>coluna1;

            cout<<endl<<"Digite o numero de linhas da matriz 2: ";
            cin>>linha2;

            cout<<"Digite o numero de colunas da matriz 2: ";
            cin>>coluna2;

            Matriz <int> m1(linha1,coluna1);
            Matriz <int> m2(linha2,coluna2);

            cout<<endl<<"Elementos da primeira matriz: ";
            cin>>m1;

            cout<<"Elementos do segunda matriz: ";
            cin>>m2;

            cout<<"Numero para fazer o escalar: ";
            cin>>num;

            cout<<"Digite 1 para multiplicar apenas uma das matrizes pelo escalar "<<endl;
            cout<<"Digite 2 para multiplicar as duas matrizes pelo escalar "<<endl;
            cin>>resp;

            cout<<endl<<"Primeira matriz: "<<endl<<m1<<endl;
            cout<<"Segunda matriz: "<<endl<<m2<<endl;

            cout<<endl<<"Adição: "<<endl<<m1+m2<<endl;
            cout<<"Subtração: "<<endl<<m1-m2<<endl;
            cout<<"Multiplicação das duas matrizes: "<<endl<<m1*m2<<endl;

            if(resp==1)
            {
                cout<<endl<<"Digite 1 para multiplicar a primeira matriz pelo escalar "<<endl;
                cout<<"Digite 2 para multiplicar a segunda matriz pelo escalar "<<endl;
                cin>>resp;

                if(resp==1)
                {
                    cout<<"Multiplicação escalar da primeira matriz: "<<endl<<m1*num<<endl;
                }

                else
                {
                    cout<<"Multiplicação escalar segunda matriz: "<<endl<<m2*num<<endl;
                }
            }

            else
            {
                cout<<"Multiplicação escalar da primeira matriz: "<<endl<<m1*num<<endl;
                cout<<"Multiplicação escalar segunda matriz: "<<endl<<m2*num<<endl;
            }

            cout<<endl<<"Digite 1 para fazer a primeira matriz receber os elementos da segunda matriz"<<endl;
            cout<<"Digite 2 para fazer a segunda matriz receber os elementos da primeira matriz"<<endl;
            cin>>resp;

            if(resp==1)
            {
                m1=m2;
            }

            else
            {
                m2=m1;
            }

            cout<<endl<<"Primeira matriz:"<<m1<<endl;
            cout<<"Segunda matriz: "<<m2<<endl;

            ok=0;
        }

        catch (string &erro)
        {
            cout<<erro<<endl;
            ok=1;
        }
    }

    return 0;
}
