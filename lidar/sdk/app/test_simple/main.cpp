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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "rplidar.h" //RPLIDAR standard sdk, all-in-one header

using namespace rp::standalone::rplidar;
using namespace std;

int main(){

    RPlidarDriver* lidar = RPlidarDriver::CreateDriver();

    u_result res = lidar->connect("/dev/ttyUSB0", 115200);

    if (IS_OK(res))
    {
        // TODO
        cout<<"Koblet til! \n";
        lidar->startMotor();
        usleep(5000000);
        lidar ->stopMotor();
        lidar->disconnect();
    }
    else
    {
        fprintf(stderr, "Failed to connect to LIDAR %08x\r\n", res);
    }

    return 0;
}