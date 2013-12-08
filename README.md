Arduino Serial Controller
=========================

The Arduino Serial Controller is a library which allows an Arduino sketch receive and execute commands which are read from the HardwareSerial input.


Commands
--------

The Controller has been written using the Command pattern design pattern. This means that the Serial Controller is adaptable to adding additional commands.

The following commands are currently available:

- SwitchOnCommand
- SwitchOffCommand


Example
-------

Please have a look at the sample sketch:

- TestArduinoSerialController.ino


Adding Commands
---------------

If you would like to create your own commands, simply 

- extend the Command class
- set the instruction string in the constructor
- implement the Command::execute(String) funtion (The execute function is what is called when the user enters the instruction.)
