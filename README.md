# Mock OS Studios/Lab
A static library that
implements a mock operating system.
A user of this mock operating system is able to
create and interact with files using commands.

## Directory structure
The directory structure aims to follow best practices,
so it will look similar to many C++ projects in the real world.

The idea is to separate the public interface from its implementation.

- [docs/](./docs)
  - This directory contains the markdown files in which you'll answer
    the studio questions and write your lab README.

- [include/](./include)
  - This directory contains the public header files for the static library.
  - They are placed within the inner directory `mockos/`,
    so when including them from source files, prefix the filename with `mockos/`.
    For example, if you wanted to use TextFile, you would type
    `#include "mockos/TextFile.h"`.
  - The prefix is not necessary when
    you're including a header file from another header file that's inside `include/mockos/`.
- [lib/](./lib)
  - This directory contains the source files for the implementation of the static library.
  - Like `include/`, the files are placed within an inner `mockos/` directory.
- [src/](./src)
  - This directory contains the source files for the executable code.
  - There's a source file for each studio and the lab.
- [tests/](./tests)
  - This directory contains the unit tests.
  - Since the tests are already written for you, you will not need to modify the files in this directory.
