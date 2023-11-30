#ifndef CLASES_H  // Directiva de preprocesador para evitar la inclusión múltiple
#define CLASES_H
#include <iostream>
#include <string.h>
#include "rlutil.h"


using namespace std;



void presionex(){
cout<<"Presione cualquier tecla para continuar."<<endl;
rlutil::anykey();
}





bool confirmarPresionandoSS() { //Editarla luego
    char respuesta;

    do {
        std::cout << "Presione S/s para confirmar N/n para cancelar: ";
        std::cin >> respuesta;

        cin.ignore();

        respuesta = std::tolower(respuesta);

        if (respuesta == 's') {
            return true;  // Usuario ha confirmado
        } else if (respuesta == 'n') {
            return false;  // Usuario ha rechazado
        } else {
            std::cout << "Respuesta no válida. Por favor, ingrese S/s para sí o N/n para no." << std::endl;
        }

    } while (true);
}





void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}






class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        ///sets: métodos para asignar valores a las propiedades
        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int d){
            if(d>=1 && d<=12) mes=d;
            else this->mes=-1;
        }
        void setAnio(int d){
            if(d>=1900) anio=d;
            else anio=-1;
        }

        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}



//SobreCarga de operadores para fecha.
 bool operator<(const Fecha& otraFecha) const {
        if (anio < otraFecha.anio)
            return true;
        if (anio > otraFecha.anio)
            return false;
        if (mes < otraFecha.mes)
            return true;
        if (mes > otraFecha.mes)
            return false;
        return dia < otraFecha.dia;
    }

    bool operator<=(const Fecha& otraFecha) const {
        return (*this < otraFecha) || (*this == otraFecha);
    }

    bool operator>(const Fecha& otraFecha) const {
        return !(*this <= otraFecha);
    }

    bool operator>=(const Fecha& otraFecha) const {
        return !(*this < otraFecha);
    }

    bool operator==(const Fecha& otraFecha) const {
        return (dia == otraFecha.dia) && (mes == otraFecha.mes) && (anio == otraFecha.anio);
    }

    bool operator!=(const Fecha& otraFecha) const {
        return !(*this == otraFecha);
    }
};










class Persona{
protected:
    char nombre[30], apellido[30], direccion[30];
    char email[30], telefono[30];
    int DNI;
    Fecha fechaNacimiento;
    bool estado;
public:
    void Cargar();
    void Mostrar();
    void setDNI(int d){DNI=d;}

    int getDNI(){return DNI;}
    void setEstado(bool e){estado=e;}
    bool getEstado(){return estado;}

    const char *getNombre() {return nombre;}
    const char *getApellido(){return apellido;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
     const char* getNombreConst() const { return nombre; }
    const char* getApellidoConst() const { return apellido; }



};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,29);
    cout<<"DIRECCION: ";
    cargarCadena(direccion,29);
    cout<<"EMAIL: ";
    cargarCadena(email,29);
    cout<<"TELEFONO: ";
    cargarCadena(telefono,29);
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    estado=true;
}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DIRECCION: ";
    cout<<direccion<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
}


class empleado:public Persona{

private:
char id_hotel[30];//Guardaremos esta data aqui como para ir relacionando entre los hoteles que vaya cargando;
char cargo[30];
float sueldo;
char id[30];//ID del empleado.
//bool estado;

public:
empleado(){;};
void setcargo(char* _cargo){strcpy(cargo,_cargo);};
void setsueldo(float _sueldo){sueldo=_sueldo;};
float getsueldo(){return sueldo;};
char* getcargo(){return cargo;};
void setid_hotel(const char* idhotel){strcpy(id_hotel,idhotel);};
char* getID(){return id;};



//Sobreescribir operador ==

bool operator==(char const* dato) const {

        if(strcmp(id,dato)==0)return true;
        else if(strcmp(getNombreConst(),dato)==0) return true;
        return false;
    }


void cargar_empleado(){
rlutil::cls();
Cargar();
cout<<"INGRESE EL CARGO: ";
cargarCadena(cargo,29);
cout<<"INGRESE EL SUELDO: ";
cin>>this->sueldo;
cout<<"INGRESE EL ID DE EMPLEADO: ";
cargarCadena(id,29);
setEstado(true);
}


void mostrar_empleado(){
cout<<"NOMBRE DEL EMPLEADO: "<<getNombre()<<" "<<getApellido()<<endl;
cout<<"CARGO DEL EMPLEADO: "<<getcargo()<<endl;
cout<<"SUELDO DEL EMPLEADO: "<<getsueldo()<<endl;
cout<<"ID DEL EMPLEADO: "<<getID()<<endl;
}

};


