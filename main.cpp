#include <iostream>
#include "Graph.h"

using namespace std;
int main(){

	Graph<char> grafo;
	grafo.addvertex('a');
	grafo.addvertex('b');
	grafo.addvertex('c');
	grafo.addvertex('d');
	grafo.addvertex('e');
	grafo.addvertex('f');
	grafo.addvertex('g');
	grafo.addvertex('h');
	grafo.addvertex('i');
	grafo.addvertex('j');
	grafo.addvertex('k');
	grafo.addvertex('l');
	grafo.connectvertex('a','b',10);
	grafo.connectvertex('a','c',13);
	grafo.connectvertex('b','d',4);
	grafo.connectvertex('c','d',1);
	grafo.connectvertex('d','e',3);
	grafo.connectvertex('d','f',11);
	grafo.connectvertex('e','g',7);
	grafo.connectvertex('f','g',8);
	grafo.connectvertex('g','h',4);
	grafo.connectvertex('g','i',2);
	grafo.connectvertex('g','j',2);
	grafo.connectvertex('g','k',5);
	grafo.connectvertex('h','l',5);
	grafo.connectvertex('i','l',11);
	grafo.connectvertex('j','l',3);
	grafo.connectvertex('k','l',1);

	grafo.dikstra('a','e');
	grafo.dikstra('a','l');
	grafo.dikstra('g','c');

	printf("Hay %d vertices. \n", grafo.getnvertex() );

	return 0;
}