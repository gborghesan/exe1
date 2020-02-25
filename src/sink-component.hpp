#ifndef OROCOS_sink_COMPONENT_HPP
#define OROCOS_sink_COMPONENT_HPP

#include <rtt/RTT.hpp>



class sink : public RTT::TaskContext{
public:
  sink(std::string const& name);
  bool configureHook();
  bool startHook();
  void updateHook();
  void stopHook();
  void cleanupHook();
  void  my_callback(RTT::base::PortInterface*p);
private:
  RTT::InputPort<int> inport_value;
  RTT::InputPort<int> event_inport_value;
};
#endif
