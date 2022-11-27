# VPL10

O projeto em anexo implementa a classe Triangulo. 

Seu construtor recebe valores inteiros referentes aos lados de um triângulo, exigindo que o primeiro lado seja o maior e que todos os lados satisfaçam o teorema da desigualdade triangular. 

Existem bugs nos métodos:
     
     getPerimeter()
     
     getArea()
     
     getKind()

Você é a pessoa que vai testar a classe Triangulo e, agora que notou os bugs, quer destacar esses erros através dos seus testes. 

Crie o arquivo triangulo_test.cpp com três casos de teste, um para cada método citado anteriormente, cada qual com dois subcasos:

    O subcaso positivo, com checagens que funcionam mesmo com os bugs.

    O subcaso negativo, com checagens que não funcionam por conta do bug, mas passarão a funcionar após sua correção.

Seu código deve estar completo e ser compilável. Lembre-se que:

    - É preciso definir a macro a seguir para que o seu arquivo tenha um ponto de entrada da execução (tenha um main).
    
    #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

    - É preciso incluir o arquivo doctest.h após a configuração anterior para usar suas macros de teste 
    
    (#include "doctest.h")
