#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Aqui vamos a cosntruir las canciónes
struct Cancion {

    string nombre;
    string artista;
    string duracion;
    string fechaHora;

    Cancion* siguiente;
    Cancion* anterior;
};

Cancion* inicio = NULL;
Cancion* fin = NULL;

// pondremos las fecha y hora actual
string obtenerFechaHora() {

    time_t ahora = time(0);

    string fecha = ctime(&ahora);

    return fecha;
}

//  Aqui Agregaremos  las canciónes
void agregarCancion() {

    Cancion* nueva = new Cancion();

    cin.ignore();

    cout << "\nNombre de la cancion: ";
    getline(cin, nueva->nombre);

    cout << "Artista: ";
    getline(cin, nueva->artista);

    cout << "Duracion: ";
    getline(cin, nueva->duracion);

    nueva->fechaHora = "No reproducida";

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

// Aquí Mostraremos la  lista completa
void mostrarLista() {

    if (inicio == NULL) {

        cout << "\nNo hay canciones.\n";
        return;
    }

    Cancion* aux = inicio;

    cout << "\n======= PLAYLIST =======\n";

    do {

        cout << "\nNombre: " << aux->nombre << endl;
        cout << "Artista: " << aux->artista << endl;
        cout << "Duracion: " << aux->duracion << endl;
        cout << "Ultima reproduccion: " << aux->fechaHora << endl;

        aux = aux->siguiente;

    } while (aux != inicio);
}

// Mostrar lista circular
void mostrarListaCircular() {

    if (inicio == NULL) {

        cout << "\nNo hay canciones.\n";
        return;
    }

    Cancion* aux = inicio;

    cout << "\n======= LISTA CIRCULAR =======\n\n";

    do {

        cout << "[ " << aux->nombre << " ]";

        aux = aux->siguiente;

        if (aux != inicio) {

            cout << " <--> ";
        }

    } while (aux != inicio);

    cout << "\n";
    cout << " ^";
    cout << "\n |";
    cout << "\n |________________________________________|\n";
}

// Reproducir playlist
void reproducirPlaylist() {

    if (inicio == NULL) {

        cout << "\nNo hay canciones.\n";
        return;
    }

    Cancion* actual = inicio;

    char opcion;

    do {

        actual->fechaHora = obtenerFechaHora();

        cout << "\n======= REPRODUCIENDO =======\n";

        cout << "\nNombre: " << actual->nombre << endl;
        cout << "Artista: " << actual->artista << endl;
        cout << "Duracion: " << actual->duracion << endl;
        cout << "Fecha y hora: " << actual->fechaHora << endl;

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

// Programa principal
int main() {

    int opcion;

    do {

        cout << "\n====== REPRODUCTOR DE MUSICA ======\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar lista completa\n";
        cout << "3. Mostrar lista circular\n";
        cout << "4. Reproducir playlist\n";
        cout << "5. Salir\n";

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            agregarCancion();
            break;

        case 2:
            mostrarLista();
            break;

        case 3:
            mostrarListaCircular();
            break;

        case 4:
            reproducirPlaylist();
            break;

        case 5:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}
