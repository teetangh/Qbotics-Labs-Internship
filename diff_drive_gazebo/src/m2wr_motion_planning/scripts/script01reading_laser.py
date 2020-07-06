#! /usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan

def clbk_laser(msg):
    rospy.loginfo(msg)

def main():
    rospy.init_node('reading_laser')

    sub = rospy.Subscriber('/m2wr/laser/scan',LaserScan,clbk_laser)

    rospy.spin()
    
if __name__ == "__main__":
    main()
