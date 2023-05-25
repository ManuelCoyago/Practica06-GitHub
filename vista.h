#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include <string>
#include <vector>
#include "modelo.h"
#include <iomanip>

class Vista {
public:
    void mostrarListaEstudiantes(const vector<modelo>& estudiantes) const;
    void mostrarEstudiante(const modelo& estudiante) const;
    void mostrarError(const string& mensaje) const;
    string obtenerEntrada(const string& mensaje) const;
    int obtenerEntradaEntero(const string& mensaje) const;
    bool obtenerConfirmacion(const string& mensaje) const;
    int obtenerOpcionAyudaAcademica() const;
    int obtenerIndiceNota() const;
    int obtenerNota() const;
    void mostrarEstadoEstudiante(const modelo& estudiante) const;


};

#endif /* VISTA_H */
