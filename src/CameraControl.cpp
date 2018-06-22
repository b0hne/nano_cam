#include "CameraControl.hpp"

#define MAIN_TEXTURE_WIDTH 512
#define MAIN_TEXTURE_HEIGHT 512

char tmpbuff[MAIN_TEXTURE_WIDTH * MAIN_TEXTURE_HEIGHT * 4];

CameraControl::CameraControl(ros::NodeHandle nodehandle, bool bw, bool hd)
{
    this->nodeHandle = nodeHandle;
    cv::Mat pic, picGrey; // creates just the header parts
    image_transport::ImageTransport it(nodehandle);
    image_transport::Publisher pub = it.advertise("camera/image", 10);

    ros::Rate loop_rate(5);
    while(ros::ok){
    pic = cv::imread("/test.bmp", CV_LOAD_IMAGE_COLOR);
    cv::waitKey(30);
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", pic).toImageMsg();
    //pic.convertTo(picGrey, CV_8U);
    //sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", pic).toImageMsg();
    //should the camera convert frame data from yuv to argb automatically?
    // bool do_argb_conversion = false;
    // int num_levels = 1;
    // if (pic.empty())
    //     std::cout << "test\n";
    // else
    //    { std::cout << "tested %d\n";
    //     cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
    // cv::imshow( "Display window", picGrey );                   // Show our image inside it.
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    //loop_rate.sleep();
    // cv::waitKey(0);   

    //    }
    }
    // CCamera *cam = StartCamera(MAIN_TEXTURE_WIDTH, MAIN_TEXTURE_HEIGHT, 30, num_levels, do_argb_conversion);
};

void CameraControl::sendPictures()
{
    //     int texidx = (i / 30)%num_levels;
    //     while (ros::ok)
    //     const void* frame_data; int frame_sz;
    // 		if(cam->BeginReadFrame(texidx,frame_data,frame_sz))
    // 		{

    // 				//if not converting argb the data will be the wrong size and look weird, put copy it in
    // 				//via a temporary buffer just so we can observe something happening!
    // 				memcpy(tmpbuff,frame_data,frame_sz);
    // 				textures[texidx].SetPixels(tmpbuff);

    // 			cam->EndReadFrame(texidx);
    // 		}

    // 		//begin frame, draw the texture then end frame (the bit of maths just fits the image to the screen while maintaining aspect ratio)
    // 		BeginFrame();
    // 		float aspect_ratio = float(MAIN_TEXTURE_WIDTH)/float(MAIN_TEXTURE_HEIGHT);
    // 		float screen_aspect_ratio = 1280.f/720.f;
    // 		DrawTextureRect(&textures[texidx],-aspect_ratio/screen_aspect_ratio,-1.f,aspect_ratio/screen_aspect_ratio,1.f);
    // 		EndFrame();
    // 	}

    // CCamera::Release()
}