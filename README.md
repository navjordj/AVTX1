# AVTX1

### Gi tillatelse på Ubuntu:

    sudo chmod a+rw /dev/ttyACM0

### Fjernstyre fra ubuntu med ssh:
Standardpassord: nvidia
#### IOT:
    ssh nvidia@10.248.0.101 
#### Eduroam:
    ssh nvidia@10.243.1.114

### Starte lidarvisualisering med ROS
    cd catkin_ws
    roslaunch rplidar_ros view_rplidar.launch
    
### Kjøre testapplikasjon på Ubuntu
    cd lidar/sdk/output/Linux/Release
    sudo ./test_simple
    
## Utstyrsliste
RPLidar-A1  
Logitech C720 webcam  
HSP Kutiger Rally 1:10 Brushed RC car  
TX1 Development kit  
