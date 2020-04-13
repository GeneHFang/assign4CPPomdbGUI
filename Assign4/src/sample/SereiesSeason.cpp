#include "SeriesSeason.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

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
 * Purpose: Implementation of SeriesSeason. SeriesSeason is a class whose properties describe a single SeriesSeason.
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist Tim.Lindquist@asu.edu
 *         Gene H Li ghli1@asu.edu
 *         Software Engineering, CIDSE, IAFSE, ASU Poly
 * @version April 2020
 */

SeriesSeason::SeriesSeason(){
    title="";
    titleAndSeason="";
    season=-1;
    rating="";
    genre="";
    imgURL="";
    episodes=null;
}


SeriesSeason::SeriesSeason(string ptitle, string pseason, string prating, string pgenre, string pimgurl){
    title=ptitle;
    titleAndSeason=ptitle+" - Season "+pseason;
    season = stoi(pseason);
    rating = prating;
    genre = pgenre;
    imgURL = pimgurl;
}


SeriesSeason::SeriesSeason(const Json::Value& jsonObj){
    Json::Value::Members mbr = jsonObj.getMemberNames();

    for (vector<string>::const_iterator i = mbr.begin(); i != mbr.end(); i++){
        Json::Value js = jsonObj[*i];
        if (*i=="Title"){
            title = js.asString();
        } else if (*i=="imdbRating"){
            rating = js.asString();
        } else if (*i=="Genre"){
            genre = js.asString();
        } else if (*i=="Poster"){
            imgURL = js.asString();
        }

    }

    titleAndSeason = title + " - Season " + season;
}