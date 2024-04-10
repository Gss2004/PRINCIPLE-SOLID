# Exemplo de Aplicação dos Princípios SOLID em C++

Este repositório contém dois conjuntos de códigos em C++, demonstrando a importância e aplicação dos princípios SOLID no desenvolvimento de software.

### Princípios SOLID Usados nos códigos:

1. **SRP (Princípio da Responsabilidade Única)**:
   - Classes devem ter apenas uma razão para mudar, encapsulando apenas uma responsabilidade.
   - Facilita a compreensão, manutenção e teste do código.

2. **Princípio de Demeter (Lei de Demeter)**:
   - Métodos devem apenas chamar métodos de sua própria classe, métodos de objetos passados como parâmetros e métodos de objetos diretamente instanciados.
   - Reduz o acoplamento entre classes e torna o código mais fácil de manter e entender.

3. **Princípio da Substituição de Liskov (LSP)**:
   - Objetos de uma superclasse devem ser substituíveis por objetos de suas subclasses sem afetar a correção do programa.
   - Garante que a herança seja usada corretamente.

4. **Princípio Aberto-Fechado (OCP)**:
   - Entidades de software devem estar abertas para extensão, mas fechadas para modificação.
   - Permite estender o comportamento do sistema sem modificar o código existente.

### Mudanças realizadas no código violando os princípios SOLID:

1. **Violando SRP e Demeter**:
   - Separou a responsabilidade de imprimir informações do aluno para a classe `Aluno`.
   - Removido o acesso direto aos atributos do aluno, chamando métodos específicos na classe `Aluno`.

2. **Violando Liskov Substitution Principle (LSP)**:
   - Evitou adicionar comportamentos não esperados pelas classes base nas subclasses.
   - Adicionou novos métodos, se necessário, sem modificar o comportamento original.

3. **Violando Open-Closed Principle (OCP)**:
   - Adicionou funcionalidades sem modificar as classes existentes, respeitando a abertura para extensão.

### Como Usar:
- O código violando os princípios SOLID está no arquivo [No-Principle.cpp](/No-Principle.cpp).
- O código respeitando os princípios SOLID está no arquivo [Principle.cpp](/Principle.cpp).


### Contribuição:
- Sinta-se à vontade para contribuir com melhorias ou correções.
