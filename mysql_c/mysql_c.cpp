// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_parcial", "P@rcial123", "parcial_2", 3306, NULL, 0);
    if (conectar) {
        //cout << "Coneccion Exitosa" << endl;
        int carnet;
        string nombres;
        string apellidos;
        char direccion;
        int telefono;
        string genero;
        char email;
        DATE fecha_nacimiento;
        cout << "Ingresa Carnet";
        cin >> carnet;
        cout << "Ingresa Nombres";
        cin >> nombres;
        cout << "Ingresa Apellidos";
        cin >> apellidos;
        cout << "Ingresa Direccion";
        cin >> direccion;
        cout << "Ingresa Telefono";
        cin >> telefono;
        cout << "Ingresa Genero";
        cin >> genero;
        cout << "Ingresa Email";
        cin >> email;
        cout << "Ingresa Fecha de Nacimineto";
        cin >> fecha_nacimiento;

        string insert = "insert into estudiantes(nombres,apellidos,direccion,telefono,genero,email,fecha_nacimineto) values ('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar,i);
        if (!q_estado) {
            cout << "Ingreso Exitoso" << endl;
        }
        else {
            cout << "Error al Ingresar" << endl;
        }

        string consulta = "select * from estudiantes";
        const char* c = consulta.cstr();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado) ) {
                cout<<fila[0],<<fila¨[]
            }
        }
        else {
            cout << "Error al Consultar" << endl;
        }


    }
    else {
        cout << "Error en la Coneccion" << endl;
    }
    system("pause");
    return 0;
}

   