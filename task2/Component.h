/**
 * @file Component.h
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief class def for component 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef COMPONENT_H_   
#define COMPONENT_H_

#include <string>
#include<vector>
#include <jsoncpp/json/json.h>
using std::string;
using std::vector;
/**
 * @brief general class for component(device) 
 * 
 */
class Component{
private:
    string id;
    string type;
    Json::Value netlist;
public:
    Component();
    ~Component();
    
    string get_id();
    string get_type();
    void set_id(string id);
    void set_type(string type);
    Json::Value get_netlist();
    void set_netlist(Json::Value n);
};


/**
 * @brief list of devices(components)
 * 
 */
typedef vector<Component> DeviceList;
#endif