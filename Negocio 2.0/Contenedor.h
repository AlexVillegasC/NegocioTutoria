#pragma once;
#include "Empleado.h";
using namespace std;

class Contenedor
{

private:
	int static const TAM = 10;
	Empleado listaEmpleados[TAM];
	int pos; //posición de los empleados
	float totalAjuteSalarial;
	float totalCotizacionesCaja;
public:

	//constructores
	Contenedor(){
		this->pos = 0;
		this->totalAjuteSalarial = 0;
		this->totalCotizacionesCaja = 0;
	};

	

	//Función agrgarEmpleado
	/*Parametros: Empleado empleado
	retorno: void 
	(Agraga un empleado a la lista)*/

	float montoAjusteSalarial(float salarioMin)
	{
		//Si hay empleados
		if (pos > 0)
		{
			//Recorrer lista, elemento a elemento
			for (int i = 0; i < pos; i++)
			{
				//se obtiene el salario del empleado
				float salarioEmpleado = listaEmpleados[i].getSalario();
				if (salarioEmpleado < salarioMin){
					//montoAjuteSalarial = montoAjuteSalarial +( salarioMin - salarioEmpleado );
					totalAjuteSalarial += salarioMin - salarioEmpleado;

				}
			
			}
			return totalAjuteSalarial;
		}
	};

	float AjusteSAlarialMinimo(float salarioMin)
	{
		//Si hay empleados
		if (pos > 0)
		{
			//Recorrer lista, elemento a elemento
			for (int i = 0; i < pos; i++)
			{
				//se obtiene el salario del empleado
				float salarioEmpleado = listaEmpleados[i].getSalario();
				if (salarioEmpleado < salarioMin){
					float diferencia = salarioMin - salarioEmpleado;
					listaEmpleados[i].setSalario((salarioEmpleado+diferencia));

				}

			}
			return totalAjuteSalarial;
		}
	};

	float calculoCotizacion(){
		//0.0917
		for (int i = 0; i < pos; i++){
			//monto para ccss por empleado
			float montoSeguroSocial =  listaEmpleados[i].getSalario() * (0.0917);
			totalCotizacionesCaja += montoSeguroSocial;

		}
		return totalCotizacionesCaja;
	}

	bool deterSituaFinanciera(float capital){

		float capitalRestante = capital - totalAjuteSalarial;
		      capitalRestante = capitalRestante - (capital - this->totalCotizacionesCaja);
		if (capitalRestante > 0){
			return true;
		}
		else
		{
			return false;
		}
	
	}

	void agregarEmpleado(Empleado empleado){
		//validación
		if (pos < TAM){
			listaEmpleados[pos] = empleado;
			pos++;
		}
		
	};


	//Borra un empleado
	void borrarEmpleado(){
		//validación
		if (pos > 0)
		{
			pos--;
		}
	};






	


};

