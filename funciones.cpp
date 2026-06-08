#include <vector>   // para std::vector
#include <iostream> // para std::cout
#include <fstream>   // para std::ofstream y std::ifstream
#include <algorithm>    // para std::sort
#include "participante.h" // para la definición de la estructura "participante"

void imprimirParticipantes(std::vector<participante> participantes){
    std::cout << "Participantes:"<< std::endl;
    for(int i=0; i<participantes.size();i++){
        std::cout << "Nombre: " << participantes[i].nombre;
        std::cout << " | Puntuacion: " << participantes[i].puntuacion << std::endl;
    }
}

void ordenarParticipantes(std::vector<participante>& participantes){
    //std::cout << "Antes de ordenar"<< std::endl;  //Imprimir los participantes antes de ordenar

    //imprimirParticipantes(participantes);

    //std::cout << "Despues de ordenar"<< std::endl;  // Ordenar los participantes por puntuación (descendente) y luego por nombre (ascendente)

    sort(participantes.begin(), participantes.end(),
    [](const participante& a, const participante& b) {
        if (a.puntuacion != b.puntuacion)
            return a.puntuacion > b.puntuacion;  // más puntos primero

        return a.nombre < b.nombre;      // desempate por nombre
    });

    //imprimirParticipantes(participantes);
}

void escribirRanking(const std::vector<participante>& participantes) {
    std::ofstream archivo("ranking.txt"); // Abrir el archivo para escribir

    if (!archivo.is_open()) { // Verificar si el archivo se abrió correctamente
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        return; // Salir de la función si no se pudo abrir el archivo
    }


    int posicion = 0; // Variable para llevar la posición del participante en el ranking
    int i = 0; // Variable para iterar sobre el vector de participantes
    for (const auto& p : participantes) { // Iterar sobre cada participante en el vector
        if(participantes[i].puntuacion != participantes[i-1].puntuacion && i > -1){
            posicion++; // Incrementar la posición solo si la puntuación del participante actual es diferente a la del participante anterior
            archivo << "Posición: " << posicion << " | Nombre: " << p.nombre << " | Puntuación: " << p.puntuacion << std::endl;
        } else {
            archivo << "Posición: " << posicion << " | Nombre: " << p.nombre << " | Puntuación: " << p.puntuacion << std::endl;
        }
        i++; // Incrementar el índice para la siguiente iteración
    }

    archivo.close(); // Cerrar el archivo después de escribir
}