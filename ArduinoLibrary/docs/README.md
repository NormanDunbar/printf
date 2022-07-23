# Printf Library

This library is a simple copy of https://github.com/mpaland/printf and is used under the MIT Licence.

## Arduino

To install the library:

* Click Sketch->Include Library->Add .ZIP Library;
* Navigate to where the zip file for this library is located on your system;
* Select it and click the OK button;
* Follow the prompts.


## PlatformIO

As of the time of typing, I have not built this library into a format suitable for uploading to the official PlatformIO Library Repository. To this end, the use of `lib_deps` will not (currently) work. 

As time goes on, I might "get my finger out" and do the necessary work to make this an official PlatformIO library. Watch this space---->[ ].

This means you have a couple of simple options, as described below.

### Install Globally

The advice is never to install libraries globally with the command `platformio lib install --global "library name"` as it can lead to problems when multiple libraries have the same name, but different platforms.

However, there is always someone with a good reason to do this, so here's my global install.

* Create a global libraries directory. Mine is called `PlatformIO_Libraries`;
* Copy the directory containing the source and header files for this library into the one above. You *must* copy the directory and contents, not just the contents.
* In your project's `platformio.ini` file, add either:
  * `lib_extra_dirs = /full/path/to/PlatformIO_Libraries` or
  * `lib_extra_dirs = relative/path/to/PlatformIO_Libraries`

When you compile the project, it will look in all the sub-directories of the `PlatformIO_Libraries` directory for any included headers and/or required source files. 

### Install per Project

To install this library for a single project, you can follow the instructions for installing globally then add the `lib_extra_dirs` as described above, or:

* Copy the directory containing the source and header files into the `lib` directory under your project's own directory. You should copy the directory and it's contents, not just the contents.

You will not need to add a `lib_deps` or `lib_extra_dirs` entry to the `platformio.ini` file in this case, the compiler will find the files and compile them as required.


Have fun.


Norman Dunbar
norman@dunbar-it.co.uk

15 September 2020.
