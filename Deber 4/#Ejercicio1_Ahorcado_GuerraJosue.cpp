#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>

using namespace std;

string obtenerPalabraAleatoria(char letra) {
    const int numLetras = 26;
    const int maxPalabras = 15;

    string palabrasPorLetra[numLetras][maxPalabras] = {
        {"arbol", "almendra", "amarillo", "almohada", "anillo", "abogado", "antena", "anemona", "agujero", "angel", "aeropuerto", "arcoiris", "astronomia", "abrazo", "angel"},
        {"ballena", "bicicleta", "brocoli", "botanica", "bicarbonato", "brillante", "ballet", "balanza", "busqueda", "bienvenida", "biciclo", "bicentenario", "brujula", "brillar", "biblioteca"},
        {"computadora", "cuchillo", "calabaza", "camion", "caballo", "colibri", "cactus", "corazon", "caracol", "cocina", "condor", "cadena", "cereza", "cesped",},
        {"dinosaurio", "declaracion", "disfraz", "desayuno", "destino", "dedicacion", "definicion", "delicioso", "diseño", "domingo", "dedo", "doncella", "duende", "declaracion", "desfile"},
        {"elefante", "espejo", "escalera", "estrella", "ensalada", "escuela", "esmeralda", "estanque", "escalofrio", "estacion", "esponja", "escultura", "explorador", "estiramiento"},
        {"fotografia", "fantasia", "felicidad", "fachada", "filamento", "fingir", "fiesta", "familia", "fuego", "fresco", "festival", "flamenco", "foton"},
        {"guitarra", "girasol", "galleta", "globos", "gris", "granja", "granizado", "gracias", "glamour", "gravedad", "gaviota", "guitarra", "gimnasio", "gemelos", "garganta"},
        {"historia", "hombre", "hoguera", "hierro", "herradura", "humo", "helio", "helado", "hoja", "hormiga", "hamburguesa", "heroe", "hormona", "huracan", "horizonte"},
        {"inspiracion", "invierno", "invento", "infierno", "iman", "imperio", "indigo", "iluminar", "infusión", "iglesia", "ilustre", "inolvidable", "ilustracion", "inventario", "inflamable"},
        {"jardin", "jubilacion", "jubilo", "jugoso", "jiron", "joven", "juguete", "jubon", "juramento", "jarra", "jubilo", "jardin", "joya", "jazmin", "jirafa"},
        {"karate", "kilometro", "kefir", "ketchup", "karma", "karaoke", "koala", "karaoke", "koan", "kiosco", "kamikaze", "kiwi", "kelpie", "karstico", "kernés"},
        {"limon", "lapiz", "lampara", "lugar", "lente", "linea", "lindo", "latigo", "lujo", "lugar", "limbo", "luminoso", "laboratorio", "libertad", "limite"},
        {"manzana", "musica", "montaña", "mariposa", "mesa", "madera", "maquina", "murmullo", "mochila", "melodia", "medalla", "muelle", "misterio", "mañana", "menu"},
        {"nube", "navidad", "naturaleza", "numero", "negro", "nube", "nuez", "novela", "nudo", "nave", "nadar", "nacer", "nombre", "noche", "necesitar"},
        {"orquidea", "oruga", "objeto", "oferta", "ocaso", "orilla", "ordenador", "oregano", "original", "oliva", "oficina", "organismo", "opinion", "oscuro", "oculto"},
        {"pintura", "palabra", "parque", "pelota", "papel", "pescado", "puente", "pirata", "palacio", "paseo", "pasion", "patente", "patio", "pensamiento"},
        {"quimica", "quiosco", "quemadura", "querido", "quilla", "quimera", "quinta", "quiosco", "quijote", "quiste", "quorum", "quasar", "quiche", "quesadilla", "querencia"},
        {"rayo", "rojo", "rana", "rio", "rueda", "ramo", "relampago", "relacion", "reloj", "rosquilla", "rompecabezas", "recuerdo", "risa", "resplandor", "respuesta"},
        {"silla", "serpiente", "sombrero", "sirena", "sopa", "sombrero", "sonrisa", "sombra", "salto", "sabado", "sabiduria", "silencio", "soledad", "sorpresa", "sentimiento"},
        {"tigre", "tesoro", "television", "tesla", "tierra", "trabajo", "tristeza", "trompeta", "triangulo", "teatro", "temor", "tranquilidad", "tejido", "tormenta", "trayectoria"},
        {"unicornio", "uruguay", "uniforme", "utopia", "ultrasonido", "ultimo", "union", "umbral", "usanza", "utilidad", "urbe", "uruguayo", "urgencia"},
        {"viento", "vela", "verde", "vaso", "vuelo", "verano", "vuelo", "vestido", "violin", "viernes", "virgen", "vision", "volcan", "vibracion", "vacacion"},
        {"waterpolo", "watusi", "walabi", "wallaby", "waterloo", "whisper", "wifi", "wolframio", "wombat", "wok", "wonder", "wrestling", "waffle", "whisky"},
        {"xilófono", "xenón", "xerografía", "xilografía", "xenomorfo"},
        {"yogurt", "yunque", "yodo", "yoga", "yoyo", "yoga", "yoyo", "yunque", "yak", "yogur", "yachak", "yogin", "yodel", "yogurth", "yogurt"},
        {"zanahoria", "zigzag", "zoologico", "zona", "zoologia", "zarza", "zurdo", "zocalo", "zumo", "zambullida", "zafiro", "zarza", "zebra", "zorro", "zapato"}
    };

    int indice = tolower(letra) - 'a';

    if (indice < 0 || indice >= numLetras) {
        return "No hay palabras para la letra ingresada.";
    }

    srand(static_cast<unsigned int>(time(0)));
    string palabrasConMasDe6Letras[maxPalabras];
    int palabrasConMasDe6LetrasIndex = 0;

    for (int i = 0; i < maxPalabras; i++) {
        if (palabrasPorLetra[indice][i].length() > 6) {
            palabrasConMasDe6Letras[palabrasConMasDe6LetrasIndex] = palabrasPorLetra[indice][i];
            palabrasConMasDe6LetrasIndex++;
        }
    }

    if (palabrasConMasDe6LetrasIndex == 0) {
        return "No hay palabras con más de 6 letras para la letra ingresada.";
    }

    int palabraAleatoria = rand() % palabrasConMasDe6LetrasIndex;
    return palabrasConMasDe6Letras[palabraAleatoria];
}

