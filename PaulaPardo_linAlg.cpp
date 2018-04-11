#include <stdlib.h>
#include <stdio.h>
#include <iostream>

float **matrix_product(float **A, int A_f, int A_c, float **B, int B_f, int B_c)  
{
    // Se asigna espacio en la memoria para la matriz "Multiplicacion" y se crea un vector
    float **Multiplicacion = (float **)malloc(A_f * sizeof(float *));
    
    // Cada elemento del vector anterior es un vector en si mismo. Multiplicacion = [[],[],...]
    for (int i=0; i<A_f; i++)
        Multiplicacion[i] = (float *)malloc(B_c * sizeof(float));
    
    // Se multiplican las matrices A y B
    for(int i=0; i<A_f; i++)
    {  
        for(int j=0; j<B_c; j++)
        {
            for(int k=0; k<B_f; k++)
            {
                Multiplicacion[i][j] += A[i][k]*B[k][j] ; 
            }
            
        }
    }
return Multiplicacion;
}

float **get_Matrix(int M, int N)
{
    // Se asigna espacio en la memoria para la matriz "Matriz" y se crea un vector
    float **Matriz = (float **)malloc(M * sizeof(float *));
    
    // Cada elemento del vector anterior es un vector en si mismo. Matriz = [[],[],...]
    for (int i=0; i<M; i++)
        Matriz[i] = (float *)malloc(N * sizeof(float));
    
    // Se imprimen las dimensiones de la matriz
    std::cout <<"Las dimensiones de la matriz son: "<<M<<","<<N<<std::endl;
    
    // Se asignan valores a matriz
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout <<"Introduzca el elemento matricial: "<<i<<","<<j<<std::endl;
            float elemento;
            std::cin >> elemento;
            Matriz[i][j] = elemento;
        }
    }

    // Imprime matriz
    std::cout << "La matriz que acabo de ingresar es: " <<std::endl;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout <<Matriz[i][j]<<" ";
        }
        std::cout << std::endl;
    }
return Matriz;
}


int main()
{
    int M_A = 5;
    int N_A = 2;
    int M_B = 2;
    int N_B = 3;

    std::cout << "Se van a introducir los valores de la matriz A: " <<std::endl;
    float **A = get_Matrix(M_A, N_A);
    std::cout << "Se van a introducir los valores de la matriz B: " <<std::endl;
    float **B = get_Matrix(M_B, N_B);

    float **Multiplicacion = matrix_product(A, M_A, N_A, B, M_B, N_B); 

    std::cout << "La multiplicacion de A y B es: " <<std::endl;
    for(int i=0; i<M_A; i++)
    {
        for(int j=0; j<N_B; j++)
        {
            std::cout <<Multiplicacion[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
