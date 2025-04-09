
#include "mockos/CommandPrompt.h"
#include <sstream>
#include <iostream>

//Default constructor sets both the fileSystem and fileFactory pointer to nullptr
CommandPrompt::CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr)  {

}

//Setter for the fileSystem member variable pointer of the CommandPrompt
void CommandPrompt::setFileSystem(AbstractFileSystem* systemPtr) {
    fileSystem = systemPtr;
}

//setter for the fileFactory pointer for the CommandPrompt object
void CommandPrompt::setFileFactory(AbstractFileFactory* factoryPtr) {
    fileFactory = factoryPtr;
}

//Takes in a name of a command and a pointer to the AbstractCommand (which points to the concrete command)
//If the AbstractCommand already exists in the map, we return a failure (non zero enum value), else wee add it to
//our map of commands
int CommandPrompt::addCommand(std::string name, AbstractCommand* commandPtr) {
    if (!collectionOfCommands.insert({name, commandPtr}).second) {
        return commandOutputs::mapInsertionFailure;
    }
    return 0;
}


//Iterates through the map: collectionOfCommands: maps a string: commandName to a AbstractComamnd pointer
//and prints out all the names of commands
void CommandPrompt::listCommands() {
    for (auto & it : collectionOfCommands) {
        std::cout << it.first << std::endl;
    }
}

//Studio 21, number 3k
//Runs repeatedly
int CommandPrompt::run() {
    while (true) {

        //Gets the user inputted prompt from the input stream (call to prompt method)
        std::string userInputtedPrompt = prompt();

        //if the user inputted prompt is "q", the user has quit and we return early
        if (userInputtedPrompt == "q") {
            return commandOutputs::quitter;
        }

        //If the user inputs "help", we list all the commands (output to the stream) and then rerun the loop,
        if (userInputtedPrompt == "help") {
            listCommands();
            continue;
        }

        //We must check to ensure that the user input is only 1 word long
        bool ifUserInputIsOneWord = true;

        //We can ensure the user input is only one word by checking if an empty string with a space is in the input " "
        //If there is a blank string then the user input is not one word then we ouput the command didn't exist
        for (char it : userInputtedPrompt) {
            if (it == ' ') { ifUserInputIsOneWord = false; }
        }

        if (ifUserInputIsOneWord) {
            //.count Returns true if the userInputtedPrompt (string, which represents the name of the command) is in the map
            if (collectionOfCommands.count(userInputtedPrompt)) {
                //Since the command is in the map we can call execute on the command
                int executeReturn = collectionOfCommands[userInputtedPrompt]->execute("");
                if (executeReturn != success) {
                    std::cout << "command failed :(" << std::endl;
                }
       
            }
            else {
                std::cout << "command did not exist" << std::endl;
            }

        }
        //If theuser input is not one word
        else {
            std::istringstream iss(userInputtedPrompt);
            std::string command;
            std::string arg1;
            iss >> command;
            //Case the first word in the command is "help"
            if (command == "help") {
                iss >> arg1;
                //This is the case the user inputted help and then a command (thats in the map
                if (collectionOfCommands.count(arg1)) {
                    //displays the information on the command
                    collectionOfCommands[arg1]->displayInfo();

                }
                else {
                    //Case that the user inputed help and then a command (that is not in the amp)
                    std::cout << "no matching command found" << std::endl;
                }
            //Case the first word in the command is not "help"/is  a command
            }else{
                //Case the first word (that is a command) is in the map
                if (collectionOfCommands.count(command)) {
                    //If the command is in the map, we execute it anyway
                    if (command == "im") {
                        collectionOfCommands[command]->execute(userInputtedPrompt);
                        
                    }
                    else {
                        collectionOfCommands[command]->execute(userInputtedPrompt.substr(userInputtedPrompt.find(' ') + 1));
                    }
                    

                }
                //We do not execute it as it is not in the map
                else {
                    std::cout << "no matching command found" << std::endl;
                }
            }

        }
    }
}

//3j
//Prompts the user to input a prompt and then returns the prompt the user inputted
std::string CommandPrompt::prompt() {
    std::cout << "Enter a command, q to quit, help for a list of commands, or" << std::endl ;
    std::cout << "help followed by a command name for more information about" << std::endl;
    std::cout << "that command." << std::endl << "$   ";
        
    std::string userInputtedPrompt;

    getline(std::cin, userInputtedPrompt); //grabs the userInputtedPrompt from the input stream
    
    return userInputtedPrompt;
}