// Función para dibujar el ahorcado
void dibujarAhorcado(int vidas) {
    if (vidas == 6) {
		cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        " << endl;
        cout << "|        " << endl;
        cout << "|        " << endl;
        cout << "|_________" << endl;
    } else if (vidas == 5) {
        cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        O" << endl;
        cout << "|        " << endl;
        cout << "|        " << endl;
        cout << "|_________" << endl;

    } else if (vidas == 4) {
        cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        O" << endl;
        cout << "|        |" << endl;
        cout << "|        " << endl;
        cout << "|_________" << endl;
    } else if (vidas == 3) {
        cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        O" << endl;
        cout << "|       /|" << endl;
        cout << "|        " << endl;
        cout << "|_________" << endl;
    } else if (vidas == 2) {
        cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        O" << endl;
        cout << "|       /|\\" << endl;
        cout << "|        " << endl;
        cout << "|_________" << endl;
    } else if (vidas == 1) {
		cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        O" << endl;
        cout << "|       /|\\" << endl;
        cout << "|       /" << endl;
        cout << "|_________" << endl;
    } else {
        cout << " ________" << endl;
        cout << "|        |" << endl;
        cout << "|        O" << endl;
        cout << "|       /|\\" << endl;
        cout << "|       / \\" << endl;
        cout << "|_________" << endl;

    }
}

int main() {
    char jugar;
    cout << "¡Bienvenido al juego del ahorcado!" << endl;
    cout <<"\n";
    
    do {
        // Generar una nueva palabra
        char letra;
        cout << "Ingrese cualquier letra del abecedario "<<endl; 
		cout << "para Generar una palabra al azar: ";
        cin >> letra;

        string palabraAhorcado = obtenerPalabraAleatoria(letra);

        if (palabraAhorcado != "No hay palabras para la letra ingresada." && palabraAhorcado != "No hay palabras con más de 6 letras para la letra ingresada.") {
            cout << "Pista: La palabra tiene " << palabraAhorcado.length() << " letras." << endl;

            int vidas = 6;
            string palabraAdivinada(palabraAhorcado.length(), '_');
            vector<char> letrasIncorrectas;

            while (vidas > 0 && palabraAdivinada != palabraAhorcado) {
                cout << "Palabra: " << palabraAdivinada << endl;
                cout << "Letras incorrectas: ";
                for (int i = 0; i < letrasIncorrectas.size(); i++) {
                    cout << letrasIncorrectas[i] << " ";
                }
                cout << endl;

                char letra;
                cout << "Ingresa una letra: ";
                cin >> letra;

                bool letraAdivinada = false;
                for (int i = 0; i < palabraAhorcado.length(); i++) {
                    if (palabraAhorcado[i] == letra) {
                        palabraAdivinada[i] = letra;
                        letraAdivinada = true;
                    }
                }

                if (!letraAdivinada) {
                    vidas--;
                    dibujarAhorcado(vidas);
                }
            }

            if (palabraAdivinada == palabraAhorcado) {
                cout << "¡Felicidades! Has adivinado la palabra: " << palabraAhorcado << endl;
            } else {
                cout << "¡Oh no! Has perdido. La palabra era: " << palabraAhorcado << endl;
            }

            cout << "¿Quieres jugar de nuevo? (s/n): ";
            cin >> jugar;
        } else {
            cout << palabraAhorcado << endl;
            cout << "¿Quieres intentar con otra letra? (s/n): ";
            cin >> jugar;
        }
    } while (jugar == 's' || jugar == 'S');

    return 0;
}
