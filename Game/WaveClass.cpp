#include "WaveClass.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "FleaFactory.h"
#include "CentipedeFactory.h"
#include <fstream>

WaveClass* WaveClass::ptrInstance = NULL;

void WaveClass::privInitData()
{
	std::ifstream inFile;
	inFile.open("WaveData.txt");
	
	if (!inFile) {
		ConsoleMsg::ShowError("Unable to open file");
		exit(1);
	}
	
	int num = -1;
	std::string line;

	while (std::getline(inFile, line)) {
		if (line.find("LEVEL") != std::string::npos) {
			num++;
			privInitWave();
		}
		else if (line.find("HEAD") != std::string::npos) {
			if (line.find("SPEED") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				int s = std::stoi(line.substr(pos + 1));
				if (16 % s != 0) assert(false && "Head Speed is not a divider of 16, calculations will not work");
				wList.headSpeed.at(num) = s;
			}
			else if (line.find("NUM") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				wList.headCount.at(num) = std::stoi(line.substr(pos + 1));
			}
			else {
				assert(false && "Unknown Head specifier. 'SPEED' and 'NUM' are the only known values.");
			}
		}
		else if (line.find("CENTI") != std::string::npos) {
			if (line.find("SPEED") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				int s = std::stoi(line.substr(pos + 1));
				if (16 % s != 0) assert(false && "Centipede Speed is not a divider of 16, calculations will not work");
				wList.centipedeSpeed.at(num) = s;
			}
			else if (line.find("LENGTH") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				wList.centipedeLength.at(num) = std::stoi(line.substr(pos + 1));
			}
			else {
				assert(false && "Unknown Centipede specifier. 'SPEED' and 'LENGTH' are the only known values.");
			}
		}
		else if (line.find("FLEA") != std::string::npos) {
			if (line.find("NUM") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				wList.numMushFlea.at(num) = std::stoi(line.substr(pos + 1));
			}
			else if (line.find("SPAWN") != std::string::npos) {
				if (line.find("TRUE") != std::string::npos) wList.fleaOn.at(num) = true;
				else if (line.find("FALSE") != std::string::npos) wList.fleaOn.at(num) = false;
				else assert(false && "Unexpected value in Flea Spawn. Please enter 'TRUE' or 'FALSE'");
			}
			else {
				assert(false && "Unknown Flea specifier. 'SPAWN' and 'NUM' are the only known values.");
			}
		}
		else if (line.find("SCORPION") != std::string::npos) {
			if (line.find("RATE") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				wList.scorpionSpawnRate.at(num) = std::stoi(line.substr(pos + 1));
			}
			else if (line.find("SPAWN") != std::string::npos) {
				if (line.find("TRUE") != std::string::npos) wList.scorpionOn.at(num) = true;
				else if (line.find("FALSE") != std::string::npos) wList.scorpionOn.at(num) = false;
				else assert(false && "Unexpected value in Scorpion Spawn. Please enter 'TRUE' or 'FALSE'");
			}
			else {
				assert(false && "Unknown Scorpion specifier. 'SPAWN' and 'RATE' are the only known values.");
			}
		}
		else if (line.find("SPIDER") != std::string::npos) {
			if (line.find("RATE") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				wList.spiderSpawnRate.at(num) = std::stoi(line.substr(pos + 1));
			}
			else if (line.find("SPAWN") != std::string::npos) {
				if (line.find("TRUE") != std::string::npos) wList.spiderOn.at(num) = true;
				else  if (line.find("FALSE") != std::string::npos) wList.spiderOn.at(num) = false;
				else assert(false && "Unexpected value in Spider Spawn. Please enter 'TRUE' or 'FALSE'");
			}
			else if (line.find("SPEED") != std::string::npos) {
				std::size_t pos = line.find_last_of(' ');
				wList.spiderSpeed.at(num) = std::stoi(line.substr(pos + 1));
			}
			else {
				assert(false && "Unknown Spider specifier. 'SPAWN', 'RATE', and 'SPEED' are the only known values.");
			}
		}
		else if (!line.empty()) {
			assert(false && "Unknown line entry. Lines must include 'LEVEL', 'CENTIPEDE', 'HEAD', 'SCORPION', 'SPIDER', or 'FLEA'");
		}
	}
}

