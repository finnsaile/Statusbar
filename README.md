# Status Bar Library
---
## Functionality
Simple library that provides the user with a way of showing the progress of a task in the terminal or writing it to a file. <br>  

## Compilation
To compile the library use `make statusbar`. \
If you are on Intel MacOs you can use `make addlibmac` to add the library to your local C++ libraries. On WSL you can use `makeaddlibwsl`. \
To use and link the library to your program, use `#include "statusbar.hpp"` and the linkerflag `-lstatusbar` \
_You may have to add the linkerflag `-lpthread` as the library uses multithreading._ <br>

## Usage 

To create a status bar, simply create an object of type `Statusbar`. Alternatively the time interval (in milliseconds) in which the status is updated, and an output stream of type `ostream` can be given as arguments. \
To update the current progress simply call the `setProgress()` member function. \
To terminate the status bar you can call the `killBar()` member function.