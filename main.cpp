#include <iostream>
#include <vector>
#include "modelo.h"
#include "controlador.h"
#include "vista.h"
#include "stdlib.h"
int main() {
    Controlador controlador;
    controlador.inicializarEstudiantes();
    Vista vista;
    cout << "Menu:\n";
    cout << "1. Listar estudiantes\n";
    cout << "2. Agregar notas a estudiante\n";
    cout << "3. Actualizar nota de estudiante\n";
    cout << "4. Obtener estudiante con mayor promedio\n";
    cout << "5. Ayuda academica\n";
    cout << "6.-Estado de nota-estudiante\n";
    cout << "0. Salir\n";
    while (true) {

        cout << "Ingrese opcion: ";

        int opcion = vista.obtenerEntradaEntero("");

        if (opcion == 0) {
            cout << "Hasta luego!\n";
            break;
        }

        switch (opcion) {
        case 1: {
            vector<modelo> estudiantes = controlador.obtenerEstudiantes();
            vista.mostrarListaEstudiantes(estudiantes);
            break;
        }
        case 2: {

            string id = vista.obtenerEntrada("Ingrese ID del estudiante: ");
            int nota1 = vista.obtenerNota();
            int nota2 = vista.obtenerNota();
            int nota3 = vista.obtenerNota();
            controlador.agregarNota(id, nota1, nota2, nota3);
            break;
        }
        case 3: {
            string id = vista.obtenerEntrada("Ingrese ID del estudiante: ");
            int indiceNota = vista.obtenerIndiceNota();
            int nuevaNota = vista.obtenerNota();
            controlador.actualizarNota(id, indiceNota, nuevaNota);
            break;
        }
        case 4: {
            modelo estudianteMayorPromedio = controlador.obtenerEstudianteMayorPromedio();
            vista.mostrarEstudiante(estudianteMayorPromedio);
            break;
        }
        case 5: {
            bool todosEstudiantes = vista.obtenerConfirmacion("Desea ayudar a todos los estudiantes?");
            controlador.ayudaAcademica(todosEstudiantes);
            break;
        }
        case 6: {
            string id = vista.obtenerEntrada("Ingrese ID del estudiante: ");
            modelo estudiante = controlador.obtenerEstudiante(id);
            if (estudiante.getID() != "N/A") {
                vista.mostrarEstadoEstudiante(estudiante);
            } else {
                vista.mostrarError("Estudiante no encontrado.");
            }
            break;
        }
        default: {
            vista.mostrarError("Opcion invalida, intente de nuevo.");
            break;
        }
        }
    }
    return 0;
}
