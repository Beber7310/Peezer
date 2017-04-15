/*
 * peeAlbum.cpp
 *
 *  Created on: 11 mars 2017
 *      Author: Bertrand
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <memory>

#include "peeAlbum.h"
#include "peeBase.h"
#include "tools.h"


using namespace std;

peeAlbum::peeAlbum() {
	// TODO Auto-generated constructor stub
	_id=NULL;
	_artisteName=NULL;
	_albumName=NULL;
	_coverHtmplPath=NULL;
	_tracks=NULL;
	_currentTrack=0;
}

peeAlbum::~peeAlbum() {
	// TODO Auto-generated destructor stub
}

peeAlbum::peeAlbum(const char* id,const char* artisteName,const char* albumName,const char* coverHtmplPath){
	// TODO Auto-generated constructor stub
	_id=(char*)malloc(strlen(id)+1);;
	_artisteName=(char*)malloc(strlen(artisteName)+1);
	_albumName=(char*)malloc(strlen(albumName)+1);
	_coverHtmplPath=(char*)malloc(strlen(coverHtmplPath)+1);

	strcpy(_id,id);
	strcpy(_albumName,albumName);
	strcpy(_artisteName,artisteName);
	strcpy(_coverHtmplPath,coverHtmplPath);
	_currentTrack=0;
	_tracks=NULL;
}

void peeAlbum::fetchTracks() {
	if(_tracks==NULL)
		_tracks=toolsGetUserAlbumTracks(this);
}

void peeAlbum::print() {

	cout << _artisteName << " " << _albumName << "(" << _id << ")" <<  endl;
	if(_tracks!=NULL)
	{
		for (vector<peeTrack*>::iterator it = _tracks ->begin(); it != _tracks->end(); it++)
		{
			(*it)->print();
		}
	}
}

