#include "CameraControl.hpp"

CameraControl::CameraControl(ros::NodeHandle &nodehandle, bool bw, bool hd)
{
    this->nodeHandle = nodeHandle;
    int trys = 0;
    while (!raspicam.open() && trys++ < 5)
        ROS_INFO_STREAM("trying to open CameraModule");

    ROS_INFO_STREAM("Camera opened");
};

void CameraControl::sendPictures(){
    while(ros::ok)
    
    ;
};