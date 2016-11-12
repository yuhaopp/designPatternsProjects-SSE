#ifndef  _Inkmoo_Elimination_h_
#define  _Inkmoo_Elimination_h_

// Define the width and height of the screen
#define GAME_SCREEN_WIDTH 600
#define GAME_SCREEN_HEIGHT 800

// Define every sprite's size and border size
#define SPRITE_WIDTH 48
#define BOADER_WIDTH 2

// the columns and rows of sprites
#define ROWS 8
#define COLS 8

// define amounts of sprites
#define TOTAL_SPRITE 6

// normal sprites
static const char *spriteNormal[TOTAL_SPRITE] = {
	"icon1.png",
	"icon2.png",
	"icon3.png",
	"icon4.png",
	"icon5.png",
	"icon6.png"
};
//player's HP
#define HERO_HP 5

#define TIME 180

#endif