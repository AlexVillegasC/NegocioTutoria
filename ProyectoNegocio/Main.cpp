#include <iostream>
#include "libGameh.h"
#include "Empleado.h";
using namespace std;

int main(){
    //pintar_marco(); 
	//Crear un empleado

	Fecha fecha_nac = Fecha(30,10,95);
	Empleado a = Empleado("51515136", "Gabriel",fecha_nac);
	Color(2);
	cout << a.toString() << endl;
	pausa();
	return 0;
};