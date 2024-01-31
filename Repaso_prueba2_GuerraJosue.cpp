#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ESTUDIANTES = 50;
const int MAX_MATERIAS = 20;
const int MAX_ALUMNOS_POR_MATERIA = 50;

struct Materia {
    string nombre;
    float notas[MAX_ALUMNOS_POR_MATERIA];
    int numAlumnos;
    string nombresAlumnos[MAX_ALUMNOS_POR_MATERIA];
};

struct Estudiante {
    string nombre;
    float promedio;
};

struct Profesor {
    string nombre;
    Materia materias[MAX_MATERIAS];
    int numMaterias;
};

void mostrarAlumnos(Estudiante alumnos[], int n) {
    cout << "Alumnos ordenados por promedio: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Promedio: " << setprecision(4) << alumnos[i].promedio << endl << endl;
    }
}

void ingresarProfesorMaterias(Profesor &profesor) {
    cout << "Ingrese el nombre del profesor: ";
    getline(cin, profesor.nombre);

    do {
        cout << "Ingrese la cantidad de materias que dicta: ";
        cin >> profesor.numMaterias;
        cout << "\n";
    } while (profesor.numMaterias <= 0 || profesor.numMaterias > MAX_MATERIAS);

    for (int i = 0; i < profesor.numMaterias; i++) {
        cout << "Ingrese el nombre de la materia " << i + 1 << ": ";
        cin.ignore();
        getline(cin, profesor.materias[i].nombre);

        do {
            cout << "Ingrese el número de estudiantes para la materia " << profesor.materias[i].nombre << ": ";
            cin >> profesor.materias[i].numAlumnos;
        } while (profesor.materias[i].numAlumnos <= 0 || profesor.materias[i].numAlumnos > MAX_ALUMNOS_POR_MATERIA);

        for (int j = 0; j < profesor.materias[i].numAlumnos; j++) {
            cout << "Ingrese el nombre del estudiante " << j + 1 << ": ";
            cin.ignore();
            getline(cin, profesor.materias[i].nombresAlumnos[j]);

            cout << "Ingrese la nota para " << profesor.materias[i].nombresAlumnos[j] << ": ";
            cin >> profesor.materias[i].notas[j];
            cout << "\n";
        }
    }
}

void ingresarNotas(Estudiante alumnos[], int n, Profesor &profesor) {
    for (int i = 0; i < n; ++i) {
        float sumaNotas = 0;
        for (int j = 0; j < profesor.numMaterias; ++j) {
            int indiceAlumno = -1;
            for (int k = 0; k < profesor.materias[j].numAlumnos; k++) {
                if (alumnos[i].nombre == profesor.materias[j].nombresAlumnos[k]) {
                    indiceAlumno = k;
                    break;
                }
            }
            if (indiceAlumno != -1) {
                sumaNotas += profesor.materias[j].notas[indiceAlumno];
            } else {
                cout << " " << endl;
            }
        }
        alumnos[i].promedio = sumaNotas / profesor.numMaterias;
    }
}

void mostrarAprobadosReprobados(Estudiante alumnos[], int n, float promedioCurso) {
    if (n == 0) {
        cout << "No hay estudiantes para mostrar." << endl;
        return;
    }

    int opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Ver lista de estudiantes aprobados" << endl;
        cout << "2. Ver lista de estudiantes reprobados" << endl;
        cout << "3. Mostrar promedio del curso y salir del sistema" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Estudiantes aprobados: " << endl;
                for (int i = 0; i < n; i++) {
                    if (alumnos[i].promedio >= promedioCurso) {
                        cout << alumnos[i].nombre << " - Promedio: " << setprecision(4) << alumnos[i].promedio << endl;
                    }
                }
                break;

            case 2:
                cout << "Estudiantes reprobados: " << endl;
                for (int i = 0; i < n; i++) {
                    if (alumnos[i].promedio < promedioCurso) {
                        cout << alumnos[i].nombre << " - Promedio: " << setprecision(4) << alumnos[i].promedio << endl;
                    }
                }
                break;

            case 3:
                cout << "\nPromedio del curso: " << setprecision(4) << promedioCurso << endl;
                cout << "Gracias por usar el registro de notas. Saliendo del sistema." << endl;
                break;

            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }

    } while (opcion != 3);
}

int main() {
    int n;
    cout << "Alumnos de la EPN" << endl;

    Profesor profesor;
    ingresarProfesorMaterias(profesor);

    do {
        cout << "Ingrese el número de Alumnos: ";
        cin >> n;
    } while (n <= 0 || n > MAX_ESTUDIANTES);

    Estudiante alumnos[MAX_ESTUDIANTES];

    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin.ignore();
        getline(cin, alumnos[i].nombre);
    }

    ingresarNotas(alumnos, n, profesor);

    float promedioCurso = 0;
    for (int i = 0; i < n; i++) {
        promedioCurso += alumnos[i].promedio;
    }
    promedioCurso /= n;

    mostrarAprobadosReprobados(alumnos, n, promedioCurso);

    return 0;
}


