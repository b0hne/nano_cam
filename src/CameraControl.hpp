#include <ros/ros.h>
#include <stdio.h>
#include <unistd.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
// #include "camera.h"


class CameraControl
{
  private:
  ros::NodeHandle nodeHandle;

  public:
    CameraControl(ros::NodeHandle nodeHandle, bool bw=true, bool hd=false);
    void sendPictures();
    
};