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
    //episodes=null;
}


SeriesSeason::SeriesSeason(string ptitle, string pseason, string prating, string pgenre, string pimgurl, vector<Episode> pepisodes){
    title=ptitle;
    titleAndSeason=ptitle+" - Season "+pseason;
    season = stoi(pseason);
    rating = prating;
    genre = pgenre;
    imgURL = pimgurl;
    episodes = pepisodes;
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
        } else if (*i=="Season"){
            season = stoi(js.asString());
        }else if (*i=="Episodes"){
            auto jsonEpisodes = jsonObj[*i];
            for (Json::Value::ArrayIndex i = 0 ; i != jsonEpisodes.size(); i++){
                Episode ep(jsonEpisodes[i]);
                
                /* Goes into Episode constructor
                string t = jsonEpisodes[i]["Title"].asString();
                int num = stoi(jsonEpisodes[i]["Episode"].asString());
                string rate = jsonEpisodes[i]["imdbRating"].asString();
                Episode ep(t, num, rate);
                */
                episodes.push_back(ep);
            }
        }
    }
    titleAndSeason = title + " - Season " + season;
}


SeriesSeason::SeriesSeason(string jsonString){
    Json::Reader reader;
    Json::Value root;

    bool parseSuccess = reader.parse(jsonString, root, false);
    if (parseSuccess){
        SeriesSeason::SeriesSeason(root);
    }
    else{
        cout << "Constructor parse error with " << jsonString << endl;
    }
}

SeriesSeason::~SeriesSeason(){
    title="";
    rating="";
    genre="";
    imgURL="";
    season=-1;
    //episodes = 0; 
}


string SeriesSeason::toString(){
    string ret= "{}";

    Json::Value jsonLib;

    jsonLib["Title"] = title;
    jsonLib["imdbRating"] = rating;
    jsonLib["Season"] = season;
    jsonLib["Poster"] = imgURL;
    jsonLib["Genre"] = genre;
    
    string jsonEpisodes = "{\"Episodes\":[" 
    for (int i = 0 ; i < episodes.size() ; i++ ){
        if (i = episodes.size()-1) {
            jsonEpisodes+=(episodes[i].toString()+"]}");
        }
        jsonEpisodes+=(episodes[i].toString()+",");
    }

    Json::Reader r;
    Json::Value epp; 

    reader.parse(jsonEpisodes, epp, false);

    auto episodeArray = epp["Episodes"];

    jsonLib["Episodes"] = episodeArray;
    


}