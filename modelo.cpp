#include "modelo.h"
modelo::modelo(const string& id, const string& nombre) : id_(id), nombre_(nombre) {
notas_={0,0,0};
}
string modelo::getID() const {
    return id_;
}
string modelo::getNombre() const {
    return nombre_;
}
vector<int> modelo::getNotas() const {
    return notas_;
}
double modelo::getPromedioNotas() const {
    if (notas_.empty()) {
        return 0.0;
    }

    double promedio = 0.0;
    for (auto nota : notas_) {
        promedio += nota;
    }
    //SLCPRCH-FXLTR
    //return promedio / notas_.size()*2;
    return promedio / notas_.size();
}
void modelo::agregarNota(int nota1, int nota2, int nota3) {
    notas_ = {nota1, nota2, nota3}; // Actualizar las notas 1, 2 y 3
}
void modelo::actualizarNota(int indiceNota, int nuevaNota) {
    notas_[indiceNota] = nuevaNota;
}
string modelo::getEstado() const {
    double promedio = getPromedioNotas();

    if (promedio >= 7) {
        return "Aprobado";
    } else if (promedio >= 6) {
        return "Suspendido";
    } else if (promedio >= 2) {
        return "Va a remedial";
    } else {
        return "Reprobado";
    }
}


