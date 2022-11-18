// Gato.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
using namespace std;


class Node
{
public:
	Node();
	~Node();
	void checarVacio(char _juegoGato[3][3])//Funcion que checa espacios vacios en el arrglo Gato
	Node* crearNodo(char arrGato[3][3], int i, int j);//Funcion para iniciar un nodo y su correspondiente juego de Gato 
	void setGato(char _juegoGato[3][3], size_t pos_i, size_t pos_j, char _equipo);//Funcion que copia los valores de gato de un nodo a otro
private:
	char juegoGato[3][3] = { ' ' };//Arrreglo de caracteres que guarda el juego de gato
	std::vector<Node*> poiterV;//Arreglo dinamico para guardar los punteros
};


Node::Node() {
}

Node::~Node() {
}

void Node::setGato(char _juegoGato[3][3], size_t pos_i, size_t pos_j, char _equipo) {//Recibe el arreglo gato, la posicion que debe cambiar y el caracter a ingresar
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++) {
			juegoGato[i][j] = _juegoGato[i][j];
			if (i == pos_i && j == pos_j)//Valor nulo que se debe modificar
				juegoGato[i][j] = _equipo;//El caracter puede ser X u O
		}
	}
}

Node* Node::crearNodo(char arrGato[3][3], int i, int j) {//Recibe el juego a inicializar y las posiciones a modificar
	Node* aux = new Node;//Se inicializa un nodo
	aux->setGato(arrGato, i, j, '#');//Ahora el nuevo nodo tiene un juego de gato inicializado
	//Se llena con un '#' solo para comprobar que se esta inicializando
	return aux;//Por ultimo regresa
}

void Node::checarVacio(char _juegoGato[3][3]) {//Funcion recursiva para crear nodos, recibe caracter actual
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++) {//Se accesede al arreglo por medio de un for anidado
			if (_juegoGato[i][j] == '$') {//Si nodo vacio
				//Crear Nodo con posibles juegos, copiar datos del arreglo actual a uno nuevo
				//Se crea un arreglo con el caracter en la posicion vacia
				//Se envia la posicion actual en ejes de i y j 
				this->poiterV.push_back(crearNodo(_juegoGato, i, j));
				//Se inserta el Caracter actual en las distintas posiciones
				_juegoGato[i][j] = '#';//Se asigan '#' para las posiciones que ya se revisaron
			}
			else {
			}
		}
	}
}

int main()
{
	cout << "Gato" << endl;
	Node* nodo = new Node;//Se inica el objeto
	char ArrGato[3][3] = { 'O','X','O','X','O','X','$','$' ,'$' };//Se inicializa el arreglo
	nodo->checarVacio(ArrGato);
}


