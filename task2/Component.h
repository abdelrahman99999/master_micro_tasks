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

using namespace std;
/**
 * @brief general class for component(device) 
 * 
 */
class Component{
private:
    string id;
    string type;
public:
    Component();
    ~Component();
    
    string get_id();
    string get_type();
    void set_id(string id);
    void set_type(string type);
};

#endif