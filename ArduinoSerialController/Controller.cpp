/*
 * Controller.cpp
 *
 *  Created on: 5 Jun 2012
 *      Author: fletcherb
 */

#include "Controller.h"

Controller::Controller(HardwareSerial* iSerial) {
	Serial = iSerial;
	Serial->begin(9600);
	Serial->println("Controller is Starting...");
	commandInstruction = "";
}
void Controller::setCommandArray(Command *inCommand, int inArraySize){
	command = inCommand;
	commandArraySize = inArraySize;
	Serial->print("Setting Command array: array size: ");
	Serial->println(inArraySize);
}

Controller::~Controller() {
}

void Controller::loop() {
	if (Serial->available()>0){

		char i = Serial->read();
		if (i!=10){
			commandInstruction += i;
		} else {
			bool runCommand = false;
			for (int i = 0; i< commandArraySize; i++){
				int locOfSpace = commandInstruction.indexOf(' ');

				String parameter = commandInstruction.substring(locOfSpace);
				if (commandInstruction.startsWith(command[i].getInstruction())){
					command[i].execute(parameter);
					runCommand = true;
				}
			}
			if (!runCommand){
				unknownCommand(commandInstruction);
			}
			commandInstruction = "";
		}
	}
}


void Controller::unknownCommand(String instruction){
	Serial->print("Unknown command: ");
	Serial->println(instruction);
}


