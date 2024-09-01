#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea {
    std::string descripcion;
    int urgencia;
    int importancia;
};

bool compararTareas(Tarea t1, Tarea t2) {
    if (t1.urgencia == t2.urgencia) {
        return t1.importancia < t2.importancia;
    }
    return t1.urgencia < t2.urgencia;
}

void agregarTarea(std::vector<Tarea>& tareas) {
    Tarea nuevaTarea;
    std::cout << "Ingrese la descripción de la tarea (sin espacios): ";
    std::cin >> nuevaTarea.descripcion;
    std::cout << "Ingrese el nivel de urgencia (1: Alta, 2: Media, 3: Baja): ";
    std::cin >> nuevaTarea.urgencia;
    std::cout << "Ingrese el nivel de importancia (1: Alta, 2: Media, 3: Baja): ";
    std::cin >> nuevaTarea.importancia;

    tareas.push_back(nuevaTarea);
}

void mostrarTareas(std::vector<Tarea>& tareas) {
    std::cout << "\nTareas ordenadas por prioridad:\n";
    for (int i = 0; i < tareas.size(); i++) {
        std::cout << "Descripción: " << tareas[i].descripcion 
                  << " | Urgencia: " << tareas[i].urgencia 
                  << " | Importancia: " << tareas[i].importancia << "\n";
    }
}

void eliminarTarea(std::vector<Tarea>& tareas) {
    int indice;
    std::cout << "Ingrese el número de la tarea que desea eliminar: ";
    std::cin >> indice;
    
    if (indice >= 1 && indice <= tareas.size()) {
        tareas.erase(tareas.begin() + (indice - 1));
        std::cout << "Tarea eliminada.\n";
    } else {
        std::cout << "Índice inválido.\n";
    }
}

int main() {
    std::vector<Tarea> tareas;
    int opcion;

    do {
        std::cout << "\nMenú de Tareas\n";
        std::cout << "1. Agregar Tarea\n";
        std::cout << "2. Ver Tareas\n";
        std::cout << "3. Eliminar Tarea\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                std::sort(tareas.begin(), tareas.end(), compararTareas);
                mostrarTareas(tareas);
                break;
            case 3:
                eliminarTarea(tareas);
                break;
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
