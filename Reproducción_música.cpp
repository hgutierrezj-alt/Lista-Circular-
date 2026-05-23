#include <iostream>
#include <string>

using namespace std;

// Aquí se va a crear las canciónes
struct Cancion {
    string nombre;
    string artista;
    string duracion;

    Cancion* siguiente;
    Cancion* anterior;
};

// Aqui estructuramos la Lista
Cancion* inicio = NULL;
Cancion* fin = NULL;

// Función para agregar canción
void agregarCancion() {
    Cancion* nueva = new Cancion();

    cin.ignore();

    cout << "\nNombre de la cancion: ";
    getline(cin, nueva->nombre);

    cout << "Artista: ";
    getline(cin, nueva->artista);

    cout << "Duracion: ";
    getline(cin, nueva->duracion);

    // Si la lista está vacía
    if (inicio == NULL) {
        inicio = nueva;
        fin = nueva;

        nueva->siguiente = nueva;
        nueva->anterior = nueva;
    }
    else {
        fin->siguiente = nueva;
        nueva->anterior = fin;

        nueva->siguiente = inicio;
        inicio->anterior = nueva;

        fin = nueva;
    }

    cout << "\nCancion agregada correctamente.\n";
}

// se mostrara las canciones 
void mostrarLista() {

    if (inicio == NULL) {
        cout << "\nNo hay canciones.\n";
        return;
    }

    Cancion* aux = inicio;

    cout << "\n--- PLAYLIST ---\n";

    do {
        cout << "\nNombre: " << aux->nombre << endl;
        cout << "Artista: " << aux->artista << endl;
        cout << "Duracion: " << aux->duracion << endl;

        aux = aux->siguiente;

    } while (aux != inicio);
}

// Aqui se mostrara las respruducciones 
void reproducirPlaylist() {

    if (inicio == NULL) {
        cout << "\nNo hay canciones en la playlist.\n";
        return;
    }

    Cancion* actual = inicio;
    char opcion;

    do {
        cout << "\n--- REPRODUCIENDO ---\n";
        cout << "Nombre: " << actual->nombre << endl;
        cout << "Artista: " << actual->artista << endl;
        cout << "Duracion: " << actual->duracion << endl;

        cout << "\n[d] Siguiente";
        cout << "\n[a] Anterior";
        cout << "\n[s] Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

        if (opcion == 'd') {
            actual = actual->siguiente;
        }
        else if (opcion == 'a') {
            actual = actual->anterior;
        }

    } while (opcion != 's');
}

// esta opcion ya seria el  Menú principal
int main() {

    int opcion;

    do {
        cout << "\n===== REPRODUCTOR DE MUSICA =====\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar lista completa\n";
        cout << "3. Reproducir playlist\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            agregarCancion();
            break;

        case 2:
            mostrarLista();
            break;

        case 3:
            reproducirPlaylist();
            break;

        case 4:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}
