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
        // TODO
        cout<<"Koblet til! \n";
        lidar->startMotor();
        //usleep(5000000);
        RplidarScanMode scanMode;
        lidar->startScan(false, true, 0, &scanMode);

        rplidar_response_measurement_node_t nodes[8192];
        size_t count = _countof(nodes);

        res = lidar->grabScanData(nodes, count);
        if (IS_OK(res)) {
            lidar->ascendScanData(nodes, count);
            for (int pos = 0; pos < (int)count ; ++pos) {

                float theta = (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT)/64.0f;
                thetas.push_back(theta);
                
                float dist = nodes[pos].distance_q2/4.0f;
                dists.push_back(dist);

                //cout<<theta << '\t' << dist << '\n';

                /*printf("theta: %03.2f Dist: %08.2f \n",  
                    (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT)/64.0f,
                    nodes[pos].distance_q2/4.0f);*/
            }
        ofstream myfile;
        myfile.open ("points.txt");

        for (size_t i; i < thetas.size(); i++){
            myfile << thetas[i];
            myfile << " ";
            myfile << dists[i];
            myfile << "\n";
        }

        myfile.close();

        }
    }
    else {
        fprintf(stderr, "Failed to connect to LIDAR %08x\r\n", res);
    }

    cout<<"Kobler fra \n";
    lidar ->stopMotor();
    lidar->disconnect();
    return 0;
}