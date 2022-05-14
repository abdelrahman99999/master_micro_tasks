/**
 * @file API.h
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief api provide operations applied on json
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef API_H_   
#define API_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <jsoncpp/json/json.h>
#include "Topology.h"
#include "API_helper.h"
#include "Topology.h"
#include "Component.h"
using namespace std;

/**
 * @brief main class of API
 * 
 */
class Result {
protected:
    /**
     * @brief //Object contain json data and operations are applied on it 
     */
    Json::Value Json_obj;   
public:

    Result readJson(string FileName);
    Result writeJson(string TopologyID);
    Result deleteTopology(string TopologyID);
    TopologyList queryTopologies();
    DeviceList queryDevices(string TopologyID);
    DeviceList queryDevicesWithNetlistNode(string TopologyID,string NetlistNodeID);

    Result();//constructor
    ~Result();//destructor
};

#endif