void WaveClass::privInitWave()
{
	wList.centipedeLength.push_back(-1);
	wList.centipedeSpeed.push_back(-1);
	wList.headCount.push_back(-1);
	wList.headSpeed.push_back(-1);
	wList.fleaOn.push_back(0);
	wList.numMushFlea.push_back(-1);
	wList.scorpionOn.push_back(0);
	wList.scorpionSpawnRate.push_back(-1);
	wList.spiderOn.push_back(0);
	wList.spiderSpawnRate.push_back(-1);
	wList.spiderSpeed.push_back(-1);
}

void WaveClass::privSetupWave()
{
	if (wList.centipedeLength[waveNum] != -1) CentipedeFactory::setLength(wList.centipedeLength[waveNum]);
	if (wList.centipedeSpeed[waveNum] != -1) CentipedeFactory::setCentiSpeed(wList.centipedeSpeed[waveNum]);
	if (wList.headCount[waveNum] != -1) CentipedeFactory::setHeads(wList.headCount[waveNum]);
	if (wList.headSpeed[waveNum] != -1) CentipedeFactory::setHeadSpeed(wList.headSpeed[waveNum]);
	
	FleaFactory::setActive(wList.fleaOn[waveNum]);
	if (wList.numMushFlea[waveNum] != -1) FleaFactory::setSpawn(wList.numMushFlea[waveNum]);

	ScorpionFactory::setActive(wList.scorpionOn[waveNum]);
	if (wList.scorpionSpawnRate[waveNum] != -1) ScorpionFactory::setSpawnRate(wList.scorpionSpawnRate[waveNum]);

	SpiderFactory::setActive(wList.spiderOn[waveNum]);
	if (wList.spiderSpeed[waveNum] != -1) SpiderFactory::setSpeed(wList.spiderSpeed[waveNum]);
	if (wList.spiderSpawnRate[waveNum] != -1) SpiderFactory::setSpawnRate(wList.spiderSpawnRate[waveNum]);

	waveNum++;
}

void WaveClass::privSetupWaveNum(int num)
{
	num--;
	if (num >= (int) wList.centipedeLength.size()) num = wList.centipedeLength.size() - 1;

	if (wList.centipedeLength[num] != -1) CentipedeFactory::setLength(wList.centipedeLength[num]);
	if (wList.centipedeSpeed[num] != -1) CentipedeFactory::setCentiSpeed(wList.centipedeSpeed[num]);
	if (wList.headCount[num] != -1) CentipedeFactory::setHeads(wList.headCount[num]);
	if (wList.headSpeed[num] != -1) CentipedeFactory::setHeadSpeed(wList.headSpeed[num]);

	if (wList.fleaOn[num] != false) FleaFactory::setActive(wList.fleaOn[num]);
	if (wList.numMushFlea[num] != -1) FleaFactory::setSpawn(wList.numMushFlea[num]);

	if (wList.scorpionOn[num] != false) ScorpionFactory::setActive(wList.scorpionOn[num]);
	if (wList.scorpionSpawnRate[num] != -1) ScorpionFactory::setSpawnRate(wList.scorpionSpawnRate[num]);

	if (wList.spiderOn[num] != false) SpiderFactory::setActive(wList.spiderOn[num]);
	if (wList.spiderSpeed[num] != -1) SpiderFactory::setSpeed(wList.spiderSpeed[num]);
	if (wList.spiderSpawnRate[num] != -1) SpiderFactory::setSpawnRate(wList.spiderSpawnRate[num]);
}

void WaveClass::privStopWave()
{
	FleaFactory::setActive(false);
	ScorpionFactory::setActive(false);
	SpiderFactory::setActive(false);
}

void WaveClass::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
