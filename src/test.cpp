#include <stdlib.h>
#include "agl/game.h"
#include "agl/drawer.h"

// ------------ Includes here ---------------
#include <iostream>
#include "agl/sound.h"
#include "agl/music.h"
#include "agl/joystick.h"
#include "agl/vector2.h"
#include "agl/intvector2.h"
#include "agl/gameobject.h"
#include "agl/support.h"
#include "agl/color.h"
#include "agl/text/imagefont.h"
#include "agl/graphics/graphics.h"
// ------------------------------------------

// ------------ Defines here ----------------
// ------------------------------------------

//const string fontPath = "/usr/share/fonts/dejavu/DejaVuSans.ttf";
//const string contentPath = "/home/USER/aleva/test/";
//const string fontPath = "/usr/share/fonts/truetype/freefont/FreeMono.ttf";
//const string contentPath = "/home/USER/test/";

AGL::Game* game = NULL;
AGL::Drawer* drawer = NULL;

// ------------ Declare variables here ------
AGL::Image* imagem = NULL, * imagem2 = NULL, * bg = NULL;
AGL::IntVector2* position;
AGL::Keyboard* kb = NULL;
AGL::Mouse* ms = NULL;
AGL::Font* font = NULL;
AGL::Sound* sound = NULL;
AGL::Music* music = NULL;
AGL::Joystick* joy = NULL;
AGL::GameObject* go = NULL;
// ------------------------------------------


void initialize()
{
	// ------------ Initialize variables here ---
	game = new AGL::Game;
	drawer = new AGL::Drawer;

	game->showMouse(true);
	kb = new AGL::Keyboard(false, false, true, true, false, false);
	ms = new AGL::Mouse;

	position = new AGL::IntVector2(10, 10);

	//font = new AGL::Font(AGL::Format::stringToChar(&(fontPath + "")), 60);
	// ------------------------------------------
}

AGL::ImageFont* ifont;

void loadContent()
{
	// ------------ Load content here -----------
//	ifont = new AGL::ImageFont(
//		new AGL::Image(AGL::Format::stringToChar(&(contentPath + "firstfont.png"))),//"imagefont2.png"))),
//		9,//4,
//		L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ÁÃÀÂÓÕÔÉÊÍÚÜÇáãàâóõôéêíúüç.,!?-");//L"ABCDEFGHIJKLMNOPQRSTUVWXYZ!?,aáÁか");
    ifont = new AGL::ImageFont(new AGL::Image("/home/USER/aleva/test/fixed.png"), 7,
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;!?!?@#$%&*()[]{}<>=+-/\\|_'\"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ifont->setOptions(0, 2, 24);
	imagem = ifont->writeJustified("Ola, isso e um teste! Fonte legal em acao. Vejamos formulas matematicas abaixo:\n"\
"x = 5; a = [y * (x - 2)];\nTambem ha operadores booleanos: p && q, p || q. Testando, testando. Mais linhas e mais linhas e maaaaaais linhas...", 800);

//    wstring longstr = L"A,Áか";
//
//    for(int i = 0; i < longstr.length(); i++) cout << longstr[i] << endl;
//
//    cout << longstr.c_str() << endl;
//
//    cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ!?,aáÁか" << endl;
//    wchar_t ch = 'か';
//    cout << ch << endl;
	// ------------------------------------------
}

void update()
{
	game->update(kb, ms, true);

	//if (game->gameCounter == 60) cout << 60 << " - " << game->cycleTime << endl;
}

void draw()
{
	drawer->clearScreen(AGL_COLOR_BLACK);

	// ------------ Draw objects here -----------
	//ifont->setOptions(10, 10, 50);
	//AGL::Image* imm = ifont->writeJustified(L"Essa é a fonte Firstfont. Esse nome foi dado à ela por ter sido a primeira fonte criada para a AGL-Text e que engloba os principais caracteres da língua portuguesa. Esperamos que essa fonte e principalmente essa biblioteca possa facilitar muito o nosso trabalho, proporcionando uma produção mais rápida dos jogos. Única é esta biblioteca chamada AGL!! Você gostaria de usá-la também?! Ela não custa 12 ou 35 Reais, ela é grátis. Seus caracteres são ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789 ÁÃÀÂÓÕÔÉÊÍÚÜÇ áãàâóõôéêíúüç .,!?-", 750);
	//AGL::Image* imm = ifont->writeBreaking(L"VICTORか ESTÁ, aá, SEM IDEIAS! かか ÁLAMO! VICTORか ESTÁ, aá, SEM IDEIAS! かか ÁLAMO! VICTORか ESTÁ, aá, SEM IDEIAS! かか ÁLAMO! VICTORか ESTÁ, aá, SEM IDEIAS! かか ÁLAMO!", 400);
	//AGL::Image* imm2 = ifont->writeBreaking(L"VICTOR ESTÁ SEM IDEIAS, DO\n QUE FAZER? VAMOS ATRAPALHAR ESSE METODO\nESCULHAMBAR!", 400);
	AGL::IntVector2 v1(0, 0);
	//AGL::IntVector2 v2(0, 100);
	drawer->draw(imagem, v1);
	//drawer->draw(imm2, v2);
	// ------------------------------------------

	drawer->updateScreen();
}

void unloadContent()
{
	// ------------ Unload objects here ---------
	delete ifont, imagem;
	// ------------------------------------------

	game->end();
}

/// Main method, initializes the program
int main(int argc, char *argv[])
{
	initialize();
	loadContent();
    game->runFixedFps(update, draw, 60);
	unloadContent();

	return 0;
}
