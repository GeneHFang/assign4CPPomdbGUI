#include "MediaLibrary.hpp"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

MediaLibrary::MediaLibrary(){
   initLibraryFromJsonFile("seriesTest.json");
}


MediaLibrary::~MediaLibrary() {
   media.clear();
}

void MediaLibrary::addLibrary(std::map<std::string, SeriesSeason> lib)
{
   media.insert(lib.begin(),lib.end());
}

bool MediaLibrary::addToLibrary(SeriesSeason ssObj){
   bool ret; 

   auto const [position, hasBeenAdded] = media.insert({ssObj.titleAndSeason, ssObj});
   ret = hasBeenAdded;

   return ret;
}

bool MediaLibrary::removeFromLibrary(std::string key){
   bool ret = false;

   ret = (media.erase(key) != 0);

   return ret;
}

bool MediaLibrary::initLibraryFromJsonFile(string jsonFileName){
   bool ret = false;
   Json::Reader reader;
   Json::Value root;
   std::ifstream json(jsonFileName.c_str(), std::ifstream::binary);
   bool parseSuccess = reader.parse(json,root,false);
   if(parseSuccess){
      Json::Value::Members mbr = root.getMemberNames();
      for(vector<string>::const_iterator i = mbr.begin(); i!= mbr.end(); i++){
         Json::Value jsonMedia = root[*i];
         SeriesSeason * aDesc = new SeriesSeason(jsonMedia);
         cout << *i << endl;
         media[*i] = *aDesc;
         cout << "adding ";
         aDesc->print();
      }
      ret = true;
   }
   return ret;
}

Json::Value MediaLibrary::getJson(){
   Json::Value jsonLib;
   for(std::map<string,SeriesSeason>::iterator i = media.begin();
                                                         i!= media.end(); i++){
      string key = i->first;
      cout << key << " " << endl;
      SeriesSeason aMedia = media[key];
      Json::Value jsonMedia = aMedia.toJson();
      jsonLib[key] = jsonMedia;
   }
   return jsonLib;
}

bool MediaLibrary::toJsonFile(string jsonFileName){
   bool ret = false;
   Json::Value jsonLib = getJson();
   Json::StyledStreamWriter ssw("  ");
   std::ofstream jsonOutFile(jsonFileName.c_str(), std::ofstream::binary);
   ssw.write(jsonOutFile, jsonLib);
   return true;
}

void MediaLibrary::printMap(){
   std::cout << getJson().toStyledString() << std::endl;
}

SeriesSeason MediaLibrary::get(string aTitle){
   SeriesSeason aMedia = media[aTitle];
   return aMedia;
}

vector<string> MediaLibrary::getTitles(){
   vector<string> myVec;
   for(map<string,SeriesSeason>::iterator it = media.begin();
                                              it != media.end();++it){
      myVec.push_back(it->first);
   }
   return myVec;
}
