#include <iostream>
#include <string>
#include <vector>

//Neste exemplo, a classe Calculator tem duas responsabilidades distintas: realizar operações matemáticas e exibir resultados na tela. Isso viola o SRP.
class Calculator {
public:
    void add(int a, int b) {
        int result = a + b;
        std::cout << "Result of addition: " << result << std::endl;
    }
                                            
    void multiply(int a, int b) {
        int result = a * b;
        std::cout << "Result of multiplication: " << result << std::endl;
    }
};

//Neste exemplo, a classe Student tem conhecimento sobre a classe Teacher através do método printTeacherName, que recebe uma instância de Teacher como argumento. Isso viola o Princípio de Demeter, pois Student está acessando indiretamente uma classe (Teacher) com a qual não deveria estar diretamente relacionada.
class Teacher {
public:
    std::string getName() const {
        return "Mr. Smith";
    }
};

class Student {
public:
    void printTeacherName(const Teacher& teacher) const {
        std::string teacherName = teacher.getName();
        std::cout << "Teacher's name is: " << teacherName << std::endl;
    }
};

class School {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void printTeachersToStudents() const {
        for (const auto& student : students) {
            Teacher teacher;
            student.printTeacherName(teacher); // Aqui a classe Student acessa indiretamente a classe Teacher
        }
    }
};

//Neste exemplo, a classe Ostrich herda de Bird, o que é uma relação "é um". No entanto, quando chamamos makeBirdFly() passando um objeto Ostrich, esperamos que o avestruz não voe. No entanto, a classe Ostrich sobrescreve o método fly() e imprime que o avestruz não pode voar. Isso viola o LSP, pois um objeto Ostrich não pode ser substituído corretamente por um objeto Bird em todas as situações, especialmente quando o comportamento esperado não é mantido.

class Bird {
public:
    virtual void fly() const {
        std::cout << "Bird flying" << std::endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() const override {
        std::cout << "Ostrich can't fly" << std::endl;
    }
};

void makeBirdFly(const Bird& bird) {
    bird.fly();
}



//Neste exemplo, a classe Switch depende diretamente da classe concreta LightBulb, violando o DIP. Se no futuro quisermos trocar o tipo de lâmpada ou adicionar outras funcionalidades, como desligar ou regular a intensidade da luz, teríamos que modificar a classe Switch, o que não está de acordo com o princípio de inversão de dependência.

class LightBulb {
public:
    void turnOn() {
        std::cout << "Light bulb turned on" << std::endl;
    }
};

class Switch {
private:
    LightBulb bulb;

public:
    void toggle() {
        bulb.turnOn();
    }
};



int main() {
    //SRP
    Calculator calculator;

    calculator.add(5, 3);
    calculator.multiply(4, 6);
    printf("\n\n");
    
    //DEMETER
    Student student1, student2;
    School school;
    school.addStudent(student1);
    school.addStudent(student2);
    school.printTeachersToStudents();
    printf("\n\n");

    //LSP
    Bird bird;
    Ostrich ostrich;

    makeBirdFly(bird);
    makeBirdFly(ostrich); // Violação do LSP, onde um Ostrich substitui um Bird, mas não se comporta como esperado
    printf("\n\n");
    
    //DIP
    Switch lightSwitch;
    lightSwitch.toggle();
    return 0;
}
