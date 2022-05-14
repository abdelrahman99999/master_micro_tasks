/**
 * @file Task2.cpp
 * @author abdelrahman elsayed (abdelrahmanelsayed341@gmail.com)
 * @brief main file to start app
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "API.h"
#include"API_test.h"
#include <exception>
#include<iostream>

using namespace std;

int main()
{

    Result API;
    int option;
    string input, input2;
    TopologyList topologies_list;
    DeviceList devices_list;

    cout<<"1. Read a topology from a given JSON file and store it in the memory\n";
    cout<<"2. Write a given topology from the memory to a JSON file.\n";
    cout<<"3. Query about which topologies are currently in the memory.\n";
    cout<<"4. Delete a given topology from memory.\n";
    cout<<"5. Query about which devices are in a given topology.\n";
    cout<<"6. Query about which devices are connected to a given netlist node in a given topology.\n";
    cout<<"7. Run Unit Tests\n";
    cout<<"8. Exit\n\n";

    while(1){
        cout << "\n>> Choose a valid option\n";
        cin >> option;
        while(option<1 && option>7){
            cout << "\n>> Choose a valid option\n";
            cin >> option;
        }

        switch (option)        
        {
            case 1:{
                cout << "\n>> Enter file name (with extension): ";
                cin >> input;
                try{
                    API.readJson(input);
                    cout<<"sucessful operation\n";
                }catch(exception &e){
                    cout << e.what() <<"\n";
                }
              
            }  break;

            case 2:{
                cout << "\n>> Enter a valid topology ID: ";
                cin >> input;
                try{
                    API.writeJson(input);
                    cout<<"sucessful operation\n";
                }catch(exception &e){
                    cout << e.what() <<"\n";
                }
            }break;
            
            case 3:{                
                try{
                    topologies_list = API.queryTopologies();
                    for(int i=0;i<topologies_list.size();i++){
                        cout<<"Topology ID -> "<<topologies_list[i].get_id()<<endl;
                        //cout<<"Topology Components -> \n"<<topologies_list[i].get_components()<<endl;
                    }              
                }catch(exception &e){
                    cout << e.what() <<"\n";
                }
            }break;

            case 4:{
                cout << "\n>> Enter a valid topology ID: ";
                cin >> input;
                try{
                    API.deleteTopology(input);
                    cout<<"sucessful operation\n";
                }catch(exception &e){
                    cout<<e.what()<<endl;
                }
            }break;

            case 5:{
                cout << "\n>> Enter a valid topology ID: ";
                cin >> input;
                try{
                    devices_list = API.queryDevices(input);
                    for(int i=0;i<devices_list.size();i++){
                        cout<<"Device ID -> "<<devices_list[i].get_id()<<endl;
                        cout<<"Device TYPE -> "<<devices_list[i].get_type()<<endl;
                        cout<<"Device netlist -> \n"<<devices_list[i].get_netlist()<<endl;
                    }
                }catch(exception &e){
                    cout<<e.what()<<endl;
                }
            }break;

            case 6:{
                cout << "\n>> Enter a valid topology ID: ";
                cin >> input;
                cout << "\n>> Enter a netlist node ID: ";
                cin >> input2;
                try{
                    devices_list = API.queryDevicesWithNetlistNode(input, input2);
                    for(int i=0;i<devices_list.size();i++){
                        cout<<"Device ID -> "<<devices_list[i].get_id()<<endl;
                        cout<<"Device TYPE -> "<<devices_list[i].get_type()<<endl;
                        cout<<"Device netlist -> \n"<<devices_list[i].get_netlist()<<endl;
                    }
                }catch(exception &e){
                    cout<<e.what()<<endl;
                }
            }break;

            case 7:{
                API_Test test;
                test.readJson_test();
                test.writeJson_test();
                test.queryTopologies_test();
                test.queryDevices_test();
                test.queryDevicesWithNetlistNode_test();
                test.deleteTopology_test();
            }break;
                
            case 8:
                return 0;
            }
    }

    return 0;
}