class archivoEmpleado{ //Archivo empleado

private:
char nombre[30]; //dsp veo si lo puedo hacer todo dinamico
int num;




public:
archivoEmpleado(const char *_nombre){
strcpy(nombre,_nombre);
}




empleado leerRegistro(int pos){
FILE* p;
int cont=0;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

empleado apertura;

while(fread(&apertura,sizeof apertura,1,p)==1){
fclose(p);
if(cont==pos)return apertura;
cont++;
}

fclose(p);


}




void escribirArchivo(empleado guardar){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
fwrite(&guardar,sizeof guardar,1,p);
fclose(p);
}




void listarArchivo(){
rlutil::cls();//Para limpiar la pantalla cuando haya que listar.
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

int contador=0;
empleado listado;

while(fread(&listado,sizeof listado,1,p)==1){

if(listado.getEstado()){
listado.mostrar_empleado();
cout<<endl;
}
contador++;
}

cout<<"Registros totales: "<<contador<<endl;
cout<<"Pulsar cualquier tecla para continuar."<<endl;
rlutil::anykey();
fclose(p);


}



//Returnea la posicion
int buscarArchivo(const char* dato){
int pos=0;
rlutil::cls();//Para limpiar la pantalla cuando haya que listar.
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

empleado busqueda;

while(fread(&busqueda,sizeof busqueda,1,p)==1){

if(busqueda==(dato)){//sobreescrito.
rlutil::cls();
cout<<"Empleado encontrado:"<<endl;
busqueda.mostrar_empleado();
cout<<endl;
return pos;
}
pos++;
}
cout<<"No se han encontrado coincidencias."<<endl;
return -1;
}





bool sobreEscribir(empleado reg,int pos){
FILE* puntero;
puntero=fopen(nombre,"rb+");
if(puntero==NULL){
 return false;
}
fseek(puntero,(sizeof reg)*pos,0); //posicionamos en la posicion del dato encontrado.
bool escribio=fwrite(&reg,sizeof reg,1,puntero);
fclose(puntero);
return escribio;
}


bool bajaFisica(){

FILE* pbak=fopen("empleados.bak","wb");
if(pbak==NULL){
 return false;
}

FILE* p=fopen(nombre,"rb");
if(p==NULL){
return false;
}

empleado bak;


while(fread(&bak,sizeof bak,1,p)==1){
 if(bak.getEstado()){
 fwrite(&bak,sizeof bak,1,pbak);// Escribira en el bak solo en caso de que el estado este correctamente dado de baja logica.
 }
}
fclose(p);
fclose(pbak);


pbak=fopen("empleados.bak","rb");
if(pbak==NULL){
 return false;
}

p=fopen(nombre,"wb");
if(p==NULL){
return false;
}


while(fread(&bak,sizeof bak,1,pbak)==1){
 fwrite(&bak,sizeof bak,1,p);// Escribira en el bak solo en caso de que el estado este correctamente dado de baja logica.
 }

fclose(p);
fclose(pbak);


return true;
}






};



class huesped:public Persona{

private:
Fecha entrada,salida;


public:
huesped(){;};
void setEntrada(Fecha _entrada){entrada=_entrada;};
void setSalida(Fecha _salida){salida=_salida;};
Fecha getEntrada(){return entrada;};
Fecha getSalida(){return salida;};
void Cargar_huesped(){
Persona:Cargar();

}

};



class archivoHuesped{

private:
   char nombre[30];
     int num;


public:

archivoHuesped(const char *_nombre){
strcpy(nombre,_nombre);
}



huesped leerArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

huesped apertura;
fseek(p,sizeof apertura*pos,0);
fread(&apertura,sizeof apertura,1,p);
fclose(p);
return apertura;

}






void escribirArchivo(huesped guardar){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
fwrite(&guardar,sizeof guardar,1,p);

fclose(p);



}




void listarArchivo(){
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
huesped nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
if(nuevo.getEstado()){
nuevo.Mostrar();
cout<<endl;
}
}
fclose(p);

}



int cantidadClientes() {
        int contador = 0;
        FILE* p;
        p = fopen(nombre, "rb"); // Modo lectura only
        if (p == NULL) {
            cout << "Error al abrir el archivo" << endl;
            fclose(p);
            exit(1);
        }
        huesped contar;
        while (fread(&contar, sizeof contar, 1, p) == 1) {
            if (contar.getEstado()) contador++;
        }
        fclose(p);
        return contador;
    }

};





class proovedor:public Persona{ //Utilizarlo en servicio. No hacer un archivo para esto.

private:
char cuit[13];
char servicio[30];



public:
proovedor(){;};
char* getCuit(){return cuit;};
char* getServicio(){return servicio;};

void setCuit(char* _cuit){strcpy(cuit,_cuit);};
void setServicio(char* _servicio){strcpy(servicio,_servicio);};


};












class Servicios{

protected:
char servicio[30];//Ver si puedo hacerlo con memoria dinamica(Puedo)
float precio;
bool estado;//Si esta en negativo ni lista esto.
proovedor empresa;


public:
Servicios(){;};
char* getServicio(){return servicio;};
void setServicio(char* _servicio){strcpy(servicio,_servicio);};
bool getEstado(){return estado;}
void setEstado(bool x) {estado=x;}
void setPrecio(float _precio){precio=_precio;};
float getPrecio(){return precio;};




Cargar(){
rlutil::cls();
cout<<"Por favor ingrese el servicio a ofrecer: ";
cargarCadena(servicio,29);
cout<<"Por favor ingrese la tarifa del servicio: $";
cin>>this->precio;
cout<<"A continuacion debera de ingresar los datos del proovedor del servicio, presione cualquier tecla para continuar."<<endl;
rlutil::anykey();
rlutil::cls();
empresa.setServicio(servicio);//Le guardamos el servicio con el que lo relacionaremos pq si
char cuit[13];
empresa.Cargar();
cout<<"Ingresar CUIT del proovedor: "<<endl;
cin>>cuit;
empresa.setCuit(cuit);
estado=true;

}


Mostrar(){ //Condicionarlo con el estado obviamente, el estado se tornara true en cada carga solo y solo si se elige un servicio es decir(s/S)
cout<<"------------------------------------"<<endl;
cout<<"TIPO DE SERVICIO: "<<servicio<<endl;
cout<<"TARIFA DEL SERVICIO: $"<<precio<<endl;
cout<<"------------------------------------"<<endl;
cout<<"\n\n";

}

};



