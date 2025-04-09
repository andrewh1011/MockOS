#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/CopyCommand.h"
#include "mockos/IMParsingStrategy.h"
#include "mockos/ChmodCommand.h"

int main() {
    //initialization of basic commands
    AbstractFileSystem* fileSystem = new SimpleFileSystem();
    AbstractFileFactory* fileFactory = new SimpleFileFactory();
    AbstractCommand* touch = new TouchCommand(fileSystem, fileFactory);
    AbstractCommand* ls = new LSCommand(fileSystem);
    AbstractCommand* rm = new RemoveCommand(fileSystem);
    AbstractCommand* cat = new CatCommand(fileSystem);
    AbstractCommand* ds = new DisplayCommand(fileSystem);
    AbstractCommand* cp = new CopyCommand(fileSystem);
    AbstractCommand* chmod = new ChmodCommand(fileSystem);

    //MacroCommands -- rename
    AbstractParsingStrategy* renameStrat = new RenameParsingStrategy();
    MacroCommand* rn = new MacroCommand(fileSystem);
    rn->setParseStrategy(renameStrat);
    rn->addCommand(cp); rn->addCommand(rm);

    //MacroCommands -- instant modification
    AbstractParsingStrategy* imStrat = new IMParsingStrategy();
    MacroCommand* im = new MacroCommand(fileSystem);
    im->setParseStrategy(imStrat);
    im->addCommand(touch); im->addCommand(cat);

    //Command Prompt
    auto* prompt = new CommandPrompt();
    //Seeting the filefactory and filesystem
    prompt->setFileFactory(fileFactory);
    prompt->setFileSystem(fileSystem);

    //Adding commands to the command prompt
    prompt->addCommand("im", im);
    prompt->addCommand("cp", cp);
    prompt->addCommand("rn", rn);
    prompt->addCommand("touch", touch);
    prompt->addCommand("ls", ls);
    prompt->addCommand("rm", rm);
    prompt->addCommand("cat", cat);
    prompt->addCommand("ds", ds);
    prompt->addCommand("chmod", chmod); //Extra credit chmod command
    prompt->run();

    //deallocation
    delete ls;
    delete rm;
    delete touch;
    delete cat;
    delete cp;
    delete ds;
    delete im;
    delete rn;
    delete fileSystem;
    delete fileFactory;
    delete prompt;
    delete renameStrat;
    delete imStrat;
    delete chmod; //Extra credit chmod command

    return programOutcomes::success;
}