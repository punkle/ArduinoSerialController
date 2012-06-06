/*
 * Controller.h
 *
 *  Created on: 5 Jun 2012
 *      Author: fletcherb
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "HardwareSerial.h"
#include "Arduino.h"
#include "Command.h"

class Controller {
public:
	Controller(HardwareSerial* iSerial);
	void setCommandArray(Command *inCommand, int inArraySize);
	virtual ~Controller();
	void loop();
private:
	Command *command;
	int commandArraySize;
	HardwareSerial* Serial;
	String commandInstruction;
	void unknownCommand(String);
};

#endif /* CONTROLLER_H_ */
