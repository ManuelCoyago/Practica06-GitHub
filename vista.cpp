#include "vista.h"

void Vista::mostrarListaEstudiantes(const vector<modelo>& estudiantes) const {
    cout << "ID\tNombre\tNota1\tNota2\tNota3\tPromedio\n";
    for (const auto& estudiante : estudiantes) {
        cout << estudiante.getID() << "\t" << estudiante.getNombre() << "\t"
             << setw(5) << estudiante.getNotas().at(0) << "\t"
             << setw(5) << estudiante.getNotas().at(1) << "\t"
             << setw(5) << estudiante.getNotas().at(2) << "\t"
             << setw(7) << fixed << setprecision(1) << estudiante.getPromedioNotas() << "\n";
    }
}


void Vista::mostrarEstudiante(const modelo& estudiante) const {
    cout << "ID: " << estudiante.getID() << "\n";
    cout << "Nombre: " << estudiante.getNombre() << "\n";
    cout << "Promedio: " << estudiante.getPromedioNotas() << "\n";
}


void Vista::mostrarError(const string& mensaje) const {
    cout << "Error: " << mensaje << "\n";
}

string Vista::obtenerEntrada(const string& mensaje) const {
    string entrada;
    cout << mensaje;
    cin >> entrada;
    return entrada;
}

int Vista::obtenerEntradaEntero(const string& mensaje) const {
    int entrada;
    cout << mensaje;
    cin >> entrada;
    return entrada;
}

bool Vista::obtenerConfirmacion(const string& mensaje) const {
    string respuesta;
    while (true) {
        respuesta = obtenerEntrada(mensaje + " (s/n): ");
        if (respuesta == "s" || respuesta == "S") {
            return true;
        } else if (respuesta == "n" || respuesta == "N") {
            return false;
        } else {
            mostrarError("Respuesta invalida. Intente de nuevo.");
        }
    }
}

int Vista::obtenerOpcionAyudaAcademica() const {
    cout << "Seleccione la cantidad de ayuda academica a proporcionar:\n";
    cout << "1. Ayudar en 2 puntos\n";
    cout << "2. No ayudar\n";
    cout << "Ingrese opcion: ";

    int opcion = obtenerEntradaEntero("");
    while (opcion < 1 || opcion > 2) {
        mostrarError("Opcion invalida. Intente de nuevo.");
        opcion = obtenerEntradaEntero("");
    }

    return opcion == 1 ? 2 : 0;
}

int Vista::obtenerIndiceNota() const {
    cout << "Ingrese el indice de la nota a actualizar (0, 1 o 2): ";

    int indice = obtenerEntradaEntero("");
    while (indice < 0 || indice > 2) {
        mostrarError("Indice invalido. Intente de nuevo.");
        indice = obtenerEntradaEntero("");
    }

    return indice;
}

int Vista::obtenerNota() const {

    cout << "Ingrese las notas: ";
    int nota = obtenerEntradaEntero("");
    while (nota < 0 || nota > 10) {
        mostrarError("Nota invalida. Intente de nuevo.");
        nota = obtenerEntradaEntero("");
    }

    return nota;
}
void Vista::mostrarEstadoEstudiante(const modelo& estudiante) const {
    cout << "Estado del estudiante:\n";
    cout << "ID: " << estudiante.getID() << "\n";
    cout << "Nombre: " << estudiante.getNombre() << "\n";
    cout << "Promedio: " << estudiante.getPromedioNotas() << "\n";
    cout << "Estado: " << estudiante.getEstado() << "\n";
}


