#include "source-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

source::source(std::string const& name) : TaskContext(name,PreOperational)
 , output_value(0){
  addProperty("output_value",output_value).doc("Value to write out");
  addPort("outport_value",outport_value).doc("My output value");
}

bool source::configureHook(){
  return true;
}

bool source::startHook(){
  return true;
}

void source::updateHook(){
outport_value.write(output_value);
}

void source::stopHook() {}


void source::cleanupHook() {}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(source)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(source)
