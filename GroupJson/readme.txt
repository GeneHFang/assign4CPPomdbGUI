Author: Tim Lindquist (Tim.Lindquist@asu.edu)
        Software Engineering, CIDSE, IAFSE, Arizona State University Polytechnic
Version: January 2020

See http://pooh.poly.asu.edu/Ser321

Purpose: Sample project showing Java and C++ use of Json for simple
serialization/deserialization. The Java program creates a group
of users and then serializes it to Json, writing the Json to a text file.
The Java program also serializes and de-serializes using Java's built-in
serialization facilities. Note also the use of serialVersionUID in the
Java Group and User classes to demonstrate its use. The C++
program reads in the json file written by the Java program,
re-constructs the Group object and then
writes it back out to a different file. Run the Java first otherwise there's no
input file for the C++ program to read.

The Java program uses the Json reference implementation from Douglas Crockford
which you can download from:

https://github.com/douglascrockford/JSON-java

The classes from this library are included in the lib directory of this project
in the jar file: json.jar. Nevertheless, you should download the library and
generate the javadocs for the classes, which will be useful in utilizing
Json with your Java programs.

http://pooh.poly.asu.edu/Ser321/Resources/setupJsonJavaNJsonRPCcpp.html

To build the Java program:
ant build.java

You should execute the Java program first with:
ant execute.java

Or execute the Java client manually with:
java -cp classes:lib/json.jar ser321.serialize.GroupFileSerialize


The C++ program uses the library package libjsoncpp. Setting up
this library on Debian Wheezy Linux can be done with:
sudo apt-get install libjsoncpp-dev
and is covered on the same page referenced above.
On MacOSX, you can install it using MacPorts with:
sudo port install jsoncpp

After building and installing libjsoncpp, to build the C++ program enter:
ant build.cpp
from the command line. This compiles and links the C++ program into
the bin directory. Execute the C++ program from the command line with:
./bin/groupJson

Completing assignments in Ser321 will require the following frameworks:
FLTK toolkit, libjsoncpp, libjson-rpc-cpp, and JSON-Java.
Instructions for installing FLTK can be found at the class web site:
http://pooh.poly.asu.edu/Ser321/Resources/setupFLTK.html

Depending on your installation of Ant, you may need to place cpp tasks,
and ant-contrib tasks for Ant where it will find them.
This project's lib directory contains the java archive:

antlibs.jar

Copy that jar file to your home directory and extract its contents with:

jar xf antlibs.jar
