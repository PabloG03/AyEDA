/* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoritmos y Estructuras de Datos Avanzadas
* Curso: 2º
* Práctica 3
* Autor: Pablo García Pérez
* Correo: alu0101496139@ull.edu.es
* Fecha: 07/03/2024
* source Autómata celular general
*/

#pragma once

#include<iostream>

/*
* @brief Método de ordenación por selección
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param sequence Secuencia de elementos
* @param size Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<class Key> void Seleccion_sort(staticSequence<Key>& sequence, int size, bool traza) {
  int min;
  int comparaciones_ = 0;
  int intercambios_ = 0;
  
  for (int i = 0; i < size - 1; i++) {
    min = i;
    for (int j = i + 1; j < size; j++) {
      comparaciones_++;
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }

    if (min != i) {
      Key aux = sequence[i];
      sequence[i] = sequence[min];
      sequence[min] = aux;
      intercambios_++;
    }

    if (traza == true) {
      std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Iteración " << i + 1 << std::endl;
      std::cout << "Intercambio: " << sequence[i] << " con " << sequence[min] << std::endl;
      std::cout << "Secuencia: ";
      for (int i = 0; i < size; i++) std::cout << sequence[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
  }
  
  std::cout << "Secuencia ordenada: ";
  for (int i = 0; i < size; i++) std::cout << sequence[i] << " ";
  std::cout << std::endl;
  std::cout << "Comparaciones: " << comparaciones_ << std::endl;
  std::cout << "Intercambios: " << intercambios_ << std::endl;
    
}

/*
* @brief Método de ordenación por burbuja
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param sequence Secuencia de elementos
* @param size Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<class Key> 
void Heapify(staticSequence<Key>& sequence, int size, int root, int comparaciones_, int intercambios_) {
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;
  
  if (left < size && sequence[left] > sequence[largest])
    comparaciones_++;
    largest = left;

  if (right < size && sequence[right] > sequence[largest])
    comparaciones_++;
    largest = right;

  if (largest != root) {
    intercambios_++;
    std::swap(sequence[root], sequence[largest]);
    Heapify(sequence, size, largest, comparaciones_, intercambios_);
  }
}

/*
* @brief Método de ordenación por montículos
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param sequence Secuencia de elementos
* @param n Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<class Key>  void Heap_sort(staticSequence<Key>& sequence, int n, float traza) {
  int contador = 0;
  int comparaciones_ = 0;
  int intercambios_ = 0;

  for (int i = n / 2 - 1; i >= 0; i--) {
    Heapify(sequence, n, i, comparaciones_, intercambios_);
    if (traza == true) {
      std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Iteración " << contador << std::endl;
      std::cout << "Secuencia: ";
      for (int i = 0; i < n; i++) std::cout << sequence[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
    contador++;
  }
  for (int i = n - 1; i > 0; i--) {
    std::swap(sequence[0], sequence[i]);
    Heapify(sequence, i, 0, comparaciones_, intercambios_);
    
    if (traza == true) {
      std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Iteración " << contador << std::endl;
      std::cout << "Secuencia: ";
      for (int i = 0; i < n; i++) std::cout << sequence[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
    contador++;
  }

  std::cout << "Secuencia Ordenada: ";
  for (int i = 0; i < n; i++) std::cout << sequence[i] << " ";
  std::cout << std::endl;
  std::cout << "Comparaciones: " << comparaciones_ << std::endl;
  std::cout << "Intercambios: " << intercambios_ << std::endl;
}

/*
* @brief Método de ordenación por inserción
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param sequence Secuencia de elementos
* @param size Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<typename Key> int Partition(staticSequence<Key>& sequence, int low, int high, int comparaciones_, int intercambios_) {
  Key pivot = sequence[high]; // Tomamos el último elemento como pivote
  int i = low - 1; // Índice del menor elemento

  for (int j = low; j <= high - 1; j++) {
    comparaciones_++;
    if (sequence[j] <= pivot) {
      i++; // Incrementa el índice del menor elemento
      std::swap(sequence[i], sequence[j]);
      intercambios_++;
    }
  }
  std::swap(sequence[i + 1], sequence[high]);
  intercambios_++;
  return i + 1;
}

/*
* @brief Método de ordenación QuickSort
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param sequence Secuencia de elementos
* @param low Índice del primer elemento
* @param high Índice del último elemento
* @param traza Muestra la traza
* @return void
*/
template<typename Key> void Quick_sort(staticSequence<Key>& sequence, int low, int high, float traza, int& comparaciones_, int& intercambios_) {
  intercambios_++;
  if (low < high) {
    comparaciones_++;
    int pi = Partition(sequence, low, high, comparaciones_, intercambios_);

    // Ordenar los elementos antes y después del pivote
    Quick_sort(sequence, low, pi - 1, traza, comparaciones_, intercambios_);

    // Imprimir la traza parcial
    if (traza > 0.0f) {
       std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Secuencia parcialmente ordenada (izquierda):" << std::endl;
      for (int i = low; i < pi; ++i) std::cout << sequence[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
    
    Quick_sort(sequence, pi + 1, high, traza, comparaciones_, intercambios_);

    // Imprimir la traza parcial
    if (traza > 0.0f) {
      std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Secuencia parcialmente ordenada (derecha):" << std::endl;
      for (int i = pi + 1; i <= high; ++i) std::cout << sequence[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
  } 

  // Si se desea imprimir la secuencia completa al final
  if (low == 0 && high == sequence.getSize() - 1 && traza) {
    std:: cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << "Secuencia ordenada final:" << std::endl;
    for (int i = low; i <= high; ++i) std::cout << sequence[i] << " ";
    std::cout << std::endl;
  }
}

/*
* @brief Método de ordenación por Shell
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param seq Secuencia de elementos
* @param alfa Factor de reducción
* @param size Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<typename Key> void Shell_sort(staticSequence<Key> &seq, float alfa, int size, float traza) {
  int comparaciones_ = 0;
  int intercambios_ = 0;
  int delta = seq.getSize() * alfa;
  while (delta > 0) {
    for (long unsigned int i = delta; i < seq.getSize(); i++) {
      comparaciones_++;
      int j = i;
      int temp = seq[i].getINT();
      while (j >= delta && seq[j - delta] > temp) {
        comparaciones_++;
        intercambios_++;
        seq[j] = seq[j - delta];
        j = j - delta;
      }
      seq[j] = temp;
    }
    if (delta == 2) {
      delta = 1;
    } else {
      delta = delta * alfa;
    } 

    if (traza == true) {
      std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Secuencia: ";
      for (int i = 0; i < size; i++) std::cout << seq[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
  }

  std::cout << "Secuencia ordenada: ";
  for (int i = 0; i < size; i++) std::cout << seq[i] << " ";
  std::cout << std::endl;
  std::cout << "Comparaciones: " << comparaciones_ << std::endl;
  std::cout << "Intercambios: " << intercambios_ << std::endl;
}

/*
* @brief Método de ordenación por Radix
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param seq Secuencia de elementos
* @param size Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<typename Key>int getMax(staticSequence<Key>& seq, int size, int& comparaciones_, int& intercambios_) {
  int max = seq[0].getINT();
  for (int i = 1; i < size; i++) {
    comparaciones_++;
    if (seq[i] > max) {
      max = seq[i].getINT();
    }
  }
  return max;
}

/*
* @brief Método de ordenación por Radix
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param seq Secuencia de elementos
* @param size Tamaño de la secuencia
* @param exp Exponente
* @return void
*/
template<typename Key>void countSort(staticSequence<Key>& seq, int size, int exp, int& comparaciones_, int& intercambios_) {
  std::vector<Key> output(size); // Arreglo de salida
  int count[10] = {0}; // Inicializamos el arreglo de conteo con 0

  // Almacenamos la cantidad de cada dígito en el arreglo de conteo
  for (int i = 0; i < size; i++) {
    count[(seq[i].getINT() / exp) % 10]++;
  }

  // Cambiamos el arreglo de conteo para que contenga las posiciones reales de los dígitos
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Construimos el arreglo de salida
  for (int i = size - 1; i >= 0; i--) {
    output[count[(seq[i].getINT() / exp) % 10] - 1] = seq[i];
    count[(seq[i].getINT() / exp) % 10]--;
  }

  // Copiamos el arreglo de salida al arreglo original
  for (int i = 0; i < size; i++) {
    intercambios_++;
    seq[i] = output[i];
  }
}

/*
* @brief Método de ordenación por Radix
* @tparam Key Tipo de dato de los elementos de la secuencia
* @param seq Secuencia de elementos
* @param size Tamaño de la secuencia
* @param traza Muestra la traza
* @return void
*/
template<typename Key>void Radix_sort(staticSequence<Key>& seq, int size, float traza) {
  int comparaciones_ = 0;
  int intercambios_ = 0;
  // Encontramos el dígito máximo para determinar el número de dígitos
  int max = getMax(seq, size, comparaciones_, intercambios_);

  // Realizamos el conteo para cada dígito, empezando desde el dígito menos significativo
  for (int exp = 1; max / exp > 0; exp *= 10) {
    countSort(seq, size, exp, comparaciones_, intercambios_);

    // Si se desea imprimir la traza
    if (traza) {
      std:: cout << "--------------------------------------------------------------------------" << std::endl;
      std::cout << "Secuencia parcialmente ordenada (exp = " << exp << "):" << std::endl;
      for (int i = 0; i < size; ++i) std::cout << seq[i] << " ";
      std::cout << std::endl;
      std::cout << std::endl;
    }
  }

  // Si se desea imprimir la secuencia completa al final
  std::cout << "--------------------------------------------------------------------------" << std::endl;
  std::cout << "Secuencia ordenada final:" << std::endl;
  for (int i = 0; i < size; ++i) std::cout << seq[i] << " ";
  std::cout << std::endl;
  std::cout << "Comparaciones: " << comparaciones_ << std::endl;
  std::cout << "Intercambios: " << intercambios_ << std::endl;
}