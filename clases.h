#ifndef CLASES_H 
#define CLASES_H
#include <iostream>
#include <string.h>
#include "rlutil.h"



using namespace std;





void presionex(){
cout<<"\nPresione cualquier tecla para continuar."<<endl;
rlutil::anykey();
}





bool confirmacion() { //Editarla luego


int opcion=1,x=43,y=5;
rlutil::hidecursor();//Oculta el cursor para que no moleste.
rlutil::cls();

do{
    rlutil::locate(45, 1);
    cout <<"Esta seguro de realizar la accion?, SI o NO:";
    rlutil::locate(45, 5);
    cout <<"SI" << endl;//wb en el archivo de reservas.
    rlutil::locate(85, 5);
    cout <<"NO" << endl;//Solo me mostrara los que tengan el id con el que los relaciono.
    rlutil::locate(10, 7);


rlutil::locate(x,y);
cout<<char(175);

switch(rlutil::getkey()){
case 16:
x=43;
rlutil::locate(83,y);
cout<<" "<<endl;
break;



case 17:
x=83;
rlutil::locate(43,y);
cout<<" "<<endl;
break;

case 1: //enter
if(x==43)return true;


if(x==83)return false;


break;

}
}while(opcion!=0);

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

        void Cargar() {
    cout << "DIA: ";
    cin >> dia;
    while (dia < 1 || dia > 31) {
        cout << "Por favor ingrese un dia valido (1-31): ";
        cin >> dia;
    }

    cout << "MES: ";
    cin >> mes;
    while (mes < 1 || mes > 12) {
        cout << "Por favor ingrese un mes valido (1-12): ";
        cin >> mes;
    }

    cout << "ANIO: ";
    cin >> anio;
    while (anio < 1900) {
        cout << "Por favor ingrese un anio valido (>= 1900): ";
        cin >> anio;
    }
}

         const char* mostrarEnLinea() const {

        static char fechaString[11]; //tamaño suficiente
        snprintf(fechaString, sizeof(fechaString), "%02d/%02d/%04d", dia, mes, anio);
        return fechaString;
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


class intervalo_ocupacion {
private:
    char idHabitacion[30];
    Fecha fechaEntrada;
    Fecha fechaSalida;
    bool estado;

public:
    // Constructor por defecto
   intervalo_ocupacion() {
    idHabitacion[0]='\0';
    estado=(false);
    };

  intervalo_ocupacion(const char* id, const Fecha& entrada, const Fecha& salida, bool estado = true) {
        strcpy(idHabitacion, id);
        idHabitacion[sizeof(idHabitacion) - 1] = '\0';
        fechaEntrada = entrada;
        fechaSalida = salida;
        this->estado = estado;
    }



void Mostrar(){
cout<<fechaEntrada.mostrarEnLinea()<<"-"<<fechaSalida.mostrarEnLinea()<<endl;
cout<<endl;
}

void setidHabitacion(char* id){strcpy(idHabitacion,id);};
char * getidHabitacion(){return idHabitacion;};

void setfechaEntrada(Fecha _entrada){fechaEntrada=_entrada;};
Fecha getfechaEntrada(){return fechaEntrada;};

void setfechaSalida(Fecha _salida){fechaSalida=_salida;};
Fecha getfechaSalida(){return fechaSalida;};

void setEstado(bool _estado){estado=_estado;};
bool getEstado(){return estado;};


 bool estaDisponibleEnFecha(Fecha entra, Fecha sale) {
if (!(fechaEntrada <= entra || fechaSalida >= sale)){
    return false;
    }
    return true;
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

    Persona(){
        // Inicializar otros miembros de la clase si es necesario
        DNI=0;
        estado=false;
        nombre[0] = '\0';
        apellido[0] = '\0';
        direccion[0] = '\0';
        email[0] = '\0';
        telefono[0] = '\0';
        // no es necesario inicializar fechaNacimiento, ya que su constructor por defecto se invoca.

    }

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
    cout<<"Nombre: ";
    cout<<nombre<<endl;
    cout<<"Apellido: ";
    cout<<apellido<<endl;
    cout<<"Direccion: ";
    cout<<direccion<<endl;
    cout<<"Email: ";
    cout<<email<<endl;
    cout<<"Telefono: ";
    cout<<telefono<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"Fecha de nacimiento: "<<fechaNacimiento.mostrarEnLinea()<<endl;

}


class empleado:public Persona{

private:
//char id_hotel[30];//Guardaremos esta data aqui como para ir relacionando entre los hoteles que vaya cargando;
char cargo[30];
float sueldo;
char id[30];//ID del empleado.
//bool estado;

public:
empleado(){
        DNI=0;
        setEstado(false);//Lo setea en la clase persona.
        nombre[0] = '\0';
        apellido[0] = '\0';
        direccion[0] = '\0';
        email[0] = '\0';
        telefono[0] = '\0';
        // No es necesario inicializar fechaNacimiento, ya que su constructor por defecto se invoca.

    }
void setcargo(char* _cargo){strcpy(cargo,_cargo);};
void setsueldo(float _sueldo){sueldo=_sueldo;};
float getsueldo(){return sueldo;};
char* getcargo(){return cargo;};
//void setid_hotel(const char* idhotel){strcpy(id_hotel,idhotel);};
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





class huesped:public Persona{

private:
Fecha entrada,salida;


public:
huesped(){;}; //No necesita inicializar nada mas.

void setEntrada(Fecha _entrada){entrada=_entrada;};
void setSalida(Fecha _salida){salida=_salida;};
Fecha getEntrada(){return entrada;};
Fecha getSalida(){return salida;};
void Cargar_huesped(){
Persona:Cargar();

}

};






class proovedor:public Persona{ //Utilizarlo en servicio. No hacer un archivo para esto.

private:
char cuit[13];
char servicio[30];



public:
proovedor(){ //Constructor por defecto.
cuit[0]='\0';
servicio[0]='\0';
};


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
proovedor empresa;// Tenemos que hacerle un contructor a este tambien.


public:
Servicios(){
servicio[0]='-';
servicio[1]='\0';
precio=0.0;
estado=false;
};

char* getServicio(){return servicio;};
void setServicio(char* _servicio){strcpy(servicio,_servicio);};
bool getEstado(){return estado;}
void setEstado(bool x) {estado=x;}
void setPrecio(float _precio){precio=_precio;};
float getPrecio(){return precio;};




void Cargar();


Mostrar(){ //Condicionarlo con el estado obviamente, el estado se tornara true en cada carga solo y solo si se elige un servicio es decir(s/S)
cout<<"------------------------------------"<<endl;
cout<<"TIPO DE SERVICIO: "<<servicio<<endl;
cout<<"TARIFA DEL SERVICIO: $"<<precio<<endl;
cout<<"------------------------------------"<<endl;
cout<<"\n\n";

}

};




class Habitacion{

protected:
char idHabitacion[30];
bool estado;
char tipo[30];
float precio;






public:

Habitacion() {
    setIdHabitacion("00");
    setEstado(true);
    setTipo("-");
    setPrecio(0);
}


void setIdHabitacion(const char* _IdHabitacion){strcpy(idHabitacion,_IdHabitacion);};
void setEstado(bool _estado){estado=_estado;};
void setTipo(const char* _tipo){strcpy(tipo,_tipo);};
void setPrecio(float _precio){precio=_precio;};
float getPrecio(){return precio;};
const char* getIdHabitacion(){return idHabitacion;};
bool getEstado(){return estado;};
const char* getTipo(){return tipo;};









void Cargar();


void Mostrar() {
    cout<<endl;
    cout << "Numero de habitacion: " << idHabitacion << endl;
    cout << "Tipo de habitacion: " << tipo << endl;
    cout << "Tarifa: $" << precio << endl;
    cout << "Estado: " << (getEstado() ? "Disponible" : "En refacciones") << endl;
}





};




class Factura {
private:
    int numeroFactura;
    Fecha fecha;
    huesped cliente;
    float montoTotal;
    int num_habitacion;

public:
    Factura() {
    montoTotal=0.0;
    };

    void Mostrar() {
        cout << "Numero de Factura: " << numeroFactura << endl;
        cout << "Fecha: "<<fecha.mostrarEnLinea()<<endl; // Asumiendo que la clase Fecha tiene un método Mostrar
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
    //char idhotel[30];
  Fecha fecha_entrada;//Tienen constructores por defecto.
  Fecha fecha_salida;
  huesped cliente;
  Habitacion habitacion; //por lo tanto todos estos tienen que tener c
  Servicios servicio;
  bool estado;
  Factura factura;
  int numNoches;



public:
    reserva(){
    estado=false;
    numNoches=0;
    }


void setFechaEntrada(Fecha _fecha_entrada) {fecha_entrada = _fecha_entrada;}

Fecha getFechaEntrada() const {return fecha_entrada;}

void setFechaSalida(Fecha _fecha_salida) {fecha_salida = _fecha_salida;}

Fecha getFechaSalida() {return fecha_salida;}

void setCliente( huesped _cliente) {cliente = _cliente;}

huesped getCliente() {return cliente;}

void setHabitacion( const Habitacion &_habitacion) {habitacion = _habitacion;}

Habitacion getHabitacion() {return habitacion;}

void setServicio(Servicios _servicio) {servicio = _servicio;}

Servicios getServicio() {return servicio;};

//void setId(const char* id){strcpy(idhotel,id);};

//const char* getId(){return idhotel;};

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

    if (mesActual != 2 && mesActual != 9) {
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
factura.setMonto(habitacion.getPrecio()*numNoches+servicio.getPrecio());
factura.setNumero(cliente.getDNI() + fecha_entrada.getAnio() + fecha_entrada.getMes() + fecha_entrada.getDia());
factura.setCliente(cliente);
cout<<"\n\nPor favor ingrese fecha en la que se realizo la reserva, para poder realizar la factura."<<endl;
Fecha fechaFactura;
fechaFactura.Cargar();
factura.setFecha(fechaFactura);
cout<<"\n\nFactura creada exitosamente.Presione cualquier tecla para continuar"<<endl;
presionex();
}




 void Cargar();// Lo declarare en manejo archivos ya que tiene que manejar archivos de todo tipo.




 void Mostrar(){
cout<<"Datos del cliente:"<<endl;
cliente.Mostrar();
cout<<"Fecha de ingreso: "<<fecha_entrada.mostrarEnLinea()<<endl;
cout<<"Fecha de egreso: "<<fecha_salida.mostrarEnLinea()<<endl;
cout<<"Numero de habitacion: "<<habitacion.getIdHabitacion()<<endl;
cout<<"Tipo de habitacion: "<<habitacion.getTipo()<<endl;
cout<<"Servicio extra:" <<endl; //Listado tal vez guardarlo en un booleano.
servicio.Mostrar();
cout<<"\nNumero de factura: "<<factura.getNumero()<<endl;
cout<<"Importe total: $"<<factura.getMonto()<<endl;
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
bool estado;

public:
Hotel(){ //Contructor por defecto.
nombre[0]='\0';
correo[0]='\0';
idHotel[0]='\0';
celular=0;
direccion[0]='\0';
cantPiezas=0;
estado=false;
};

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

setEstado(true);//Pasadas todas las confirmaciones.
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






void escribirArchivo(Hotel nuevo){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo"<<endl;
fclose(p);
exit(1);
}
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
