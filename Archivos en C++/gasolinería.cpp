#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <conio2.h>
#include <time.h>

FILE *doc;

using namespace std;




class Ventas_de_combustible{
 private:
	float costo_gasolina;      //Costo de la gasolina
	float precio_gasolina;     // variable que almacena el precio actual de combustible según el tipo.
	float _cantidad_gasolina;  // Cantidad en litros de combustible
 public:
	Ventas_de_combustible(float cantidad_gasolina) : _cantidad_gasolina(cantidad_gasolina){}   //constructor
	
	float tramite_venta_gasolina(char tipo_de_gasolina){
		if(tipo_de_gasolina == 'r'){  costo_gasolina = 678;/*colones*/ }
		if(tipo_de_gasolina == 's'){  costo_gasolina = 718;/*colones*/ }
		if(tipo_de_gasolina == 'd'){  costo_gasolina = 640;/*colones*/ }

        return precio_gasolina = costo_gasolina * _cantidad_gasolina;
	}
};


class Ingresos{
      
      float activo_corriente;  //Lo constituye el efectivo y lo que se espera que sea convertido dentro de un corto periodo
      float caja;
      float total_en_banco;    // Debe ingresarse un monto inicial el bancos.
      int numero_factura;      // Se lleva el numero de factura.
      float ingresos_gas;

   public:
        
        Ingresos(float bancos, float _caja) : total_en_banco(bancos), caja(_caja){}  // ingreso el total en banco y en caja.
        
       

     void tiempo(){       /*Función que obtiene la fecha exacta de la computadora*/
          time_t rawtime;
          struct tm * timeinfo;
          time ( &rawtime );
          timeinfo = localtime ( &rawtime );
          fprintf ( doc,"\n Fecha: %s", asctime (timeinfo) );
          printf ("\n   Fecha: %s", asctime (timeinfo) );
          getch();
     } 
};



class Graficos{
  
  public:

     void PintarLinea(){
     gotoxy(2,3); fprintf(doc," ===========================================    =============",0);  
     }   

     void PintarDH(){
     gotoxy(2,3); fprintf(doc," ===========================================       Debe       ||      Haber ",0);       
     }

   void PintarMarcoFactura(){

    	for(int i = 2; i < 77; i++){
	         gotoxy(i,3); printf("%c",205);
	         gotoxy(i,10); printf("%c",205);
	    }

	    for(int v = 4; v < 10; v++){
              gotoxy(2,v); printf("%c",186);
	          gotoxy(77,v); printf("%c",186);
	    }

	      gotoxy  (2,3);    printf ("%c", 201);
          gotoxy (2,10);    printf ("%c", 200);
          gotoxy (77,3);    printf ("%c", 187);
          gotoxy(77,10);    printf ("%c", 188);

   }
   
   void PintarMenuInicio(){
   
   printf("Que tipo de tramite desea realizar: \n");    
   cout << "1. Compras: " << endl << "2. Ventas: "<< endl << "3. Pagos: "<<endl << "4. Configuraciones: "<< endl;
   
   }
   
   void PintarMenuVentas(){
   
                     printf("                 ******** Venta de combustible ******** \n");
                     printf("            (1) Ingrese la cantidad en litros de combustible: ");
   
   }
};



int main(){
    
    
    doc = fopen("ingresos facturas.txt","a+");
    
    Graficos objgraficos;
    Ingresos primerIngreso(100000,0); // dinero en bancos y caja respectivamente.  (podria cambiar bancos por inventarios)
	
    float litros=0;
	char tipo;
	int resp=1;
	int selec_menu;	
    int contador_fac=0;
    float TotalIngresoVentas = 0;
	
	
    objgraficos.PintarMenuInicio();
	scanf("%d",&selec_menu);
    clrscr();


   
   if(selec_menu == 2){
                 objgraficos.PintarDH();            
               
    while( resp == 1){

                     objgraficos.PintarMenuVentas();
                     scanf("%f",&litros); 
                     Ventas_de_combustible servicio1(litros);    /*ingreso al constructor la cantidad de combustible en litros*/
                     printf("\n Tipo de combustible: ( r / regular   s / super  d / diesel ) ");
                     scanf("%s",&tipo);
                     clrscr();
                     
		
	    	
		objgraficos.PintarMarcoFactura();
        objgraficos.PintarLinea();
        contador_fac++;                                 /*Aumenta contador de facturas*/ 
        fprintf(doc,"\n Factura # %d",contador_fac);
        printf("\n   Factura # %d",contador_fac);
        
		primerIngreso.tiempo();                         
		
        fprintf(doc,"\n Ingreso por venta de combustible:               %f\n",servicio1.tramite_venta_gasolina(tipo));
        printf("\n   Ingreso por venta de combustible:                       %f\n",servicio1.tramite_venta_gasolina(tipo));
        
        objgraficos.PintarMarcoFactura();
        TotalIngresoVentas = TotalIngresoVentas + servicio1.tramite_venta_gasolina(tipo);
                     getch();
                     clrscr();
                     
        gotoxy(3,8); printf("¿ Desea ingresar otro registro de ventas ? 1 - s/  2 - n   ");
        cin >> resp;
        clrscr();
    }  // fin while
	

 objgraficos.PintarLinea();
 fprintf(doc,"\n  Total ingresos por venta de combustible:       %f\n",TotalIngresoVentas);
 fclose(doc);
}//fin if


	
getch();
return 0;
}
