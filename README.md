# zvision point cloud listener

## Prerequisite
* OS: ubuntu18.04 LTS
* ROS Melodic
* PCL 1.8

## Usage
```bash
mkdir -p catkin_ws/src #如果已有工作空间，跳过这步
cd catkin_ws/src
git clone https://github.com/Chenskkk/zvision_pointcloud_listener.git
cd ..
catkin_make -DCMAKE_BUILD_TYPE=Release
source devel/setup.bash #如果使用的是zsh改为 setup.zsh
rosrun zvision_pointcloud_listener zvision_pointcloud_listener_node
```