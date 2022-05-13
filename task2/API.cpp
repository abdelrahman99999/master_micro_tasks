/**
 * @file API.cpp
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief api provide operations applied on json
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "API.h"
/**
 * @brief Construct a new Result:: Result object
 * 
 */
Result::Result(){
 
}
 
/**
 * @brief Destroy the Result:: Result object
 * 
 */
Result::~Result(){

}

/**
 * @brief used to Read a topology from a given JSON file and store it in the memory.
 * 
 * @param FileName name with extension of file of json
 * @return Result 
 */
Result Result::readJson(string FileName){
    ifstream input_handler(FileName, std::ifstream::binary);
    input_handler >> this->Json_obj;
    input_handler.close();
    return *this;
}

/**
 * @brief Write a given topology from the memory to a JSON file.
 * 
 * @param FileName name with extension of file of json
 * @return Result 
 */
Result Result::writeJson(string FileName){
    ofstream output_handler;
    output_handler.open(FileName);
    output_handler << this->Json_obj<<endl;
    output_handler.close();
    return *this;        
}

/**
 * @brief Delete a given topology from memory. 
 * 
 * @param TopologyID 
 * @return Result 
 */
Result Result::deleteTopology(string TopologyID){

    if(Json_obj.empty()==true){//if object is [ ] or { } only
        throw EMPTY_JSON();
    }

    if(Json_obj.isArray()==false ){     //if there is only one topology (not in list)
        if(Json_obj["id"].asString()==TopologyID){//if you find topology
            this->Json_obj.clear();
        }else{
            throw NOT_FOUND_TOPOLOGY();
        }
    }else{  //if there are list of topologies
        int flag=0;//flag used to know if no topology is found with the given topology id 
        Json::Value newArray = Json::arrayValue;
        for (Json::ValueIterator topo_iterator = this->Json_obj.begin(); topo_iterator != this->Json_obj.end(); ++topo_iterator){
            /*loop on topologies*/
            if(0 != (*topo_iterator)["id"].asString().compare(TopologyID))//if you don't find this topolgy
            {
                newArray.append((*topo_iterator));
            }else{
                //if you find this topolgy
                flag=1;
            }
        }
        if(flag==0){
            throw NOT_FOUND_TOPOLOGY();
        }
        this->Json_obj = newArray;
    }
    return *this;
}

/**
 * @brief Query about which topologies are currently in the memory
 * 
 * @return TopologyList 
 */
TopologyList Result::queryTopologies(){
    if(Json_obj.empty()==true){//if object is [ ] or { } only
        throw EMPTY_JSON();
    }
    TopologyList result;
    if(Json_obj.isArray()==false ){ //if there is only one topology (not in list)
        //add this topology to our result TopologyList
        topology* tx = new topology();
        tx->set_id(Json_obj["id"].asString());
        result.push_back(*tx);
    }else{  //if there are list of topologies
        for (Json::ValueIterator topo_iterator = this->Json_obj.begin(); topo_iterator != this->Json_obj.end(); ++topo_iterator){
            /* loop on topologies*/
            //add each topology to our result TopologyList
            topology* tx = new topology();
            tx->set_id( (*topo_iterator)["id"].asString() );
            result.push_back(*tx);
        }     
    }
    return result;
}

/**
 * @brief Query about which devices are in a given topology.
 * 
 * @param TopologyID 
 * @return DeviceList 
 */
DeviceList Result::queryDevices(string TopologyID){
    if(Json_obj.empty()==true){//if object is [ ] or { } only
        throw EMPTY_JSON();
    }

    DeviceList result;
    if(Json_obj.isArray()==false ){ //if there is only one topology (not in list)
        if(Json_obj["id"].asString()==TopologyID){//if you find topology
            if(Json_obj["components"].size()==0){   //if components is empty "components": [ ]
                throw EMPTY_COMPONENTS();
            }
            for (Json::ValueIterator compo_iterator = Json_obj["components"].begin(); compo_iterator != Json_obj["components"].end(); ++compo_iterator){
                    /*loop on components */
                    //add each components to our result DeviceList
                    Component* cx = new Component();
                    cx->set_id((*compo_iterator)["id"].asString());
                    cx->set_type((*compo_iterator)["type"].asString());
                    result.push_back(*cx);
            }
        }else{//if you don't find topology
            throw NOT_FOUND_TOPOLOGY();
        }
    }else{//if there are list of topologies
        int flag=0;//flag used to know if no topology is found with the given topology id 
        Json::Value newArray = Json::arrayValue;
        for (Json::ValueIterator topo_iterator = this->Json_obj.begin(); topo_iterator != this->Json_obj.end(); ++topo_iterator){
            /*loop ob topologies*/
            if ((*topo_iterator)["id"].asString().compare(TopologyID)==0){//if you find topology
                flag=1;
                if((*topo_iterator)["components"].size()==0){ //if components is empty "components": [ ]
                    throw EMPTY_COMPONENTS();
                }
                for (Json::ValueIterator compo_iterator = (*topo_iterator)["components"].begin(); compo_iterator != (*topo_iterator)["components"].end(); ++compo_iterator){
                    /*loop on components */
                    //add each components to our result DeviceList
                    Component* cx = new Component();
                    cx->set_id((*compo_iterator)["id"].asString());
                    cx->set_type((*compo_iterator)["type"].asString());
                    result.push_back(*cx);
                }
            }
        }
        if(flag==0){
            throw NOT_FOUND_TOPOLOGY();
        }
    }
    return result;
}


