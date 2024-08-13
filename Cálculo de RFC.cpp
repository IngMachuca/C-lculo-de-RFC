// Cálculo de RFC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <string>
using namespace std;

char obtenerPrimeraVocalInterna(const std::string& apellido) { //Funcion para obtener la primera vocal del apellido.
    for (size_t i = 1; i < apellido.length(); ++i) {
        char letra = toupper(apellido[i]);
        if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            return letra;
        }
    }
    return 'X'; // En caso de no encontrar vocal interna.
}

std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento) {
    std::string rfc; // Funcion para calcular el rfc. 

    char letraInicial = apellidoPaterno[0]; // Primera letra del apellido paterno.
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno); // Primera vocal interna del primer apellido.
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X'; // inicial del apellido materno o 'x' si no hay.
    char inicialNombre = nombre[0]; // primer letra del primer nombre.

    std::string anio = fechaNacimiento.substr(2, 2); // añadir año (ultimo dos digitos).
    std::string mes = fechaNacimiento.substr(5, 2); // añade el mes.
    std::string dia = fechaNacimiento.substr(8, 2); // añade el dia.

    rfc += toupper(letraInicial); 
    rfc += toupper(primeraVocalInterna);
    rfc += toupper(inicialApellidoMaterno);
    rfc += toupper(inicialNombre);
    rfc += anio;
    rfc += mes;
    rfc += dia;

    return rfc;
}

int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese el apellido paterno: "; //solicita los datos del usuario
    std::getline(std::cin, apellidoPaterno);

    std::cout << "Ingrese el apellido materno (si no tiene, pulse Enter): ";
    std::getline(std::cin, apellidoMaterno);

    std::cout << "Ingrese la fecha de nacimiento en formato (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    // Calcular y mostrar el rfc
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento); 

    std::cout << "El RFC generado es: " << rfc << endl;

    return 0;
}
	