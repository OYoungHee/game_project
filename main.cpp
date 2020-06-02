#include <bangtal.h>
#include <stdio.h>
#include "game.h"


const int G = 1;
const int TPS = 20;


enum class STATE { YELLOW, RED, BLUE, PURPLE };


SceneID scene1, scene2, scene3,scene4;
ObjectID play, exit, back1,back2,back3, blank, home, how_to_play, lock, next, sound, soundx, star, step1, step2, step3,step2x,step3x;
ObjectID player;

TimerID timer;

int x, y;
int y_speed;
int clickedStage;

bool isPlay = false;
bool isStarted = false;
bool issound = true;
bool isclear;
bool isAllStar;
STATE player_state = STATE::YELLOW;

SoundID sound1;


void draw() {
	
}

void tick() {
	draw();
	if (isStarted) {
		setTimer(timer, 1.f / TPS);
		startTimer(timer);
	}
}

void start() {
	if (!isStarted) {
		isStarted = true;
		setTimer(timer, 1.f / TPS);
		startTimer(timer);
	}
}

void end() {
	endGame();
}
void map_load(int stage) {
	if (stage == 1)
	{
		showMessage("1번맵 로드");
	}
	else if (stage == 2)
	{
		showMessage("2번맵 로드");
	}
	else if (stage == 3)
	{
		showMessage("3번맵 로드");
	}
}

void mouseCallback(ObjectID object,int x, int y, MouseAction action) {
	
	if (object == play)
	{
		enterScene(scene2);
	}
	else if (object == exit)
	{
		end();
	}
	else if (object == sound)
	{
		
		if (issound)
		{
			playSound(sound1);
			setObjectImage(sound, "Images/soundx.png");
			issound = false;
		}
		else if (issound == false)
		{
			stopSound(sound1);
			setObjectImage(sound, "Images/sound.png");
			issound = true;
		}
	}
	else if (object == how_to_play)
	{
		enterScene(scene4);
	}
	else if (object == back1)
	{
		enterScene(scene1);
	}
	else if (object == back2)
	{
		enterScene(scene1);
	}
	else if (object == back3)
	{
		enterScene(scene2);
	}
	else if (object == soundx)
	{
		issound = false;
		stopSound(sound1);
		showObject(soundx);
	}
	else if (object == step2x)
	{
		showMessage("1단계를 먼저 클리어 하세요");
	}
	else if (object == step3x)
	{
		showMessage("2단계를 먼저 클리어 하세요");
	}
	else if (object == step1)
	{
		clickedStage = 1;
		enterScene(scene3);
		map_load(clickedStage);
		
	}
	else if (object == step2)
	{
		clickedStage = 2;
		enterScene(scene3);
		map_load(clickedStage);
	}
	else if (object == step3)
	{
		clickedStage = 3;
		enterScene(scene3);
		map_load(clickedStage);
	}

		
}
