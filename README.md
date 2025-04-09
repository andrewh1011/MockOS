# Mock OS
A static library that
implements a mock operating system.
A user of this mock operating system can
create and interact with files using commands.

## Commands included:

• Touch command [touch] (creates a file -> use .txt extension to create text files and .img extension to create image files)

• LS command [ls] (lists current files in system)

• Remove command [rm] (deletes a file)

• Cat command [cat] (adds data to a file)

• Display command [ds] (displays the contents of a file)

• Copy command [cp] (copys the contents of an existing file to a new file)

• Rename command [rn] (renames a file)

• Instand modification command [im] (touch + cat -> creates a file and then adds to it)

• CHMOD command [chmod] (changes permissions of a file)

More information on commands can be accessed by running the program and typing help and the command name. Many commands have additional options in the form of flags.

## Directory structure

- [docs/](./docs)
  - This directory contains markdown files

- [include/](./include)
  - This directory contains the public header files for the static library.
    
- [lib/](./lib)
  - This directory contains the source files for the implementation of the static library.

- [src/](./src)
  - This directory contains the source files for the executable code.

- [tests/](./tests)
  - This directory contains the unit tests.

