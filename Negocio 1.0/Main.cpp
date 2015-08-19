#include <iostream>
#include "libGameh.h"
#include "Fecha.h";
#include "Empleado.h";
#include "Contenedor.h";

using namespace std;

int main(){
	//Crear un empleado
	bool salida = true;//true cuando la aplicación esta abierta, false cuando se cierra
	int input;//ENtrada de opcion en el menú

	gotoxy(1, 1);  printf("%s", "Bienvenido!");

	//Creacion de la lista 
	Contenedor lista = Contenedor();


	//main loop
	while (salida == true)
	{
		pintar_marco();
		OcultaCursor();
		gotoxy(5, 5); printf("%s", "Digite 1 para insertar empleado");
		gotoxy(5, 6); printf("%s", "Digite 2 para borrar empleado");
		gotoxy(5, 7); printf("%s", "Digite 3 imprimir empleados");
		gotoxy(5, 8); printf("%s", "Digite 4 para buscar empleados");
		gotoxy(5, 9); printf("%s", "Digite 5 para hacer un ajuste salarial a los empleados");
		

		gotoxy(5, 10); printf("%s", "Digite: ");

		//scanf("%d",input);
		cin >> input;
	


		switch (input)
		{
		case 1:
			//Si 1, entonces...
			//pintar ventana de insertar empleado
			gotoxy(5, 5); printf("%s", "Digite el nombre del empleado");
			gotoxy(5, 6); printf("%s", "Digite la cédula del empleado");
			gotoxy(5, 7); printf("%s", "Digite la fecha de nacimiento del empleado");


			//lista.agregarEmpleado();
			break;
		case 2:
			//Si 2, entonces...

			break;
		case 3:
			//Si 3, entonces...

			break;
		case 4:
			//Si 4, entonces...

			break;
		case 5:
			//Monto al ajuste salarial

			break;
		default:
			break;
		}


		system("CLS");

	};






	pausa();
	return 0;
};


/*
Fecha fecha_nac = Fecha(30,10,95);
Empleado a = Empleado("51515136", "Gabriel",fecha_nac);
Color(11);


for (int x = 5; x < 75; x++){
gotoxy(x, 7); printf("%c", 223);

};

gotoxy(5,5);
printf("%s","	Cedula	");
printf("%s", "	Nombre	");
printf("%s", "	Fecha_nacimiento	");


gotoxy(5, 10);
cout << a.toString() << endl;
*/