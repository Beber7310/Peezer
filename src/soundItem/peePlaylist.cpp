/*
 * peePlaylist.cpp
 *
 *  Created on: 11 mars 2017
 *      Author: Bertrand
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include "peePlaylist.h"

using namespace std;

peePlaylist::peePlaylist() {
	// TODO Auto-generated constructor stub
	_id=NULL;
	_name=NULL;
	_coverHtmplPath=NULL;
}

peePlaylist::~peePlaylist() {
	// TODO Auto-generated destructor stub
}

peePlaylist::peePlaylist(const char*  id,const char* name,const char* coverHtmplPath) {
	// TODO Auto-generated constructor stub
	_id=(char*)malloc(strlen(id)+1);
	_name=(char*)malloc(strlen(name)+1);
	_coverHtmplPath=(char*)malloc(strlen(coverHtmplPath)+1);

	strcpy(_id,id);
	strcpy(_name,name);
	strcpy(_coverHtmplPath,coverHtmplPath);


}

void peePlaylist::print() {
	cout << _name  << "(" << _id << ")" <<  endl;

}
