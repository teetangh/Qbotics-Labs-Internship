#! /usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan


def clbk_laser(msg):
    regions = [
    min(msg.ranges[0:143]),
    min(msg.ranges[144:287]),
    min(msg.ranges[288:432]),
    min(msg.ranges[432:576]),
    min(msg.ranges[576:719]),
    ]
    
    rospy.loginfo(regions)

def main():
    rospy.init_node('reading_laser')

    sub = rospy.Subscriber('/m2wr/laser/scan',LaserScan,clbk_laser)

    rospy.spin()
    
if __name__ == "__main__":
    main()
