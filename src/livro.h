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
    Livro(const std::string& t, int nP, const std::vector<Autor*>& a);
    ~Livro();

    void set_titulo(const std::string& t);
    std::string get_titulo() const;

    void set_num_paginas(int nP);
    int get_num_paginas() const;

    std::vector<Autor*> get_autores() const;
    Livro& operator+(Autor* a);
    Livro& operator-(Autor* a);
    
    virtual void print_info() const = 0;


};

class LivroFisico : public Livro{
    std::string tipoFolha;

public:
    LivroFisico(const std::string& t, int nP, const std::vector<Autor*>& a, const std::string& tF);
    ~LivroFisico();
    void set_tipo_folha(const std::string& tF);
    std::string& get_tipo_folha();
    void print_info() const override;
    
    
};

class LivroDigital : public Livro{
    std::string tipoArquivo;

public:
    LivroDigital(const std::string& t, int nP, const std::vector<Autor*>& a, const std::string& tA);
    ~LivroDigital();
    void set_tipo_arquivo(const std::string& tA);
    std::string& get_tipo_arquivo();
    void print_info() const override;

};

#endif