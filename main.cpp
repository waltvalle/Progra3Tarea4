#include "Evaluador.h"
#include <fstream>
#include <math.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream escribir(nombre_archivo.c_str());
    //con el ofstream se crea un archivo en base a la string dada
    escribir<<num;
    //escribe en el archivo lo que contenta num, en este caso un int
    escribir.close();
    //el .close cierra el archivo
}

int leerNumeroTexto(string nombre_archivo)
{
    ifstream leer(nombre_archivo.c_str());
    //el ifstream lee el archivo
    int leido;
    //leer apunta a la variable int creada anteriormente y la devuelve
    leer>>leido;
    return leido;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream escribir(nombre_archivo.c_str());
    //con el ofstream se crea un archivo en base a la string dada
    escribir<<str;
    //escribe en el archivo lo que contenta str, en este caso un string
    escribir.close();
    //el .close cierra el archivo
}
string leerStringTexto(string nombre_archivo)
{
    ifstream leer(nombre_archivo.c_str());
    //el ifstream lee el archivo
    string c;
    leer>>c;
    //se crea una variable string que sera leida y retornada respectivamente
    return c;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream escribir(nombre_archivo.c_str());
    //con el ofstream se crea un archivo en base a la string dada
    escribir.write((char*)&num,4);
    //esta funcion se encarga de escribir un char* de un int asignandole 4 espacios de memoria
    escribir.close();
    //el .close cierra el archivo
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream leer(nombre_archivo.c_str());
    int leido;
    //esta in sera leida y devuelta
    leer.read((char*)&leido,4);
    //esta funcion se encarga de leer un char* de un int leyendo 4 espacios de memoria
    return leido;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream escribir(nombre_archivo.c_str());
    //con el ofstream se crea un archivo en base a la string dada
    escribir.write(str.c_str(),4);
    //esta funcion se encarga de escribir un char* de un int asignandole 4 espacios de memoria
    escribir.close();
    //el .close cierra el archivo

}
string leerStringBinario(string nombre_archivo)
{
    ifstream leer(nombre_archivo.c_str());
    //el ifstream lee el archivo basado en u=la string dada
    char cadena[4];
    //declaramos un char cadena con 4 espacios
    string chain;
    //una string que es la que sera igualada al contenido de cada uno de los espacios del char
    leer.read(cadena,4);
    //el read lee lo que contiende cadena con 4 espacios
    chain = cadena;
    //se devuelve cadena ya con el contenido de la string
    return cadena;
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream leer(nombre_archivo.c_str());
    int cant=0;
    //ifstream lee el archivo. La primera variable almacenara la cantidad, la sefunda sera un string vacio que usara despues
    string word;
    for(int i=0;i<cant;i++)
    {
        //leer apunta a lo que tenga word
        leer>>word;
        //si word es igual a lo que tenga cadena entonces devolvera true, de lo contrario sera falsa
        if(word == str)
            {
                return true;
            }
        return false;
    }
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream leer(nombre.c_str());
    leer.seekg(0,ios::end);
    // el seekg recibe la instruccion de leer hasta el final del archivo
    int cant=leer.tellg();
    // esta variable almacenara la cantidad de espacio que ocupa el grupo de numeros
    leer.seekg(0,ios::beg);
    //este seekg apunta al inicio del archivo
    int mayor=-99999;
    // una int con un numero en negativo
    //el for avanzara en tanto i sea menor que el largo del grupo
    for(int i=leer.tellg();i<cant;i++)
    {
        //una vez se ejecuta el for se crea una variable
        int num;
        //se escribira como archivo binario lo que tenga num
        leer.read((char*)&num,4);
        //si lo que se escribio es menor que num entonces mayor sera igual a num
        if(mayor<num)
        {
            mayor=num;
        }
    }
    // se devuelve lo que se almaceno en la variable mayor
    return mayor;
}

int main ()
{
    //Funcion evaluadora

    evaluar();
    return 0;
}
