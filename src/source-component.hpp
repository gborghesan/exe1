#ifndef OROCOS_source_COMPONENT_HPP
#define OROCOS_source_COMPONENT_HPP

#include <rtt/RTT.hpp>

class source : public RTT::TaskContext{
public:
  source(std::string const& name);
  bool configureHook();
  bool startHook();
  void updateHook();
  void stopHook();
  void cleanupHook();
private:
  int output_value;
  RTT::OutputPort<int> outport_value;
};
#endif