class archivoServicio{
private:
   char nombre[30];
     int num;


public:

archivoServicio(const char *_nombre){
strcpy(nombre,_nombre);
}



Servicios leerArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error apertura de archivo."<<endl;
exit(1);
}
Servicios buscar;
fseek(p,sizeof buscar*pos,0);
fread(&buscar,sizeof buscar,1,p);
return buscar;
}


int cantidadServicios(){
int contador=0;
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error al abrir el archivo."<<endl;
fclose(p);
exit(1);
}
Servicios loc;
while(fread(&loc,sizeof loc,1,p)==1){
contador++;
}

fclose(p);
return contador;

}



int busquedaArchivo(const char* busqueda){
int pos=0;
FILE* p;
p=fopen(nombre,"rb");//Leera
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
return -1;
}
Servicios buscando;
while(fread(&buscando,sizeof buscando,1,p)==1){

if(strcmp(buscando.getServicio(),busqueda)==0){
cout<<"Servicio encontrado: "<<endl;
buscando.Mostrar();
return pos;
}
pos++;
}
fclose(p);
return -1;

}




bool sobreEscribir(Servicios reg,int pos){
FILE* puntero;
puntero=fopen(nombre,"rb+");
if(puntero==NULL){
 return false;
}
fseek(puntero,(sizeof reg)*pos,0); //posicionamos en la posicion del dato encontrado.
bool escribio=fwrite(&reg,sizeof reg,1,puntero);
fclose(puntero);
return escribio;
}




bool bajaFisica(){

FILE* pbak=fopen("servicios.bak","wb");
if(pbak==NULL){
 return false;
}

FILE* p=fopen(nombre,"rb");
if(p==NULL){
return false;
}

Servicios bak;


while(fread(&bak,sizeof bak,1,p)==1){
 if(bak.getEstado()){
 fwrite(&bak,sizeof bak,1,pbak);// Escribira en el bak solo en caso de que el estado este correctamente dado de baja logica.
 }
}
fclose(p);
fclose(pbak);


pbak=fopen("servicios.bak","rb");
if(pbak==NULL){
 return false;
}

p=fopen(nombre,"wb");
if(p==NULL){
return false;
}


while(fread(&bak,sizeof bak,1,pbak)==1){
 fwrite(&bak,sizeof bak,1,p);// Escribira en el bak solo en caso de que el estado este correctamente dado de baja logica.
 }

fclose(p);
fclose(pbak);


return true;
}




bool escribirArchivo(Servicios guardar){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

bool x=fwrite(&guardar,sizeof guardar,1,p);
fclose(p);
return x;


}




void listarArchivo(){
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
Servicios nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
if(nuevo.getEstado()){
nuevo.Mostrar();
cout<<endl;
}
}

cout<<"Pulsar cualquier tecla para continuar."<<endl;
rlutil::anykey();
fclose(p);


}



void ordenarPorNombre() {
    Servicios* servicios = new Servicios[cantidadServicios()];
    rlutil::cls();

    for (int i = 0; i < cantidadServicios(); i++) {
        servicios[i] = leerArchivo(i);
    }


    for (int i = 0; i < cantidadServicios() - 1; i++) {
        for (int j = 0; j < cantidadServicios() - i - 1; j++) {
            if (strcmp(servicios[j].getServicio(), servicios[j + 1].getServicio()) > 0) {
                Servicios temp = servicios[j];
                servicios[j] = servicios[j + 1];
                servicios[j + 1] = temp;
            }
        }
    }

    // Mostrar listado ordenado
    cout << "Listado de Servicios Ordenados por Nombre:" << endl;
    for (int i = 0; i < cantidadServicios(); i++) {
        servicios[i].Mostrar();
        cout << endl;
    }

    delete[] servicios;
    presionex();
}




void ordenarPorCosto(int opcion) {
    Servicios* servicios = new Servicios[cantidadServicios()];
    rlutil::cls();

    for (int i = 0; i < cantidadServicios(); i++) {
        servicios[i] = leerArchivo(i);
    }

    if(opcion==0){// Ordenar servicios por costo de menor a mayor
    for (int i = 0; i < cantidadServicios() - 1; i++) {
        for (int j = 0; j < cantidadServicios() - i - 1; j++) {
            if (servicios[j].getPrecio() > servicios[j + 1].getPrecio()) {
                Servicios temp = servicios[j];
                servicios[j] = servicios[j + 1];
                servicios[j + 1] = temp;
            }
        }
    }
    }
    else if(opcion==1){

   // Ordenar servicios por costo de mayor a menor
    for (int i = 0; i < cantidadServicios() - 1; i++) {
        for (int j = 0; j < cantidadServicios() - i - 1; j++) {
         if (servicios[j].getPrecio() < servicios[j + 1].getPrecio()) {
                Servicios temp = servicios[j];
                servicios[j] = servicios[j + 1];
                servicios[j + 1] = temp;
            }
        }
    }

    }



    cout << "Listado de Servicios Ordenados por Costo de Menor a Mayor:" << endl;
    for (int i = 0; i < cantidadServicios(); i++) {
        servicios[i].Mostrar();
        cout << endl;
    }

    delete[] servicios;
    presionex();
}








};


class reserva;

class archivoHabitacion;

