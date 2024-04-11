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
     
### Exemplificação dos princípios violados:

1. **Violando SRP**:
   - Neste exemplo, a classe Calculator tem duas responsabilidades distintas: realizar operações matemáticas e exibir resultados na tela. Isso viola o SRP.
   
2. **Violando Demeter**:
   - Neste exemplo, a classe Student tem conhecimento sobre a classe Teacher através do método printTeacherName, que recebe uma instância de Teacher como 
     argumento. Isso viola o Princípio de Demeter, pois Student está acessando indiretamente uma classe (Teacher) com a qual não deveria estar diretamente 
     relacionada.
   
3. **Violando Liskov Substitution Principle**:
   - Neste exemplo, a classe Ostrich herda de Bird, o que é uma relação "é um". No entanto, quando chamamos makeBirdFly() passando um objeto Ostrich, 
     esperamos que o avestruz não voe. No entanto, a classe Ostrich sobrescreve o método fly() e imprime que o avestruz não pode voar. Isso viola o LSP, 
     pois um objeto Ostrich não pode ser substituído corretamente por um objeto Bird em todas as situações, especialmente quando o comportamento esperado 
     não é mantido.
    
   
4.  **Violando Dependency Inversion Principle**:
   - Neste exemplo, a classe Ostrich herda de Bird, o que é uma relação "é um". No entanto, quando chamamos makeBirdFly() passando um objeto Ostrich, 
     esperamos que o avestruz não voe. No entanto, a classe Ostrich sobrescreve o método fly() e imprime que o avestruz não pode voar. Isso viola o LSP, 
     pois um objeto Ostrich não pode ser substituído corretamente por um objeto Bird em todas as situações, especialmente quando o comportamento esperado 
     não é mantido.



### Mudanças realizadas no código violando os princípios SOLID:

1. **Violando SRP**:
   - a classe MathOperations é responsável apenas por realizar as operações matemáticas, enquanto a classe ResultPrinter é responsável apenas por exibir os 
     resultados na tela. Isso separa claramente as responsabilidades e garante que cada classe tenha uma única razão para mudar.

2. **Violando Demeter**:
   - a classe Student não precisa mais acessar indiretamente a classe Teacher para obter o nome do professor. Em vez disso, o nome do professor é obtido na 
     classe School e passado diretamente para o método printTeacherName() da classe Student. Isso elimina a dependência indireta da classe Student em 
     relação à classe Teacher, tornando o código mais compatível com o Princípio de Demeter.
  

3. **Violando Liskov Substitution Principle**:
   - removemos a sobrescrita do método fly() na classe Ostrich. Dessa forma, quando chamamos makeBirdFly() com um objeto Ostrich, ele simplesmente usará a 
     implementação padrão do método fly() da classe base Bird, que é "Bird flying". Isso garante que o comportamento esperado seja mantido e que não haja 
     violação do Princípio de Substituição de Liskov (LSP).

  
4. **Violando Dependency Inversion Principle**:
   - introduzimos a interface Bulb que contém o método turnOn(). LightBulb implementa essa interface. Em seguida, modificamos a classe Switch para depender 
     da interface Bulb em vez de uma implementação concreta. Agora, se quisermos adicionar novos tipos de lâmpadas ou funcionalidades, como desligar a luz, 
     podemos fazer isso sem modificar a classe Switch, mantendo assim o Princípio de Inversão de Dependência (DIP).

### Como Usar:
- O código violando os princípios SOLID está no arquivo [No-Principle.cpp](/No-Principle.cpp).
- O código respeitando os princípios SOLID está no arquivo [Principle.cpp](/Principle.cpp).


### Contribuição:
- Sinta-se à vontade para contribuir com melhorias ou correções.
