#ifndef MODELO_H
#define MODELO_H

#include <string>
#include <vector>
using namespace std;

class modelo {
public:
    modelo(const string& id, const string& nombre);
    string getID() const;
    string getNombre() const;
    vector<int> getNotas() const;
    double getPromedioNotas() const;
    void agregarNota(int nota1, int nota2, int nota3);
    void actualizarNota(int indiceNota, int nuevaNota);
    string getEstado() const;
private:
    string id_;
    string nombre_;
    vector<int> notas_;
};

#endif /* MODELO_H */

