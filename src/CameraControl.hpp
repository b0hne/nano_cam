#include <raspicam_cv.h>
#include <ros/ros.h>

class CameraControl
{
  private:
    raspicam::RaspiCam_Cv raspicam;

  public:
    CameraControl(ros::NodeHandle &nodeHandle, bool bw=true, bool hd=false);
    void sendPictures();
};