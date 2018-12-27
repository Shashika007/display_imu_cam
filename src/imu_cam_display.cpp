#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_msgs/TFMessage.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf/transform_broadcaster.h>



int main(int argc, char** argv){
  
  ros::init (argc, argv, "tf_broadcaster_imu_cam");
  ros::NodeHandle nh;
  
  //static tf2_ros::TransformBroadcaster br;
  // tf2::Matrix3x3 tm(0.9920450279807901,-0.10283084205416222, -0.07261184738749156, -0.1151213079393174, -0.5077291604809916, -0.8537904801856293, 0.050928841700290814, 0.8553577716486234, -0.515528210249805);
 // tf2::Vector3 translation(-0.027076431025978582, 0.036773077520205595, -0.04600904056413611);
//  tf2::Transform trans(tm, translation);
  ros::Rate r(1000);
  while(ros::ok()) {
  static tf::TransformBroadcaster br;
  tf::Matrix3x3 tm(-0.04924428974548434, -0.9986440102899544, -0.016886107883660795, -0.3357486035808753, 0.03247417770642991, -0.9413916841441621, 0.9406635291755248, -0.040688677716129495, -0.33689249974547963);
  tf::Vector3 translation(-0.011516402916193462, 0.02017991316364573, -0.030988829057995392);
  tf::Transform trans(tm, translation);

  //geometry_msgs::TransformStamped new_frame;
  //new_frame.header.stamp = ros::Time::now();
  //new_frame.header.frame_id = "cam";
  //new_frame.child_frame_id = "imu";
  //new_frame.transform = tf2::toMsg(trans);

  br.sendTransform(tf::StampedTransform(trans, ros::Time::now(), "cam", "imu"));
  r.sleep();
  ros::spinOnce();
  }
  return 0;
};
