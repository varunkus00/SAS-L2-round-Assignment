# SAS-L2-round-Assignment
#A small C/C++ project for validation and removing of duplicate of #timestamps


# Project Structure
include : Includes the header files
include/api : Includes for the validation api header
src : source code implementation
src/api : source code for validation api
test : test case implementation
Makefile : project makefile
exec.exe : final executable

#Improvements : 

1. Final Validation is failing, The logic is there but some minor corrections needed to fix the code and bring it in running state.
2. From UT perspective , validated the basic cases 
a. validation of year, validation of hour, validation of min, validation of sec, date, month and tzd. Final Executable run is failing because of some minor issue. I am out of time, can not fix it.
3. The code implements sequential execution, to implement concurrent execution modifications are needed
4. Code is using single threaded architecture, can be modified for asynchronous behavior.