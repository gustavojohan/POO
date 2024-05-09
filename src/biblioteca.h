#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "livro.h"

class Biblioteca{
    std::vector<Livro*> livros;

public:
    Biblioteca(const std::vector<Livro*>& l);
    ~Biblioteca();

    void adicionar_livro(Livro* l);
    void remover_livro(Livro* l);

    Biblioteca& operator+(Livro* l);
    Biblioteca& operator-(Livro* l);

    void print_info() const;
};

#endif
