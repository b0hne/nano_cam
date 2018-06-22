/*
converts raw RGB image taken from cam, converts it to u8 and publisches it on /nano_cam/image
*/

#include "NanoCam.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, 
    "nano_cam");
    ros::NodeHandle nodeHandle("~");
    ros::Rate loopRate(10);
    CameraControl cameraControl(nodeHandle);
    unsigned int count = 0;
    cameraControl.sendPictures();
    return 0;
}