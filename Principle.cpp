#include <iostream>
#include <string>
using namespace std;

class Aluno {
public:
    string nome;
    string ra;
    int idade;

public:
    Aluno(string _nome, string _ra, int _idade) : nome(_nome), ra(_ra), idade(_idade) {}

    ~Aluno() {
        cout << "O objeto Aluno foi excluído" << endl;
    }

    void mostrar_info() const {
        cout << "Nome: " << nome << endl;
        cout << "RA: " << ra << endl;
        cout << "Idade: " << idade << endl;
    }
};

class Livro {
protected:
    string nome;
    int numero;
    int numero_de_paginas;
    int numero_do_livro;

public:
    Livro(string _nome, int _numero, int _numero_de_paginas, int _numero_do_livro) 
        : nome(_nome), numero(_numero), numero_de_paginas(_numero_de_paginas), numero_do_livro(_numero_do_livro) {}

    ~Livro() {
        cout << "O objeto Livro foi excluído" << endl;
    }

    void mostrar_info() const {
        cout << "Nome do livro: " << nome << endl;
        cout << "Número do livro: " << numero << endl;
        cout << "Número de páginas: " << numero_de_paginas << endl;
        cout << "Número do livro: " << numero_do_livro << endl;
    }
};

class Emprestimolivro : public Livro {
private:
    string autor;

public:
    Emprestimolivro(string _nome, int _numero, int _numero_de_paginas, int _numero_do_livro, string _autor)
        : Livro(_nome, _numero, _numero_de_paginas, _numero_do_livro), autor(_autor) {}

    ~Emprestimolivro() {
        cout << "O objeto Emprestimolivro foi destruído" << endl;
    }

    void mostrar_info_autor() const {
        cout << "Autor: " << autor << endl;
    }
};

int main() {
    // Criando um objeto Aluno
    Aluno aluno("João", "123456", 20);
    
    // Imprimindo informações do aluno
    aluno.mostrar_info();
    
    cout << endl;

    // Criando um objeto Livro
    Livro livro("Introdução à Programação", 123, 300, 456);
    
    // Imprimindo informações do livro
    livro.mostrar_info();
    
    cout << endl;

    // Criando um objeto Emprestimolivro
    Emprestimolivro emprestimo("Clean Code", 456, 400, 789, "Robert C. Martin");

    // Imprimindo informações do empréstimo de livro
    emprestimo.mostrar_info();
    emprestimo.mostrar_info_autor(); // Mostra informações específicas do empréstimo

    return 0;
}

