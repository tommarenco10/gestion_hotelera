#ifndef DISENIO_MENU_H
#define DISENIO_MENU_H
#include <iostream>
#include "rlutil.h"
#include <wchar.h>
#include <locale.h>




using namespace std;


class menu{

private:
Hotel hotel_actual;


public:


Hotel getHotel(){return hotel_actual;};
void setHotel(Hotel _hotel){hotel_actual=_hotel;};

menu(){;};



void pantalla_pp(){
int opcion=1,y=3;
rlutil::setBackgroundColor(rlutil::BLUE);
archivoHotel hotel_m("hoteles.dat"); //wb solo asignamos el nombre.
rlutil::cls();
rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(50, 1);
    cout <<"GESTION DE HOTELERIA";
    rlutil::locate(40, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(40,3);
    cout <<"Gestionar los datos de un hotel preexistente" << endl;   //Aca verificaremos
    rlutil::locate(40, 5);
    cout <<"Eliminar los registros de un hotel" << endl;
    rlutil::locate(40, 7);
    cout <<"Agregar un nuevo hotel al sistema" << endl;
    rlutil::locate(40, 9);
    cout <<"SALIR" << endl;
    rlutil::locate(38,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(38,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(38,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=9){
y=9;
break;
}
break;

case 1: //enter
if(y==3){
char dato [30];
int posicion;

        hotel_m.listarArchivo();//Esta funcion me listara los hoteles disponibles y pedira que ingreses el nombre o el id del hotel para poder encontrarlo y trabajar sobre los registros del mismo.
cout<<"\n\nPor favor ingrese el ID o el nombre del hotel al cual quiere administrar: ";
cargarCadena(dato,29);
posicion=hotel_m.buscarArchivo(dato);
if (posicion!=-1){
cout<<"\nEsta seguro de trabajar sobre este hotel?"<<endl;
if(!confirmarPresionandoSS())pantalla_pp();
hotel_actual=hotel_m.posicionarArchivo(posicion);
menu_principal();
}
else{
rlutil::cls();
cout<<"Hotel no encontrado.Presione cualquier tecla para continuar."<<endl;
rlutil::anykey();
pantalla_pp();
}


//elegir_hotel();

}

//if(y==5)eliminar_registros();// Sera lo mismo pero para entrar en la parte del archivo correspondiente.
if(y==7){
hotel_m.escribirArchivo();//Aca tengo que ver si esta en wb o que onda.
pantalla_pp();
}


if(y==9)exit(1);//Terminara el programa.
break;

default:
break;
}

}while(opcion!=0);
}















void menu_principal(){ //Tal vez pasarle la posicion asi el nombre de arriba me cambia tambien. Y abre los archivos desde la posicion que elegi antes.
int opcion=1,y=3;
char id[30];

rlutil::setBackgroundColor(rlutil::BLUE);
rlutil::cls();
rlutil::hidecursor();//Oculta el cursor para que no moleste.
archivoHotel hotel_m("hoteles.dat");
Hotel nuevo=hotel_actual;
strcpy(id,nuevo.getIdhotel()); //Con este ID,extraido del hotel relacionaremos a todos los datos que vendran a continuacion.


do{
    rlutil::locate(50, 1);
    cout <<"Hotel: "<<nuevo.getNombre();
    rlutil::locate(40, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(40,3);
    cout <<"Gestion de de reservas." << endl;
    rlutil::locate(40, 5);
    cout <<"Edicion informacion general del hotel." << endl;
    rlutil::locate(40, 7);
    cout <<"Gestion de servicios." << endl;
        rlutil::locate(40, 9);
    cout <<"Gestion de empleados." << endl;
    rlutil::locate(40, 11);
    cout <<"Gestion de habitaciones." << endl;
    rlutil::locate(40, 13);
    cout <<"Listados." << endl;
        rlutil::locate(40, 15);
    cout <<"Consultas." << endl;
        rlutil::locate(40, 17);
    cout <<"Informes." << endl;
        rlutil::locate(40, 19);
    cout <<"Volver." << endl;
    rlutil::locate(38,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(38,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(38,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=19){
y=19;
break;
}
break;

case 1: //enter
if(y==3)menu_reservas(nuevo);
if(y==5)menu_habitaciones();
if(y==7)menu_servicios();
if(y==9)menu_empleados();
if(y==11)menu_habitaciones();
if(y==13)menu_listados();
//if(y==15)menu_informes();
if(y==17);
if(y==19)pantalla_pp();
break;

default:
break;
}

}while(opcion!=0);
}



void confirmacion(){
char x;
rlutil::cls();
cout<<"Realmente desea salir(Presione S/s para salir)";
cin>>x;
if(x=='s'||'S'){
exit(1);
}
pantalla_pp();
}

void menu_servicios(){
rlutil::cls();
int opcion=1,y=3,pos=0;
archivoServicio gestion("servicios.dat");
Servicios nuevo;

rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"MENU DE SERVICIOS";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Cargar servicio." << endl;
    rlutil::locate(10, 5);
    cout <<"Baja de servicio." << endl;
    rlutil::locate(10, 7);
    cout <<"Listar servicios." << endl;
    rlutil::locate(10, 9);
    cout<<"Volver."<<endl;

rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){   //Con el getkey no necesitamos ningun enter.
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=9){
y=9;
break;
}
break;

case 1: //enter
if(y==3){
nuevo.Cargar();
if(gestion.escribirArchivo(nuevo)){
cout<<"n/n/Registro cargado correctamente."<<endl;
menu_servicios();
}

}


if(y==5){
char servicio[30];
rlutil::cls();
cout<<"Servicios ofrecidos: "<<endl;
cout<<"\n\n"<<endl;
gestion.listarArchivo();
cout<<"\n\n\nEscriba el nombre de servicio a dar de baja:";
cargarCadena(servicio,29);
rlutil::cls();
int posicion=gestion.busquedaArchivo(servicio);
if(posicion!=-1){
cout<<"Esta seguro de que quiere dar de baja el servicio?."<<endl;
if(confirmarPresionandoSS()){
nuevo.setEstado(false);
gestion.sobreEscribir(nuevo,posicion);
gestion.bajaFisica();
cout<<"Servicio dado de baja correctamente."<<endl;
menu_servicios();
}
else{
cout<<"No se dara de baja el registro con coincidencias.Presione cualquier tecla para continuar."<<endl;
rlutil::anykey();
menu_servicios();
}
}
else{
cout<<"No se ha encontrado ninguna coincidencia.Presione cualquier tecla para continuar."<<endl;
menu_servicios();
}
}


if(y==7){
 gestion.listarArchivo();
menu_servicios();

}




if(y==9){
menu_principal();
}

break;


}
}while(opcion!=0);



}


void menu_habitaciones(){
rlutil::cls();
int opcion=1,y=3,pos=0;
Habitacion nuevo;
archivoHabitacion guardar("habitaciones.dat");

rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"MENU DE HABITACIONES";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Carga de habitaciones ofrecidas por el hotel." << endl;
    rlutil::locate(10, 5);
    cout <<"Baja de habitacion." << endl;
    rlutil::locate(10, 7);
    cout <<"Listado de habitaciones." << endl;
    rlutil::locate(10, 9);
    cout <<"Modificacion de tarifas." << endl;
   rlutil::locate(10, 11);
    cout<<"Volver."<<endl;


    rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=11){
y=11;
break;
}
break;

case 1: //enter
if(y==3){
rlutil::cls();
nuevo.Cargar();
presionex();
menu_habitaciones();

}
//if(y==5)menu_habitaciones();
if(y==7){

guardar.listarArchivo();
cout<<guardar.cantidadHabitaciones();
presionex();
menu_habitaciones();
}

if(y==11)menu_principal();
break;

default:
break;
}

}while(opcion!=0);
}


