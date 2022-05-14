#ifndef API_TEST_H_
#define API_TEST_H_
#include "API.h"

class API_Test{
private: 
    Result api;
public:
    void readJson_test();
    void writeJson_test();
    void deleteTopology_test();
    void queryTopologies_test();
    void queryDevices_test();
    void queryDevicesWithNetlistNode_test();
    API_Test();
    ~API_Test();
};

#endif 