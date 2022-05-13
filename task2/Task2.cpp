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
#define EXIT 7
int main()
{
    Result R1;
    int n=0;
    while(n!=EXIT){
        cout<<"1. Read a topology from a given JSON file and store it in the memory\n";
        cout<<"2. Write a given topology from the memory to a JSON file.\n";
        cout<<"3. Query about which topologies are currently in the memory.\n";
        cout<<"4. Delete a given topology from memory.\n";
        cout<<"5. Query about which devices are in a given topology.\n";
        cout<<"6. Query about which devices are connected to a given netlist node in a given topology.\n";
        cout<<"7. exit\n\n";

        cout<<"enter vaild option: "; 
        cin>>n;

        cout<<"bla bla\n\n";
    }



    return 0;
}

