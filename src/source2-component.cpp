#include "source2-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

source2::source2(std::string const& name) : TaskContext(name,PreOperational)
, amplitude_prop(0)
, frequency_prop(0){
  addProperty("amplitude",amplitude_prop).doc("Value amplitude");
  addProperty("frequency",frequency_prop).doc("Value frequency");
  addPort("outport_value",outport_value).doc("My output value");
  addOperation( "set_amplitude",  &source2::set_amplitude, this, RTT::OwnThread)
  .doc("Set The amplitude");

   addPort("outport_value_ros",outport_value_ros).doc("My output value, ros");
}

bool source2::configureHook(){
  return true;
}
bool source2::set_amplitude(double a){
  if (this->isRunning()){
       RTT::Logger::In in(this->getName());
      RTT::log(RTT::Error)<<" set amplitude failed, component is running"<<RTT::endlog();
      return false;
}
  amplitude_prop=amplitude=a;
  return true;
}

bool source2::startHook(){
  time_begin=RTT::os::TimeService::Instance()->getTicks();
  amplitude=amplitude_prop;
  frequency=frequency_prop;
  return true;
}

void source2::updateHook(){
  double time_passed=RTT::os::TimeService::Instance()->secondsSince(time_begin);
  double val=amplitude_prop*sin(2*M_PI*frequency_prop*time_passed);
  outport_value.write(val);
  //std::cout<<time_passed<<"  "<<val<<std::endl;

  std_msgs::Float64 f;
  f.data=val;
  outport_value_ros.write(f);
}

void source2::stopHook() {}


void source2::cleanupHook() {}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(source2)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(source2)
