#include "livro.h"

Livro::Livro(const std::string& t, int nP) : titulo(t), num_paginas(nP){
}
Livro::~Livro(){ // desaloca a memoria do vector dos autores
    for (auto autor : autores){
        delete autor;
    }
}

void Livro::set_titulo(const std::string& t){
    titulo = t;
}
std::string& Livro::get_titulo(){
    return titulo;
}

void Livro::set_num_paginas(int nP){
    num_paginas = nP;
}
int Livro::get_num_paginas(){
    return num_paginas;
}

std::vector<Autor*> Livro::get_autores(){
    return autores;
}
Livro& Livro::operator+(Autor* autor){ // operador para adicionar autores
    autores.push_back(autor);
    return *this;
}
Livro& Livro::operator-(Autor* autor){ // operador para remover autores
    auto it = std::find(autores.begin(), autores.end(), autor);
    if (it != autores.end()){
        autores.erase(it);
    }
    return *this;
}
