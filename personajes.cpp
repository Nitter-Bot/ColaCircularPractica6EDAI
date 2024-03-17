/*
Author : Nitter
Date : March 16 2024
*/

#include <iostream>
 
using namespace std;
#define ll long long 
#define pb push_back 
#define max 5 //Constante para el tamanio estatico de la cola

/*Clase persona que almacenara los datos de los personajes
con su constructor Persona() y una sola funcion que imprime
los datos de la clase*/

class Persona{
public:
    string nombre;
    string poder;
    string debilidad;
    string raza;
    string videojuego;
    Persona(string nombre,string poder,string debilidad,string raza,string videojuego);
    void imprimir();
};

//Constructor
Persona::Persona(string nombre,string poder,string debilidad,string raza,string videojuego){
    this->nombre = nombre;
    this->poder = poder;
    this->debilidad = debilidad;
    this->raza = raza;
    this->videojuego = videojuego;
}

//Imprime los datos a partir de un apuntador
void Persona::imprimir(){
    cout << "\n\nNombre     : "<< this->nombre << endl;
    cout << "Poder      : "<< this->poder << endl;
    cout << "Debilidad  : "<< this->debilidad << endl;
    cout << "Raza       : "<< this->raza << endl;
    cout << "Videojuego : "<< this->videojuego << endl;
}

/*Clase de la estructura de datos Cola circular,
cuenta con un frente y un final, los datos se almacenan
en un arreglo de max elementos de tipo Persona

Metodos: 
Constructor ; 
Push, agrega elementos a la 
estructura; 
Full retorna falso o verdadero dependiendo 
si el modulo max de end+1 es igual al valor del
apuntador front;
apt, metodo que imprime el valor de los apuntadores alrededor
de la cola circular, solo para debug;
Recorrer mueve el apuntador de enfrente hacia atras o enfrente
de acuerdo a si se desea ir a la derecha o izquierda;
Primero, ya que tengo flojera es para imprimir el primer valor en 
haber entrado solo para el funcionamiento del programa jeje
*/
class ColaCircular{
private:
    int front,end;
    Persona *p[max];
public:
    ColaCircular();
    void push(Persona *valor);
    bool full(){return ((end+1)%max == front);}
    friend class Persona;
    void apt(){cout<< front << " "<< end <<endl;}
    void recorrer(bool n);
    void primero(){p[0]->imprimir();}
};

//Constructor
ColaCircular::ColaCircular(){
    end = -1;
    front = -1;
}

//Metodo push, evalua
void ColaCircular::push(Persona *valor){
    if(!full()){
        end = (end+1)%max;
        p[end]=valor;
        if(front == -1){
            front=0;
        }
    }else cout<< "Cola llena" <<endl;
}

//Metodo recorrer
void ColaCircular::recorrer(bool n){
    front += (n==true)? 1:-1;
    if (front == -1)front = end;
    if (front == max)front = 0;
    p[front]->imprimir();
    return;
}

void menu(){
    cout<<"\n[0]Izquierda\t\t[1]Derecha"<<endl;
}

int main()
{
    cout << "\n\t*** Personajes en cola circular ***\n"<<endl;
    //Creacion de personajes
    //
    //Nombre,poder,debilidad,raza y videojuego de origen
    Persona *mc = new Persona("Master Chief","Fuerza sobrehumana","Exponer su rostro","Desconocida","Halo");
    Persona *heim = new Persona ("Heimerdinger","Mago","Al ser lento es propenso a emboscadas ya ataques sorpresa","Yordle","League of Legends");
    Persona *goku = new Persona ("Goku","Super Fuerza","Las cosquilas","Sayayin","Dragon Ball");
    Persona *arthurM = new Persona ("Arthur Morgan","Maestro de las armas y capacidad sobre humana","Tuberculosis","Humano","Red Dead Redemption 2");
    Persona *cammy = new Persona("Cammy","Combate militar","Posiblemente poderes arcanos","Humana","Street Fighter");
    
    //Prueba de que se llena la cola pusheando otro elemento al maximo
    //Persona *prueba = new Persona(" "," "," "," "," ");
    
    //Agragamos personajes a la cola circular
    ColaCircular cola;
    cola.push(mc);
    //cola.apt();
    cola.push(heim);
    //cola.apt();
    cola.push(goku);
    //cola.apt();
    cola.push(arthurM);
    //cola.apt();
    cola.push(cammy);
    //cola.apt();
    //cola.push(prueba);
    //Prueba de que el metode imprimir funcionan
    //mc->imprimir();
    
    cola.primero();
    menu();
    //Para deternolo presiona ctrl+c
    while (true){
        bool dir;
        int n;
        cin >> n;
        if (n==1)dir=true;
        else dir=false;

        cola.recorrer(dir);
        menu();
    }

}

