# Lab 5
Contributors
Andrew Hartmann <a.r.hartmann@wustl.edu>
Mario Rodriguez-Montoya <m.rodriguez-montoya@wustl.edu>
Shangwe Nyota <s.nyota@wustl.edu>


Lab5 Summary and How to Use the program: 
      This lab creates a simulation of a file system and a command line interface to interact with the filesystem. This base of the lab was built and designed during studios 16-21 and the majority of the functionality (commands) were implemented throughout the lab5 process. The lab was created and designed using various Software Engineering Object Oriented Design Patterns such as the Abstract File Factory Pattern, Visitor pattern, strategy pattern, and more!
      Command line and file system program. Supports text files and images. This program does not expect any command line arguments. Simply run the lab5.cpp file.


Errors Occured and How We Fixed Them:

• Encoutered many errors when importing header files. This was fixed by including "#pragma once" in almost every header file.

• When developing the copy command we had trouble copying an image file. We tried to copy an image file the same way we copied a text file, but this did not work as the data is stored differently. A simple refactor fixed this.

• When developing the append flag for the cat command, we got errors if you tried to append to an image. Once we realized the problem, a simple if statement fixed this.

• For multiple commands, if the user entered a file that did not exist, an error occured. Therefore, when we oppened a file from the FileSystem, we first check to see if it is a nullptr before continuing. If it is a nullptr, we return a non-zero value indicating this. If not, we continue knowing the file exists.

• We had some circular inclusion errors that occured, but after using the forward declaration technique learned from recitation the error was resolved.


Commands included:

• Touch command [touch] (creates a file -> use .txt extension to create text files and .img extension to create image files)

• LS command [ls] (lists current files in system)

• Remove command [rm] (deletes a file)

• Cat command [cat] (adds data to a file)

• Display command [ds] (displays the contents of a file)

• Copy command [cp] (copys the contents of an existing file to a new file)

• Rename command [rn] (renames a file)

• Instand modification command [im] (touch + cat -> creates a file and then adds to it)

• CHMOD command [chmod] (changes permissions of a file)

More information on commands can be accessed by running the program and typing help and the command name. Many commands have additional options in the form of flags.

- Testing ListCommand, TouchCommand, and RemoveCommand:

$   touch text.txt

$   touch image.img

$   touch image2.img

$   ls
image.img           image2.img
text.txt

$   rm image2.img

$   ls
image.img           text.txt

$   ls -m
image.img image 0
text.txt text 0

- Invalid arguments:

$   touch fileNameIsWayTooLong.txt
File name too long (must be less than 20 characters).

$   touch too many arguments
Invalid arguments.

$   ls too many arguments
Invalid arguments for ls command.

- Testing CatCommand and DisplayCommand:

$   touch text.txt

$   cat text.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
These are words
:wq

$   ds text.txt
These are words

$   cat text.txt -a
Current contents: 
These are words
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
 Append more words
:wq

$   ds text.txt
These are words Append more words

$   cat text.txt -a
Current contents: 
These are words Append more words
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
Test not saving
:q

$   ds text.txt
These are words Append more words

- Testing CatCommand, TouchCommand -p, and DisplayCommand (both formatted and unformatted):

$   touch image.img -p
What is the password?
123

$   cat image.img
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
X X X X X3
:wq
What is the password?
123

$   ds image.img
What is the password?
123
X X
 X 
X X

$   ds image.img -d
What is the password?
123
X X X X X

- Testing CopyCommand:

$   touch text.txt

$   cat text.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
123
:wq

$   cp text.txt copy

$   ds copy.txt
123

$   cat copy.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
12345
:wq

$   ds copy.txt
12345 

$   ds text.txt
123     //Changes to copy did not effect original file

- Testing CopyCommand with passwords and images 

$   touch imageWithPass.img -p
What is the password?
123

$   cat imageWithPass.img
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
X X X X X3
:wq
What is the password?
123

$   ds imageWithPass.img
What is the password?
123
X X
 X 
X X

$   cp imageWithPass.img new
What is the password?
123
X X X X X

$   ls
imageWithPass.img   new.img

$   ds new.img
What is the password?
123
X X
 X 
X X

- Testing MacroCommands (im):

$   im test.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
12345
:wq

$   ls
test.txt

$   ds test.txt
12345

$   im image.img
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
X X X X X3
:wq

$   ds image.img
X X
 X 
X X

$   im textWithPass.txt -p
What is the password?
123
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
file text
:wq
What is the password?
123

$   ds textWithPass.txt
What is the password?
123
file text

- Testing MacroCommands (rn):

//Text files

$   touch first.txt

$   cat first.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
These are words
:wq

$   ds first.txt
These are words

$   rn first.txt second

$   ls
second.txt

$   ds second.txt
These are words

//Image with password

$   touch firstImage.img -p
What is the password?
123

$   cat firstImage.img
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
X X X X X3
:wq
What is the password?
123

$   rn firstImage.img secondImage
What is the password?
123

$   ls
secondImage.img

$   ds secondImage.img
What is the password?
123
X X
 X 
X X


Extra Credit: After Discussing with Prof. Shidal, we implemented readonly file permissions. 
Process: We decided to use the proxy pattern to create a "Chmod" proxy object that inherited from the Abstract File class. This allows the proxy object to be added into the filesystem (and replace the existing file that a user wants to add permissions on). One particularly challenging part came when copying the chmod object as I had to research dynamic casting and utilize this in the copy command. This was difficult at first, but after doing some research on dynamic casting from the c++ reference site, I was able to use this well. https://en.cppreference.com/w/cpp/language/dynamic_cast
I also used the command pattern to create a "Chmod Command object" to allow for execution of the chmod command (and allowing for dispalying info for the command)! 
Errors Occured During development: This was a relatively simple command (after doing the entire lab), so no real problems occured and this was relatively straight forward to create!
- Testing CHMODCommand: 

$   touch test.txt

$   chmod test.txt - //Makes files read only

$   cat test.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
Attempt to add to file with - flag
:wq
This file is read only, so you cannot modify the file!

$   chmod test.txt + //Makes file writable again

$   cat test.txt
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
Attempt to write with + flag
:wq

$   ds test.txt
Attempt to write with + flag //Changes were saved because file was writable
$   chmod test.txt - //Makes the file readonly again
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$   cp test.txt copied //makes a new file that is readonly
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$   cat copied.txt -a //Attempting to write to the copied readonly file (this should fail)
Current contents:
Attempt to write with + flag
Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:
Testing this should fail!
:wq
This file is read only, so you cannot modify the file!
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$   q

Process finished with exit code 0


These tests ran as expected!

   