// Suma de Arreglos Paralela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

// Sección 1. Implementación de las librerías, creación de las constantes y creación del prototipo de la función.
#include <iostream>
#include <omp.h>

#define CE 1000 // CE es la cantidad de elementos a manejar en los arreglos.
#define SP 100 // SP es el tamaño que tendrán los pedazos de los arreglos para que cada hilo creado se encargue de esta cantidad de elementos.
#define Control 10 //Control, permite manejar la cantidad de datos a imprimir.

void imprimeArreglo(float* d); // Función encargada de imprimir los arreglos

int main()
{
    // Sección 2. Creación de arreglos y asignación de valores.
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[CE], b[CE], c[CE]; // Declaración de 3 arreglos, a los arreglos a y b se les asignan valores, mientras que el arreglo c almacenara el resultado de la suma de los dos primeros arreglos.
    int i;

    for (i = 0; i < CE; i++)
    {
        a[i] = i * 10; // Asignación de valor al arreglo A.
        b[i] = (i + 3) * 3.7; // Asignación de valor al arreglo B.
    }
    int pedazos = SP;

    // Sección 3. Creación de un for paralelo con OpenMP
#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos) 

        for (i = 0; i < CE; i++) // Instrucción for de la suma de arreglos.
            c[i] = a[i] + b[i];

    // Sección 4. Impresión de los arreglos.
    std::cout << "Imprimiendo los primeros" << Control << " valores del arreglo a: " << std::endl; // Imprimimos parte de los arreglos de a.
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros" << Control << " valores del arreglo b: " << std::endl; // Imprimimos parte de los arreglos de b.
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros" << Control << " valores del arreglo c: " << std::endl; // Imprimimos parte de los arreglos de c.
    imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < Control; x++)
        std::cout << d[x] << "-";
    std::cout << std::endl;
}