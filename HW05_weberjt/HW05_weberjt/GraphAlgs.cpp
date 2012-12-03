#include "GraphAlgs.h"


//Solves Travelling Salesman Problem given Graph* G
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){

	std::pair<std::vector<NodeID>, EdgeWeight> result(std::vector<NodeID>(G->size()),0);//Result pair to return
	std::vector<bool> blockedIDs(G->size(), false); //IDs that have already been to
	EdgeWeight bound = G->size() * 0.5; // Bound of EdgeWeight
	unsigned curID = 0; //ID of current node

	//Iterate through every node
	for(unsigned i = 0; i < G->size(); i++){
		std::list<NWPair> temp = G->getAdj(curID); // Available list of NWPairs to choose from
		std::list<NWPair>::const_iterator it; //Iterator for temp
		EdgeWeight weight = 1.0; // weight to set EdgeWeight to. initial 1.0 is just large value

		//Iterate through adjacent nodes
		for(it = temp.begin(); it != temp.end(); it++){
			if(it->second < weight && !blockedIDs[it->first]){
				if(weight != 1.0){ //if iteration is not the first
					blockedIDs[curID] = false;
				}

				curID = it->first;
				blockedIDs[curID] = true;
				weight = it->second;
			}
			//If EdgeWeight + weight is greater than the bound
			//set back i by 2 so when i++ is called in for(), so i = i - 1
			//set id at curID to false so it can be used again
			if(result.second + weight > bound){
				i = i - 2;
				blockedIDs[curID] = false;
				continue;
			}
		}

		//Set id
		result.first[i] = curID;
	}
	
	//Sums all weights of determined path
	result.second = 0;
	for(int i = 0; i < result.first.size() -1; i++){
		result.second += G->weight(result.first[i], result.first[i+1]);
	}
	result.second += G->weight(result.first[result.first.size()-1], result.first[0]);
	return result;
}