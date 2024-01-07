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
	void setParentNode( rclcpp::Node::SharedPtr parent_node_ptr);

private:
	rclcpp::Node::SharedPtr parent_node;
	
	rclcpp::Publisher<rto_msgs::msg::AnalogReadings>::SharedPtr analog_pub_;

	rto_msgs::msg::AnalogReadings analog_msg_;

	rclcpp::Time stamp_;

	void valuesChangedEvent( const float* values, unsigned int size );

};


#endif /* ANALOGINPUTARRAYROS_H_ */
