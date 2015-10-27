GCCErrC
=======

What is it?
-----------
GCCErrC (GCC Error Colorizer) is a simple Python 3.x script that accepts GCC output through stdin and prints nearly identical text, except that the words "warning" and "error" are colored. This was created to facilitate use of older versions of GCC (or any other compiler) which does not have colorized output.

This was created as a quickie project to help me in creating Lyle in Cube Sector for Sega Genesis. The code isn't particularly elegant or thorough, and I'm sure making it cause problems isn't too difficult. Use at your own risk; identified bugs and bugfix submissions are appreciated.

Usage
-----
As this operates with stdin and stdout it is easy to integrate into a makefile or build script by piping the compiler's output into GCCErrC. You must remember to redirect stderr as well as stdout. An example usage:

cc foo.c 2>&1 | python3 gccerrc.py

