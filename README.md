# AVTX1

### Gi tillatelse på Ubuntu:

    sudo chmod a+rw /dev/ttyACM0

### Fjernstyre fra ubuntu med ssh:
Standardpassord: nvidia
#### IOT:
    ssh nvidia@10.248.0.101 
#### Eduroam:
    ssh nvidia@10.243.1.114
    
### Fjernstyre Jetson Nano med ssh:
Standardpassord: nvidia
#### Eduroam:
    ssh eik@128.39.234.208
### Fjernstyre Jetson nano med VNC:
    Standardpassord: nvidia
    Bruker vnc-viewer:
    eik@128.39.234.208
### Starte lidarvisualisering med ROS
    cd catkin_ws
    roslaunch rplidar_ros view_rplidar.launch
    
### Kjøre testapplikasjon på Ubuntu
    cd lidar/sdk/output/Linux/Release
    sudo ./test_simple
    
### Visualisere lidardata med matplotlib
    cd visualizor
    python vizualize_data.py points.txt
    
## Utstyrsliste
RPLidar-A1  
Logitech C720 webcam  
HSP Kutiger Rally 1:10 Brushed RC car  
TX1 Development kit  
