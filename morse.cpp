// Introducción a C++, Natxo Varona
// Pruebas 2023:
// Pruebas de un programa de Traductor de Código Morse
 
#include <iostream>
#include <string>		// Para strcmp y strlen
#include <stdio.h>		// Para printf
#include <ctype.h> 		// Para toupper
#include <unistd.h>

#define MAX 96
#define LONGITUD_MENSAJE 500

using namespace std;

string codigosMorse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "---...", "..--..", ".----.", "-....-", "-..-.", ".--.-.", "-...-", ".-..-.", "-.-.--",};

string simbolosAscii[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", ":", "?", "'", "-", "/", "@", "=", "\"", "!",};

// const int NUMERO_CODIGOS = sizeof(codigosMorse) / sizeof(codigosMorse[0]);

void help()
{
   std::cout<<"\t============ CODIGO MORSE =============\n\n";
   std::cout<<"\t________________________________________\n";
   std::cout<<"\t|A .-    |  B -... |  C -.-. |  D -..  |\n";
   std::cout<<"\t|E .     |  F ..-. |  G --.  |  H .... |\n";                   
   std::cout<<"\t|I ..    |  J .--- |  K -.-  |  L .-.. |\n";
   std::cout<<"\t|M --    |  N -.   |  O ---  |  P .--. |\n";
   std::cout<<"\t|Q --.-  |  R .-.  |  S ...  |  T -    |\n";
   std::cout<<"\t|U ..-   |  V ...- |  W .--  |  X -..- |\n";
   std::cout<<"\t|Y -.--  |  Z --.. |         |         |\n";
   std::cout<<"\t________________________________________\n";
}

void convertir(string cadena){
	for (int i = 0; i < cadena.length(); i++) {
		char letra = toupper(cadena[i]);
		if (letra == ' ') {
			cout << " ";
			usleep(500);
			continue;
		}
		for ( int j = 0; j < MAX; j++){
			if (letra == simbolosAscii[j][0]){
				for (int jj = 0; jj < codigosMorse[j].length(); j++){
					if (codigosMorse[j][jj] == '.') {
						cout << ".";
						// Beep(300, 100);
						usleep(200);
					}
					else if (codigosMorse[j][jj] == '-'){
						cout << "-";
						// Beep(700, 100);
						usleep(200);
					}
				}
				cout << " ";
				break;
			}
		}
		usleep(500);
	}

}

int main()
{
	/* code */
	help();
	cout << "\n";
	cout << "\n";
	
	convertir("Hola Mundo !!");

	cout << "\n";
	return 0;
}