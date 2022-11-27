#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "triangulo.hpp"

TEST_CASE("Testando a primeira função, getPerimeter: "){

    /*Neste caso, a função getPerimeter() possui um bug na adição dos lados do triângulo, isso porque soma
    lado 1 + lado 2 + lado 2. Isso implica um erro no tamanho do perímetro. Temos definido assim, dois casos,
    (1) positivo, em que, apesar do erro, o código ainda funciona conforme esperado, e (2) negativo, em que o
    código apresenta mal funcionamento devido ao erro.
    (1) Ocorrerá quando calcularmos o perímetro de um triângulo equilátero, no qual lado 1 = lado 2 = lado 3, 
    não fazendo diferença no somatório final, ou quando calcularmos o perímetro de um triângulo isósceles em 
    que lado 2 = lado 3
    (2) Ocorrerá quando calcularmos o perímetro de um triângulo isósceles, no qual os lados iguais são 1 e 2
    ou quando calcularmos o perímetro de um triângulo escaleno, em que os três lados possuem medidas diferentes*/

    SUBCASE("Caso positivo: "){

        shapes::Triangle isosceles1(7, 5, 5);
        shapes::Triangle isosceles2(11, 9, 9);
        shapes::Triangle equilateral1(4, 4, 4);
        shapes::Triangle equilateral2(8, 8, 8);

        CHECK_EQ(17, isosceles1.getPerimeter());
        CHECK_EQ(29, isosceles2.getPerimeter());
        CHECK_EQ(12, equilateral1.getPerimeter());
        CHECK_EQ(24, equilateral2.getPerimeter());

    }

    SUBCASE("Caso negativo: "){

        shapes::Triangle isosceles3(7, 7, 5);
        shapes::Triangle isosceles4(9, 9, 6);
        shapes::Triangle scalene1(7, 4, 5);
        shapes::Triangle scalene2(10, 8, 5);

        CHECK_EQ(19, isosceles3.getPerimeter());
        CHECK_EQ(24, isosceles4.getPerimeter());
        CHECK_EQ(16, scalene1.getPerimeter());
        CHECK_EQ(23, scalene2.getPerimeter());

    }

}

TEST_CASE("Testando a segunda função, getArea: "){

    /*Neste caso, a função getArea() possui um bug que é diretamente ligado à função getPerimeter(), isso porque
    para o cálculo do semiperímetro, utilizado na fórmula de Heron, é utilizada a função getPerimeter(), que possui
    o erro descrito no test_case acima. Assim, esse erro será "carregado para a função getArea, o que determina que
    os casos positivos e negativos são os mesmos citados acima.
    Poderiamos falar também da possibilidade de tratar casos relativos à valores de lados negativos, que determinariam
    o cálculo de uma raíz negativa, que não está definida, contudo os asserts realizados no arquivo triângulo.cpp não
    permitem que um triângulo com um, dois ou três lados negativos seja criado."*/

    SUBCASE("Caso positivo: "){

        shapes::Triangle isosceles1(7, 5, 5);
        shapes::Triangle isosceles2(11, 9, 9);
        shapes::Triangle equilateral1(4, 4, 4);
        shapes::Triangle equilateral2(8, 8, 8);

        CHECK_EQ(12.497, isosceles1.getArea());
        CHECK_EQ(39.181, isosceles2.getArea());
        CHECK_EQ(6.928, equilateral1.getArea());
        CHECK_EQ(27.712, equilateral2.getArea());

    }

    SUBCASE("Caso negativo: "){

        shapes::Triangle isosceles3(7, 7, 5);
        shapes::Triangle isosceles4(9, 9, 6);
        shapes::Triangle scalene1(7, 4, 5);
        shapes::Triangle scalene2(10, 8, 5);

        CHECK_EQ(16.345, isosceles3.getArea());
        CHECK_EQ(25.455, isosceles4.getArea());
        CHECK_EQ(9.797, scalene1.getArea());
        CHECK_EQ(19.81, scalene2.getArea());

    }

}

TEST_CASE("Testando a terceira função, getKind: "){

    /*Neste caso, a função getKind() possui um bug relacionado á ordem de execução das checagens do tipo de triângulo,
    isso se dá, pois o primeiro caso a ser testado é o de triãngulos isósceles, contudo há uma chance de o triângulo ser
    confirmado como isósceles sendo, na verdade, um triângulo equilátero, isto porque, como triângulos isósceles tem dois
    lados iguais e equiláteros tem três lados iguais, todo equilátero é um isósceles. Assim, os triângulos equiláteros são
    como uma especialização dos triãngulos isósceles, devendo ser testados antes. Ou seja, temos caso positivo quando o 
    triângulo a ser testado é realmente isósceles, e temos caso negatuvo quando o triângulo testado é equilátero.
    Poderiamos falar também de uma exceção para triãngulos escalenos, quando estes possume lados na proporção X, 2X e 3X, 
    mas este caso já é tratado pelas asserts do arquivo triângulo.cpp*/

    SUBCASE("Caso positivo: "){

        shapes::Triangle isosceles5(8, 5, 5);
        shapes::Triangle isosceles6(9, 9, 6);
        shapes::Triangle scalene3(9, 14, 11);
        shapes::Triangle scalene4(10, 17, 15);

        CHECK_EQ(shapes::Triangle::Kind::ISOSCELES, isosceles5.getKind());
        CHECK_EQ(shapes::Triangle::Kind::ISOSCELES, isosceles6.getKind());
        CHECK_EQ(shapes::Triangle::Kind::SCALENE, scalene3.getKind());
        CHECK_EQ(shapes::Triangle::Kind::SCALENE, scalene4.getKind());

    }

    SUBCASE("Caso negativo: "){

        shapes::Triangle equilateral3(7, 7, 7);
        shapes::Triangle equilateral4(9, 9, 9);

        CHECK_EQ(shapes::Triangle::Kind::EQUILATERAL, equilateral3.getKind());
        CHECK_EQ(shapes::Triangle::Kind::EQUILATERAL, equilateral4.getKind());

    }

}