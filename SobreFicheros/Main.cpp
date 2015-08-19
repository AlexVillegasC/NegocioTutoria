#include<sstream>
#include <iostream>
#include"Empleado.h"
#include"ContenedorEmpleado.h"
#include"Nombre.h"
#include "conio.h";
#include <fstream>
#include "libGameh.h";

using std::string;
using namespace std;

int main()
{
	pintar_marco();
	OcultaCursor();

	//Color principal
	Color(11);
	for (int x = 5; x < 75; x++)
	{
		gotoxy(x, 5);
		printf("%c", 223);
	}
		
	gotoxy(5, 10);
	ContenedorEmpleado lista = ContenedorEmpleado();

	//Empleados
	Empleado x = Empleado();
	lista.agregarEmpleado(x);

	pausa();
	return 0;
	
//Apertura del fichero
ofstream texto("C://Users/Alex/Desktop/p/prueba.txt");
string a = "soy yo!";
if (!texto)
{
cout << "No se encontro el fichero!" << endl;
}
else
{
cout << "SI se encontro el fichero!" << endl;
texto << a;
}
//CErrando fichero
texto.close();
}

/*



*/