#include "livro.h"

// implementacao da classe livro

Livro::Livro(const std::string& t, int nP, const std::vector<Autor*>& a) : titulo(t), num_paginas(nP), autores(a){
}
Livro::~Livro(){ // desaloca a memoria do vector dos autores
    for (auto a : autores){
        delete a;
    }
}

void Livro::set_titulo(const std::string& t){
    titulo = t;
}
std::string Livro::get_titulo() const{
    return titulo;
}

void Livro::set_num_paginas(int nP){
    num_paginas = nP;
}
int Livro::get_num_paginas() const{
    return num_paginas;
}

std::vector<Autor*> Livro::get_autores() const{
    return autores;
}

Livro& Livro::operator+(Autor* a){ // operador para adicionar autores
    autores.push_back(a);
    return *this;
}
Livro& Livro::operator-(Autor* a){ // operador para remover autores
    auto it = std::find(autores.begin(), autores.end(), a);
    if (it != autores.end()){
        autores.erase(it);
    }
    return *this;
}

void Livro::print_info() const{
}

// fim da implementacao da classe livro

// implementacao da classe LivroFisico

LivroFisico::LivroFisico(const std::string& t, int nP, const std::vector<Autor*>& a, const std::string& tF) : Livro(t, nP, a), tipoFolha(tF){
}
LivroFisico::~LivroFisico(){
}

void LivroFisico::set_tipo_folha(const std::string& tF){
    tipoFolha = tF;
}

std::string& LivroFisico::get_tipo_folha(){
    return tipoFolha;
}

void LivroFisico::print_info() const{
    std::cout << "Livro Fisico: " << get_titulo() << " - " << get_num_paginas() << " paginas - Tipo de Folha: " << tipoFolha << std::endl;
    std::cout << "Autor(es): ";
   // for (const Autor* autor : get_autores()){
        //std::cout << autor->get_nome();
    //}
}

// fim da implementacao da classe LivroFisico

// implementacao da classe LivroDigital

LivroDigital::LivroDigital(const std::string& t, int nP, const std::vector<Autor*>& a, const std::string& tA) : Livro(t, nP, a), tipoArquivo(tA){
}
LivroDigital::~LivroDigital(){
}

void LivroDigital::set_tipo_arquivo(const std::string& tA){
    tipoArquivo = tA;
}

std::string& LivroDigital::get_tipo_arquivo(){
    return tipoArquivo;
}

void LivroDigital::print_info() const{
    std::cout << "Livro Digital: " << get_titulo() << " - " << get_num_paginas() << " paginas - Tipo de Arquivo: " << tipoArquivo << std::endl;
}