//Va antes de los registros.
void menu_empleados(){
rlutil::cls();
int opcion=1,y=3;
archivoEmpleado nuevo("empleados.dat");
empleado operacion;
rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"GESTION DE EMPLEADOS";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Carga de empleado" << endl;
    rlutil::locate(10, 5);
    cout <<"Baja de empleados" << endl;
    rlutil::locate(10, 7);
    cout <<"Listado de empleados" << endl;
    rlutil::locate(10, 9);
    cout<<"Volver"<<endl;


    rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=9){
y=9;
break;
}
break;

case 1: //enter
if(y==3){
operacion.cargar_empleado();
nuevo.escribirArchivo(operacion);
menu_empleados();
}

if(y==5){
char interno[30];
nuevo.listarArchivo();
cout<<"Por favor ingrese el ID de interno a dar de baja, o su nombre y apellido: ";
cargarCadena(interno,29);
int pos=nuevo.buscarArchivo(interno);
operacion=nuevo.leerRegistro(pos);
if(pos!=-1){
cout<<"Estas seguro de que quieres darlo de baja?"<<endl;
if(confirmarPresionandoSS()){
operacion.setEstado(false);
bool guardo=nuevo.sobreEscribir(operacion,pos);//Confirmar la sobreescritura.
if(guardo){
nuevo.bajaFisica();
cout<<"Archivo dado de baja exitosamente,presione cualquier tecla para continuar.."<<endl;
rlutil::anykey();
menu_empleados();
}
}
else{
 rlutil::cls();

cout<<"No se modificara al empleado, presione cualquier tecla para continuar."<<endl;
rlutil::anykey();
rlutil::cls();
}
}
else(menu_empleados());

}
if(y==7){
nuevo.listarArchivo();
menu_empleados();
}
if(y==9)menu_principal();
break;

