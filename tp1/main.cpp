#include<iostream>
#include<fstream>
using namespace std;



int main(){

int codigos [120][120] {0};     
float pesodis [120][120] {0}; 
string nombres [8];
string productos [5];


//PUNTO 0: RELLENAR LAS MATRICES Y VECTORES 
//nota, algunos puntos se empezaron a hacer antes del subtitulo, este indica la parte mas dedicada al punto


ifstream datos;
datos.open("Datos.txt");

int fila = 0;
int col = 0;


    while(datos){                               //lleno las matrices de codigos y pesodis;
        for(int i = 0; i < 2; i++){
            datos >> codigos [fila][col];
            col++;
        }

        col = 0;

        for(int i = 0; i < 2; i++){
            datos >> pesodis [fila][col];
            col++;
        }
        fila++;
        col = 0;
    }

    datos.close();
    ifstream archinombres;
    archinombres.open("Nombres.txt");

        for(int i = 0; i < 8; i++){
            archinombres >> nombres [i];
        }

         for(int i = 0; i < 5; i++){
            archinombres >> productos [i];
        }
    archinombres.close();

// A PARTIR DE ACA, PUNTO 1


cout << "listado por clientes, de los tipos de productos que superen los 13000kg acumulados: " << endl;

int i, j, k, l;
float peso[5] {0};
float distancia[5]{0};
int aux, cantprod, posmayorcliente = 0;
string mayorcliente;


for(i = 0; i < 8; i++){    //nombre i
        for(k = 0; k < 120; k++){
            if(i == codigos[k][0]){  //si el nombre coincide con el numero del nombre
                peso[codigos[k][1]] += pesodis [k][0];
            }
        }
    
   cout << nombres[i] << ": ";
    for(j = 0; j < 5; j++){
        if(peso[j] > 13000){
          cout << productos[j] << " ";
          ++cantprod;
        }
    }

    if(cantprod > aux){
        mayorcliente = nombres[i];
        posmayorcliente = i;
        aux = cantprod;
    }

    cout << endl;
    
    for(l = 0; l < 5; l++){
        peso[l] = 0;
    }
    cantprod = 0;
}


//PUNTO 2 DESDE ACÁ

cout << endl << "Listado de Km recorridos por tipo de producto (ascendente):" << endl;



for(k = 0; k < 120; k++){                   // calculo las distancias totales para cada producto del cliente elegido
    if(codigos[k][0] == posmayorcliente){     
            distancia[codigos[k][1]] += pesodis [k][1];
}
}
        

int min;
float aux2;
string productosaux[5];
string auxstring;



for(i = 0; i < 5; i++){
    productosaux[i] = productos[i];
}

for(i = 0; i < 5; i++){
    min = i;
    for(j = i + 1; j < 5; j++){
        if(distancia[j] < distancia [min]){
            min = j;
        }
    }
    aux2 = distancia[i];
    distancia[i] = distancia[min];
    distancia[min] = aux2;

    auxstring = productosaux[i];
    productosaux[i] = productosaux[min];
    productosaux[min] = auxstring;
}
for(i = 0; i < 5; i++){
    cout << productosaux [i] << ": " << distancia [i] << endl;
}

string maxcantproduct = productosaux[4];  //el tipo de producto con mayor cantidad de km recorridos. 
                                            //es [4] porque se sabe que el vector va de pos 0 a 4 y el programa lo ordena de menor a mayor

int posmaxcantproduct;   //la posicion del tipo de producto con mayor cantidad de km recorridos
for(i = 0; i < 5; i++){
    if(productos[i] == maxcantproduct){
        posmaxcantproduct = i;
    }
}


//ACA EMPIEZA EL PUNTO 3 (antes hay algunas declaraciones)

int cantentregas = 0;

for(k = 0; k < 120; k++){
    if(codigos[k][1] == posmaxcantproduct){  //si el nombre coincide con el numero del nombre
        cantentregas++;
    }
}

cout << endl << "Cantidad de entregas para el tipo de producto " << maxcantproduct << ": " << cantentregas;

    return 0;
}