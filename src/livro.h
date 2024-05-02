#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "autor.h"

class Livro{
    std::string titulo;
    int num_paginas;
    std::vector<Autor*> autores;
    

public:
    Livro(const std::string& n, int nP, Autor* );
    ~Livro();

    void set_titulo(const std::string& t);
    std::string& get_titulo();

    void set_num_paginas(int nP);
    int get_num_paginas();

    std::vector<Autor*> get_autores();


};

#endif