#include "StdAfx.h"
#include "SDL_Setup.h"

CSDL_Setup::CSDL_Setup(bool exit, int p_screenW, int p_screenH)
{
	TTF_Init();
	unitLabel = NULL;
	menuLabel = NULL;
	unitLabelOutline = NULL;
	unitLabel = TTF_OpenFont("trineroksSerious.ttf", 18);
	if (unitLabel == NULL)
		printf("Cannot open font!\n");
	unitLabelOutline = TTF_OpenFont("trineroksSerious.ttf", 18);
	menuLabel = TTF_OpenFont("trineroksSerious.ttf", 20);
	menuOutline = TTF_OpenFont("trineroksSerious.ttf", 20);

	music = NULL;
    
    

	//
	//INFO FOR AUDIO
	//
    
	int audio_rate = 44100;
	Uint16 audio_format = MIX_DEFAULT_FORMAT;
	int audio_channels = 2;
	int audio_buffers = 4096;
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    //SDL_GL_SetAttribute(SDL_GL_RETAINED_BACKING, 1);

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        printf("Cannot initialize SDL!: %s\n", SDL_GetError());
	if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers))
		printf("Cannot open audio!\n");

	Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);

	music = Mix_LoadMUS("RedAlert.mp3");
	if (music == NULL)
		printf("Cannot open sample audio!\n");

	screenW = p_screenW;
	screenH = p_screenH;
	window = NULL;
	//window = SDL_CreateWindow("triN@TE Industries", 0, 0, screenW, screenH, SDL_WINDOW_SHOWN); For Windows
    window = SDL_CreateWindow(NULL, 0, 0, screenW, screenH, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == 0)
        printf("Context could not be set!\n");
    
	renderer = NULL;
    
	//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //For Windows
    renderer = SDL_CreateRenderer(window, -1, 0);

	gameWorld.x = 0;
	gameWorld.y = 0;
	gameWorld.w = screenW;
	gameWorld.h = screenH - ONSCREEN_MENU_HEIGHT;

	onScreenMenu.x = 0;
	onScreenMenu.y = screenH - ONSCREEN_MENU_HEIGHT;
	onScreenMenu.w = screenW;
	onScreenMenu.h = ONSCREEN_MENU_HEIGHT;

	fullscreen.x = 0;
	fullscreen.y = 0;
	fullscreen.w = screenW;
	fullscreen.h = screenH;

	mainevent = new SDL_Event();

	buttons_ = NULL;
	buttons_ = IMG_LoadTexture(renderer, "ButtonSheet.png");
    if (buttons_ == NULL)
        printf("Cannot open spritesheet!\n");

	terrain_ = NULL;
	terrain_ = IMG_LoadTexture(renderer, "TerrainSpriteSheet.png");

	background_ = NULL;
	background_ = IMG_LoadTexture(renderer, "background.png");

	units_ = NULL;
	units_ = IMG_LoadTexture(renderer, "UnitSpriteSheet.png");
}


CSDL_Setup::~CSDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_DestroyTexture(buttons_);
	SDL_DestroyTexture(terrain_);
	SDL_DestroyTexture(units_);

	delete mainevent;
	Mix_FreeMusic(music);
	TTF_CloseFont(unitLabel);
	TTF_CloseFont(unitLabelOutline);
	TTF_CloseFont(menuLabel);
	TTF_Quit();
}

void CSDL_Setup::useGameWorld()
{
	SDL_RenderSetViewport(renderer, &gameWorld);
}

void CSDL_Setup::useOnscreenMenu()
{
	SDL_RenderSetViewport(renderer, &onScreenMenu);
}

void CSDL_Setup::useFullscreen()
{
	SDL_RenderSetViewport(renderer, &fullscreen);
}

void CSDL_Setup::start()
{
	//SDL_PollEvent(mainevent);
	SDL_RenderClear(renderer);
}

void CSDL_Setup::end()
{
	/*
	int texW = 0;
	int texH = 0;
	fontTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
	SDL_Rect test = { 0, 0, texW, texH };
	SDL_RenderCopy(renderer, fontTexture, NULL, &test);
	*/
	SDL_RenderPresent(renderer);
}
