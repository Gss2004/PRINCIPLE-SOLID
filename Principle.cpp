#include <iostream>
#include <iostream>
#include <string>
#include <vector>
//SRP
class MathOperations {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }
};

class ResultPrinter {
public:
    static void printAdditionResult(int result) {
        std::cout << "Result of addition: " << result << std::endl;
    }

    static void printMultiplicationResult(int result) {
        std::cout << "Result of multiplication: " << result << std::endl;
    }
};

//DEMETER
class Teacher {
public:
    std::string getName() const {
        return "Mr. Smith";
    }
};

class Student {
public:
    void printTeacherName(const std::string& teacherName) const {
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
        Teacher teacher;
        std::string teacherName = teacher.getName(); // Obtem o nome do professor aqui

        for (const auto& student : students) {
            student.printTeacherName(teacherName); // Passa o nome do professor diretamente
        }
    }
};

//LSP
class Bird {
public:
    virtual void fly() const {
        std::cout << "Bird flying" << std::endl;
    }
};

class Ostrich : public Bird {
public:
    // O avestruz não voa, então não precisamos sobrescrever o método fly()
};

void makeBirdFly(const Bird& bird) {
    bird.fly();
}

//DIP
// Interface para lâmpada
class Bulb {
public:
    virtual void turnOn() = 0;
};

// Implementação concreta da lâmpada
class LightBulb : public Bulb {
public:
    void turnOn() override {
        std::cout << "Light bulb turned on" << std::endl;
    }
};

// Switch depende da interface Bulb
class Switch {
private:
    Bulb& bulb;

public:
    Switch(Bulb& bulb) : bulb(bulb) {}

    void toggle() {
        bulb.turnOn();
    }
};

int main() {
    //SRP
    int a = 5;
    int b = 3;

    int additionResult = MathOperations::add(a, b);
    ResultPrinter::printAdditionResult(additionResult);

    int multiplicationResult = MathOperations::multiply(a, b);
    ResultPrinter::printMultiplicationResult(multiplicationResult);
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

    makeBirdFly(bird);    // Deve imprimir "Bird flying"
    makeBirdFly(ostrich); // Deve imprimir "Bird flying", pois um avestruz é um tipo de pássaro
    printf("\n\n");
    //DIP
    LightBulb lightBulb;
    Switch lightSwitch(lightBulb);

    lightSwitch.toggle(); // Deve imprimir "Light bulb turned on"


    return 0;
}