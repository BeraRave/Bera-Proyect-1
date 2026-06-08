#include <iostream> // para std::cout
#include <vector>   // para std::vector
#include <algorithm>    // para std::sort
#include <fstream>   // para std::ofstream y std::ifstream
#include "participante.h" // para la definición de la estructura "participante"
#include "funciones.cpp"   // para importar las funciones necesairias

int main() {
    
    std::vector<participante> participantes; // Crear un vector de participantes

    std::string modo;

    std::cout << "Seleccione el modo de operación (manual/automatico): ";
    std::cin >> modo;
    std::cin.ignore();

    if(modo == "manual"){
        std::cout << "Modo manual seleccionado. Ingrese los participantes y sus puntuaciones." << std::endl;
        
        while (true){

            std::string nombre;
            int puntuacion;

            std::cout << "Ingrese el nombre del participante (o 'salir' para terminar): ";
            std::cin >> nombre; // Leer el nombre del participante
            std::cin.ignore(); // Limpiar el buffer de entrada

            if (nombre == "salir") { // Verificar si el usuario desea salir
                break; // Salir del bucle
            }

            std::cout << "Ingrese la puntuación del participante: ";
            std::cin >> puntuacion; // Leer la puntuación del participante
            std::cin.ignore(); // Limpiar el buffer de entrada

            participantes.push_back({nombre, puntuacion}); // Agregar el participante al vector

            ordenarParticipantes(participantes); // Ordenar e imprimir los participantes después de cada entrada
            
        }

        std::cout <<"Archivo listo. Se ha generado el ranking final en el archivo 'ranking.txt'." << std::endl;

    } else if(modo == "automatico"){
        std::cout << "Modo automático seleccionado. Se accedera al archivo de participantes." << std::endl;
        
        std::ifstream archivo("participantes.txt"); // Abrir el archivo para leer
        
        if (!archivo.is_open()) { // Verificar si el archivo se abrió correctamente
            std::cerr << "Error al abrir el archivo para leer." << std::endl;
            return 1; // Salir con un código de error
        }       

        participante p; // Crear una variable para almacenar temporalmente los datos de cada participante

        while (archivo >> p.nombre >> p.puntuacion) { // Leer el nombre y la puntuación de cada participante desde el archivo
            participantes.push_back(p); // Agregar el participante al vector    
        }

        archivo.close(); // Cerrar el archivo después de leer

        ordenarParticipantes(participantes); // Ordenar la lista de participantes después de leer todos los datos

        std::cout <<"Archivo listo. Se ha generado el ranking final en el archivo 'ranking.txt'." << std::endl;

    } else {
        std::cout << "Modo no válido. Por favor, seleccione 'manual' o 'automatico'." << std::endl;
        return 1; // Salir con un código de error
    }

    escribirRanking(participantes); // Escribir el ranking final en el archivo "ranking.txt"

    return 0;
}