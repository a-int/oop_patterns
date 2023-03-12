#include "facade.hpp"
#include <iostream>

int main(){
	MediaPlayerFacade multimedia;
	multimedia.playMusic();
	multimedia.playVideo();
	multimedia.playPhoto();

	return 0;
}