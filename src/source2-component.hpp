#ifndef OROCOS_source2_COMPONENT_HPP
#define OROCOS_source2_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/os/TimeService.hpp>
#include <std_msgs/Float64.h>

class source2 : public RTT::TaskContext{
public:
  source2(std::string const& name);
  bool configureHook();
  bool startHook();
  void updateHook();
  void stopHook();
  void cleanupHook();
  bool set_amplitude(double);
private:
  double amplitude_prop, amplitude;
  double frequency_prop, frequency;
  RTT::OutputPort<double> outport_value;
  RTT::os::TimeService::ticks time_begin;


  //ros integration
   RTT::OutputPort<std_msgs::Float64> outport_value_ros;
};
#endif