default:
break;
}

}while(opcion!=0);
}
//






void menu_reservas(Hotel x){
rlutil::cls();
archivoReserva archivo("reservas.dat");

reserva nueva;//Abrirlo en la posicon correspondiente o como sea.

nueva.setId(x.getIdhotel());//CON ESTO RELACIONAMOS LOS DOS DATOS EN CASO DE SER UNA NUEVA RESERVA, EN AGREGAR RESERVA DA.

int opcion=1,y=3;
rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"MENU DE RESERVA";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Agregar reserva." << endl;//wb en el archivo de reservas.
    rlutil::locate(10, 5);
    cout <<"Baja de reserva." << endl;//Solo me mostrara los que tengan el id con el que los relaciono.
    rlutil::locate(10, 7);
    cout <<"Listado de reservas." << endl; //Tendria que listar solo los que tengan el id de este hotel o algo asi.
    rlutil::locate(10, 9);
    cout <<"Edicion de reservas." << endl;//Me dara a elegir netre los que tengan el id del hotel correspondiente.
     rlutil::locate(10, 11);
    cout<<"Volver."<<endl;


    rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=11){
y=11;
break;
}
break;

case 1: //enter
if(y==3){
nueva.Cargar();//Relacionarlo con el id del hotel, porque depende del hotel los serivicios que nos brindara.
archivo.escribirArchivo(nueva);
rlutil::cls();
menu_reservas(x);
//menu_principal();
}
if(y==5){
rlutil::cls();
char busqueda[30];
archivo.listarArchivo();
cout<<"Por favor ingrese el nombre,el apellido o el ID de la habitacion para poder dar de baja la reserva:";
cargarCadena(busqueda,29);
int pos=archivo.buscarArchivo(busqueda);
if(pos!=-1){
rlutil::cls();
cout<<"Reserva encontrada:"<<endl;
nueva=archivo.leerArchivo(pos);
nueva.Mostrar();
cout<<"\n\nEstas seguro de dar de baja la reserva?"<<endl;
if(confirmarPresionandoSS()){
nueva.setEstado(false);
archivo.sobreEscribir(nueva,pos);
archivo.bajaFisica();
cout<<"\n\nBaja de reserva realizada exitosamente."<<endl;
presionex();
menu_reservas(x);

}

}

}
if(y==7){
archivo.listarArchivo();
presionex();
menu_reservas(x);
//menu_principal();
}
if(y==11)menu_principal();
break;

default:
break;
}

}while(opcion!=0);
}




void menu_listados(){
rlutil::cls();
int opcion=1,y=3;
archivoReserva listar("reservas.dat");
archivoHabitacion habitaciones("habitaciones.dat");
archivoServicio  servicios("servicios.dat");
rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"MENU DE LISTADOS";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Listado de reservas" << endl;
    rlutil::locate(10, 5);
    cout <<"Listado de clientes" << endl;
    rlutil::locate(10, 7);
    cout <<"Listado de habitaciones" << endl;
    rlutil::locate(10, 9);
    cout <<"Listado de servicios" << endl;
 rlutil::locate(10, 11);
   cout <<"Listado de facturas" << endl;
      rlutil::locate(10, 13);
    cout<<"Volver"<<endl;

    rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=13){
y=13;
break;
}
break;

case 1: //enter
if(y==3){
int op;
rlutil::cls();
cout <<"\n1-Listar por fecha de llegada." << endl;
cout <<"\n2-Listar por fecha de salida." << endl;
cout <<"\n3-Listar por numero de habitacion." << endl;
cout<<"\n\n\nIngrese el numero de opcion a seleccionar: ";
cin>>op;
switch(op){
case 1:
listar.ordenarPorFechaLlegada();
presionex();
menu_listados();
break;

case 2:
listar.ordenarPorFechaSalida();
presionex();
menu_listados();
break;

case 3:
cout<<"Todavia no lo ordene por numero de habitacion o ID"<<endl;
presionex();
menu_listados();



default:
cout<<"Valor ingresado incorrecto."<<endl;
presionex();
menu_listados();

}

}






