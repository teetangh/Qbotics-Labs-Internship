import rospy

from sensor_msgs.msgs import LaserScan

def clbk_laser(msgs):
	rospy.loginfo(msgs)

def main():
	rospy.init('reading_laser')
	sub = rospy.Subsriber('/m2wr/laser/scan',LaserScan,clbk_laser)
	rospy.spin()

if __name__ == "__main__":
	main()