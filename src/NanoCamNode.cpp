#include "NanoCamNode.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, 
    "nano_cam");
    ros::NodeHandle nodeHandle("~");
    ros::Rate loopRate(10);
    CameraControl::CameraControl cameraControl(nodeHandle);
    unsigned int count = 0;
    cameraControl.sendPictures();
    return 0;
}