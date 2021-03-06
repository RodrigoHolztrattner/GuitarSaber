// BeatDetector.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "Detector\BeatDetector.h"
#include "Detector\TimeStamp.h"
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
	BeatDetector::Instance()->loadSystem();
	BeatDetector::Instance()->LoadSong(1024, (char*)"Horns - Bryce Fox.mp3");

	BeatDetector::Instance()->setStarted(true);

	TimeStamp* localLastBeatOccured = nullptr;

	while (true)
	{
		BeatDetector::Instance()->update();

		if (localLastBeatOccured != BeatDetector::Instance()->getLastBeat())
		{
			//Beat Occured
			std::cout << "Beat!" << std::endl;

			//DO SOMETHING

			//Update localLastBeat
			localLastBeatOccured = BeatDetector::Instance()->getLastBeat();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

    return 0;
}

