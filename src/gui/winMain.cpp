/*
 * guiMain.cpp
 *
 *  Created on: 13 mars 2017
 *      Author: Bertrand
 */

// first OpenVG program

#include "configuration.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <string.h>
#include <dirent.h>

#include "EGL/egl.h"


#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

#include <pthread.h>
#include <semaphore.h>

#include "guiRoot.h"
#include "peeAlbum.h"
#include "peePlaylist.h"
#include "main.h"
#include "winMain.h"
#include "homeControl.h"


guiBase* guiBuild()
{
#ifdef BOOMBOOM_SALON
	guiList* 			albumsWindows 		= new guiList();
	guiList* 			playlistWindows 	= new guiList();
	guiList* 			homecontrolWindows  = new guiList();
#endif
	guiList*			mp3Windows		  	= new guiList();
	guiList* 			podcastWindows  	= new guiList();
	guiPlayer* 			playerWindows   	= new guiPlayer();
	guiTabLayout*		tabLayout			= new guiTabLayout();
	guiVerticalSplit*	verticalSplit		= new guiVerticalSplit();

#ifdef BOOMBOOM_SALON
	for (vector<peeAlbum*>::iterator it = appContext.Albums->begin(); it != appContext.Albums->end(); it++)
	{
		albumsWindows->AddChild(new guiAlbum(*it));
	}

	for (vector<peePlaylist*>::iterator it = appContext.Playlist->begin(); it != appContext.Playlist->end(); it++)
	{
		playlistWindows->AddChild(new guiPlaylist(*it));
	}
#endif
	for (vector<peePodcast*>::iterator it = appContext.Podcasts->begin(); it != appContext.Podcasts->end(); it++)
	{
		podcastWindows->AddChild(new guiPodcast(*it));
	}

	// ADD MP3 Directory
	DIR* dirp = opendir("audio/mp3/");
	if(dirp==NULL)
	{
		printf("audio/mp3/ not found...");
	}
	else
	{
		dirent * dp;
		while ((dp = readdir(dirp)) != NULL)
		{
			if(dp->d_name[0]!='.')
				mp3Windows->AddChild(new guiMP3(dp->d_name) );
		}
		(void)closedir(dirp);
	}

#ifdef BOOMBOOM_SALON
	homecontrolWindows->AddChild(new guiCourant());
	homecontrolWindows->AddChild(new guiVmc(HC_LIGHT_VMC));
	homecontrolWindows->AddChild(new guiVmc(HC_LIGHT_DISCO));
	homecontrolWindows->AddChild(new guiThermo(HC_TEMP_EXTERIEUR));
	homecontrolWindows->AddChild(new guiHeater(HC_HEATER_SALON));
	homecontrolWindows->AddChild(new guiHeater(HC_HEATER_CUISINE));
	homecontrolWindows->AddChild(new guiHeater(HC_HEATER_BARNABE));
	homecontrolWindows->AddChild(new guiHeater(HC_HEATER_DAPHNEE));
	homecontrolWindows->AddChild(new guiThermo(HC_TEMP_VICTOR));
	homecontrolWindows->AddChild(new guiThermo(HC_TEMP_PARENT));
	homecontrolWindows->AddChild(new guiHeater(HC_HEATER_HOMECINEMA));
	homecontrolWindows->AddChild(new guiThermo(HC_TEMP_GARAGE));
#endif

#ifdef BOOMBOOM_SALON
	playlistWindows->SetName("Playlists");
	albumsWindows->SetName("Albums");
	homecontrolWindows->SetName("Home Control");
#endif
	podcastWindows->SetName("Podcasts");
	playerWindows->SetName("Player");
	mp3Windows->SetName("MP3");



#ifdef BOOMBOOM_SALON
	tabLayout->AddChild(playlistWindows);
	tabLayout->AddChild(albumsWindows);
#endif
	tabLayout->AddChild(podcastWindows);
	tabLayout->AddChild(mp3Windows);
#ifdef BOOMBOOM_SALON
	tabLayout->AddChild(homecontrolWindows);
#endif


	verticalSplit->AddChild(tabLayout);
	verticalSplit->AddChild(playerWindows);
#ifdef SCREEN_7P
	verticalSplit->_verticalSplitSize=900;
#elif defined(SCREEN_5P)
	verticalSplit->_verticalSplitSize=675;
#else
#error
#endif
	return verticalSplit;
}


int winLaunch()
{
	guiLaunch();
	guiSetMainWindows(guiBuild());
	//pthread_exit(NULL);
	return 0;
}