class Habitacion{

protected:
char idHabitacion[30];    //Deberiamos dimensionar cuantas habitaciones tiene nuestro hotel asi podemos ver cuantas habitaciones dejariamos activas para cada tipo, podemos usar arrays y/o arrays dinamicos para preguntar cuantas habitaciones de cada tipo.
bool estado;
char tipo[30];
float precio;
int cantidad_habitaciones;

struct IntervaloFecha {
    Fecha entrada;
    Fecha salida;
};







public:
Habitacion(){;};

void setIdHabitacion(const char* _IdHabitacion){strcpy(idHabitacion,_IdHabitacion);};
void setEstado(bool _estado){estado=_estado;};
void setTipo(const char* _tipo){strcpy(tipo,_tipo);};
void setPrecio(float _precio){precio=_precio;};
float getPrecio(){return precio;};
const char* getIdHabitacion(){return idHabitacion;};
bool getEstado(){return estado;};
const char* getTipo(){return tipo;};

void Cargar();



void Mostrar(){
cout<<"ID de la habitacion: "<<idHabitacion<<endl;
cout<<"Tipo de habitacion: "<<tipo<<endl;
cout<<"Tarifa: $"<<precio<<endl;
cout<<"Estado: "<<(getEstado() ? "Disponible" : "Ocupada")<<endl;
}







 //void agregarReserva(Fecha fechaEntrada, Fecha fechaSalida) {




   // bool estaDisponibleEnFecha(Fecha fechaEntrada, Fecha fechaSalida) {
        //for (const auto& intervalo : fechas) {
           // if (!(intervalo.salida <= fechaEntrada || intervalo.entrada >= fechaSalida)) {


};






class archivoHabitacion{
private:
   char nombre[30];
     int num;


public:

archivoHabitacion(const char *_nombre){
strcpy(nombre,_nombre);
}


Habitacion leerArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error al abrir el archivo."<<endl;
fclose(p);
exit(1);
}
Habitacion loc;
fseek(p,sizeof loc*pos,0);
fread(&loc,sizeof loc,1,p);
fclose(p);
return loc;
}



void escribirArchivo(Habitacion guardar){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
fwrite(&guardar,sizeof guardar,1,p);
fclose(p);
}




void listarArchivo(){
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
Habitacion nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
if(nuevo.getEstado()){
nuevo.Mostrar();
cout<<endl;
}
}
fclose(p);
}


int buscarArchivo(const char* dato){
int pos=0;
FILE* p;
p=fopen(nombre,"rb");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
Habitacion guardar;

while(fread(&guardar,sizeof guardar,1,p)==1){
  if(strcmp(guardar.getIdHabitacion(),dato)==0){
   cout<<"Habitacion encontrada: "<<endl;
   cout<<"\n\n"<<endl;
   guardar.Mostrar();
   presionex();
   rlutil::cls();
   fclose(p);
   return pos;
}
pos++;
}

fclose(p);
return-1;




}


int cantidadHabitaciones(){
int contador=0;
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error al abrir el archivo."<<endl;
fclose(p);
exit(1);
}
Habitacion loc;
while(fread(&loc,sizeof loc,1,p)==1){
contador++;
}

fclose(p);
return contador;
}






void ordenarPorTipo() {
    Habitacion* puntero = new Habitacion[cantidadHabitaciones()];
    rlutil::cls();

    for (int i = 0; i < cantidadHabitaciones(); i++) {
        puntero[i] = leerArchivo(i);
    }

    for (int i = 0; i < cantidadHabitaciones() - 1; i++) {
        for (int j = 0; j < cantidadHabitaciones() - i - 1; j++) {
            if (strcmp(puntero[j].getTipo(), puntero[j + 1].getTipo()) > 0) {
                Habitacion temp = puntero[j];
                puntero[j] = puntero[j + 1];
                puntero[j + 1] = temp;
            }
        }
    }

    cout << "Listado de habitaciones ordenadas por tipo:" << endl;
    for (int i = 0; i < cantidadHabitaciones(); i++) {
        puntero[i].Mostrar();
        cout << endl;
    }

   if (puntero != nullptr) {
    delete[] puntero;
}

}







bool ordenarPorEstado(int orden) { //Varia segun el int que le mande.
    Habitacion* habitaciones = new Habitacion[cantidadHabitaciones()];
    rlutil::cls();

    for (int i = 0; i < cantidadHabitaciones(); i++) {
        habitaciones[i] = leerArchivo(i);
    }

    if (orden==0){// Ordenar habitaciones por estado (ocupado primero)
    for (int i = 0; i < cantidadHabitaciones() - 1; i++) {
        for (int j = 0; j < cantidadHabitaciones() - i - 1; j++) {
            // Compara los estados de las habitaciones
            if (!habitaciones[j].getEstado() && habitaciones[j + 1].getEstado()) {
                Habitacion temp = habitaciones[j];
                habitaciones[j] = habitaciones[j + 1];
                habitaciones[j + 1] = temp;
            }
        }
    }
    }
    else if(orden==1){  // Ordenar habitaciones por estado (libre)
     for (int i = 0; i < cantidadHabitaciones() - 1; i++) {
        for (int j = 0; j < cantidadHabitaciones() - i - 1; j++) {
          if (habitaciones[j].getEstado() && !habitaciones[j + 1].getEstado()) {
                Habitacion temp = habitaciones[j];
                habitaciones[j] = habitaciones[j + 1];
                habitaciones[j + 1] = temp;
            }
        }
    }
    }

    // Mostrar listado ordenado
    cout << "Listado de habitaciones ordenadas por estado:" << endl;
    for (int i = 0; i < cantidadHabitaciones(); i++) {
        habitaciones[i].Mostrar();
        cout << endl;
    }

    delete[] habitaciones;
    presionex();
}





