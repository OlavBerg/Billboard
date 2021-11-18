# Billboard

Before compiling, you need to enter some lines main.cpp. In main.cpp, under the label named "Add serial ports", enter, for every serial port you want to use, a code line in the form of "port_name_list.push_back("\\\\.\\<port name>");", where <port name> is the name of the port.
  
 To compile, type "g++ main.cpp billboard.cpp account.cpp message_time_pair.cpp Serial.cpp".
  
  To run (on Windows), type "./a.exe"
