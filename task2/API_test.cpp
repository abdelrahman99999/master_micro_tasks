#include "API_test.h"
#include "API_helper.h"
#include <iostream>
using namespace std;


API_Test::API_Test(){

}

API_Test::~API_Test(){

}

void API_Test::readJson_test(){
    cout << "[ RUN    ] readJson_test\n";
    try{
        api.readJson("test.json");
        cout << "[ PASSED ] readJson_test\n";
    }catch(...){
            cout << "[ FAILED ] readJson_test\n";
    }

}

void API_Test::writeJson_test(){
    cout << "[ RUN    ] writeJson_test \n";
    try{
        api.writeJson("top88");
        cout << "[ PASSED ] writeJson_test\n";
    }catch(...){
            cout << "[ FAILED ] writeJson_test\n";
    }

}



void API_Test::queryTopologies_test(){
    cout << "[ RUN    ] queryTopologies_test \n";
    TopologyList actual;
    topology t1; t1.set_id("top88");
    topology t2; t2.set_id("top1");
    topology t3; t3.set_id("top3");
    TopologyList expected={t1,t2,t3};
    try{
        actual = api.queryTopologies();
        if (actual.size() != expected.size()){
            cout << "[ FAILED ] queryTopologies_test\n";
            return;
        }
        for (int i=0; i< 3; i++){
            if (expected[i].get_id() != actual[i].get_id()){
                cout << "[ FAILED ] queryTopologies_test\n";
                return;
            }
        }
        cout << "[ PASSED ] queryTopologies_test\n";
    }
    catch(exception &e1){
            cout << "[ FAILED ] queryTopologies_test\n";
    }

}

void API_Test::queryDevices_test(){
    cout << "[ RUN    ] queryDevices_test \n";
    Component c1,c2;
    c1.set_id("res1");
    c2.set_id("m1");
    DeviceList expected= {c1,c2};
    try{
        DeviceList actual = api.queryDevices("top1");

        if (expected.size() != actual.size()){
            cout << "[ FAILED ] queryDevices_test\n";
            return;
        }

        for (int i=0; i< 2; i++){
            if (actual[i].get_id() != expected[i].get_id()){
                cout << "[ FAILED ] queryDevices_test\n";
                return;
            }
        }
        cout << "[ PASSED ] queryDevices_test\n";
    }catch(...){
        cout << "[ FAILED ] queryDevices_test\n";
    }
    
}

void  API_Test::queryDevicesWithNetlistNode_test(){
    cout << "[ RUN    ] queryDevicesWithNetlistNode_test \n";
    Component c1,c2;
    c1.set_id("test_id");
    c2.set_id("bla1");
    DeviceList expected = {c1,c2};
    try{
        DeviceList actual = api.queryDevicesWithNetlistNode("top88", "abcd");

        if (actual.size() != expected.size()){
            cout << "[ FAILED ] queryDevicesWithNetlistNode_test\n";
            return;
        }

        for (int i=0; i< 2; i++){
            if (actual[i].get_id() != expected[i].get_id()){
                cout << "[ FAILED ] queryDevicesWithNetlistNode_test\n";
                return;
            }
        }
        cout << "[ PASSED ] queryDevicesWithNetlistNode_test\n";
    }catch(...){
        cout << "[ FAILED ] queryDevicesWithNetlistNode_test\n";
    }
}


void API_Test::deleteTopology_test(){
    cout << "[ RUN    ] deleteTopology_test \n";
    int size_before=api.queryTopologies().size();
    
    try{ 
        api.deleteTopology("top3");
        int size_after=api.queryTopologies().size();
        if(size_after==size_before-1){
            cout << "[ PASSED ] deleteTopology_test\n";
        }else{
            cout << "[ FAILED ] deleteTopology_test\n";
        }
    }catch(...){
        cout << "[ FAILED ] deleteTopology_test\n";
    }
}