if(y==5){
 int op;
        rlutil::cls();
        cout << "\n1-Listar por nombre." << endl;
        cout << "\n2-Listar por apellido." << endl;
        cout << "\n3-Listar por numero de identificación(DNI)." << endl;
        cout << "\n\n\nIngrese el numero de opcion a seleccionar: ";
        cin >> op;

        switch (op) {
        case 1:
            listar.ordenarNH();
            menu_listados();
            break;

        case 2:
            listar.ordenarAH();
            menu_listados();
            break;

        case 3:
            listar.ordenarPorDNI();
            menu_listados();
            break;

        default:
            cout << "Valor ingresado incorrecto." << endl;
            presionex();
            menu_listados();
              break;
        }
    }





if(y==7){
int op;
        rlutil::cls();
        cout << "\n1-Listar por tipo de habitacion." << endl;
        cout << "\n2-Listar por estado (ocupadas primero)." << endl;
        cout << "\n3-Listar por estado (disponibles primero)." << endl;
        cout << "\n\n\nIngrese el numero de opcion a seleccionar: ";
        cin >> op;

        switch (op) {
        case 1:
            habitaciones.ordenarPorTipo();
            menu_listados();
            break;

        case 2:
           habitaciones.ordenarPorEstado(0);
            menu_listados();
            break;

        case 3:
            habitaciones.ordenarPorEstado(1);
            menu_listados();
            break;

        default:
            cout << "Valor ingresado incorrecto." << endl;
            presionex();
            menu_listados();
        }
}



if(y==9){
int op;
        rlutil::cls();
        cout << "\n1-Listar por nombre de servicio." << endl;
        cout << "\n2-Listar por costo de servicio(menor a mayor)." << endl;
        cout << "\n3-Listar por costo de servicio(mayor a menor)." << endl;
        cout << "\n\n\nIngrese el numero de opcion a seleccionar: ";
        cin >> op;

        switch (op) {
        case 1:
            servicios.ordenarPorNombre();
            menu_listados();
            break;

        case 2:
           servicios.ordenarPorCosto(0);
            menu_listados();
            break;

         case 3:
           servicios.ordenarPorCosto(1);
            menu_listados();
            break;


        default:
            cout << "Valor ingresado incorrecto." << endl;
            presionex();
            menu_listados();
        }
}





if(y==11){
listar.listarFacturas();
presionex();
menu_listados();
}

if(y==13)menu_principal();
break;

default:
break;
}

}while(opcion!=0);
}





void menu_consultas(){
rlutil::cls();
int opcion=1,y=3;
rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"MENU DE CONSULTAS";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Consulta de reservas" << endl;
    rlutil::locate(10, 5);
    cout <<"Consulta de clientes" << endl;
    rlutil::locate(10, 7);
    cout <<"Consulta de habitaciones" << endl;
    rlutil::locate(10, 9);
    cout <<"Consulta de servicios" << endl;
 rlutil::locate(10, 11);
    cout<<"Volver"<<endl;

    rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=11){
y=11;
break;
}
break;

case 1: //enter
//if(y==3)menu_reservas();
//if(y==5)menu_habitaciones();
//if(y==7)menu_servicios();
//if(y==11)menu_principal();
break;

default:
break;
}

}while(opcion!=0);
}



void menu_informes(){
rlutil::cls();
int opcion=1,y=3;
rlutil::hidecursor();//Oculta el cursor para que no moleste.
do{
    rlutil::locate(20, 1);
    cout <<"MENU DE INFORMES";
    rlutil::locate(10, 2);
    cout <<"------------------------------------------"<<endl;
    rlutil::locate(10,3);
    cout <<"Informe de ocupacion anual" << endl;
    rlutil::locate(10, 5);
    cout <<"Informe de ingresos por tipo de habitacion" << endl;
    rlutil::locate(10, 7);
    cout <<"Informe de ingresos por servicios" << endl;
    rlutil::locate(10, 9);
    cout <<"Informe de facturacion anual" << endl;
     rlutil::locate(10, 11);
    cout<<"Volver"<<endl;


    rlutil::locate(8,0+y);
cout<<char(175);
//rlutil::anykey();//Funcion que espera que toque cualquier tecla
switch(rlutil::getkey()){
case 14:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y-2;
if(y<=3){y=3;
break;
}

break;



case 15:
rlutil::locate(8,0+y);
cout<<" "<<endl;
y=y+2;
if(y>=11){
y=11;
break;
}
break;

case 1: //enter
//if(y==3)menu_reservas();
//if(y==5)menu_habitaciones();
//if(y==7)menu_servicios();
//if(y==11)menu_principal();
break;

default:
break;
}

}while(opcion!=0);
}
};















#endif
