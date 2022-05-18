/**
 * @file Component.cpp
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief class imp for component 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Component.h"
/**
 * @brief Construct a new Component:: Component object
 * 
 */
Component::Component(){

}
/**
 * @brief Destroy the Component:: Component object
 * 
 */
Component::~Component(){

}
/**
 * @brief getter
 * 
 * @return string id
 */
string Component::get_id(){
    return this->id;
}
/**
 * @brief setter
 * 
 * @param id 
 */
void Component::set_id(string &id){
    this->id = id;
}
/**
 * @brief getter
 * 
 * @return string type
 */
string Component::get_type(){
    return this->type;
}
/**
 * @brief setter
 * 
 * @param type 
 */
void Component::set_type(string &type){
    this->type = type;
}

/**
 * @brief getter
 * 
 * @return Json::Value 
 */
Json::Value Component::get_netlist(){
    return this->netlist;
}

/**
 * @brief setter
 * 
 * @param n 
 */
void Component::set_netlist(Json::Value n){
    this->netlist = n;
}