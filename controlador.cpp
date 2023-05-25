#include "controlador.h"
#include "modelo.h"
#include "vista.h"
Controlador::Controlador() {
    // Constructor del controlador
}
void Controlador::inicializarEstudiantes() {
    estudiantes_ ={ modelo("1", "Manuel"),
                    modelo("2", "Daniel"),
                    modelo("3", "Andrea"),
                    modelo("4", "Samuel"),
                    modelo("5", "Alicia"),
                    modelo("6", "Carmen"),
                    modelo("7", "Carlos"),
                    modelo("8", "Sandra"),
                    modelo("9", "Miguel"),
                    modelo("10","Marco") };
}

vector<modelo> Controlador::obtenerEstudiantes() const {
    return estudiantes_;
}

modelo Controlador::obtenerEstudiante(const string& id) const {
    for (auto estudiante : estudiantes_) {
        if (estudiante.getID() == id) {
            return estudiante;
        }
    }
    return modelo("N/A", "N/A");
}

void Controlador::agregarNota(const string& id, int nota1, int nota2, int nota3) {
    for (auto& estudiante : estudiantes_) {
        if (estudiante.getID() == id) {
            estudiante.agregarNota(nota1, nota2, nota3); // Actualizar las notas 1, 2 y 3
            break;
        }
    }
}


void Controlador::actualizarNota(const string& id, int indiceNota, int nuevaNota) {
    for (auto& estudiante : estudiantes_) {
        if (estudiante.getID() == id) {
            estudiante.actualizarNota(indiceNota, nuevaNota);
            break;
        }
    }
}


void Controlador::ayudaAcademica(bool todosEstudiantes) {
    int opcionAyuda = -1;
    if (!todosEstudiantes) {
        string id = "";
        while (id.empty()) {
            id = vista_.obtenerEntrada("Ingrese ID del estudiante al que desea ayudar: ");
            if (id == "0") {
                return;
            }
            modelo estudiante = obtenerEstudiante(id);
            if (estudiante.getID() == "N/A") {
                vista_.mostrarError("Estudiante no encontrado. Intente nuevamente o ingrese '0' para cancelar.");
                id = "";
            }
            else {
                opcionAyuda = vista_.obtenerOpcionAyudaAcademica();
                if (opcionAyuda == 0) {
                    return;
                }
                int indiceNota = vista_.obtenerIndiceNota();
                int notaActual = estudiante.getNotas()[indiceNota];
                int nuevaNota = notaActual + opcionAyuda;
                estudiante.actualizarNota(indiceNota, nuevaNota);
                vista_.mostrarEstudiante(estudiante);
            }
        }
    }
    else {
        opcionAyuda = vista_.obtenerOpcionAyudaAcademica();
        if (opcionAyuda == 0) {
            return;
        }
        int indiceNota = vista_.obtenerIndiceNota();
        for (auto& estudiante : estudiantes_) {
            int notaActual = estudiante.getNotas()[indiceNota];
            int nuevaNota = notaActual + opcionAyuda;
            estudiante.actualizarNota(indiceNota, nuevaNota);
            vista_.mostrarEstudiante(estudiante);
        }
   }
}
modelo Controlador::obtenerEstudianteMayorPromedio() const {
    if (estudiantes_.empty()) {
        return modelo("N/A", "N/A");
    }

    modelo estudianteMayorPromedio = estudiantes_[0];
    double promedioMayor = estudianteMayorPromedio.getPromedioNotas();

    for (const auto& estudiante : estudiantes_) {
        double promedio = estudiante.getPromedioNotas();
        if (promedio > promedioMayor) {
            estudianteMayorPromedio = estudiante;
            promedioMayor = promedio;
        }
    }

    return estudianteMayorPromedio;
}
