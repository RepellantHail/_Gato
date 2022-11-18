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
	void checarVacio(char _juegoGato[3][3]); 
	Node* crearNodo(char arrGato[3][3], int i, int j); 
	void setGato(char _juegoGato[3][3], size_t pos_i, size_t pos_j, char _equipo);
private:
	char juegoGato[3][3] = { ' ' };
	std::vector<Node*> poiterV;
};


Node::Node() {
}

Node::~Node() {
}

void Node::setGato(char _juegoGato[3][3], size_t pos_i, size_t pos_j, char _equipo) {
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++) {
			juegoGato[i][j] = _juegoGato[i][j];
			if (i == pos_i && j == pos_j)//Valor nulo que se debe modificar
				juegoGato[i][j] = _equipo;
		}
	}
}

Node* Node::crearNodo(char arrGato[3][3], int i, int j) {
	Node* aux = new Node;
	aux->setGato(arrGato, i, j, '#');//Ahora el nuevo nodo tiene un juego de gato inicializado
	return aux;
}

void Node::checarVacio(char _juegoGato[3][3]) {//Funcion recursiva para crear nodos, recibe caracter actual
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++) {
			if (_juegoGato[i][j] == '$') {//Si nodo vacio
				//Crear Nodo con posibles juegos, copiar datos del arreglo actual a uno nuevo
				//Se crea un arreglo con el caracter en la posicion vacia
				//Se envia la posicion actual en ejes de i y j 
				this->poiterV.push_back(crearNodo(_juegoGato, i, j));
				//Se inserta el Caracter actual en las distintas posiciones
				_juegoGato[i][j] = '#';
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
	cout << "Neko" << endl;
}


