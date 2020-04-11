#include "Group.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <json/json.h>

using namespace std;

/**
 * Copyright 2020 Tim Lindquist,
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * Purpose: demonstrate json serialization and deserialization in C++
 * Ser321 Foundations of Distributed Applications
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist Tim.Lindquist@asu.edu
 *         Software Engineering, CIDSE, IAFSE, ASU Poly
 * @version January 2020
 */
Group::Group(){
}

void Group::initGroupFromJsonFile(string jsonFileName){
   ifstream jsonFile(jsonFileName.c_str());
   string line;
   cout << "The content of the Json file as a string: " << endl;
   if(jsonFile.is_open()){
      while(getline(jsonFile,line)){
         cout << line << endl;
      }
   }else{
      cout << "Json file not opened properly" << endl;
   }
   jsonFile.close();
   Json::Reader reader;
   Json::Value root;
   std::ifstream json(jsonFileName.c_str(), std::ifstream::binary);
   bool parseSuccess = reader.parse(json,root,false);
   if(parseSuccess){
      //cout << "successful parse" << endl;
      Json::Value::Members mbr = root.getMemberNames();
      for(vector<string>::const_iterator i = mbr.begin(); i!= mbr.end(); i++){
         //cout << *i << " " << endl;
         Json::Value jsonUser = root[*i];
         string nameStr = "name";
         if(nameStr.compare(*i)==0){
            name = jsonUser.asString();
            //cout << "found name " << *i << " value: " << name << endl;
         }else{
            //cout << "found " << *i << endl;
            string userId = jsonUser["userId"].asString();
            string userPwd = jsonUser["userPwd"].asString();
            //cout << "pwd: " << userPwd << " user: " << userId << endl;
            User * user = new User(userId, userPwd);
            //user->print();
            users[*i] = *user;
         }
      }
   }
}

void Group::toJsonFile(string jsonFileName){
   Json::Value jsonLib;
   jsonLib["name"] = name;
   for(std::map<string,User>::iterator i = users.begin(); i!= users.end(); i++){
      string key = i->first;
      //cout << key << " " << endl;
      Json::Value jsonUser;
      User usr = users[key];
      jsonUser["userId"] = usr.userId;
      jsonUser["userPwd"] = usr.userPwd;
      jsonLib[key] = jsonUser;
   }
   Json::StyledStreamWriter ssw("  ");
   std::ofstream jsonOutFile(jsonFileName.c_str(), std::ofstream::binary);
   ssw.write(jsonOutFile, jsonLib);
}

Group::~Group() {
   //cout << "Group destructor.\n";
   users.clear();
}

void Group::add(User usr){
   users[usr.userId]=usr;
}

void Group::remove(User usr){
   users.erase(usr.userId);
}

User Group::get(string usrName){
   User ret = users[usrName];
   return ret;
}

std::vector<string> Group::getNames(){
   vector<string> myVec;
   for(map<string,User>::iterator it = users.begin();it!=users.end();++it){
      myVec.push_back(it->first);
      //cout << it->first << "\n";
   }
   return myVec;
}

void Group::printGroup(){
   cout << "Group " << name << " has users" << endl;
   for(map<string,User>::iterator it = users.begin();it!=users.end();++it){
      cout << "key " << it->first << " is ";
      (it->second).print();
   }
   cout << endl;

}
