/**
 * @file API_helper.h
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief helper definations used in api 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef API_HELPER_H
#define API_HELPER_H

#include<vector>
#include<exception>
#include "Topology.h"
#include "Component.h"
using namespace std;

/**
 * @brief need if no topology is found with same topology id 
 * 
 */
class NOT_FOUND_TOPOLOGY : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "no topology is found with same topology id ";  
        }  
};  

/**
 * @brief need if he json object is empty
 * 
 */
class EMPTY_JSON : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "the json object is empty";  
        }  
};

/**
 * @brief need if no components exist in this topology
 * 
 */
class EMPTY_COMPONENTS : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "no components exist in this topology (empty components)";  
        }  
};  

/**
 * @brief need if no component is found with the given netlist node in a given topology.
 * 
 */
class NO_COMPONENT_WITH_NETLIST_NODE : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "no component is found with the given netlist node ";  
        }  
}; 

/**
 * @brief list of topologies
 * 
 */
typedef vector<topology> TopologyList;

/**
 * @brief list of devices(components)
 * 
 */
typedef vector<Component> DeviceList;


#endif