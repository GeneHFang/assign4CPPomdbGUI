#include <string>
#include <cmath>
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
 * Purpose: Episode is a class whose properties describe a single Episode. Episodes belong to a SeriesSeason.
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist Tim.Lindquist@asu.edu
 *         Gene H Li ghli1@asu.edu
 *         Software Engineering, CIDSE, IAFSE, ASU Poly
 * @version April 2020
 */

class Episode{
    //attributes
    public:
        string title;
        int episode;
        string rating;

    //constructors
    Episode();
    Episode(string ptitle, int pepisode, string prating);
    Episode(const Json::Value& jsonObj);
    Episode(string jsonString);

    //destructor
    ~Episode();

    //Create json string from object values
    string toString();
    
    //Create json from object values
    Json::Value toJson();

    //setter
    void setValues(string ptitle, int pepisode, string prating);

    //Log to Console
    void print();

};