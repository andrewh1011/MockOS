#include "mockos/MacroCommand.h"
using namespace std;

//Constructor for the macro command simply sets the concrete file system
MacroCommand::MacroCommand(AbstractFileSystem *abstractFileSystem)
: abstractFileSystem(abstractFileSystem){}

void MacroCommand::displayInfo() {
cout <<"The Macro Command combines two commands in order to create another command."<<endl;
cout<<"One of the two commands in this program is rename which is rn (used by 'rn <originalFileName> <newFileName>"<<endl;
cout<<"The other of the two commands is im <originalFileName> which combines the touch and cat command."<<endl;
}

//Execute command simply executes each of the command that a Macro Object is composed of
int MacroCommand::execute(std::string command) {
    //Firstly, we want to get the parsed executionformat based the Macro Objects current ParsingStrategy
    vector<string> parsedExecutionFormat = this->parsingStrategy->parse(command);
    //We want to perform execute on each of the Macro Objects Commands that it's composed of
    for (int i = 0; i < this->abstractCommandVector.size(); ++i) {
            //Get the current parsing strategy
            string currentParsingStrategy = parsedExecutionFormat[i];
            //Get the current concrete command (recall, the Macro Object is composed of various commands)
            AbstractCommand* currentAbstractCommand =this->abstractCommandVector[i];
            int resultOfCommandExecuteFunction = currentAbstractCommand->execute(currentParsingStrategy);
            //Call execute on each command (utilizing the parsed strategy) that the Macro object is composed of
            //however if at any point an execution fails, we can simply return early
            if (resultOfCommandExecuteFunction != programOutcomes::success) {
                return resultOfCommandExecuteFunction;
            }
        }

    //If we ran the concrete parsing strategy on every concrete command that a macro object is composed off,
    //and no errors occured, we can safely return success.
    return programOutcomes::success;
}

//Takes a pointer to an abstract command and pushes it back to the vector of abstractCommandVector
//These concrete commands are what a specific Macro Object is composed of!
void MacroCommand::addCommand(AbstractCommand* command) {
    this->abstractCommandVector.push_back(command);
}

//Sets the strategy for the parsing object, ex: RenameParsingStategy
void MacroCommand::setParseStrategy(AbstractParsingStrategy *parsingStrategy) {
    this->parsingStrategy = parsingStrategy;
}