bool sobreEscribir(Habitacion reg,int pos){
FILE* puntero;
puntero=fopen(nombre,"rb+");
if(puntero==NULL){
 return false;
}
fseek(puntero,(sizeof reg)*pos,0); //posicionamos en la posicion del dato encontrado.
bool escribio=fwrite(&reg,sizeof reg,1,puntero);
fclose(puntero);
return escribio;
}




/*void listarHabitacionesDisponiblesEnFecha(Fecha fechaEntrada, Fecha fechaSalida) {
    rlutil::cls();
    for (int i = 0; i < cantidadHabitaciones(); i++) {
        Habitacion habitacion = leerArchivo(i);
        if (habitacion.estaDisponibleEnFecha(fechaEntrada, fechaSalida)) {
            habitacion.Mostrar();
            cout << endl;
        }
    }
    presionex();
}
*/
};





void Habitacion::Cargar() {
    int cantidad;
    archivoHabitacion guardar("habitaciones.dat");
    Habitacion nuevaHabitacion; // Crea una nueva habitación para cada iteración
    cout << "Por favor escriba el tipo de habitacion ofrecida a cargar (individual, doble, suite, etc.) : ";
    cargarCadena(tipo, 29);
    cout << "Por favor ingrese la tarifa de este tipo de habitacion: $";
    cin >> precio;
    cout << "Por favor ingrese la cantidad de habitaciones de este tipo que quiere cargar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        cout << "Por favor ingrese el numero de la habitacion a cargar #" << i + 1 << " :";
       cargarCadena(nuevaHabitacion.idHabitacion, 29);
       nuevaHabitacion.setPrecio(precio);
       nuevaHabitacion.setEstado(true);
       guardar.escribirArchivo(nuevaHabitacion);

    }
    cout << "\n\nHabitaciones cargadas correctamente. Presione cualquier tecla para continuar." << endl;
    rlutil::anykey();
}



class Factura {
private:
    int numeroFactura;
    Fecha fecha;
    huesped cliente;
    float montoTotal;

public:
    Factura() {;};
    void Mostrar() {
        cout << "Numero de Factura: " << numeroFactura << endl;
        cout << "Fecha: ";
        fecha.Mostrar(); // Asumiendo que la clase Fecha tiene un método Mostrar
        cout << "Cliente: ";
        cliente.Mostrar(); // Asumiendo que la clase huesped tiene un método Mostrar
        cout << "Monto Total: $" << montoTotal << endl;
        // Puedes agregar más detalles si es necesario
        cout << "------------------------------------" << endl;
    }



    void setNumero(int _numero){numeroFactura=_numero;};
    int getNumero(){return numeroFactura;};
    void setFecha(Fecha _fecha){fecha=_fecha;};
    Fecha getFecha(){return fecha;};
    void setMonto(float _monto){montoTotal=_monto;};
    float getMonto(){return montoTotal;};
    void setCliente(huesped _cliente){cliente=_cliente;};
    huesped getCliente(){return cliente;};
};



class reserva {
private:
    char idhotel[30];
    Fecha fecha_entrada;
    Fecha fecha_salida;
    huesped cliente;
    Habitacion habitacion;
    Servicios servicio;
  bool estado;
  Factura factura;

public:
    reserva() {;};

void setFechaEntrada(Fecha _fecha_entrada) {fecha_entrada = _fecha_entrada;}

Fecha getFechaEntrada() const {return fecha_entrada;}

void setFechaSalida(Fecha _fecha_salida) {fecha_salida = _fecha_salida;}

Fecha getFechaSalida() {return fecha_salida;}

void setCliente( huesped _cliente) {cliente = _cliente;}

huesped getCliente() {return cliente;}

void setHabitacion( Habitacion _habitacion) {habitacion = _habitacion;}

Habitacion getHabitacion() {return habitacion;}

void setServicio(Servicios _servicio) {servicio = _servicio;}

Servicios getServicio() {return servicio;};

void setId(const char* id){strcpy(idhotel,id);};

const char* getId(){return idhotel;};

bool getEstado(){return estado;};

void setEstado(bool _estado){estado=_estado;};

Factura getFactura(){return factura;};
void setFactura(Factura _factura){factura=_factura;};




void sumarDias(int numDias) {
    // Se obtienen los valores de fecha entrada
    int diaActual = fecha_entrada.getDia();
    int mesActual = fecha_entrada.getMes();
    int anioActual = fecha_entrada.getAnio();

    diaActual += numDias;

    if (mesActual != 2 || mesActual != 9) {
        int limiteDias = 31;

        // Manejo de febrero
        if (mesActual == 2) {
            if(anioActual % 4 == 0 && (anioActual % 100 != 0 || anioActual % 400 == 0)){
             limiteDias=29;
            }
            else{
            limiteDias=28;
            }
        }
        else if (mesActual == 9) {
            limiteDias = 30;
        }

        while (diaActual > limiteDias) {
            diaActual -= limiteDias;
            mesActual++;
        }
    }

    // Se ajusta el mes y el año si es necesario
    while (mesActual > 12) {
        mesActual -= 12;
        anioActual++;
    }

    // Se calculan los valores de fecha de salida y ya los guardamos.
    fecha_salida.setDia(diaActual);
    fecha_salida.setMes(mesActual);
    fecha_salida.setAnio(anioActual);
}




