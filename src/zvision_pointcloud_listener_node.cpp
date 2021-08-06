/*
 * Copyright 2017-2021 ZVISION.co. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 PointCloud2 listener
 */


#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
static void points_callback(const sensor_msgs::PointCloud2::ConstPtr& input)
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr scan(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromROSMsg(*input, *scan);

    /*
     *Process Point Cloud Here
    */
   std::cout << scan->size() << std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "zvison_pointcloud_listener");
  ros::NodeHandle nh;
  ros::NodeHandle private_nh("~");
  ros::Subscriber points_sub = nh.subscribe("zvision_lidar_points", 100000, points_callback);

  ros::spin();
  return 0;
}