/**
 * @brief Query about which devices are connected to a given netlist node in a given topology.
 * 
 * @param TopologyID 
 * @param NetlistNodeID 
 * @return DeviceList 
 */
DeviceList Result::queryDevicesWithNetlistNode(string TopologyID,string NetlistNodeID){
    if(Json_obj.empty()==true){//if object is [ ] or { } only
        throw EMPTY_JSON();
    }
    DeviceList result;
    if(Json_obj.isArray()==false ){ //if there is only one topology (not in list)
        if(Json_obj["id"].asString()==TopologyID){//if you find topology
            if(Json_obj["components"].size()==0){//if components is empty "components": [ ]
                throw EMPTY_COMPONENTS();
            }
            int flag=0;//flag used to check if you find devices are connected to a given netlist node
            for (Json::ValueIterator compo_iterator = (Json_obj)["components"].begin(); compo_iterator != (Json_obj)["components"].end(); ++compo_iterator){
                /*loop on components*/
                for (Json::ValueIterator netlist_item_iter = (*compo_iterator)["netlist"].begin(); netlist_item_iter != (*compo_iterator)["netlist"].end(); ++netlist_item_iter){
                    /*loop on netlist items*/
                    if((*compo_iterator)["netlist"][netlist_item_iter.name()].asString().compare(NetlistNodeID) == 0){//if you find matched component
                        flag=1;
                        /*if find this netlist node id then add the component to our result DeviceList */
                        Component* cx = new Component();
                        cx->set_id((*compo_iterator)["id"].asString());
                        cx->set_type((*compo_iterator)["type"].asString());
                        result.push_back(*cx);
                        break;//go to next component
                    }
                }
            }
            if(flag==0){
                throw NO_COMPONENT_WITH_NETLIST_NODE();
            }
        }else{
            throw NOT_FOUND_TOPOLOGY();
        }
    }else{  //if there are list of topologies
        int flag_for_top=0;//flag used to know if no topology is found with the given topology id 
        for (Json::ValueIterator topo_iterator = this->Json_obj.begin(); topo_iterator != this->Json_obj.end(); ++topo_iterator){
            /*loop on topologies*/
            if (0 == (*topo_iterator)["id"].asString().compare(TopologyID)){//if find the topology
                if((*topo_iterator)["components"].size()==0){//if components is empty "components": [ ]
                    throw EMPTY_COMPONENTS();
                }
                flag_for_top=1;
                int flag_for_component=0;//flag used to check if you find devices are connected to a given netlist node
                for (Json::ValueIterator component_iterator = (*topo_iterator)["components"].begin(); component_iterator != (*topo_iterator)["components"].end(); ++component_iterator){
                    /*loop on components*/
                    for (Json::ValueIterator netlist_item_iter = (*component_iterator)["netlist"].begin(); netlist_item_iter != (*component_iterator)["netlist"].end(); ++netlist_item_iter){
                        /*loop on netlist items*/
                        if((*component_iterator)["netlist"][netlist_item_iter.name()].asString().compare(NetlistNodeID) == 0){//if you find matched component
                            flag_for_component=1;
                           /*if find this netlist node id then add the component to our result DeviceList */
                            Component* cx = new Component();
                            cx->set_id((*component_iterator)["id"].asString());
                            cx->set_type((*component_iterator)["type"].asString());
                            result.push_back(*cx);
                            break;//go to next component
                        }
                    }
                }
                if(flag_for_component==0){
                    throw NO_COMPONENT_WITH_NETLIST_NODE();
                }
            }
        }
        if(flag_for_top==0){
            throw NOT_FOUND_TOPOLOGY();
        }
    
    }

    return result;
}
