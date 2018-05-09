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
	printf("Hay %d vertices. \n", grafo.getnvertex() );
	grafo.connectvertex('a','b',10);
	grafo.connectvertex('a','c',8);
	grafo.connectvertex('a','d',5);
	grafo.connectvertex('a','d',16);
	grafo.connectvertex('c','e',1);
	grafo.connectvertex('c','a',10);
	grafo.connectvertex('e','b',2);
	grafo.draw("graph.txt");

	grafo.deleteedge('a','b',10);
	grafo.draw("graph.txt");
	grafo.deletevertex('c');
	grafo.draw("graph.txt");


	printf("Hay %d vertices. \n", grafo.getnvertex() );
	return 0;
}