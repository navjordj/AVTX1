#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <fstream>


#include "rplidar.h"

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif


using namespace rp::standalone::rplidar;
using namespace std;

int main(){

    RPlidarDriver* lidar = RPlidarDriver::CreateDriver();

    vector<float> thetas;
    vector<float> dists;

    u_result res = lidar->connect("/dev/ttyUSB0", 115200);

    if (IS_OK(res)) {  
        cout<<"Koblet til! \n";
        lidar->startMotor();
        RplidarScanMode scanMode;
        lidar->startScan(false, true, 0, &scanMode);

        rplidar_response_measurement_node_hq_t nodes[8192];
        size_t nodeCount = sizeof(nodes)/sizeof(rplidar_response_measurement_node_hq_t);
        res = lidar->grabScanDataHq(nodes, nodeCount);

    }
    else {
        fprintf(stderr, "Failed to connect to LIDAR %08x\r\n", res);
    }

    cout<<"Kobler fra \n";
    lidar ->stopMotor();
    lidar->disconnect();
    return 0;
}