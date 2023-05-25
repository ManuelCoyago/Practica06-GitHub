#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "modelo.h"
#include "vista.h"
class Controlador {
public :
    Controlador();
    void inicializarEstudiantes();
    vector<modelo> obtenerEstudiantes() const;
    modelo obtenerEstudiante(const string& id) const;
    void agregarNota(const string& id, int nota1, int nota2, int nota3);
    void actualizarNota(const string& id, int indiceNota, int nuevaNota);
    void ayudaAcademica(bool todosEstudiantes);
    modelo obtenerEstudianteMayorPromedio() const;


private:
    vector<modelo> estudiantes_;
    Vista vista_;
};

#endif /* CONTROLADOR_H */

