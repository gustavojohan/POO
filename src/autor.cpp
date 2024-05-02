#include "autor.h"

Autor::Autor(const std::string& n) : nome(n){
}

Autor::~Autor(){
}

void Autor::set_nome(const std::string& n){
    nome = n;
}

std::string& Autor::get_nome(){
    return nome;
}
