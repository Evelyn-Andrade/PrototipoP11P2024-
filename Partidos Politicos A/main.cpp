// Evelyn Sofía Andrade Luna
//Carnet : 9959-23-1224
//variable A

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Se realiza una estructura para representar el nombre del candidato
struct Candidato {
    string nombre;
    int votos[4]; // Arreglo para almacenar los votos de cada año
};

// Estructura para representar un partido político
struct Partido {
    string nombre;
    vector<Candidato> candidatos; // Vector de candidatos
};

// Función para imprimir una línea horizontal
void imprimirLineaHorizontal(int ancho) {
    cout << "+";
    for (int i = 0; i < ancho; ++i) {
        cout << "-";
    }
    cout << "+" << endl;
}

int main() {
    do {
        srand(time(nullptr)); // Inicializar la semilla para generar números aleatorios

        // Aqui se crea 3 partidos Politicos
        vector<Partido> partidos = {
            {"Partido REPUBLICANO"},
            {"Partido DEMOCRATA"},
            {"Partido INDEPENDIENTE"}
        };

        // Aqui pide al usurio que ingrese 5 nombres para cada Partido Politico
        for (auto& partido : partidos) {
            for (int i = 0; i < 5; ++i) {
                Candidato candidato;
                cout << "Ingrese el NOMBRE del candidato " << i + 1 << " del PARTIDO " << partido.nombre << ": ";
                cin >> candidato.nombre;
                for (int j = 0; j < 4; ++j) {
                    candidato.votos[j] = rand() % 1001; // Generar votos aleatorios entre 0 y 1,000,000
                }
                partido.candidatos.push_back(candidato); // Aqui agrega al candidato
            }
        }

        // Ciclo Principal
        while (true) {
            // Muestra datos de cada partido y candidato
            for (auto& partido : partidos) {
                imprimirLineaHorizontal(80);
                cout << "| " << setw(20) << partido.nombre << " |" << endl;
                imprimirLineaHorizontal(80);
                for (auto& candidato : partido.candidatos) {
                    cout << "| " << setw(20) << candidato.nombre << " |";
                    for (int i = 0; i < 4; ++i) {
                        cout << " " << setw(4) << candidato.votos[i] << " |";
                    }
                    cout << endl;
                }
            }

            // Ciclo donde calcula el total de votos, votos más altos, votos más bajos y promedio de votos para cada partido
            for (auto& partido : partidos) {
                int totalVotos = 0;
                int maxVotos = 0;
                int minVotos = 1000000;
                for (auto& candidato : partido.candidatos) {
                    for (int i = 0; i < 4; ++i) {
                        totalVotos += candidato.votos[i];
                        maxVotos = max(maxVotos, candidato.votos[i]);
                        minVotos = min(minVotos, candidato.votos[i]);
                    }
                }
                imprimirLineaHorizontal(80);
                cout << "| " << setw(20) << "TOTAL de votos: " << totalVotos << " |" << endl;
                cout << "| " << setw(20) << "Votos MAS ALTOS: " << maxVotos << " |" << endl;
                cout << "| " << setw(20) << "Votos MAS BAJOS: " << minVotos << " |" << endl;
                cout << "| " << setw(20) << "PROMEDIO de votos: " << totalVotos / 20.0 << " |" << endl;
            }

            // Identifica el mejor partido político y su promedio de votos obtenidos
            auto mejorPartido = max_element(partidos.begin(), partidos.end(), [](const Partido& a, const Partido& b) {
                int totalVotosA = 0;
                int totalVotosB = 0;
                for (auto& candidato : a.candidatos) {
                    for (int i = 0; i < 4; ++i) {
                        totalVotosA += candidato.votos[i];
                    }
                }
                for (auto& candidato : b.candidatos) {
                    for (int i = 0; i < 4; ++i) {
                        totalVotosB += candidato.votos[i];
                    }
                }
                return totalVotosA < totalVotosB;
            });

            imprimirLineaHorizontal(80);
            cout << "| " << setw(20) << "MEJOR PARTIDO: " << mejorPartido->nombre << " |" << endl;
            cout << "| " << setw(20) << "PROMEDIO DE VOTOS: " << (mejorPartido->candidatos.size() * 5 * 1000) / 20.0 << " |" << endl;

            // Pregunta si quiere hacer el proceso de nuevo
            imprimirLineaHorizontal(80);
            cout << "¿Desea continuar? (s/n): ";
            char respuesta;
            cin >> respuesta;
            if (respuesta != 's' && respuesta != 'S') {
                break; // Sale del ciclo y termina la ejecución
            }
        }
    } while (true);

    return 0;
}









