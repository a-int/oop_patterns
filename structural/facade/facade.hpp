#pragma once
#include <iostream>

class MediaPlayer{ //interface for media players
public: 
	virtual void play() =0;
};

class MusicPlayer: public MediaPlayer{
public:
	void play() override{std::cout<<"Start music ...\n";}
};

class VideoPlayer: public MediaPlayer{
public:
	void play() override{std::cout<<"Start video ...\n";}
};

class PhotoViewer: public MediaPlayer{
public:
	void play() override{std::cout<<"Open photo ...\n";}
};

class MediaPlayerFacade{
public:
	void playMusic(){
		MusicPlayer player;
		player.play();
	}
	void playVideo(){
		VideoPlayer player;
		player.play();
	}
	void playPhoto(){
		PhotoViewer player;
		player.play();
	}
};