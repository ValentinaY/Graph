/**
@author Valentina Yate
*/

#ifndef __GRAPH__HXX__
#define __GRAPH__HXX__

#include <map>
#include <queue>
using namespace std;

template<class T >
Graph<T>::Graph()
{
}

template<class T >
Graph<T>::~Graph()
{
}

template<class T >
void Graph<T>::addvertex(T v){
	this->vertex.push_back(v);
	vector< vrt<T> > list;
	list.clear();
	this->edges.insert( pair<T,vector < vrt<T> > >(v, list) );
	printf("El vertice se agrego. \n");
}

template<class T>
void Graph<T>::connectvertex(T a, T b, int w){
int exists=0;

for(int i=0;i<Graph::vertex.size();i++){
	if(vertex[i]==a || vertex[i]==b){
		exists++;
	}
}

if(exists==2){
	vrt<T> newva, newvb;
	newva.data=a;	newvb.data=b;
	newva.weight=w;	newvb.weight=w;
	this->edges[a].push_back(newvb);
	this->edges[b].push_back(newva);	
	printf("Se han conectado los vertices. \n");
}
else{
	printf("Alguno de los vertices no se encuentra.\n");
}
}

template<class TEdge >
long Graph<TEdge>::getnvertex(){
	long n=this->vertex.size();
	return n;
}

template<class T >
void Graph<T>::deletevertex( T v){
	
	vector< vrt<T> > temp=this->edges[v];
	int cont=0;
	vrt<T> vertextemp;
	while(cont<temp.size()){
		vertextemp=temp.at(cont);
		vector< vrt<T> > temp2=this->edges[vertextemp.data];
		int j=0;
		for(j=0;j<temp2.size();j++){
			if(v==temp2.at(j).data){
				break;
			}
		}
		this->edges[vertextemp.data].erase(this->edges[vertextemp.data].begin()+j);	
		cont++;
	}

	int i=0;
	for(i=0;i<Graph::vertex.size();i++){
		if(vertex[i]==v){
			break;
		}
	}
	this->vertex.erase( (this->vertex.begin() )+i);

	printf("Se ha eliminado el vertice.\n");	
}

template<class T >
void Graph<T>::deleteedge(T a, T b, int w){

	vector< vrt<T> > temp=this->edges[a];
	
	int j=0;
	for(j=0;j<temp.size();j++){
		if(b==temp.at(j).data && w==temp.at(j).weight){
			break;
		}
	}	
	this->edges[a].erase(this->edges[a].begin()+j);		

	temp=this->edges[b];
	j=0;
	for(j=0;j<temp.size();j++){
		if(a==temp.at(j).data && w==temp.at(j).weight){
			break;
		}
	}	
	this->edges[b].erase(this->edges[b].begin()+j);
	printf("Se ha eliminado la arista.\n");			
}

template<class T >
int Graph<T>::hasedge(T a, T b){
	int t=0;

	vector< vrt<T> > temp=this->edges[a];
	int i=0;
	for(i=0; i<temp.size(); i++){
		if(temp.at(i).data == b ){
			t++;
		}
	}

	return t;
}

template<class T>
void Graph<T>::dikstra(T a, T b){
	std::map<T, bool> used;
	std::map<T, int > way;
	vector < vrt<T> > temp;

	T actual=a;
	temp=this->edges[actual];
	bool end=false;

	bool nohaymas=false;
	int cont=0;
	while(!end){
		int wayactual=way[actual];
		int wayoni;
		for(int i=0; i<temp.size(); i++){
			wayoni=way[temp.at(i).data];
			if( (wayoni > temp.at(i).weight+way[actual]) || (way[temp.at(i).data] == 0) ) {
				way[temp.at(i).data]=temp.at(i).weight+way[actual];
				
			}
		}
		used[actual]=true;
		typename std::map<T, int >::iterator it;
		int i= 0xFFFFF;
		T datatemp;
		for(it= way.begin();	it!=way.end();	++it){
			if(it->second != 0 && it->second<i && !used[it->first]){
				i=it->second;
				datatemp=it->first;
			}
		}
		actual=datatemp;
		temp=this->edges[actual];
		if(cont== this->vertex.size()+1){
			if ( way[b] == 0)
				printf("No se encuentra el vertice\n");
			
			break;
		}
		cont++;
	}
	printf("Camino encontrado con longitud: %d\n", way[b]);
}

template<class T >
void Graph<T>::draw(std::string filename){
	T datus;
	vector< vrt<T> > temp;
	for(int i=0;i< this->vertex.size();i++){
		datus=this->vertex.at(i);
		temp = this->edges[datus];
		cout<<datus;
		cout<<"\t";
		for(int j=0;j<temp.size();j++){
			cout<<temp.at(j).data;
			cout<<" ";
			cout<<temp.at(j).weight;
			cout<<" \t";
		}
		cout<<endl;
	}
}


#endif