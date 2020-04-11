#include "User.hpp"
#include <iostream>
#include <stdlib.h>
#include <cmath>

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
 * Purpose: demonstrate Json serialization in C++
 * Ser321 Foundations of Distributed Applications
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist Tim.Lindquist@asu.edu
 *         Software Engineering, CIDSE, IAFSE, ASU Poly
 * @version January 2020
 */
User::User(){
   userId = "Null";
   userPwd = "Null";
}

User::User(string aUserId, string aUserPwd) {
   userId = aUserId;
   userPwd = aUserPwd;
}

User::~User() {
   //cout << "User destructor.\n";
   userId="";
   userPwd="";
}

void User::setValues(string aUserId, string aUserPwd) {
   userId = aUserId;
   userPwd = aUserPwd;
}

void User::print(){
   cout << "User " << userId << " with password " << userPwd << "\n";
}
