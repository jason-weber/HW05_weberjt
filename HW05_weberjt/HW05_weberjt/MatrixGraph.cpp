#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);
	for(unsigned i = 0; i < num_nodes; i++){
		M.at(i).resize(num_nodes);
	}
	num_edges = 0;
	
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	M.at(u).at(v) = weight;
	M.at(v).at(u) = weight;
	num_edges++;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v)const{
	if(M.at(u).at(v) <= 0.00001){
		return 0.0;
	}
	return M.at(u).at(v);
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	EList result;
	for(unsigned i = 0; i < M.at(u).size(); i++){
		if(M.at(u).at(i) >= 0.00001){
			result.push_back(NWPair(i, M.at(u).at(i))); 
		}
	}
	return result;
}
unsigned MatrixGraph::degree(NodeID u) const{
	unsigned count = 0;
	for(unsigned i = 0; i < M.at(u).size(); i++){
		if(M.at(u).at(i) >= 0.00001){
			count++;
		}
	}
	return count;
}
unsigned MatrixGraph::size() const{
	return M.size();
}
unsigned MatrixGraph::numEdges() const{
	return num_edges;
}