    void generarFactura(){
factura.setMonto(habitacion.getPrecio()+servicio.getPrecio());
factura.setNumero(cliente.getDNI() + fecha_entrada.getAnio() + fecha_entrada.getMes() + fecha_entrada.getDia());
factura.setCliente(cliente);
cout<<"\n\nPor favor ingrese fecha en la que se realizo la reserva, para poder realizar la factura."<<endl;
Fecha fechaFactura;
fechaFactura.Cargar();
factura.setFecha(fechaFactura);
cout<<"\n\nFactura creada exitosamente.Presione cualquier tecla para continuar"<<endl;
presionex();

    }








 void Cargar(){
  char seleccion[30];
    archivoHabitacion nuevo("habitaciones.dat");
    archivoServicio serv("servicios.dat");
    rlutil::cls();
    cout << "Por favor ingrese los datos del cliente" << endl;
    cliente.Cargar();
    cout << "Por favor indique la fecha de ingreso" << endl;
    fecha_entrada.Cargar();
    rlutil::cls();
    cout << "Por favor ingrese el numero de noches que se quedara: ";
    int numNoches;
    cin >> numNoches;
    sumarDias(numNoches);

     cout << "\nHabitaciones disponibles para las fechas seleccionadas:" << endl;
//    nuevo.listarHabitacionesDisponiblesEnFecha(fecha_entrada, fecha_salida);
    cout << "\n\nPor favor indicar el ID de habitacion a elegir entre las disponibles :";
    cargarCadena(seleccion, 29);
    int pos = nuevo.buscarArchivo(seleccion);
    if (pos != -1) {
        // Obtener la habitación seleccionada
        Habitacion habitacionSeleccionada = nuevo.leerArchivo(pos);

        // Verificar disponibilidad e agregar reserva
       // habitacionSeleccionada.agregarReserva(fecha_entrada, fecha_salida);

        // Sobrescribir la habitación en el archivo con la nueva información
        nuevo.sobreEscribir(habitacionSeleccionada, pos);

        cout << "\n\nHabitacion cargada correctamente." << endl;
    } else {
        cout << "Habitacion no encontrada";
        rlutil::cls();
        Cargar();
}
cout<<"Requiere algun servicio extra?" <<endl; //Listado tal vez guardarlo en un booleano.
if(confirmarPresionandoSS()){
char servicio[30];
rlutil::cls();
serv.listarArchivo();
cout<<"Por favor escribir el tipo de servicio extra solicitado: ";
cargarCadena(servicio,29);
int poserv=serv.busquedaArchivo(servicio);
if(poserv!=-1){
cout<<"Quiere realmente contratar este servicio?"<<endl;
if(confirmarPresionandoSS()){
setServicio(serv.leerArchivo(poserv));//Carganis el registro que corresponde.
cout<<"Servicio seleccionado exitosamente."<<endl;
presionex();
}

}
else{
 cout<<"\n\nServicio no encontrado."<<endl;
 presionex();
}

}
generarFactura(); //lo acabo de agregar
setEstado(true);
 }




 void Mostrar(){
cout<<"Datos del cliente:"<<endl;
cliente.Mostrar();
cout<<"Fecha de ingreso: "<<endl;
fecha_entrada.Mostrar();
cout<<"Fecha de egreso: "<<endl;
fecha_salida.Mostrar();
cout<<"Tipo de habitacion: "<<endl;
habitacion.Mostrar();
cout<<"Servicio extra:" <<endl; //Listado tal vez guardarlo en un booleano.
servicio.Mostrar();
cout<<"\nNumero de factura: "<<factura.getNumero()<<endl;
cout<<"Importe total: $"<<factura.getMonto()<<endl;
 }









};




class archivoReserva{
private:
   char nombre[30];
     int num;


public:
archivoReserva(const char *_nombre){
strcpy(nombre,_nombre);
}

void listarFacturas(){
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
reserva nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
(nuevo.getFactura()).Mostrar();
cout<<endl;
}

fclose(p);





}

bool sobreEscribir(reserva reg,int pos){
FILE* puntero;
puntero=fopen(nombre,"rb+");
if(puntero==NULL){
 return false;
}
fseek(puntero,(sizeof reg)*pos,0); //posicionamos en la posicion del dato encontrado.
bool escribio=fwrite(&reg,sizeof reg,1,puntero);
fclose(puntero);
return escribio;
}


bool bajaFisica(){

FILE* pbak=fopen("reservas.bak","wb");
if(pbak==NULL){
 return false;
}

FILE* p=fopen(nombre,"rb");
if(p==NULL){
return false;
}

reserva bak;


while(fread(&bak,sizeof bak,1,p)==1){
 if(bak.getEstado()){
 fwrite(&bak,sizeof bak,1,pbak);// Escribira en el bak solo en caso de que el estado este correctamente dado de baja logica.
 }
}
fclose(p);
fclose(pbak);


pbak=fopen("reservas.bak","rb");
if(pbak==NULL){
 return false;
}

p=fopen(nombre,"wb");
if(p==NULL){
return false;
}


while(fread(&bak,sizeof bak,1,pbak)==1){
 fwrite(&bak,sizeof bak,1,p);// Escribira en el bak solo en caso de que el estado este correctamente dado de baja logica.
 }

fclose(p);
fclose(pbak);


return true;
}





