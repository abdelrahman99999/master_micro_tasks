/**
 * @file Topology.cpp
* @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief class imp for topology
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Topology.h"

/**
 * @brief Construct a new topology::topology object
 * 
 */
topology::topology(){
}
/**
 * @brief Destroy the topology::topology object
 * 
 */
topology::~topology(){
}
/**
 * @brief getter
 * 
 * @return string id
 */
string topology::get_id(){
    return this->id;
}
/**
 * @brief setter
 * 
 * @param id 
 */
void topology::set_id(string id){
    this->id = id;
}