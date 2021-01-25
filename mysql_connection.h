// Declaración de la clase MySQLConnection
// Implementación en mysql_connection.cpp

// Evita más de una inclusión del archivo de encabezado
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H

// MySQL
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
// Clases
#include "persona.h"
#include "proveedor.h"
#include "vehiculo.h"

using std::string;

// Clase para conectar el Front con la BDD remota a través de funciones
class MySQLConnection
{
    private:
        // Atributos
        sql::Driver *driver;
        sql::Connection *con;

        // Funciones
        char *encriptar(const char *password);
        int registrarUsuario(const char *correo, const char *password, const char *tipo);
        int obtenerIdUsuario(const char *correo);
        char *timeToString(time_t *fecha);

    public:
        // Constructor
        MySQLConnection();

        // Funciones get
        sql::Connection *getConnection() const;

        // Funciones
        int iniciarSesion(const char *correo, const char *password);
        int registrarCliente(Persona cliente, const char *correo, const char *password);
        int registrarProveedor(Proveedor proveedor, const char *correo, const char *password);
        int registrarTransportista(Persona transportista, Vehiculo vehiculo, const char *correo, const char *password);
};

#endif // MYSQLCONNECTION_H
