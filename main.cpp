#include <iostream>
#include <fmt/printf.h>
#include <random>

int main() {
    fmt::print("Jogo de Advinhação!\n");
    fmt::print("Tente adivinhar o número entre 1 e 100.\n");
    fmt::print("Você tem 3 tentativas.\n");
    bool continuar = true;
    int tentativas = 1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(1, 100);
    int numeroAleatorio = static_cast<int>(dis(gen)); // Gera um número aleatório entre 1 e 100
    while (continuar || tentativas < 3) {
        int palpite;
        fmt::print("Tentativa de palpite: {} de 3\n", tentativas);
        fmt::print("Digite seu palpite: ");
        if (!(std::cin >> palpite)) {
            fmt::print("Entrada inválida! Por favor, insira um número.\n");
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta a entrada inválida
            continue; // Pede o palpite novamente
        }

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
                tentativas = 1; // Reseta as tentativas
                numeroAleatorio = static_cast<int>(dis(gen));
            } else {
                continuar = false; // Encerra o jogo
            }
        }
    }
    return 0;
}
