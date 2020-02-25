#include "sink-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

sink::sink(std::string const& name) : TaskContext(name){
  addPort("inport_value",inport_value)
          .doc("My input port");

  addEventPort("event_inport_value",event_inport_value)
          .doc("My input port - event");
  //addEventPort("event_inport_value",event_inport_value,boost::bind(&sink::my_callback, this,_1))
    //      .doc("My input port - event");
}

bool sink::configureHook(){
  return true;
}

bool sink::startHook(){
  return true;
}
void  sink::my_callback(RTT::base::PortInterface*p){
  this->trigger();
  std::cout<<"callback"<<std::endl;
}

void sink::updateHook(){
  int data_in;
  RTT::FlowStatus fs;
  fs  = inport_value.read(data_in);
  if (fs==RTT::NoData){std::cout<<"no data"<<std::endl;}
  else if(fs==RTT::OldData){std::cout<<"old data"<<std::endl;}
  else {std::cout<<"data: "<< data_in<<std::endl;}//fs=RTT::NewData

  fs = event_inport_value.read(data_in);
  if (fs==RTT::NoData){std::cout<<"event no data"<<std::endl;}
  else if(fs==RTT::OldData){std::cout<<"event old data "<< data_in<<std::endl;}
  else {std::cout<<"event data: "<< data_in<<std::endl;}//fs=RTT::NewData

}

void sink::stopHook() {
}

void sink::cleanupHook() {
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(sink)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(sink)
