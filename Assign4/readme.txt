Author: Tim Lindquist (Tim.Lindquist@asu.edu)
        Gene H Li (ghli1@asu.edu)
        Software Engineering, CIDSE, IAFSE, Arizona State University Polytechnic
Version: April 2020

See http://pooh.poly.asu.edu/Ser321/Assigns/Assign4/assign4.html

Purpose: Assignment 4 based on sample C++ program demonstrating Ant builds and an FLTK
 GUI for SeriesSeason Browser.

This program is has been tested on Linux and MacOS (build.xml only works on
Linux).

*****NOTE: series.json is replaced with seriesTest.json******

To execute Ant using the build.xml in this directory, you will need to
copy the file: antlibs.jar from the lib directory to your home directory:
cp lib/antlibs.jar ~
or
cp lib/antlibs.jar $HOME/
Note that ~ (tilde) is a shortcut for $HOME
then extract the antlibs.jar file:
pushd ~
jar xvf antlibs.jar
pushd -0
The pushd commands manipulate a stack of directories for switching your
bash's current directory. The first pushd pushes home onto the stack and
switches the current directory to home. The second pushd takes you
back to whatever directory you were in before the first.

To compile the GUI and to do OMDb searches, you must also provide the Curlpp
library, which is a C++ wrapper for cURL. See:  http://www.curlpp.org/
This example depends on the library curlpp to download a file or make
a URL request. This should be used in problem solutions to search
OMDb for Series, season and episode information. Download the library from: 
  http://www.curlpp.org/
Extract the archive and from a terminal change to the directory created.
Execute the following commands looking for errors. Note the following steps
require that libcurl first be installed, if its not already present.
   cmake ./
   make
   sudo make install
   sudo ldconfig
To see the make options available do: make help. You will need to have cmake and make installed (you can use apt-get install the same way as for installing other packages). 

To run the example GUI, from a bash shell in the project directory, execute the
command:
ant execute.sample -Domdbkey=myomdbkey

if you have your key in the file omdb.key then use:
ant execute.sample -Domdbkey=`cat omdb.key`

To clean the project (remove the executable files) execute:
ant clean


