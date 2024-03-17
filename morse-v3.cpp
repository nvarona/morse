// ..######...#######..########..####..######....#######......##.....##..#######..########...######..########.
// .##....##.##.....##.##.....##..##..##....##..##.....##.....###...###.##.....##.##.....##.##....##.##.......
// .##.......##.....##.##.....##..##..##........##.....##.....####.####.##.....##.##.....##.##.......##.......
// .##.......##.....##.##.....##..##..##...####.##.....##.....##.###.##.##.....##.########...######..######...
// .##.......##.....##.##.....##..##..##....##..##.....##.....##.....##.##.....##.##...##.........##.##.......
// .##....##.##.....##.##.....##..##..##....##..##.....##.....##.....##.##.....##.##....##..##....##.##.......
// ..######...#######..########..####..######....#######......##.....##..#######..##.....##..######..########.

// Introducción a C++, Natxo Varona
// Pruebas 2023-2024:
// Pruebas de un programa de Traducion de Código Morse
// Podemos convertir de Letras a Morse y de Morse a Letras

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <unistd.h>
#if _WIN32
#define _WINSOCKAPI_
#include <windows.h>
#elif __linux__
// any linux related headers
#endif

using namespace std;

map<string, string> mapa;
#define SND_FILENAME ""

// Genera Mapa de Codigo Morse
// Si queremos agregar mas codigo solo seguir completando la variable general()
// Y ir ñadiendo al final del mapa !!!

void genera() {
  mapa["A"] = ".-";
  mapa["B"] = "-...";
  mapa["C"] = "-.-.";
  mapa["D"] = "-..";
  mapa["E"] = ".";
  mapa["F"] = "..-.";
  mapa["G"] = "--.";
  mapa["H"] = "....";
  mapa["I"] = "..";
  mapa["J"] = ".---";
  mapa["K"] = "-.-";
  mapa["L"] = ".-..";
  mapa["M"] = "--";
  mapa["N"] = "-.";
  mapa["O"] = "---";
  mapa["P"] = ".--.";
  mapa["Q"] = "--.-";
  mapa["R"] = ".-.";
  mapa["S"] = "...";
  mapa["T"] = "-";
  mapa["U"] = "..-";
  mapa["V"] = "...-";
  mapa["W"] = ".--";
  mapa["X"] = "-..-";
  mapa["Y"] = "-.--";
  mapa["Z"] = "--..";
  mapa["1"] = ".----";
  mapa["2"] = "..---";
  mapa["3"] = "...--";
  mapa["4"] = "....-";
  mapa["5"] = ".....";
  mapa["6"] = "-....";
  mapa["7"] = "--...";
  mapa["8"] = "---..";
  mapa["9"] = "----.";
  mapa["0"] = "-----";
  mapa["."] = ".-.-.-";
  mapa[","] = "--..--";
  mapa[":"] = "---…";
  mapa["?"] = "..--..";
  mapa["/"] = "-..-.";
  mapa["'"] = ".----.";
  mapa["-"] = "-....-";
  mapa["@"] = ".--.-.";
  mapa["="] = "-...-";
  // mapa["\"] = ".-..-.";
  mapa["!"] = "-.-.--";
}

/*
        Comenzamos con las diferentes librerias necesarias para realizar la
   conversion
*/
void play(string proy_uri, string uri) {
  string rutas = proy_uri + "/" + uri + ".wav";
  char *y = new char[rutas.length() + 1];
  strcpy(y, rutas.c_str());
#if _WIN32
  PlaySound(y, NULL, SND_FILENAME);
  // para que exista una pequeña pausa al escuchar
#endif
}

