#include "NanoCam_node.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, 
    "nano_cam");
    ros::NodeHandle nodeHandle("~");
    ros::Rate loopRate(10);
    cameraControl = CameraControl(&nodeHandle);
    unsigned int count = 0;
    cameraControl.sendPictures();
    return 0;
}