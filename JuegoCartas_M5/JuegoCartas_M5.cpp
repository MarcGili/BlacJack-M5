#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    using namespace std;

    // Cartas
    srand(time(NULL));
    string numcartas[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    string tipocarta[] = { "Picas", "Corazones", "Tréboles", "Diamantes" };

    // Opciones
    string s = "si";
    string n = "no";

    // Ejecución
    cout << "\033[33m BLACK JACK" << "\n\n\n";

    string opcion;

    cout << "Quieres empezar a jugar? (si/no)";
    cin >> opcion;
    if (opcion == n) {
        cout << "Inshallah hirmano \n\n";
    }

    int total_jugador = 0;
    int total_crupier = 0;
    int num_as = 0;

    string carta1 = numcartas[rand() % 13];
    string palo1 = tipocarta[rand() % 4];
    string carta2 = numcartas[rand() % 13];
    string palo2 = tipocarta[rand() % 4];

    cout << "Tus cartas son: " << numcartas << " de " << tipocarta << " y " << numcartas << " de " << tipocarta << endl;

    while (total_jugador < 21) {
        int cartas_jugador = 1 + rand() % 13;
        int cartas_crupier = 1 + rand() % 13;

        if (opcion == s) {
            if (cartas_jugador == 1) {
                cout << "Tienes un AS. Quieres que cuente como 1 o como 11? ";
                int valor_as;
                cin >> valor_as;
                if (valor_as == 1 || valor_as == 11) {
                    total_jugador += valor_as;
                }
                else {
                    cout << "Opción inválida, se contará como 1.\n";
                    total_jugador += 1;
                }
            }
            else {
                total_jugador += cartas_jugador;
            }

            total_crupier += cartas_crupier;

            cout << "El Crupier esta barajando las cartas... Tienes un " << total_jugador << "\n";

            if (total_jugador >= 21) {
                break;
            }
            if (total_crupier >= 21) {
                break;
            }

            cout << "El Crupier tiene " << total_crupier << "\n\n";
            cout << "Quieres pedir mas cartas? (si/no)";
            cin >> opcion;

            if (opcion == n) {
                cout << "El crupier tiene " << total_crupier + cartas_crupier << "\n";
            }
        }
        else {
            break;
        }
    }


    if (total_jugador > 21) {
        cout << "Has perdido. Te has pasado de 21 puntos.\n";
    }
    else if (total_crupier > 21) {
        cout << "¡Felicidades! Has ganado. El crupier se paso de 21 puntos.\n";
    }
    else if (21 - total_jugador < 21 - total_crupier) {
        cout << "Felicidades! Has ganado.\n";
    }
    else if (21 - total_jugador > 21 - total_crupier) {
        cout << "Has perdido. El crupier tiene." << total_crupier << "\n";
    }
    else {
        cout << "Es un empate. Tienes el mismo número de puntos que el crupier.\n";
    }

    return 0;
}
