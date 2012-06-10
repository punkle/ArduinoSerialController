#include <Controller.h>
#include <SwitchOffCommand.h>
#include <SwitchOnCommand.h>

// create controller object and pass it a reference to serial
Controller controller(&Serial);

// create command objects
SwitchOnCommand sonCommand;
SwitchOffCommand soffCommand;

// create an array of pointers to the command objects
Command *commandArray[] = {
		&sonCommand,
		&soffCommand,
};

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	Serial.print("Starting up");
	Serial.println("...");

	// set the command array
	controller.setCommandArray(commandArray[0], 2);
	
	// print the list of instructions
	Serial.println("The list of instructions: ");
	
    for(int i=0;i<2;i++){
          Serial.println(commandArray[i]->getInstruction());
    }
}

void loop()
{
	// controller.loop parses the serial input and executes the command
	controller.loop();
}

