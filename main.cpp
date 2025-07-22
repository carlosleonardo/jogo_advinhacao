#include <iostream>
#include <fmt/printf.h>
#include <random>

int main() {
    fmt::print("Jogo de Advinhação!\n");
    fmt::print("Tente adivinhar o número entre 1 e 100.\n");
    fmt::print("Você tem 3 tentativas.\n");
    bool continuar = true;
    int tentativas = 0;
    int numeroAleatorio = std::rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
    while (continuar || tentativas < 3) {
        int palpite;
        fmt::print("Tentativa de palpite: {} de 3\n", tentativas + 1);
        fmt::print("Digite seu palpite: ");
        std::cin >> palpite;

        if (palpite == numeroAleatorio) {
            fmt::print("Parabéns! Você adivinhou o número!\n");
            break;
        } else if (palpite < numeroAleatorio) {
            fmt::print("Muito baixo! Tente novamente.\n");
        } else {
            fmt::print("Muito alto! Tente novamente.\n");
        }
        tentativas++;
        if (tentativas > 3) {
            fmt::print("Você perdeu, o número era {}.\n", numeroAleatorio);
            fmt::print("Você esgotou as tentativas. Quer tentar novamente? (s/n): ");
            char resposta;
            std::cin >> resposta;
            if (resposta == 's' || resposta == 'S') {
                continuar = true;
                tentativas = 0; // Reseta as tentativas
            } else {
                continuar = false; // Encerra o jogo
            }
        }
    }
    return 0;
}
