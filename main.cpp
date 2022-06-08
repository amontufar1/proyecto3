#include <iostream>
#include <mysql.h>
using namespace std;

char serverdb[] = "localhost";//El servidor 
char userdb[] = "proyecto";    //El nombre del usuario es proyecto es proyecto
char passworddb[] = "Umg$2019"; //contraseña para el usuario es Umg$2019
char database[] = "proyecto2"; //variables con el valor para la base de datos
int main() {
	
	
	MYSQL* connection; //puntero 
	long alumnoId; //objeto de la coneccion 
	string alumnoNombre;
	string correo;
	string telefono;
	string grado;
	string seccion;
	const char* query; //como puntero
	int promedio;
	int bimestre1;
	int bimestre2;
	int bimestre3;
	int bimestre4;
	string sql;//sql que voy a ejecutar
	int resul;
	int op;

	connection = mysql_init(0);         
    if(connection)
	{
		cout<< "la biblioteca msql se ha iniciado correctamente" << endl;
	    connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL,0 );
	     if(connection)
	{
	struct Alumno {
	int clave;
	string nombre;
	Alumno *siguiente;
};

Alumno *inicio = NULL;

void insertarFinal() {
	Alumno *alumno = new Alumno();
	cout << "Ingrese la clave: ";
	cin >> alumno->clave;
	cin.ignore();
	cout << "Ingrese el nombre: ";
	getline(cin, alumno->nombre);
	alumno->siguiente = NULL;
	if (inicio == NULL) 
	{
		inicio = alumno;
		return;
	}
	Alumno *aux = inicio;
	Alumno *anterior = NULL;
	while(aux->siguiente != NULL) {
		aux = aux->siguiente;
	}
	aux->siguiente = alumno;
}

void mostrarLista() 
{
	if (inicio == NULL) 
	{
		cout << "No hay datos en base" << endl;
		return;
	}
	Alumno *aux = inicio;
	while(aux != NULL) {
		cout << "Clave: " << aux->clave << endl;
		cout << "Nombre: " << aux->nombre << endl;
		aux = aux->siguiente;
	}
}        
        	cout<< "Por favor ingrese la opcion que desee del menu" << endl;
			cout<< "opcion 1: Cargar alumno" << endl;
			cout<< "opcion 2: Agregar Alumno" << endl;
			cout<< "opcion 3: Agreagar notas del alumno" << endl;
			cout<< "opcion 4: Buscar un alumno" << endl;
			cout<< "opcion 5: Buscar un grado" << endl;
			cout<< "opcion 6: Eliminar un alumno o grado" << endl;
			cout<< "opcion 7: modificar los datos de un alumno" << endl;
			cout<< "opcion 8: Modificar los datos de un grado" << endl;
			cout<< "opcion 9: lista de los alumnos de un grado y seccion" << endl;
			cout<< "opcion 10: Guardar cambios " << endl;
			cout<< "opcion 11: salir" << endl;
			cin>>op;
			
    	switch(op){
			case 1:
					cout<< "ingrese el nombre completo del alumno"  << endl;
	               	getline(cin, alumnoNombre); // ingreso el nombre del alumno y lo guardo 
		            cout<< "ingrese el correo del alumno"  << endl;
		            getline(cin, correo);
		            cout<< "ingrese el telefono del alumno"  << endl;
		            getline(cin, telefono);
		            sql = "INSERT INTO proyecto2(alumno_nombre, correo, telefono, grado, seccion)  VALUES ('" + alumnoNombre + "' , '" + correo + "' ,'" + telefono + "' , '" + grado + "' ,'" + seccion + "' , )";
	             	query = sql.c_str(); // lo convierto en puntero 
		            resul = mysql_query(connection, query);
		if (resul == 0 ){
			cout << "registro guardado";
		}
		else {
			cout << "no fue posible guardar el registro" << mysql_error(connection) <<endl;
		}
				break;
			case 2:
					cout<< "ingrese el grado del alumno"  << endl;
	              	getline(cin, grado);
	             	cout<< "ingrese la seccion del alumno"  << endl;
	            	getline(cin, seccion);
	            	sql = "INSERT INTO proyecto2(alumno_nombre, correo, telefono, grado, seccion)  VALUES ('" + alumnoNombre + "' , '" + correo + "' ,'" + telefono + "' , '" + grado + "' ,'" + seccion + "' , )";
		query = sql.c_str(); // lo convierto en puntero 
		resul = mysql_query(connection, query);
		if (resul == 0 ){
			cout << "registro guardado";
		}
		else {
			cout << "no fue posible guardar el registro" << mysql_error(connection) <<endl;
		}
				break;
			case 3:
				cout<< "ingrese las noas del alumno de los bimestres 1,2,3 y 4"  << endl;
				cout<< "Ingrese la nota del primer bimestre"  << endl;
	               	cin>> bimestre1; // ingreso el nombre del alumno y lo guardo 
		          	cout<< "Ingrese la nota del segundo bimestre"  << endl;
	               	cin>> bimestre2;
	               	cout<< "Ingrese la nota del tercer bimestre"  << endl;
	               	cin>> bimestre3;
	               	cout<< "Ingrese la nota del cuarto bimestre"  << endl;
	               	cin>> bimestre4;
	               	
		            sql = "INSERT INTO proyecto2(alumno_nombre, correo, telefono, grado, seccion)  VALUES ('" + alumnoNombre + "' , '" + correo + "' ,'" + telefono + "' , '" + grado + "' ,'" + seccion + "' , )";
	             	query = sql.c_str(); // lo convierto en puntero 
		            resul = mysql_query(connection, query);
		if (resul == 0 ){
			cout << "registro guardado";
		}
		else {
			cout << "no fue posible guardar el registro" << mysql_error(connection) <<endl;
		}
		
		promedio = bimestre1+bimestre2+bimestre3+bimestre4/4;
				break;
			case 4:
				 MYSQL_ROW row; //consulta, ROW PARA UNA FILA
	  MYSQL_RES* data; //aculuma los registros, marcamos como puntero 
	  sql = "SELECT * FROM alumno";
	  query = sql.c_str();
	  resul = mysql_query(connection, query);
	  if (resul == 0 ){
			cout << "Se obtivieron los siguientes datos "<< endl;
			data = mysql_store_result(connection);
			int countColumns = mysql_num_fields(data);
			row = mysql_fetch_row(data);
			while(row = mysql_fetch_row(data))
			{
				for (int i = 0; i< countColumns; i++)
				{
					cout<< row[i] <<"/t";
				}
				cout<<endl;
			}
		}
		else {
			cout << "no fue posible obtener el registro " << mysql_error(connection) <<endl;
		}
				break;
			case 5:
					 MYSQL_ROW row; //consulta, ROW PARA UNA FILA
	                 MYSQL_RES* data; //aculuma los registros, marcamos como puntero 
	                 sql = "SELECT * FROM grado";
	                 query = sql.c_str();
	                resul = mysql_query(connection, query);
	                 if (resul == 0 ){
		            	cout << "Se obtivieron los siguientes datos "<< endl;
		              	data = mysql_store_result(connection);
		            	int countColumns = mysql_num_fields(data);
	            		row = mysql_fetch_row(data);
		             	while(row = mysql_fetch_row(data))
		         	{
				for (int i = 0; i< countColumns; i++)
				{
					cout<< row[i] <<"/t";
				}
				cout<<endl;
			}
		}
		else {
			cout << "no fue posible obtener el registro " << mysql_error(connection) <<endl;
		}
				
				break;
			case 6:
				eliminar(); 
                  pausa()
				break;
			case 7:
				modificar(); 
                 pausa();
				break;
			case 8:
				modificar(); 
                pausa();
				break;
			case 9:
				cout << "Lista de alumnos " << endl;	
            	int agregar = 1;
         	do {
         		insertarFinal();
	    	cout << "Desea agregar otro alumno, presione 1 para si y cualquier numero para no" << endl;
	          	cin >> agregar;
            	} while (agregar == 1);	
	           mostrarLista();
				
				break;
			case 10:
				break;
			case 11:
				 	cout<<"Gracias por usar el programa";
				exit(0); 
				break;
			
		}
		
	
	
		
		
	}
	else {
		cout<< "no se pudo establecer la coneccion " << mysql_error(connection) <<endl;
	}
	 
 	
		}
	
	else {
		cout<< "no es posible iniciar la biblioteca" << endl;
	}
	return 0;	
	
}



