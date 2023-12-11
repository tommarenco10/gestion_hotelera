#ifndef MANEJO_ARCHIVOS_H_INCLUDED
#define MANEJO_ARCHIVOS_H_INCLUDED





using namespace std;

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



bool empleadoExistente(Empleado _empleado){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
fclose(p);
return false;
}
empleado check;
while(fopen(&check,sizeof empleado,1,p)==1){
if(strcmp(check.getNombre(),_empleado.getNombre())==0&&strcmp(check.getApellido(),_empleado.getApellido())==0)
}
fclose(p);
return true;
}







bool archivoExistente(){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
fclose(p);
return false;
}
fclose(p);
return true;
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
fseek(puntero,sizeof (empleado)*pos,0); //posicionamos en la posicion del dato encontrado.
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
fclose(p);
}
Servicios buscar;
fseek(p,sizeof buscar*pos,0);
fread(&buscar,sizeof buscar,1,p);
fclose(p);
return buscar;
}







bool checkServicio(const char* id){  //Returneara true si no hay ninguna habitacion con ese ID.
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"No hay ninguna habitacion cargada."<<endl;
fclose(p);
return true;
}
Servicios nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
if(strcmp(nuevo.getServicio(),id)==0){
fclose(p);
cout<<"\nServicio ya registrado. Por favor elija otro."<<endl;
presionex();
rlutil::cls();
return false;
}
}
fclose(p);
return true;
}


bool archivoExistente(){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
fclose(p);
return false;
}
fclose(p);
return true;
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

bool noRegistros(){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
fclose(p);
return true;
}
return false;
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
fseek(puntero,sizeof (Servicios)*pos,0); //posicionamos en la posicion del dato encontrado.
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





class archivoHabitacion{
private:
   char nombre[30];
     int num;


public:

archivoHabitacion(const char *_nombre){
strcpy(nombre,_nombre);
}


  Habitacion leerArchivo(int pos) {
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL) {
        cout << "Error al abrir el archivo." << endl;
        fclose(p);
        exit(1);
    }



    Habitacion loc;
    fseek(p, sizeof(loc) * pos, 0);

    // Leer los datos de Habitacion

    fread(&loc, sizeof(loc), 1, p);

    fclose(p);

    return loc;
}



bool archivoExistente(){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
fclose(p);
return false;
}
fclose(p);
return true;
}




void escribirArchivo(const Habitacion &guardar) {
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL) {
        cout << "Error al abrir el archivo" << endl;
        fclose(p);
        exit(1);
    }


fwrite(&guardar, sizeof guardar, 1, p);


fclose(p);
}


void listarDisponibles(Fecha fecha_entrada,Fecha fecha_salida); //Hago la declaracion aca y la implementacion abajo porque necesito de otras funciones declaradas abajo.



void listarArchivo(){
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







bool checkHabitacion(const char* id){  //Returneara true si no hay ninguna habitacion con ese ID.
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"No hay ninguna habitacion cargada."<<endl;
fclose(p);
return true;
}
Habitacion nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
if(strcmp(nuevo.getIdHabitacion(),id)==0){
fclose(p);
cout<<"\nNumero de habitacion ya registrado. Por favor elija otro."<<endl;
presionex();
rlutil::cls();
return false;
}
}
fclose(p);
return true;
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





bool sobreEscribir(const Habitacion &reg, int pos) {
        FILE *puntero;
        puntero = fopen(nombre, "rb+");
        if (puntero == NULL) {
            return false;
        }

        // Mover el puntero a la posición correcta
        fseek(puntero,sizeof(Habitacion) * pos, 0);
        fclose(puntero);
        return true;
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


bool archivoExistente(){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
fclose(p);
return false;
}
fclose(p);
return true;
}



bool sobreEscribir(const reserva &reg,int pos){
cout<<"INgrese a sobreescribir"<<endl;
presionex();
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
fseek(p,(sizeof buscar)*pos,0);
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



class archivoOcupacion{

private:
   char nombre[30];
     int num;


public:
archivoOcupacion(const char *_nombre){
strcpy(nombre,_nombre);
}


intervalo_ocupacion leerArchivo(int pos){
FILE* p;
p=fopen(nombre,"rb");
if(p==NULL){
cout<<"Error apertura de archivo."<<endl;
exit(1);
}
intervalo_ocupacion buscar;
fseek(p,(sizeof buscar)*pos,0);
fread(&buscar,sizeof buscar,1,p);
return buscar;
}





void escribirArchivo(intervalo_ocupacion guardar){
FILE* p;
p=fopen(nombre,"ab");//Escribira y aniadira despues del ultimo registro que tengamos.
if(p==NULL){
cout<<"Error al abrir el archivo, no hay registros de ocupaciones"<<endl;
fclose(p);
presionex();
}
fwrite(&guardar,sizeof guardar,1,p);

fclose(p);



}



bool listarArchivo(const char* id){ //Lo hago booleano para que me liste el archivo normal en caso de que no encuentre ninguna reserva.
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"Ninguna ocupacion registrada"<<endl;
fclose(p);
return false;
}
intervalo_ocupacion nuevo;

while(fread(&nuevo,sizeof nuevo,1,p)==1){
if(strcmp(nuevo.getidHabitacion(),id)==0){
nuevo.Mostrar();
cout<<endl;
}
}

fclose(p);
return true;

}







bool verificarDisponibilidad(Fecha entrada,Fecha salida,const char* id){ //Va a ser id o numeroHabitacion je
FILE *p;
p=fopen(nombre,"rb");
if (p==NULL){
return false;//Para que siga.
}

intervalo_ocupacion ocupacion;
while(fread(&ocupacion,sizeof (intervalo_ocupacion),1,p)==1){

if(strcmp(ocupacion.getidHabitacion(),id)==0){ //es asi porque lo tengo como cadena de caracteres todavia, el numero de habitacion o id lo va a comprobar aqui.
    if(ocupacion.estaDisponibleEnFecha(entrada,salida)){
    fclose(p);
    return false;
    }
}
}
fclose(p);
return true;
}





bool todasLibres(){ //Comprobacion extra
FILE *p;
p=fopen(nombre,"rb");
if (p==NULL){
return true;//Para que siga.
}
else{
return false;
}

}



};







void archivoHabitacion::listarDisponibles(Fecha entrada,Fecha salida){ //Lo desarollamos booleano aca, booleano asi si no hay ningun ingreso me diga que todas las habitacioens estan librs para cualq fecha.
rlutil::cls();
FILE* p;
p=fopen(nombre,"rb");//Modo lectura only
if(p==NULL){
cout<<"No hay registros de ninguna habitacion."<<endl;
fclose(p);
}

Habitacion nuevo;
archivoOcupacion buscar("ocupaciones.dat"); //O getteara nombre de otro lao.


if(!buscar.todasLibres()){ //Asi andara mejor el programa y no hara tanta recursividad.
while(fread(&nuevo,sizeof nuevo,1,p)==1){

if(buscar.verificarDisponibilidad(entrada,salida,nuevo.getIdHabitacion())){
nuevo.Mostrar();
cout<<"Fechas de ocupacion: "<<endl;
buscar.listarArchivo(nuevo.getIdHabitacion());
cout<<"---------------------------------"<<endl;
cout<<endl;
}
}
}
else{
listarArchivo(); //Listara todas las habitaciones y cuando termine..
cout<<"\nTodas las habitaciones estan libres para cualquier fecha, por favor elija la que prefiera."<<endl;
}

}






#endif // MANEJO_ARCHIVOS_H_INCLUDED
