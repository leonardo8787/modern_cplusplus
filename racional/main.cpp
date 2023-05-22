#include "racional.hpp"

int main() {
    Racional racional1(3, 4);
    Racional racional2(1, 2);
    Racional racional3(2, 3);

    vector<Racional> racionais;

    cout << "racional1 < racional2: " << (racional1 < racional2) << endl;
    cout << "racional1 <= racional2: " << (racional1 <= racional2) << endl;
    cout << "racional1 > racional2: " << (racional1 > racional2) << endl;
    cout << "racional1 >= racional2: " << (racional1 >= racional2) << endl;
    cout << "racional1 == racional2: " << (racional1 == racional2) << endl;

    // Teste dos operadores aritméticos
    Racional soma = racional1 + racional2;
    cout << "racional1 + racional2: " << soma.getNumerador() << "/" << soma.getDenominador() << endl;

    Racional subtracao = racional1 - racional2;
    cout << "racional1 - racional2: " << subtracao.getNumerador() << "/" << subtracao.getDenominador() << endl;

    Racional multiplicacao = racional1 * racional2;
    cout << "racional1 * racional2: " << multiplicacao.getNumerador() << "/" << multiplicacao.getDenominador() << endl;

    Racional divisao = racional1 / racional2;
    cout << "racional1 / racional2: " << divisao.getNumerador() << "/" << divisao.getDenominador() << endl;

    // Teste dos operadores de atribuição
    Racional racional4 = racional1;
    racional4 += racional2;
    cout << "racional4: " << racional4.getNumerador() << "/" << racional4.getDenominador() << endl;

    Racional racional5 = racional1;
    racional5 -= racional2;
    cout << "racional5: " << racional5.getNumerador() << "/" << racional5.getDenominador() << endl;

    Racional racional6 = racional1;
    racional6 *= racional2;
    cout << "racional6: " << racional6.getNumerador() << "/" << racional6.getDenominador() << endl;

    Racional racional7 = racional1;
    racional7 /= racional2;
    cout << "racional7: " << racional7.getNumerador() << "/" << racional7.getDenominador() << endl;

    // Teste dos métodos constantes numerador() e denominador()
    cout << "racional1 numerador: " << racional1.getNumerador() << endl;
    cout << "racional1 denominador: " << racional1.getDenominador() << endl;

    racionais.push_back(Racional(3, 4));
    racionais.push_back(Racional(1, 2));
    racionais.push_back(Racional(2, 3));

    sort(racionais.begin(), racionais.end());

    Racional somatorio;
    for (const Racional& racional : racionais) {
        somatorio += racional;
    }

    cout << "Somatório: " << somatorio.getNumerador() << "/" << somatorio.getDenominador() << std::endl;

    return 0;
}