#include "SeriesSeason.hpp"
#include <string>
#include <map>
#include <vector>
#include <json/json.h>

using namespace std;

/**
 * Copyright 2020 Tim Lindquist, Gene Li
 *
 * This software is the intellectual property of the author, and can not be 
 * distributed, used, copied, or reproduced, in whole or in part, for any purpose, commercial or otherwise.
 * The author grants the ASU Software Engineering program the right to copy, execute, and evaluate this
 * work for the purpose of determining performance of the author in coursework,
 * and for Software Engineering program evaluation, so long as this copyright and
 * right-to-use statement is kept in-tact in such use.
 * All other uses are prohibited and reserved to the author.
 * 
 *
 * Purpose: MediaLibrary is a class defining the interface between clients
 * and the server. The server implementation of MediaLibrary
 * provides storage for description of multiple media works -- SeriesSeason(s).
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist Tim.Lindquist@asu.edu
 *         Gene H Li ghli1@asu.edu
 *         Software Engineering, CIDSE, IAFSE, ASU Poly
 * @version April 2020
 */
class MediaLibrary {
protected:
   std::map<std::string, SeriesSeason> media;

public:
   MediaLibrary();
   ~MediaLibrary();

   Json::Value getJson();
   bool addToLibrary(SeriesSeason ss);
   bool initLibraryFromJsonFile(string jsonFileName);
   bool toJsonFile(string jsonFileName);
   void printMap();
   string serviceInfo();
   SeriesSeason get(string aTitle);
   std::vector<string> getTitles();
};
