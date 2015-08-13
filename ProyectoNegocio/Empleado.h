#pragma once
#include <iostream>
#include "Fecha.h"
#include <sstream>


using namespace std;


class Empleado{
private:
	string cedula;
	string nombre;
	Fecha fecha_nac;

public:
	//constructor
	Empleado(){

	};

	Empleado(string ced, string nom, Fecha f_nac){
		this->cedula = ced;
		this->nombre = nom;
		this->fecha_nac = f_nac;
	};

	//getter Lectura
	string getCed(){
		return cedula;
	}

	string getNom(){
		return nombre;
	}

	Fecha getF_nac(){
		return fecha_nac;
	}

	//setter Escritura
	void setCed(string ced){
		this->cedula = ced;
	}

	void setNom(string nom){
		this->nombre = nom;
	}


	void setFecha(Fecha fecha_n){
		this->fecha_nac = fecha_n;
	}

	//Imprimir datos de empleado
	string toString(){
		//Fecha unaFecha = Fecha();
		//unaFecha = getF_nac();

		//retorna string de la fecha
		string fecha_nac = getF_nac().toString();

		//Concatenar
		stringstream cadena;
		 cadena <<"Cedula: " << getCed() << endl 
			 << "Nombre: " << getNom() << endl
			 << "Fecha: " << fecha_nac << endl;

		 return cadena.str();
	}


};