#include "Group.hpp"

#include <json/json.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

/**
 * Copyright (c) 2020 Tim Lindquist,
 * Software Engineering,
 * Arizona State University at the Polytechnic campus
 * <p/>
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation version 2
 * of the License.
 * <p/>
 * This program is distributed in the hope that it will be useful,
 * but without any warranty or fitness for a particular purpose.
 * <p/>
 * Please review the GNU General Public License at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 * see also: https://www.gnu.org/licenses/gpl-faq.html
 * so you are aware of the terms and your rights with regard to this software.
 * Or, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,USA
 * <p/>
 * Purpose: Deomonstrate serialization to/from Json
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist (Tim.Lindquist@asu.edu) CIDSE - Software Engineering,
 *                       IAFSE, ASU at the Polytechnic campus
 * @file    main.cpp
 * @date    January, 2020
 **/
int main() {
   Group * aGroup = new Group();
   aGroup->initGroupFromJsonFile("admin.json");
   std::cout << endl << "Done initializing from admin.json" << endl;

   std::vector<string> names = aGroup->getNames();
   cout << endl;
   for(int i=0; i< names.size(); i++){
      std::cout << "found " << names[i] << endl;
   }

   User usr = aGroup->get("Joe");
   cout << endl;
   usr.print();

   cout << endl;
   aGroup->printGroup();

   aGroup->toJsonFile("adminFromCPP.json");
   std::cout << "Done writing a json file. I quit." << endl;

   return (0);
}
