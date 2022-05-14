/**
 * @file Topology.h
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief class def for topology
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOPOLOGY_H_   
#define TOPOLOGY_H_

#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
using namespace std;

/**
 * @brief general class for topology
 * 
 */
class topology{
private:
    string id;
    Json::Value components;
public:
    topology();
    ~topology();

    string get_id();
    void set_id(string );

    Json::Value get_components();
    void set_components(Json::Value comp);
};


/**
 * @brief list of topologies
 * 
 */
typedef vector<topology> TopologyList;

#endif