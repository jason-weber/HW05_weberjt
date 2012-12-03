#include "ListGraph.h"

ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	num_edges = 0;
}

ListGraph::~ListGraph(){
	
}

//adds edge between u and v with EdgeWeight weight
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	edgeList.at(u).push_back(NWPair(v,weight));
	edgeList.at(v).push_back(NWPair(u,weight));
	num_edges++;
}

//Returns edge weight between u and v
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	EList::const_iterator it;
	for(it = edgeList.at(u).begin(); it != edgeList.at(u).end(); it++){
		if(it->first == v){
			return it->second;
		}
	}
	return 0;
}

//Gets a list of all adjacent nodes to u
EList ListGraph::getAdj(NodeID u) const {
	return edgeList.at(u);
}

//Returns how many edges are connected to u
unsigned ListGraph::degree(NodeID u) const {
	return edgeList.at(u).size();
}

//returns number of nodes 
unsigned ListGraph::size() const {
	return edgeList.size();
}

//returns number of edges
unsigned ListGraph::numEdges() const {
	return num_edges;
}