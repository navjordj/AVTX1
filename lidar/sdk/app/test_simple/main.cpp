/*
 *  RPLIDAR
 *  Ultra Simple Data Grabber Demo App
 *
 *  Copyright (c) 2009 - 2014 RoboPeak Team
 *  http://www.robopeak.com
 *  Copyright (c) 2014 - 2019 Shanghai Slamtec Co., Ltd.
 *  http://www.slamtec.com
 *
 */
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
Applikasjon for å sette oss inn i Lidaren sin API
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "rplidar.h" //RPLIDAR standard sdk, all-in-one header

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif


using namespace rp::standalone::rplidar;
using namespace std;

int main(){

    RPlidarDriver* lidar = RPlidarDriver::CreateDriver();

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
                printf("%s theta: %03.2f Dist: %08.2f \n", 
                    (nodes[pos].sync_quality & RPLIDAR_RESP_MEASUREMENT_SYNCBIT) ?"S ":"  ", 
                    (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT)/64.0f,
                    nodes[pos].distance_q2/4.0f);
            }
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