#versionskontrolle
cmake_minimum_required(VERSION 2.8.3)
#projektname
project(nano_cam)

## Use C++11
#add_definitions(--std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED
    COMPONENTS
        roscpp
        sensor_msgs
        image_transport
        cv_bridge
)

#set(opencv_DIR "/usr/share/OpenCV")

find_package( OpenCV REQUIRED )

#    include_directories(${OpenCV_INCLUDE_DIRS}) # Not needed for CMake >= 2.8.11
#    target_link_libraries(MY_TARGET_NAME ${OpenCV_LIBS})

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS
    include
#  LIBRARIES
  CATKIN_DEPENDS 
    sensor_msgs
    image_transport
    cv_bridge
#  DEPENDS 
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
//    ${raspicam_CV_LIBS}
  include
  ${catkin_INCLUDE_DIRS}
    src/
)
include_directories(/opt/vc/lib)
include_directories(/opt/vc/include)
include_directories(/opt/vc/userland-master/interface/vcos)
include_directories(/opt/vc/userland-master)
include_directories(/opt/vc/userland-master/interface/vcos/pthreads)
include_directories(/opt/vc/userland-master/interface/vmcs_host/linux)
include_directories(/opt/vc/userland-master/host_applications/linux/libs/bcm_host/include)


## Declare a C++ executable
add_executable(${PROJECT_NAME}
  src/NanoCam.cpp
  src/CameraControl.cpp 
)


## Specify libraries to link a library or executable target against
target_link_libraries(
  ${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
  ${cv_bridge_LIBS}
  ${sensor_msgs_LIBS}
  ${image_transport_LIBS}

  #libmmal_core.so
  #libmmal_util.so
  #libmmal_vc_client.so
  #libvcos.so
  #libbcm_host.so
  #GLESv2 EGL
  )