int buscarArchivo(const char* dato){
int pos=0;
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error apertura de archivo."<<endl;
exit(1);
}
reserva buscar;
while(fread(&buscar,sizeof buscar,1,p)==1){
if(strcmp((buscar.getCliente()).getNombre(),dato)==0||strcmp((buscar.getCliente()).getApellido(),dato)==0||strcmp((buscar.getHabitacion()).getIdHabitacion(),dato)==0){
fclose(p);
return pos;
}
}


return -1;






}


reserva leerArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error apertura de archivo."<<endl;
exit(1);
}
reserva buscar;
fseek(p,sizeof buscar*pos,0);
fread(&buscar,sizeof buscar,1,p);
return buscar;
}





void escribirArchivo(reserva guardar){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
fwrite(&guardar,sizeof guardar,1,p);

fclose(p);



}




void listarArchivo(){
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
reserva nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){

nuevo.Mostrar();
cout<<endl;

}

fclose(p);


}



int cantidadReservas(){
int contador=0;
    FILE* p;
    p = fopen(nombre, "rb"); // Modo lectura only
    if (p == NULL) {
        cout << "Error al abrir el archivo" << endl;
        fclose(p);
        exit(1);
    }
       reserva contar;
        while(fread(&contar,sizeof contar,1,p)==1){
          if(contar.getEstado())contador++;
        }
fclose(p);
return contador;
}


void ordenarPorFechaLlegada() {  //cantidadReservas devolvera un int al leer el archivo y buscar estados true;

reserva* reservas = new reserva[cantidadReservas()];


for (int i = 0; i < cantidadReservas(); i++) {
    reservas[i] = leerArchivo(i);
}


rlutil::cls();

for (int i = 0; i < cantidadReservas() - 1; i++) {
        for (int j = 0; j < cantidadReservas() - i - 1; j++) {
            if (reservas[j].getFechaEntrada() > reservas[j + 1].getFechaEntrada()) {
                reserva temp = reservas[j];
                reservas[j] = reservas[j + 1];
                reservas[j + 1] = temp;
            }
        }
    }

cout << "Listado de Reservas Ordenadas por Fecha de Llegada:" << endl;
for (int i = 0; i < cantidadReservas(); i++) {
    reservas[i].Mostrar();
    cout << endl;
}

delete[] reservas;
presionex();

}


void ordenarPorFechaSalida() {
    reserva* reservas = new reserva[cantidadReservas()];


    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i] = leerArchivo(i);
    }

    rlutil::cls();

    for (int i = 0; i < cantidadReservas() - 1; i++) {
        for (int j = 0; j < cantidadReservas() - i - 1; j++) {
            if (reservas[j].getFechaSalida() > reservas[j + 1].getFechaSalida()) {
                reserva temp = reservas[j];
                reservas[j] = reservas[j + 1];
                reservas[j + 1] = temp;
            }
        }
    }

    cout << "Listado de Reservas Ordenadas por Fecha de Salida:" << endl;
    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i].Mostrar();
        cout << endl;
    }

    delete[] reservas;
    presionex();
}



void ordenarPorNombre() {
    reserva* reservas = new reserva[cantidadReservas()];

    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i] = leerArchivo(i);
    }

    rlutil::cls();

    for (int i = 0; i < cantidadReservas() - 1; i++) {
        for (int j = 0; j < cantidadReservas() - i - 1; j++) {
            if (strcmp(reservas[j].getCliente().getNombre(), reservas[j + 1].getCliente().getNombre()) > 0) {
                reserva temp = reservas[j];
                reservas[j] = reservas[j + 1];
                reservas[j + 1] = temp;
            }
        }
    }

    cout << "Listado de Reservas Ordenadas por Nombre:" << endl;
    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i].Mostrar();
        cout << endl;
    }

    delete[] reservas;
    presionex();
}



void ordenarNH() {
reserva* reservas = new reserva[cantidadReservas()];
rlutil::cls();

    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i] = leerArchivo(i);
    }
    for (int i = 0; i < cantidadReservas() - 1; i++) {
        for (int j = 0; j < cantidadReservas() - i - 1; j++) {

            if (strcmp(reservas[j].getCliente().getNombreConst(), reservas[j + 1].getCliente().getNombreConst()) > 0) {
                reserva temp = reservas[j];
                reservas[j] = reservas[j + 1];
                reservas[j + 1] = temp;
            }
        }
    }

    cout << "Listado de Reservas Ordenadas por Nombre del Huesped:" << endl;
    for (int i = 0; i < cantidadReservas(); i++) {
        (reservas[i].getCliente()).Mostrar();
        cout << endl;
    }

    delete[] reservas;
    presionex();
}

void ordenarAH() {
    reserva* reservas = new reserva[cantidadReservas()];
    rlutil::cls();

    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i] = leerArchivo(i);
    }

    for (int i = 0; i < cantidadReservas() - 1; i++) {
        for (int j = 0; j < cantidadReservas() - i - 1; j++) {
            if (strcmp(reservas[j].getCliente().getApellidoConst(), reservas[j + 1].getCliente().getApellidoConst()) > 0) {
                reserva temp = reservas[j];
                reservas[j] = reservas[j + 1];
                reservas[j + 1] = temp;
            }
        }
    }
    cout << "Listado de Reservas Ordenadas por Apellido del Huesped:" << endl;
    for (int i = 0; i < cantidadReservas(); i++) {
        (reservas[i].getCliente()).Mostrar();
        cout << endl;
    }

    delete[] reservas;
    presionex();
}