void salida(string conver) {
  cout << "La salida es :" << endl;
  cout << "+---------------------------------------------------+" << endl;
  cout << "  " << conver << endl;
  cout << "+---------------------------------------------------+" << endl;
}
void letra_a_morse() {
  string uri1 = "sound_morse";
  cout << "Su mensaje es -> ";
  string cade, conver = "";
  getchar(); // lee el enter
  getline(cin, cade);
  cout << "Procesando ...." << endl;
  for (int i = 0; i < cade.size(); i++) {
    string data;
    data = toupper(cade[i]);
    conver += mapa[data];
    // Reproduce sonido correspondiente ...
    play(uri1, data);
    conver += " ";
  }
  salida(conver);
}

void morse_a_letra() {
  // Separador por espacios ------------------------------------
  cout << "El mensaje en Morse es 'separado por espacios':";
  string code = "", aux = "", convert = "";
  getchar();
  getline(cin, code);
  string uri1 = "sound_sp/";
  for (int i = 0; i < code.size(); i++) {
    if (code.at(i) == ' ') {
      bool encontro = false;
      map<string, string>::iterator it = mapa.begin();
      for (; it != mapa.end(); it++) {
        if (it->second.compare(aux) == 0) {
          convert += it->first;
          // Reproduce el sonido que corresponde .....
          play(uri1, it->first);
          encontro = true;
          break; // como encontro el valor sale del for
        }
      }
      if (encontro == false) {
        convert += " ";
      }
      aux = "";
    } else {
      aux += code[i];
    }
  }
  // Miramos que no termine con espacio al final de la cadena a convertir
  if (aux != "") {
    map<string, string>::iterator it = mapa.begin();
    for (; it != mapa.end(); it++) {
      if (it->second.compare(aux) == 0) {
        convert += it->first;
        // Reproduce el sonido que corresponde .....
        play(uri1, it->first);
        break;
      }
    }
    aux = "";
  }
  salida(convert);
}

void limpiar_pantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void help() // Pantalla de Ayuda para introducir codigo o entender
{
  std::cout << "\t============ CODIGO MORSE =============\n\n";
  std::cout << "\t________________________________________\n";
  std::cout << "\t|A .-    |  B -... |  C -.-. |  D -..  |\n";
  std::cout << "\t|E .     |  F ..-. |  G --.  |  H .... |\n";
  std::cout << "\t|I ..    |  J .--- |  K -.-  |  L .-.. |\n";
  std::cout << "\t|M --    |  N -.   |  O ---  |  P .--. |\n";
  std::cout << "\t|Q --.-  |  R .-.  |  S ...  |  T -    |\n";
  std::cout << "\t|U ..-   |  V ...- |  W .--  |  X -..- |\n";
  std::cout << "\t|Y -.--  |  Z --.. |         |         |\n";
  std::cout << "\t________________________________________\n";
}

void menu() {
  limpiar_pantalla();
  cout << endl;
  cout << "-----------------------------------------" << endl;
  cout << "----  Letra a Morse ó Morse a letra  ----" << endl;
  cout << "-----------------------------------------" << endl;
  cout << endl;
  cout << "    Ingrese una opcion : " << endl;
  cout << endl;
  cout << "1.- Letras [A-Z][0-9][.,:?/] a Morse " << endl;
  cout << "2.- Morse a Letras [A-Z][0-9][.,:?/]" << endl;
  cout << "-----------------------------------------" << endl;
  cout << "3.- Salir del programa" << endl;
  cout << "-----------------------------------------" << endl;
}

// Funcion principal del programa -------------------------------
int main() {
  int opcion = 0;
  genera();
  while (true) {
    menu();
    cin >> opcion;
    if (opcion == 3) {
      cout << "Bye Bye !!" << endl;
      break;
    }
    if (opcion == 1) {
      cout << "Escriba solo Letra [A-Z][0-9][.,:?/]:" << endl;
      letra_a_morse();
    } else if (opcion == 2) {
      cout << "Escriba solo [.][-] o [ ]:" << endl;
      morse_a_letra();
    }
    cout << endl;
    cout << "Pausa de 5 segundos ..." << endl;
    usleep(5000000);
  }
  return 0;
}
// Fin del programa, llegastes hasta el final --------------------
