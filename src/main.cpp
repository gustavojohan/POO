#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include "autor.h"
#include "livro.h"
#include "biblioteca.h"

void apaga_enter(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Livro* cria_livro_fisico(){
    std::string titulo, tipoFolha;
    int num_paginas;
    int qnt_autores;
    std::vector<Autor*> autores;
    std::cout << "Digite o titulo do livro fisico: ";
    getline(std::cin, titulo);
    std::cout << "Digite o numero de paginas do livro fisico: ";
    std::cin >> num_paginas;
    apaga_enter();
    std::cout << "Quantos autores o livro fisico possui?: ";
    std::cin >> qnt_autores;
    for (int i = 0; i < qnt_autores; i++){
        std::string nome;
        std::cout << "Digite o nome do autor: ";
        getline(std::cin, nome);
        apaga_enter();
        Autor* autor = new Autor(nome);
        autores.push_back(autor);
    }

    std::cout << "Digite o tipo de folha do livro fisico: ";
    getline(std::cin, tipoFolha);
    return new LivroFisico(titulo, num_paginas, autores, tipoFolha);
}

Livro* cria_livro_digital(){
    std::string titulo, tipoArquivo;
    int num_paginas;
    int qnt_autores;
    std::vector<Autor*> autores;
    std::cout << "Digite o titulo do livro digital: ";
    getline(std::cin, titulo);
    std::cout << "Digite o numero de paginas do livro digital: ";
    std::cin >> num_paginas;
    apaga_enter();
    std::cout << "Quantos autores o livro digital possui?: ";
    std::cin >> qnt_autores;
    for (int i = 0; i < qnt_autores; i++){
        std::string nome;
        std::cout << "Digite o nome do autor: ";
        getline(std::cin, nome);
        apaga_enter();
        Autor* autor = new Autor(nome);
        autores.push_back(autor);
    }
    std::cout << "Digite o tipo de arquivo do livro digital: ";
    getline(std::cin, tipoArquivo);
    return new LivroDigital(titulo, num_paginas, autores, tipoArquivo);
}

void imprimir_menu() {
    std::cout << "\nEscolha uma opcao:\n"
         << "1. Adicionar o livro (fisico ou digital)\n"
         << "2. Remover livro da biblioteca\n"
         << "3. Imprimir livros da biblioteca\n"
         << "4. Sair\n";
}


int main(){
    Biblioteca biblioteca({});

    int opcao;
    do {
        imprimir_menu();
        std::cout << "Opcao: ";
        std::cin >> opcao;
        apaga_enter();

        switch(opcao) {
            case 1: {
                char tipoLivro;
                std::cout << "Informe o tipo de livro (D para digital ou F para fisico): " << std::endl;
                std::cin >> tipoLivro;
                apaga_enter();
                tipoLivro = std::toupper(tipoLivro);

                if (tipoLivro == 'D'){
                    Livro* livroDigital = cria_livro_digital();
                    std::cout << "Livro digital criado com sucesso!" << std::endl;
                    biblioteca = biblioteca + livroDigital;
                    std::cout << "Livro digital adicionado na biblioteca!" << std::endl;
                break;
                }else{
                    Livro* livroFisico = cria_livro_fisico();
                    std::cout << "Livro fisico criado com sucesso!" << std::endl;
                    biblioteca = biblioteca + livroFisico;
                    std::cout << "Livro fisico adicionado na biblioteca!" << std::endl;
                break;
                }
            }
            case 2: {
                std::cout << "Selecione o titulo do livro e o tipo para remove-lo da biblioteca"; // nao consegui, tentei de varias maneiras mas nao deu certo

                break;
            }
            case 3: {
                biblioteca.print_info();
                break;
            }
            case 4:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 4);

    return 0;
}