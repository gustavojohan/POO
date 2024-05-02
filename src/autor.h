#ifndef AUTOR_H
#define AUTOR_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Autor{
    std::string nome;

public:
    Autor(const std::string& n);
    ~Autor();
    void set_nome(const std::string& n);
    std::string& get_nome();
};

#endif