void ordenarPorDNI() {
    reserva* reservas = new reserva[cantidadReservas()];
    rlutil::cls();

    for (int i = 0; i < cantidadReservas(); i++) {
        reservas[i] = leerArchivo(i);
    }


    for (int i = 0; i < cantidadReservas() - 1; i++) {
        for (int j = 0; j < cantidadReservas() - i - 1; j++) {
            if (reservas[j].getCliente().getDNI() > reservas[j + 1].getCliente().getDNI()) {
                reserva temp = reservas[j];
                reservas[j] = reservas[j + 1];
                reservas[j + 1] = temp;
            }
        }
    }


    cout << "Listado de Reservas Ordenadas por DNI del Huesped:" << endl;
    for (int i = 0; i < cantidadReservas(); i++) {
        (reservas[i].getCliente()).Mostrar();
        cout << endl;
    }

    delete[] reservas;
    presionex();
}

};

//FIN ARCHIVORESERVA.


class Hotel{

protected:
char nombre[30];
char correo[30];
char idHotel[30];
int celular;
char direccion[30];
int cantPiezas; //Limitara la cantidad de ids diferentes de habitacion que podre agregar a mi sistema.
empleado empleados;
Servicios servicios_hotel;//Tendremos los diferentes servicios ofrecidos por el hotel,su debido proovedor, su tarifa y  cuit. Luego elegiremos dentro de la reserva a partir de los  servicios cargados aqui.
reserva nueva_reserva;//Aca guardaremos la mayoria de los datos.//Podremos dar de baja los sistemas las reservas y todo.
bool estado;

public:
Hotel(){;};

char* getNombre(){return nombre;};
char* getCorre(){return correo;};
int   getCelular(){return celular;};
char*  getIdhotel(){return idHotel;};
char* getDireccion(){return direccion;};
int getCantPiezas(){return cantPiezas;};
void setEstado(bool _estado){estado=_estado;};
bool getEstado(){return estado;};

Cargar(){
    rlutil::cls();
cout<<"INGRESE NOMBRE DEL HOTEL: ";
cargarCadena(nombre,29);
cout<<"INGRESE CORREO DEL HOTEL: ";
cargarCadena(correo,29);
cout<<"INGRESE NUMERO TELEFONICO DEL HOTEL: ";
cin>>this->celular;
cout<<"INGRESE ID DEL HOTEL: ";
cargarCadena(idHotel,29);
cout<<"INGRESE DIRECCION DEL HOTEL: ";
cargarCadena(direccion,29);
//La cantidad de habitaciones se actualizara automaticamente al hacer la carga de habitaciones.
//cout<<"INGRESE CANTIDAD DE HABITACIONES: "; //podemos hacer totales y las libres, utilizando algo que nos diga si estan ocupadas o no. Ademas solo puede haber la cantidad de ids diferentes que se ingrese aca.
//cin>>this->cantPiezas;
}






Mostrar(){
cout<<"NOMBRE DEL HOTEL: "<<nombre<<endl;
cout<<"CORREO DEL HOTEL: "<<correo<<endl;
cout<<"NUMERO DEL HOTEL: "<<celular<<endl;
cout<<"ID DEL HOTEL: "<<idHotel<<endl;
cout<<"DIRECCION DEL HOTEL: "<<direccion<<endl;
cout<<"CANTIDAD DE PIEZAS: "<<cantPiezas; //podemos hacer totales y las libres, utilizando algo que nos diga si estan ocupadas o no.
}

};



class archivoHotel{


private:
   char nombre[30];
     int num;


public:

archivoHotel(const char *_nombre){
strcpy(nombre,_nombre);
}



void leerArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);


}

Hotel apertura;

while(fread(&apertura,sizeof apertura,1,p)==1){

apertura.Mostrar();
cout<<endl;

}

fclose(p);


}




Hotel posicionarArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

Hotel apertura;
fseek(p,sizeof apertura*pos,0);
fread(&apertura,sizeof apertura,1,p);
return apertura;
fclose(p);

}






void escribirArchivo(){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
Hotel nuevo;
nuevo.Cargar();
fwrite(&nuevo,sizeof nuevo,1,p);
fclose(p);
}




void listarArchivo(){
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
cout<<"Listado de hoteles disponibles:"<<endl;
cout<<"\n\n";
cout<<"-----------------------------"<<endl;
cout<<"\n\n";
Hotel nuevo;
while(fread(&nuevo,sizeof nuevo,1,p)==1){
nuevo.Mostrar();
cout<<"\n"<<endl;
cout<<"-----------------------------"<<endl;
cout<<"\n"<<endl;
}

fclose(p);
}



int buscarArchivo(const char* dato){
int pos=0;//Inicializar en 0 porque buscara desde el principio del archivo, tambien podria hacerlo con fseek pero da igual.
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}

Hotel apertura;

while(fread(&apertura,sizeof apertura,1,p)==1){

if(strcmp(apertura.getIdhotel(),dato)==0||strcmp(apertura.getNombre(),dato)==0){
cout<<"Hotel encontrado: "<<apertura.getNombre()<<endl;
fclose(p);
rlutil::anykey();
return pos;//Returneara la posicion en la que fue encontrado el id;
}
pos++;
}
fclose(p);

return -1;

}

};

#endif
