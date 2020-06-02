#include <bangtal.h>
#include <stdio.h>
#include "game.h"


const int G = 1;
const int TPS = 20;


enum class STATE { YELLOW, RED, BLUE, PURPLE };


SceneID scene1, scene2, scene3;
ObjectID button1, button2, button3, button4, button5, button6;
ObjectID player;

TimerID timer;

int x, y;
int y_spped;

bool isStarted = false;

STATE state = STATE::YELLOW;



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

}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
}

void keyboardCallback(int keycode, KeyState state) {
}

void timerCallback(TimerID timer) {
	tick();
}

void map_load(int stage) {
}

int main() {
	setMouseCallback(mouseCallback);
	setKeyboardCallback(keyboardCallback);
	setTimerCallback(timerCallback);

	timer = createTimer(1.f / TPS);


	scene1 = createScene("main", "Images/home_background.png");


	scene2 = createScene("main", "Images/background.png");


	scene3 = createScene("game", "Images/background.png");


	startGame(scene1);
	return 0;
}
