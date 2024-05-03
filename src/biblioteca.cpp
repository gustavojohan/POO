#include "biblioteca.h"

Biblioteca::Biblioteca(const std::vector<Livro*>& l = {}) : livros(l){
}
Biblioteca::~Biblioteca(){
    for (auto l : livros) {
            delete l;
        }
        livros.clear();
}

void Biblioteca::adicionar_livro(Livro* l){
    livros.push_back(l);
}

void Biblioteca::remover_livro(Livro* l){
    auto it = std::find(livros.begin(), livros.end(), l);
    if (it != livros.end()){
        livros.erase(it);
        delete l;
    }
}

Biblioteca& Biblioteca::operator+(Livro* l){
    adicionar_livro(l);
    return *this;
}
Biblioteca& Biblioteca::operator-(Livro* l){
    remover_livro(l);
    return *this;
}

