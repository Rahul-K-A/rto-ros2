/*
 * AnalogInputArrayROS.h
 *
 *  Created on: 08.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#ifndef ANALOGINPUTARRAYROS_H_
#define ANALOGINPUTARRAYROS_H_

#include "rec/robotino/api2/AnalogInputArray.h"
#include "rclcpp/rclcpp.hpp"
#include "rto_msgs/msg/analog_readings.hpp"

class AnalogInputArrayROS: public rec::robotino::api2::AnalogInputArray
{
public:
	AnalogInputArrayROS();
	~AnalogInputArrayROS();

	void setTimeStamp(rclcpp::Time stamp);

private:
	ros::NodeHandle nh_;

	ros::Publisher analog_pub_;

	rto_msgs::AnalogReadings analog_msg_;

	ros::Time stamp_;

	void valuesChangedEvent( const float* values, unsigned int size );

};


#endif /* ANALOGINPUTARRAYROS_H_ */
