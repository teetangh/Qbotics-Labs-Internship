#! /usr/bin/env python

import rospy

from sensor.msgs import LaserScan

def clbk_laser(msgs):
	rospy.loginfo(msgs)

def main():
	rospy.init('reading_laser')

	sub = rospy.Subsriber('/m2wr/laser/scan',LaserScan,clbk_laser)

if __name__ == '__main__':
	main()
