/*##########################################################################*/
/*                                                                          */
/* Pacman_091044046.c                                                       */
/* ----------------                                                         */
/* Furkan YAVUZ 091044046 tarafindan yapildi                                */
/*                                                                          */
/* Tanim                                                                    */
/* -----                                                                    */
/*    Pacman_091044046.c pacman oyununun demosu seklinde C programlama      */
/*    diliyle, allegro kutuphanesiyle yazilmis, ubuntu isletim sistemiyle   */
/*    denenmistir.                                                          */
/*																			*/
/*                                                                          */
/* Kaynaklar                                                                */
/* ---------                                                                */
/*    C How to Program Third Edition - Harvey M. Deitel - Paul J. Deitel    */
/*    www.allegro.cc                                                        */
/*    www.ubuntuforums.org                                                  */
/*    www.thepcmanwebsite.com/pcman.shtml                                   */
/*                                                                          */
/*##########################################################################*/

/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/

#include <allegro.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define UP    0
#define LEFT  1
#define DOWN  2
#define RIGHT 3

#define Width  800
#define Height 688

/*--------------------------------------------------------------------------*/
/*                            Function Prototypes                           */
/*--------------------------------------------------------------------------*/

/*###########################################################################*/
/*                                                                           */
/* void respondToKeyboard( void )                                            */
/* ----------------------                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*###########################################################################*/

void respondToKeyboard( void );

/*###########################################################################*/
/*                                                                           */
/* void move( volatile int *man_x, volatile int *man_y, int way )            */
/* ---------                                                                 */
/*                                                                           */
/*      *man_x		- Character's X coordinate 	                             */
/*      *man_y		- Character's Y coordinate 	                             */
/*      way         - Character's direction                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*                                                                           */
/*###########################################################################*/

void move( volatile int *man_x, volatile int *man_y, int way );

/*###########################################################################*/
/*                                                                           */
/* void turn( void )                                                         */
/* ---------                                                                 */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*###########################################################################*/

void turn( void );

/*######################################################################################*/
/*                                                                                      */
/* void findBlinky( void )                                                              */
/* ---------------                                                                      */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/* Return                                                                               */
/* ------                                                                               */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/*                                                                                      */
/*######################################################################################*/

void findBlinky( void );

/*######################################################################################*/
/*                                                                                      */
/* void findPinky( void )                                                               */
/* --------------                                                                       */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/* Return                                                                               */
/* ------                                                                               */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/*                                                                                      */
/*######################################################################################*/

void findPinky( void );

/*######################################################################################*/
/*                                                                                      */
/* void findinky( void )                                                                */
/* -------------                                                                        */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/* Return                                                                               */
/* ------                                                                               */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/*                                                                                      */
/*######################################################################################*/

void findinky( void );

/*######################################################################################*/
/*                                                                                      */
/* void findClyde( void )                                                               */
/* --------------                                                                       */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/* Return                                                                               */
/* ------                                                                               */
/*                                                                                      */
/*     void                                                                             */
/*                                                                                      */
/*                                                                                      */
/*######################################################################################*/

void findClyde( void );

/*###########################################################################*/
/*                                                                           */
/* void featdot( void )                                                      */
/* ------------                                                              */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*                                                                           */
/*###########################################################################*/

void featdot( void );

/*###########################################################################*/
/*                                                                           */
/* void draw( int way )                                                      */
/* ---------                                                                 */
/*                                                                           */
/*      way         - Pacman's direction                                     */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*                                                                           */
/*###########################################################################*/

void draw( int way );

/*######################################################################################*/
/*                                                                                      */
/* int loser( volatile int *man_x, volatile int *man_y, int *way, int *confuse )        */
/* ---------                                                                            */
/*                                                                                      */
/*      *man_x		- Character's X coordinate 	                                        */
/*      *man_y		- Character's Y coordinate 	                                        */
/*      way         - Character's direction                                             */
/*      confuse     - if ghosts confused '1' else '0'                                   */
/*                                                                                      */
/* Return                                                                               */
/* ------                                                                               */
/*                                                                                      */
/*     - 1          - Life is - 1 and game over                                         */
/*                                                                                      */
/*                                                                                      */
/*######################################################################################*/

int loser( volatile int *man_x, volatile int *man_y, volatile int *way, volatile int *confuse );

/*###########################################################################*/
/*                                                                           */
/* void out( volatile int *man_x, volatile int *man_y )                      */
/* ---------                                                                 */
/*                                                                           */
/*      *man_x		- Character's X coordinate 	                             */
/*      *man_y		- Character's Y coordinate	                             */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*                                                                           */
/*###########################################################################*/

void out( volatile int *man_x, volatile int *man_y );

/*###########################################################################*/
/*                                                                           */
/* void end( void )                                                          */
/* --------                                                                  */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/*                                                                           */
/*     void                                                                  */
/*                                                                           */
/*###########################################################################*/

void end( void );


volatile int pac_x;    // Pacman's X coordinate
volatile int pac_y;    // Pacman's Y coordinate

volatile int blinky_x; // Blinky's X coordinate
volatile int blinky_y; // Blinky's Y coordinate

volatile int inky_x;   // inky's X coordinate
volatile int inky_y;   // inky's Y coordinate

volatile int pinky_x;  // Pinky's X coordinate
volatile int pinky_y;  // Pinky's Y coordinate

volatile int clyde_x;  // Clyde's X coordinate
volatile int clyde_y;  // Clyde's Y coordinate

volatile int cherry_x; // Cherry's X coordinate
volatile int cherry_y; // Cherry's Y coordinate

BITMAP *map;              // Map's bitmap
BITMAP *gate;             // Right Teleport gate's bitmap
BITMAP *buffer;           // Buffer
BITMAP *dot;              // Dot's bitmap
BITMAP *pellet;           // Power Pellet's bitmap
BITMAP *cherry;           // Cherry's bitmap

BITMAP *pac;              // Pacman's bitmaps
BITMAP *pacup;            // Pacman's bitmaps
BITMAP *pacdown;          // Pacman's bitmaps
BITMAP *pacleft;          // Pacman's bitmaps
BITMAP *pac2;             // Pacman's bitmaps
BITMAP *pac2up;           // Pacman's bitmaps
BITMAP *pac2down;         // Pacman's bitmaps
BITMAP *pac2left;         // Pacman's bitmaps

BITMAP *blinky;           // Blinky's bitmaps
BITMAP *blinky2;          // Blinky's bitmaps

BITMAP *inky;             // inky's bitmaps
BITMAP *inky2;            // inky's bitmaps

BITMAP *pinky;            // Pinky's bitmaps
BITMAP *pinky2;           // Pinky's bitmaps

BITMAP *clyde;            // Clyde's bitmaps
BITMAP *clyde2;           // Clyde's bitmaps

BITMAP *conf;             // Confused Ghost's bitmaps
BITMAP *conf2;            // Confused Ghost's bitmaps

SAMPLE *enemy;            // Siren sample
SAMPLE *death;            // Pacman death sample
SAMPLE *intermission;     // Animation sample
SAMPLE *start;            // Game Start sample
SAMPLE *extra;            // Extra Life sample
SAMPLE *eatdot;           // Eat Dot sample
SAMPLE *eatghost;         // Eat Ghost sample
SAMPLE *eatcherry;        // Eat Cherry sample
SAMPLE *turnblue;         // Ghost's Confused sample

FONT *pacfont;            // Pacman Game font

// Dots coordinates

volatile int dots[ 2 * 240 ] = { 28,28, 50,28, 72,28, 94,28, 118,28, 140,28, 162,28, 184,28, 207,28, 229,28, 252,28, 274,28, 342,28, 364,28, 386,28, 409,28, 431,28, 454,28, 476,28, 499,28, 522,28, 544,28, 566,28, 589,28,
28,50, 140,50, 274,50, 342,50, 476,50, 589,50,
140,74, 274,74, 342,74, 476,74,
28,97, 140,97, 274,97, 342,97, 476,97, 589,97,
28,123, 50,123, 72,123, 94,123, 118,123, 140,123, 162,123, 184,123, 206,123, 229,123, 252,123, 274,123, 297,123, 319,123, 342,123, 364,123, 386,123, 409,123, 431,123, 454,123, 476,123, 499,123, 522,123, 544,123, 566,123, 589,123,
28,146, 140,146, 206,146, 409,146, 476,146, 589,146,
28,169, 140,169, 206,169, 409,169, 476,169, 589,169,
28,191, 50,191, 72,191, 94,191, 118,191, 140,191, 206,191, 229,191, 252,191, 274,191, 342,191, 364,191, 386,191, 409,191, 476,191, 499,191, 522,191, 544,191, 566,191, 589,191,
140,213, 476,213, 140,234, 476,234, 140,255, 476,255, 140,277, 476,277, 140,299, 476,299, 140,321, 476,321, 140,345, 476,345, 140,368, 476,368, 140,391, 476,391, 140,413, 476,413, 140,435, 476,435,
28,458, 50,458, 72,458, 94,458, 118,458, 140,458, 162,458, 184,458, 206,458, 229,458, 252,458, 274,458, 342,458, 364,458, 386,458, 409,458, 431,458, 454,458, 476,458, 499,458, 522,458, 544,458, 566,458, 589,458,
28,480, 140,480, 274,480, 342,480, 476,480, 589,480,
28,502, 140,502, 274,502, 342,502, 476,502, 589,502,
50,524, 72,524, 140,524, 162,524, 184,524, 207,524, 229,524, 252,524, 274,524, 342,524, 364,524, 386,524, 409,524, 431,524, 454,524, 476,524, 544,524, 566,524,
72,547, 140,547, 206,547, 409,547, 476,547, 544,547,
72,569, 140,569, 206,569, 409,569, 476,569, 544,569,
28,592, 50,592, 72,592, 94,592, 118,592, 140,592, 206,592, 229,592, 252,592, 274,592, 342,592, 364,592, 386,592, 409,592, 476,592, 499,592, 522,592, 544,592, 566,592, 589,592,
28,615, 274,615, 342,615, 589,615,
28,637, 274,637, 342,637, 589,637,
28,660, 50,660, 72,660, 94,660, 118,660, 140,660, 162,660, 184,660, 206,660, 229,660, 252,660, 274,660, 297,660, 319,660, 342,660, 364,660, 386,660, 409,660, 431,660, 454,660, 476,660, 499,660, 522,660, 544,660, 566,660, 589,660 };

// Power Pellets coordinates

volatile int pellets[ 2 * 4 ] = { 28,74, 589,74, 28,524, 589,524 };

// Turn Points coordinates

volatile int ways[ 7 * 64 ] = { 1,0,0,7,2,28,28,  2,0,1,8,3,140,28,  3,0,2,10,0,274,28,  4,0,0,11,5,342,28,  5,0,4,13,6,476,28,  6,0,5,14,0,589,28,
7,1,0,15,8,28,123,  8,2,7,16,9,140,123,  9,0,8,17,10,206,123,  10,3,9,0,11,274,123,  11,4,10,0,12,342,123,  12,0,11,20,13,409,123,  13,5,12,21,14,476,123,  14,6,13,22,0,589,123,
15,7,0,0,16,28,191,  16,8,15,27,0,140,191,  17,9,0,0,18,206,191,  18,0,17,24,0,274,191,  19,0,0,25,20,342,191,  20,12,19,0,0,409,191,  21,13,0,30,22,476,191,  22,14,21,0,0,589,191,
23,0,0,28,24,206,257,  24,18,23,0,25,274,257,  25,19,24,0,26,342,257,  26,0,25,29,0,409,257,
27,16,30,34,28,140,321,  28,23,27,31,0,206,321,  29,26,0,32,30,409,321,  30,21,29,39,27,476,321,
31,28,0,35,32,206,389,  32,29,31,38,0,409,389,
33,0,0,41,34,28,458,  34,27,33,43,35,140,458,  35,31,34,0,36,206,458,  36,0,35,45,0,274,458,  37,0,0,46,38,342,458,  38,32,37,0,39,409,458,  39,30,38,48,40,476,458,  40,0,39,50,0,589,458,
41,33,0,0,42,28,524,  42,0,41,52,0,72,524,  43,34,0,53,44,140,524,  44,0,43,54,45,206,524,  45,36,44,0,46,274,524,  46,37,45,0,47,342,524,  47,0,46,57,48,409,524,  48,39,47,58,0,476,524,  49,0,0,59,50,544,524, 50,40,49,0,0,589,524,
51,0,0,61,52,28,592,  52,42,51,0,53,72,592,  53,43,52,0,0,140,592,  54,44,0,0,55,206,592,  55,0,54,62,0,274,592,  56,0,0,63,57,342,592,  57,47,56,0,0,409,592,  58,48,0,0,59,476,592,  59,49,58,0,60,544,592,  60,0,59,64,0,589,592,
61,51,0,0,62,28,660,  62,55,61,0,63,274,660,  63,56,62,0,64,342,660,  64,60,63,0,0,589,660 };

volatile int take[ 240 ] = { 0 };   // if 'Dot' take, take[ 'Dot' ] = 1

volatile int takeP[ 4 ] = { 0 };    // if 'Power Pellet' take, take[ 'Power Pellet' ] = 1

volatile int takeLife[ 5 ] = { 0 }; // if 'Life' take, take[ 'Life' ] = 1

volatile int takeChr = 1;           // if 'Cherry' take, takeCherry = 1

volatile int score   = 0; // Game Score

volatile int life    = 2; // Pacman's Life

volatile int stage   = 1; // Game Stage

volatile int combo   = 0; // Eat Ghost Combo

volatile int confuseBlinky = 0; // if Blinky confused, confuseBlinky = 1
volatile int confuseinky   = 0; // if inky confused, confuseinky = 1
volatile int confusePinky  = 0; // if Pinky confused, confusePinky = 1
volatile int confuseClyde  = 0; // if Clyde confused, confuseClyde = 1

volatile int homeinky   = 0;    // if inky at home, homeinky = 0
volatile int homePinky  = 0;    // if Pinky at home, homePinky = 0
volatile int homeClyde  = 0;    // if Clyde at home, homeClyde = 0

volatile int wayPacman = RIGHT; // Pacman's way
volatile int wayBlinky = RIGHT; // Blinky's way
volatile int wayinky   = RIGHT; // inky's way
volatile int wayPinky  = LEFT;  // Pinky's way
volatile int wayClyde  = LEFT;  // Clyde's way

volatile int turnPacman = RIGHT; // Pacman's way for next Turn Point

time_t pelletS;     // Power Pellet's taken time
time_t timeStart;   // Game Starting time
time_t timeElapsed; // Elapsed time

/*--------------------------------------------------------------------------*/
/*                         Function Implementations                         */
/*--------------------------------------------------------------------------*/

END_OF_FUNCTION(increment_speed_counter);

int main( void )
{
	allegro_init();

 	install_keyboard();
 	install_timer();
// 	install_int(move, 60);
 	install_sound( DIGI_AUTODETECT, MIDI_NONE, NULL );
 	set_color_depth( 16 );
 	set_gfx_mode( GFX_SAFE, Width, Height, 0, 0 );
    map      = load_bitmap( "map.bmp", NULL );
 	gate     = load_bitmap( "gate.bmp", NULL );
 	dot      = load_bitmap( "dot.bmp", NULL );
 	pellet   = load_bitmap( "pellet.bmp", NULL );
 	cherry   = load_bitmap( "cherry.bmp", NULL );

 	pac      = load_bitmap( "pacman.bmp", NULL );
 	pacup    = load_bitmap( "pacmanup.bmp", NULL );
 	pacdown  = load_bitmap( "pacmandown.bmp", NULL );
 	pacleft  = load_bitmap( "pacmanleft.bmp", NULL );

 	pac2     = load_bitmap( "pacman2.bmp", NULL );
 	pac2up   = load_bitmap( "pacman2up.bmp", NULL );
 	pac2down = load_bitmap( "pacman2down.bmp", NULL );
 	pac2left = load_bitmap( "pacman2left.bmp", NULL );

 	blinky   = load_bitmap( "blinky.bmp", NULL );
 	inky     = load_bitmap( "inky.bmp", NULL );
 	pinky    = load_bitmap( "pinky.bmp", NULL );
 	clyde    = load_bitmap( "clyde.bmp", NULL );
 	conf     = load_bitmap( "conf.bmp", NULL );

 	blinky2  = load_bitmap( "blinky2.bmp", NULL );
 	inky2    = load_bitmap( "inky2.bmp", NULL );
 	pinky2   = load_bitmap( "pinky2.bmp", NULL );
 	clyde2   = load_bitmap( "clyde2.bmp", NULL );
 	conf2    = load_bitmap( "conf2.bmp", NULL );

	enemy        = load_sample( "enemy.wav" );
	death        = load_sample( "death.wav" );
	start        = load_sample( "start.wav" );
	extra        = load_sample( "extra.wav" );
	eatdot       = load_sample( "eatdot.wav" );
	eatghost     = load_sample( "eatghost.wav" );
	eatcherry    = load_sample( "eatcherry.wav" );
	intermission = load_sample( "intermission.wav" );
	turnblue     = load_sample( "turnblue.wav" );

	pacfont = load_font("pacfont.pcx", NULL, NULL);

 	buffer = create_bitmap( SCREEN_W, SCREEN_H );

	pac_x    = 308 - 19;
 	pac_y    = 524 - 19;

 	blinky_x = 308 - 19;
 	blinky_y = 257 - 19;

 	inky_x   = 274 - 19;
 	inky_y   = 321 - 19;

 	pinky_x  = 308 - 19;
 	pinky_y  = 321 - 19;

 	clyde_x  = 342 - 19;
 	clyde_y  = 321 - 19;

	cherry_x = 308 - 19;
	cherry_y = 389 - 19;

	draw( wayPacman );

	play_sample( start, 255, 128, 1000, 0 );

   	rest ( 5000 );

   	play_sample( enemy, 255, 128, 1000, 1 );

 	srand( time( NULL ) );

	timeStart = time( NULL );

 	while ( !key[KEY_ESC] )
 	{
		respondToKeyboard();
        turn();

 	    timeElapsed = time ( NULL );

 	    if( difftime( timeElapsed, pelletS ) == 7 )
 	    {
			stop_sample( turnblue );

			if( confuseBlinky == 1 )
				play_sample( enemy, 255, 128, 1000, 1 );

			confuseBlinky = 0;
			confuseinky   = 0;
			confusePinky  = 0;
			confuseClyde  = 0;
            combo         = 0;
		}

		if( difftime( timeElapsed, timeStart ) >= 5 && homePinky == 0 )
		{
			out( &pinky_x, &pinky_y );

			if( pinky_x == 308 - 19 && pinky_y == 257 - 19 )
				homePinky = 1;
		}

		if( difftime( timeElapsed, timeStart ) >= 10 && homeinky == 0 )
		{
			out( &inky_x, &inky_y );

			if( inky_x == 308 - 19 && inky_y == 257 - 19 )
				homeinky = 1;
		}

 	    if( difftime( timeElapsed, timeStart ) >= 15 && homeClyde == 0 )
 	    {
			out( &clyde_x, &clyde_y );

			if( clyde_x == 308 - 19 && clyde_y == 257 - 19 )
				homeClyde = 1;
		}

 	    if( difftime( timeElapsed, timeStart ) == 18 )
			takeChr = 0;

 	    if( difftime( timeElapsed, timeStart ) == 25 )
			takeChr = 1;

		findBlinky();
		findinky();
		findPinky();
		findClyde();

        if ( loser(	&blinky_x, &blinky_y, &wayBlinky, &confuseBlinky ) == - 1 )
            return 0;

 	    if ( loser( &inky_x, &inky_y, &wayinky, &confuseinky ) == - 1 )
            return 0;

 	    if ( loser( &pinky_x, &pinky_y, &wayPinky, &confusePinky ) == - 1 )
            return 0;

 	    if ( loser( &clyde_x, &clyde_y, &wayClyde, &confuseClyde ) == - 1 )
            return 0;

        move( &pac_x, &pac_y, wayPacman );

 	    if ( loser(	&blinky_x, &blinky_y, &wayBlinky, &confuseBlinky ) == - 1 )
            return 0;

 	    if ( loser( &inky_x, &inky_y, &wayinky, &confuseinky ) == - 1 )
            return 0;

 	    if ( loser( &pinky_x, &pinky_y, &wayPinky, &confusePinky ) == - 1 )
            return 0;

 	    if ( loser( &clyde_x, &clyde_y, &wayClyde, &confuseClyde ) == - 1 )
            return 0;

        move( &blinky_x, &blinky_y, wayBlinky );
        move( &inky_x, &inky_y, wayinky );
        move( &pinky_x, &pinky_y, wayPinky );
        move( &clyde_x, &clyde_y, wayClyde );

        draw( wayPacman );
 	    end();
    }
    return 0;
}
END_OF_MAIN()

/* respondToKeyboard                                                         */
/* -----------------	                                                     */
/*                                                                           */
/*     Klavyeden aldigi  bilgiye göre Pacman'in yonunu degistirir.           */

void respondToKeyboard()
{
     if ( key[KEY_UP] )
		turnPacman = UP;

     if ( key[KEY_DOWN] )
		turnPacman = DOWN;

     if ( key[KEY_LEFT] )
		turnPacman = LEFT;

     if ( key[KEY_RIGHT] )
		turnPacman = RIGHT;
}

/* move                                                                      */
/* ----          		                                                     */
/*                                                                           */
/*     Butun karakterler icin haritaya uygun hareket etmeyi saglar.          */

void move( volatile int *man_x, volatile int *man_y , int way )
{
 	 int ctr = 0;
 	 for( ctr = 0; ctr < 64 * 7; ctr += 7 )
	 {
        if( way == UP )
        {
            if( ways[ ctr + 1 + UP ] != 0 )
            {
                if( *man_x + 19 == ways[ ctr + 5 ] && *man_y + 19 == ways[ ctr + 6 ] )
                {
                    featdot();
                    *man_y -= 1;
                    return;
                }
                if( *man_x + 19 == ways[ ctr + 5 ] && *man_y + 19 < ways[ ctr + 6 ] && *man_y + 19 > ways[ ( ways[ ctr + 1 + UP ] - 1 ) * 7 + 6 ] )
                {
                    featdot();
                    *man_y -= 1;
                    return;
                }
            }
        }
        if( way == DOWN )
        {
            if( ways[ ctr + 1 + DOWN ] != 0 )
            {
                if( *man_x + 19 == ways[ ctr + 5 ] && *man_y + 19 == ways[ ctr + 6 ] )
                {
                    featdot();
                    *man_y += 1;
                    return;
                }
                if( *man_x + 19 == ways[ ctr + 5 ] && *man_y + 19 > ways[ ctr + 6 ] && *man_y + 19 < ways[ ( ways[ ctr + 1 + DOWN ] - 1 ) * 7 + 6 ] )
                {
                    featdot();
                    *man_y += 1;
                    return;
                }
            }
        }
        if( way == LEFT )
        {
            if( ways[ ctr + 1 + LEFT ] != 0 )
            {
                if( *man_x + 19 == ways[ ctr + 5 ] && *man_y + 19 == ways[ ctr + 6 ] )
                {
                    featdot();
                    *man_x -= 1;
                    return;
                }
                if( *man_y + 19 == ways[ ctr + 6 ] && *man_x + 19 < ways[ ctr + 5 ] && *man_x + 19 > ways[ ( ways[ ctr + 1 + LEFT ] - 1 ) * 7 + 5 ] )
                {
                    featdot();
                    *man_x -= 1;
                    return;
                }
            }

        }
        if( way == RIGHT )
        {
            if( ways[ ctr + 1 + RIGHT ] != 0 )
            {
                if( *man_x + 19 == ways[ ctr + 5 ] && *man_y + 19 == ways[ ctr + 6 ] )
                {
                    featdot();
                    *man_x += 1;
                    return;
                }
                if( *man_y + 19 == ways[ ctr + 6 ] && *man_x + 19 > ways[ ctr + 5 ] && *man_x + 19 < ways[ ( ways[ ctr + 1 + RIGHT ] - 1 ) * 7 + 5 ] )
                {
                    featdot();
                    *man_x += 1;
                    return;
                }
            }
        }
    }
    // Özel durum : Soldaki geçiþ bölgesi için
    if( way == LEFT )
    {
        if( *man_y + 19 == ways[ 26 * 7 + 6 ] && *man_x + 19 < ways[ 26 * 7 + 5 ] && *man_x + 38 > - 1 )
            *man_x -= 1;
        if( *man_y + 19 == ways[ 29 * 7 + 6 ] && *man_x + 19 > ways[ 29 * 7 + 5 ] && *man_x < 617 )
            *man_x -= 1;
        if( *man_x == -39 )
            *man_x = 616;
    }
    // Özel durum : Saðdaki geçiþ bölgesi için
    if( way == RIGHT )
    {
        if( *man_y + 19 == ways[ 29 * 7 + 6 ] && *man_x + 19 > ways[ 29 * 7 + 5 ] && *man_x < 617 )
            *man_x += 1;
        if( *man_y + 19 == ways[ 26 * 7 + 6 ] && *man_x + 19 < ways[ 26 * 7 + 5 ] && *man_x + 38 > - 1 )
            *man_x += 1;
        if( *man_x == 617 )
            *man_x = -38;
    }
}

/* turn                                                                      */
/* ----          		                                                     */
/*                                                                           */
/*     Klavyeden girilen yönü aktif yön yapmak icin kullanilan fonksiyon.    */

void turn( void )
{
	int ctr = 0;
	for( ctr = 0; ctr < 64 * 7; ctr += 7 )
	{
         if( pac_x + 19 == ways[ ctr + 5 ] && pac_y + 19 == ways[ ctr + 6 ] )
         {
             if( turnPacman == LEFT && ways[ ctr + 1 + LEFT ] != 0 )
                wayPacman = turnPacman;

             if( turnPacman == DOWN && ways[ ctr + 1 + DOWN ] != 0 )
				wayPacman = turnPacman;

             if( turnPacman == RIGHT && ways[ ctr + 1 + RIGHT ] != 0 )
				wayPacman = turnPacman;

             if( turnPacman == UP && ways[ ctr + 1 + UP ] != 0 )
				wayPacman = turnPacman;
        }
		else
		{
			if( wayPacman == UP && turnPacman == DOWN )
				wayPacman = turnPacman;

			if( wayPacman == DOWN  && turnPacman == UP )
				wayPacman = turnPacman;

			if( wayPacman == LEFT  && turnPacman == RIGHT )
				wayPacman = turnPacman;

			if( wayPacman == RIGHT  && turnPacman == LEFT )
				wayPacman = turnPacman;
		}
	}
}

/* findBlinky                                                                */
/* ----------      		                                                     */
/*                                                                           */
/*     Eger Blinky'nin kafasi karismamis ise Pacman'i takip etmesini,        */
/*     karismis ise rastlantisal olarak hareket etmesini saglar.             */

void findBlinky( void )
{
 	 int ctr    = 0;
 	 int turn   = 0;
	 int target = 0;
 	 int total  = 1000000000;

 	 if( confuseBlinky == 0 )
 	 {
		 for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		 {
			 if( blinky_x + 19 == ways[ ctr + 5 ] && blinky_y + 19 == ways[ ctr + 6 ] )
			 {
				if( ways[ ctr + 1 + UP ] != 0 && wayBlinky != DOWN )
				{
					if( pow( ( pac_x - blinky_x ), 2 ) + pow( ( pac_y - ( blinky_y - 1 ) ), 2 ) < total )
					{
						total = pow( ( pac_x - blinky_x ), 2 ) + pow( ( pac_y - ( blinky_y - 1 ) ), 2 );
						turn = UP;
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayBlinky != UP )
				{
					if( pow( ( pac_x - blinky_x ), 2 ) + pow( ( pac_y - ( blinky_y + 1 ) ), 2 ) < total )
					{
						total = pow( ( pac_x - blinky_x ), 2 ) + pow( ( pac_y - ( blinky_y + 1 ) ), 2 );
						turn = DOWN;
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayBlinky != RIGHT )
				{
					if( pow( ( pac_x - ( blinky_x - 1 ) ), 2 ) + pow( ( pac_y - blinky_y ), 2 ) < total )
					{
						total = pow( ( pac_x - ( blinky_x - 1 ) ), 2 ) + pow( ( pac_y - blinky_y ), 2 );
						turn = LEFT;
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayBlinky != LEFT )
				{
					if( pow( ( pac_x - ( blinky_x + 1 ) ), 2 ) + pow( ( pac_y - blinky_y ), 2 ) < total )
					{
						total = pow( ( pac_x - ( blinky_x + 1 ) ), 2 ) + pow( ( pac_y - blinky_y ), 2 );
						turn = RIGHT;
					}
				}
				wayBlinky = turn;
			}
		}
	}
	else
	{
		for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		{
			 if( blinky_x + 19 == ways[ ctr + 5 ] && blinky_y + 19 == ways[ ctr + 6 ] )
			 {
				target = time( NULL ) % 64;

				if( ways[ ctr + 1 + UP ] != 0 && wayBlinky != DOWN )
				{
					if( pow( ( ways[ target * 7 + 5 ] - blinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( blinky_y - 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - blinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( blinky_y - 1 ) ), 2 );
						turn = UP;
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayBlinky != UP )
				{
					if( pow( ( ways[ target * 7 + 5 ] - blinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( blinky_y + 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - blinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( blinky_y + 1 ) ), 2 );
						turn = DOWN;
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayBlinky != RIGHT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( blinky_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - blinky_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( blinky_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - blinky_y ), 2 );
						turn = LEFT;
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayBlinky != LEFT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( blinky_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - blinky_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( blinky_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - blinky_y ), 2 );
						turn = RIGHT;
					}
				}
				wayBlinky = turn;
			}
		}
	}
}

/* findPinky                                                                 */
/* ---------      		                                                     */
/*                                                                           */
/*     Eger Pinky'nin kafasi karismamis ise Pacman'in 74 px ilerisini takip  */
/*     etmesini, karismis ise rastlantisal olarak hareket etmesini saglar.   */

void findPinky( void )
{
 	 int ctr    = 0;
 	 int turn   = 0;
	 int target = 0;
 	 int total  = 1000000000;

 	if( confusePinky == 0 )
 	{
		for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		{
			if( pinky_x + 19 == ways[ ctr + 5 ] && pinky_y + 19 == ways[ ctr + 6 ] )
			{
				if( ways[ ctr + 1 + UP ] != 0 && wayPinky != DOWN )
				{
					if( wayPacman == UP )
					{
						if( pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y - 74 - ( pinky_y - 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y - 74 - ( pinky_y - 1 ) ), 2 );
							turn = UP;
						}
					}

					if( wayPacman == LEFT )
					{
						if( pow( ( pac_x - 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y - 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y - 1 ) ), 2 );
							turn = UP;
						}
					}

					if( wayPacman == DOWN )
					{
						if( pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y + 74 - ( pinky_y - 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y + 74 - ( pinky_y - 1 ) ), 2 );
							turn = UP;
						}
					}

					if( wayPacman == RIGHT )
					{
						if( pow( ( pac_x + 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y - 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x + 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y - 1 ) ), 2 );
							turn = UP;
						}
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayPinky != UP )
				{
					if( wayPacman == UP )
					{
						if( pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y - 74 - ( pinky_y + 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y - 74 - ( pinky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}

					if( wayPacman == LEFT )
					{
						if( pow( ( pac_x - 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y + 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}

					if( wayPacman == DOWN )
					{
						if( pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y + 74 - ( pinky_y + 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - pinky_x ), 2 ) + pow( ( pac_y + 74 - ( pinky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}

					if( wayPacman == RIGHT )
					{
						if( pow( ( pac_x + 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y + 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x + 74 - pinky_x ), 2 ) + pow( ( pac_y - ( pinky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayPinky != RIGHT )
				{
					if( wayPacman == UP )
					{
						if( pow( ( pac_x - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y - 74 - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y - 74 - pinky_y ), 2 );
							turn = LEFT;
						}
					}

					if( wayPacman == LEFT )
					{
						if( pow( ( pac_x - 74 - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x - 74 - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 );
							turn = LEFT;
						}
					}

					if( wayPacman == DOWN )
					{
						if( pow( ( pac_x - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y + 74 - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y + 74 - pinky_y ), 2 );
							turn = LEFT;
						}
					}

					if( wayPacman == RIGHT )
					{
						if( pow( ( pac_x + 74 - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x + 74 - ( pinky_x - 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 );
							turn = LEFT;
						}
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayPinky != LEFT )
				{
					if( wayPacman == UP )
					{
						if( pow( ( pac_x - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y - 74 - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y - 74 - pinky_y ), 2 );
							turn = RIGHT;
						}
					}

					if( wayPacman == LEFT )
					{
						if( pow( ( pac_x - 74 - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x - 74 - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 );
							turn = RIGHT;
						}
					}

					if( wayPacman == DOWN )
					{
						if( pow( ( pac_x - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y + 74 - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y + 74 - pinky_y ), 2 );
							turn = RIGHT;
						}
					}

					if( wayPacman == RIGHT )
					{
						if( pow( ( pac_x + 74 - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 ) < total )
						{
							total = pow( ( pac_x + 74 - ( pinky_x + 1 ) ), 2 ) + pow( ( pac_y - pinky_y ), 2 );
							turn = RIGHT;
						}
					}
				}
				wayPinky = turn;
			}
		}
	}
	else
	{
		for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		{
			 if( pinky_x + 19 == ways[ ctr + 5 ] && pinky_y + 19 == ways[ ctr + 6 ] )
			 {
				target = time( NULL ) % 64;

				if( ways[ ctr + 1 + UP ] != 0 && wayPinky != DOWN )
				{
					if( pow( ( ways[ target * 7 + 5 ] - pinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( pinky_y - 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - pinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( pinky_y - 1 ) ), 2 );
						turn = UP;
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayPinky != UP )
				{
					if( pow( ( ways[ target * 7 + 5 ] - pinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( pinky_y + 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - pinky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( pinky_y + 1 ) ), 2 );
						turn = DOWN;
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayPinky != RIGHT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( pinky_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - pinky_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( pinky_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - pinky_y ), 2 );
						turn = LEFT;
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayPinky != LEFT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( pinky_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - pinky_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( pinky_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - pinky_y ), 2 );
						turn = RIGHT;
					}
				}
				wayPinky = turn;
			}
		}
	}
}

/* findinky                                                                  */
/* --------      		                                                     */
/*                                                                           */
/*     Eger inky'nin kafasi karismamis ise Blinky'den Pacman'e cizilen       */
/*     cizginin iki kati daha cizilerek bulunan noktayi takip etmesini       */
/*     karismis ise rastlantisal olarak hareket etmesini saglar.             */

void findinky( void )
{
 	 int ctr    = 0;
 	 int turn   = 0;
	 int target = 0;
 	 int total  = 1000000000;

 	 if( confuseinky == 0 )
 	 {
		 for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		 {
			 if( inky_x + 19 == ways[ ctr + 5 ] && inky_y + 19 == ways[ ctr + 6 ] )
			 {
				if( ways[ ctr + 1 + UP ] != 0 && wayinky != DOWN )
				{
					if( blinky_x < pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y - 1 ) ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y - 1 ) ), 2 );
							turn = UP;
						}
					}
					if( blinky_x > pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y - 1 ) ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y - 1 ) ), 2 );
							turn = UP;
						}
					}
					if( blinky_x < pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y - 1 ) ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y - 1 ) ), 2 );
							turn = UP;
						}
					}
					if( blinky_x > pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y - 1 ) ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y - 1 ) ), 2 );
							turn = UP;
						}
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayinky != UP )
				{
					if( blinky_x < pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y + 1 ) ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
					if( blinky_x > pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y + 1 ) ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - ( inky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
					if( blinky_x < pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y + 1 ) ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
					if( blinky_x > pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y + 1 ) ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - inky_x, 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - ( inky_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayinky != RIGHT )
				{
					if( blinky_x < pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - ( inky_x - 1 ), 2 ) + pow( pac_y + ( pac_y - blinky_y ) - inky_y, 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 );
							turn = LEFT;
						}
					}
					if( blinky_x > pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 );
							turn = LEFT;
						}
					}
					if( blinky_x < pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 );
							turn = LEFT;
						}
					}
					if( blinky_x > pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - ( inky_x - 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 );
							turn = LEFT;
						}
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayinky != LEFT )
				{
					if( blinky_x < pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 );
							turn = RIGHT;
						}
					}
					if( blinky_x > pac_x && blinky_y < pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y + ( pac_y - blinky_y ) - inky_y ), 2 );
							turn = RIGHT;
						}
					}
					if( blinky_x < pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x + ( pac_x - blinky_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x + ( pac_x - blinky_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 );
							turn = RIGHT;
						}
					}
					if( blinky_x > pac_x && blinky_y > pac_y )
					{
						if( pow( pac_x - ( blinky_x - pac_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 ) < total )
						{
							total = pow( pac_x - ( blinky_x - pac_x ) - ( inky_x + 1 ), 2 ) + pow( ( pac_y - ( blinky_y - pac_y ) - inky_y ), 2 );
							turn = RIGHT;
						}
					}
				}
				wayinky = turn;
			}
		}
	}
	else
	{
		for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		{
			 if( inky_x + 19 == ways[ ctr + 5 ] && inky_y + 19 == ways[ ctr + 6 ] )
			 {
				target = time( NULL ) % 64;

				if( ways[ ctr + 1 + UP ] != 0 && wayinky != DOWN )
				{
					if( pow( ( ways[ target * 7 + 5 ] - inky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( inky_y - 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - inky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( inky_y - 1 ) ), 2 );
						turn = UP;
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayinky != UP )
				{
					if( pow( ( ways[ target * 7 + 5 ] - inky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( inky_y + 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - inky_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( inky_y + 1 ) ), 2 );
						turn = DOWN;
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayinky != RIGHT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( inky_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - inky_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( inky_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - inky_y ), 2 );
						turn = LEFT;
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayinky != LEFT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( inky_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - inky_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( inky_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - inky_y ), 2 );
						turn = RIGHT;
					}
				}
				wayinky = turn;
			}
		}
	}
}

/* findClyde                                                                 */
/* ---------       		                                                     */
/*                                                                           */
/*     Eger Clyde'nin kafasi karismamis ise Pacman'in 8 kare cevresine       */
/*     gelene kadar Pacman'i takip etmesini, 8 kare icerisindeyse sol alt    */
/*     koseye gitmesini, Clyde'nin kafasi karismissa rastlantisal olarak     */
/*     hareket etmesini saglar.                                              */

void findClyde( void )
{
 	 int ctr    = 0;
 	 int turn   = 0;
	 int target = 0;
 	 int total  = 1000000000;

 	 if( confuseClyde == 0 )
 	 {
		 for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		 {
			 if( clyde_x + 19 == ways[ ctr + 5 ] && clyde_y + 19 == ways[ ctr + 6 ] )
			 {
				if( ways[ ctr + 1 + UP ] != 0 && wayClyde != DOWN )
				{
					if( pow( clyde_x - pac_x, 2 ) < 148 * 148 )
					{
						if( pow( ( 28 - clyde_x ), 2 ) + pow( ( 660 - ( clyde_y - 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - clyde_x ), 2 ) + pow( ( pac_y - ( clyde_y - 1 ) ), 2 );
							turn = UP;
						}
					}
					else
					{
						if( pow( ( pac_x - clyde_x ), 2 ) + pow( ( pac_y - ( clyde_y - 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - clyde_x ), 2 ) + pow( ( pac_y - ( clyde_y - 1 ) ), 2 );
							turn = UP;
						}
					}

				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayClyde != UP )
				{
					if( pow( clyde_x - pac_x, 2 ) < 148 * 148 )
					{
						if( pow( ( 28 - clyde_x ), 2 ) + pow( ( 660 - ( clyde_y + 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - clyde_x ), 2 ) + pow( ( pac_y - ( clyde_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
					else
					{
						if( pow( ( pac_x - clyde_x ), 2 ) + pow( ( pac_y - ( clyde_y + 1 ) ), 2 ) < total )
						{
							total = pow( ( pac_x - clyde_x ), 2 ) + pow( ( pac_y - ( clyde_y + 1 ) ), 2 );
							turn = DOWN;
						}
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayClyde != RIGHT )
				{
					if( pow( clyde_x - pac_x, 2 ) < 148 * 148 )
					{
						if( pow( ( 28 - ( clyde_x - 1 ) ), 2 ) + pow( ( 660 - clyde_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( clyde_x - 1 ) ), 2 ) + pow( ( pac_y - clyde_y ), 2 );
							turn = LEFT;
						}
					}
					else
					{
						if( pow( ( pac_x - ( clyde_x - 1 ) ), 2 ) + pow( ( pac_y - clyde_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( clyde_x - 1 ) ), 2 ) + pow( ( pac_y - clyde_y ), 2 );
							turn = LEFT;
						}
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayClyde != LEFT )
				{
					if( pow( clyde_x - pac_x, 2 ) < 148 * 148 )
					{
						if( pow( ( 28 - ( clyde_x + 1 ) ), 2 ) + pow( ( 660 - clyde_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( clyde_x + 1 ) ), 2 ) + pow( ( pac_y - clyde_y ), 2 );
							turn = RIGHT;
						}
					}
					else
					{
						if( pow( ( pac_x - ( clyde_x + 1 ) ), 2 ) + pow( ( pac_y - clyde_y ), 2 ) < total )
						{
							total = pow( ( pac_x - ( clyde_x + 1 ) ), 2 ) + pow( ( pac_y - clyde_y ), 2 );
							turn = RIGHT;
						}
					}
				}
				wayClyde = turn;
			}
		}
	}
	else
	{
		for( ctr = 0; ctr < 64 * 7; ctr += 7 )
		{
			 if( clyde_x + 19 == ways[ ctr + 5 ] && clyde_y + 19 == ways[ ctr + 6 ] )
			 {
				target = time( NULL ) % 64;

				if( ways[ ctr + 1 + UP ] != 0 && wayClyde != DOWN )
				{
					if( pow( ( ways[ target * 7 + 5 ] - clyde_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( clyde_y - 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - clyde_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( clyde_y - 1 ) ), 2 );
						turn = UP;
					}
				}
				if( ways[ ctr + 1 + DOWN ] != 0 && wayClyde != UP )
				{
					if( pow( ( ways[ target * 7 + 5 ] - clyde_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( clyde_y + 1 ) ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - clyde_x ), 2 ) + pow( ( ways[ target * 7 + 6 ] - ( clyde_y + 1 ) ), 2 );
						turn = DOWN;
					}
				}
				if( ways[ ctr + 1 + LEFT ] != 0 && wayClyde != RIGHT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( clyde_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - clyde_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( clyde_x - 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - clyde_y ), 2 );
						turn = LEFT;
					}
				}
				if( ways[ ctr + 1 + RIGHT ] != 0 && wayClyde != LEFT )
				{
					if( pow( ( ways[ target * 7 + 5 ] - ( clyde_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - clyde_y ), 2 ) < total )
					{
						total = pow( ( ways[ target * 7 + 5 ] - ( clyde_x + 1 ) ), 2 ) + pow( ( ways[ target * 7 + 6 ] - clyde_y ), 2 );
						turn = RIGHT;
					}
				}
				wayClyde = turn;
			}
		}
	}
}

/* featdot                                                                   */
/* -------                                                                   */
/*                                                                           */
/*     Haritadaki noktalar, power pelletler ve meyvenin alinmasi ve puan     */
/*     10000'in katlari oldugu zaman can artmasi olaylarini yapar.           */

void featdot( void )
{
    int ctr = 0;
    for( ctr = 0; ctr < 240; ++ctr )
    {
        if( pac_x + 19 == dots[ 2 * ctr ] && pac_y + 19 == dots[ 2 * ctr + 1 ] )
        {
            if( take[ ctr ] != 1 )
            {
                take[ ctr ] = 1;
                score += 10;
                play_sample( eatdot, 255, 128, 1100, 0 );
            }
        }
    }
    for( ctr = 0; ctr < 4; ++ctr )
    {
        if( pac_x + 19 == pellets[ 2 * ctr ] && pac_y + 19 == pellets[ 2 * ctr + 1 ] )
        {
            if( takeP[ ctr ] != 1 )
            {
                takeP[ ctr ] = 1;
                score += 50;

				stop_sample( enemy );

                play_sample( eatdot, 255, 128, 1100, 0 );
                play_sample( turnblue, 255, 128, 1100, 1 );

                confuseBlinky = 1;
                confuseinky = 1;
                confusePinky = 1;
                confuseClyde = 1;

                pelletS = time( NULL );
                wayBlinky += 2;
                wayBlinky = wayBlinky % 4;

                wayinky += 2;
                wayinky = wayinky % 4;

                wayPinky += 2;
                wayPinky = wayPinky % 4;

                wayClyde += 2;
                wayClyde = wayClyde % 4;
            }
        }
    }
    for( ctr = 1; ctr < 6; ++ctr )
    {
        if( score >= 10000 * ctr && score < 10000 * ctr + 10000 && takeLife[ ctr ] == 0 )
        {
            ++life;
            takeLife[ ctr ] = 1;
            play_sample( extra, 255, 128, 1000, 0 );
        }
    }

    if( pac_x == cherry_x && pac_y == cherry_y )
	{
        if( takeChr != 1 )
        {
			takeChr = 1;
			score += 100;
			play_sample( eatcherry, 255, 128, 1100, 0 );
		}
	}
}

/* draw                                                                      */
/* ----                                                                      */
/*                                                                           */
/*     Ekrandaki tum cizim olaylarini yapar.                                 */

void draw( volatile int way )
{
    int ctr = 0;
    int lifeCtr = life;

    clear_to_color( buffer, makecol( 0, 0, 0 ) );
	blit( map, buffer, 0, 0, 0, 0, map->w, map->h );

	for( lifeCtr = life; lifeCtr > 0; --lifeCtr )
	{
        masked_blit( pac, buffer, 0, 0, SCREEN_W - 180 + lifeCtr * 45, 550, pac->w, pac->h );
    }

	for( ctr = 0; ctr < 240; ++ctr )
	{
        if( take[ ctr ] == 0 )
            masked_blit( dot, buffer, 0, 0, dots[ 2 * ctr ] - 4, dots[ 2 * ctr + 1 ] - 4, dot->w, dot->h );
    }
   	for( ctr = 0; ctr < 4; ++ctr )
    {
        if( takeP[ ctr ] == 0 )
            masked_blit( pellet, buffer, 0, 0, pellets[ 2 * ctr ] - 10, pellets[ 2 * ctr + 1 ] - 10, pellet->w, pellet->h );
    }

    if( takeChr == 0 )
		masked_blit( cherry, buffer, 0, 0, cherry_x, cherry_y, cherry->w, cherry->h );

    if( way == UP )
        masked_blit( pac2up, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( way == DOWN )
        masked_blit( pac2down, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( way == LEFT )
        masked_blit( pac2left, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( way == RIGHT )
        masked_blit( pac2, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( confuseBlinky == 0 )
    {
        masked_blit( blinky, buffer, 0, 0, blinky_x, blinky_y, blinky->w, blinky->h );
	}
    else
    {
        masked_blit( conf, buffer, 0, 0, blinky_x, blinky_y, blinky->w, blinky->h );
	}

    if( confuseinky == 0 )
    {
        masked_blit( inky, buffer, 0, 0, inky_x, inky_y, inky->w, inky->h );
	}
    else
    {
        masked_blit( conf, buffer, 0, 0, inky_x, inky_y, inky->w, inky->h );
	}

    if( confusePinky == 0 )
    {
  	    masked_blit( pinky, buffer, 0, 0, pinky_x, pinky_y, pinky->w, pinky->h );
	}
    else
    {
        masked_blit( conf, buffer, 0, 0, pinky_x, pinky_y, pinky->w, pinky->h );
	}

    if( confuseClyde == 0 )
    {
        masked_blit( clyde, buffer, 0, 0, clyde_x, clyde_y, clyde->w, clyde->h );
	}
    else
    {
        masked_blit( conf, buffer, 0, 0, clyde_x, clyde_y, clyde->w, clyde->h );
	}

    textprintf_ex(buffer, pacfont, SCREEN_W - 140, 25, makecol(253, 253, 253), -1, "Game Score");
	textprintf_ex(buffer, pacfont, SCREEN_W - 100, 50, makecol(253, 253, 253), -1, "%d", score );
	textprintf_ex(buffer, pacfont, SCREEN_W - 120, 500, makecol(253, 253, 253), -1, "%d Up", life );
    textprintf_ex(buffer, pacfont, SCREEN_W - 140, SCREEN_H - 50, makecol(253, 253, 253), -1, "Furkan Yavuz");
    textprintf_ex(buffer, pacfont, SCREEN_W - 125, SCREEN_H - 25, makecol(253, 253, 253), -1, "091044046");

    blit( gate, buffer, 0, 0, 617, 321 - 19, gate->w, gate->h );
	blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );

    clear_to_color( buffer, makecol( 0, 0, 0 ) );
	blit( map, buffer, 0, 0, 0, 0, map->w, map->h );

	for( lifeCtr = life; lifeCtr > 0; --lifeCtr )
        masked_blit( pac, buffer, 0, 0, SCREEN_W - 180 + lifeCtr * 45, 550, pac->w, pac->h );

	for( ctr = 0; ctr < 240; ++ctr )
	{
        if( take[ ctr ] == 0 )
            masked_blit( dot, buffer, 0, 0, dots[ 2 * ctr ] - 4, dots[ 2 * ctr + 1 ] - 4, dot->w, dot->h );
    }
   	for( ctr = 0; ctr < 4; ++ctr )
    {
        if( takeP[ ctr ] == 0 )
            masked_blit( pellet, buffer, 0, 0, pellets[ 2 * ctr ] - 10, pellets[ 2 * ctr + 1 ] - 10, pellet->w, pellet->h );
    }

    if( takeChr == 0 )
		masked_blit( cherry, buffer, 0, 0, cherry_x, cherry_y, cherry->w, cherry->h );

    if( way == UP )
        masked_blit( pacup, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( way == DOWN )
        masked_blit( pacdown, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( way == LEFT )
        masked_blit( pacleft, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( way == RIGHT )
        masked_blit( pac, buffer, 0, 0, pac_x, pac_y, pac->w, pac->h );

    if( confuseBlinky == 0 )
    {
        masked_blit( blinky2, buffer, 0, 0, blinky_x, blinky_y, blinky->w, blinky->h );
	}
    else
    {
        masked_blit( conf2, buffer, 0, 0, blinky_x, blinky_y, blinky->w, blinky->h );
	}

    if( confuseinky == 0 )
    {
        masked_blit( inky2, buffer, 0, 0, inky_x, inky_y, inky->w, inky->h );
	}
    else
    {
        masked_blit( conf2, buffer, 0, 0, inky_x, inky_y, inky->w, inky->h );
	}

    if( confusePinky == 0 )
    {
  	    masked_blit( pinky2, buffer, 0, 0, pinky_x, pinky_y, pinky->w, pinky->h );
	}
    else
    {
        masked_blit( conf2, buffer, 0, 0, pinky_x, pinky_y, pinky->w, pinky->h );
	}

    if( confuseClyde == 0 )
    {
        masked_blit( clyde2, buffer, 0, 0, clyde_x, clyde_y, clyde->w, clyde->h );
	}
    else
    {
        masked_blit( conf2, buffer, 0, 0, clyde_x, clyde_y, clyde->w, clyde->h );
	}

    textprintf_ex(buffer, pacfont, SCREEN_W - 140, 25, makecol(253, 253, 253), -1, "Game Score");
	textprintf_ex(buffer, pacfont, SCREEN_W - 100, 50, makecol(253, 253, 253), -1, "%d", score );
	textprintf_ex(buffer, pacfont, SCREEN_W - 120, 500, makecol(253, 253, 253), -1, "%d Up", life );
    textprintf_ex(buffer, pacfont, SCREEN_W - 140, SCREEN_H - 50, makecol(253, 253, 253), -1, "Furkan Yavuz");
    textprintf_ex(buffer, pacfont, SCREEN_W - 125, SCREEN_H - 25, makecol(253, 253, 253), -1, "091044046");

    blit( gate, buffer, 0, 0, 617, 321 - 19, gate->w, gate->h );
	blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );
}

/* loser                                                                     */
/* -----                                                                     */
/*                                                                           */
/*     Pacman ve hayaletler ayni nokta uzerine geldiginde eger hayaletlerin  */
/*     kafalari karisiksa Pacman yer, degilse Pacman'in bir cani gider ve    */
/*     butun karakterler baslangic noktalarina doner.                        */

int loser( volatile int *man_x, volatile int *man_y, volatile int *way, volatile int *confuse )
{
    // Hayaletler tarafýndan yakalanma durumu
    if( *confuse == 0 )
    {
        if( ( *man_x == pac_x && *man_y == pac_y ) )
        {
			stop_sample( turnblue );
            stop_sample( enemy );

			pac_x    = 308 - 19;
			pac_y    = 524 - 19;

			blinky_x = 308 - 19;
			blinky_y = 257 - 19;

			inky_x   = 274 - 19;
			inky_y   = 321 - 19;

			pinky_x  = 308 - 19;
			pinky_y  = 321 - 19;

			clyde_x  = 342 - 19;
			clyde_y  = 321 - 19;

			wayPacman  = RIGHT;
			wayBlinky  = RIGHT;
			wayinky    = RIGHT;
			wayPinky   = LEFT;
			wayClyde   = LEFT;

			turnPacman = RIGHT;

			homeinky   = 0;
			homePinky  = 0;
			homeClyde  = 0;

            --life;

            play_sample( death, 255, 128, 1000, 0 );

            if( life == -1 )
            {
                textprintf_ex(screen, pacfont, SCREEN_W / 2 - 137 , 389 - 9, makecol(253, 253, 253), -1, "Game Over");
                rest( 4000 );
                return - 1;
            }

            rest( 2000 );

			timeStart = time( NULL );
			takeChr = 1;
			confuseBlinky = 0;
			confuseinky   = 0;
			confusePinky  = 0;
			confuseClyde  = 0;

            play_sample( enemy, 255, 128, 1000, 0 );
        }
    }
    else
    {    // Hayaletleri yakalama durumu
        if( ( *man_x == pac_x && *man_y == pac_y ) )
        {
			*confuse = 0;

			switch ( combo )
			{
				case 0:
					score += 200;
					break;

				case 1:
					score += 400;
					break;

				case 2:
					score += 800;
					break;

				case 3:
					score += 1600;
					break;

				case 4:
					combo = 0;
					score += 200;
					break;

				default:
					break;
			}
			++combo;
            play_sample( eatghost, 255, 128, 1000, 0 );
			*man_x = 308 - 19;
			*man_y = 257 - 19;
            *way   = RIGHT;
        }
    }
    return 0;
}

/* out                                                                       */
/* ---                                                                       */
/*                                                                           */
/*     Hayaletler icin evi terk etme durumunu duzenler.                      */

void out( volatile int *man_x, volatile int *man_y )
{
	if( *man_x < 308 - 19 )
		++*man_x;

	if( *man_x > 308 - 19 )
		--*man_x;

	if( *man_y > 257 - 19 && *man_x == 308 - 19 )
		--*man_y;
}


/* end                                                                       */
/* ---                                                                       */
/*                                                                           */
/*     Eger bütün noktalar alinmis ise yeni bölüme geçis.                    */

void end( void )
{
	int fin = 1;
	int ctr = 0;

    for( ctr = 0; ctr < 240; ++ctr )
    {
		if( take[ ctr ] == 0 )
			fin = 0;
	}

    for( ctr = 0; ctr < 4; ++ctr )
    {
		if( takeP[ ctr ] == 0 )
			fin = 0;
	}

    if( key[KEY_F] )
		fin = 1;

	if( fin == 1 )
	{
		stop_sample( turnblue );
		stop_sample( enemy );
		clear_to_color( buffer, makecol( 0, 0, 0 ) );
		play_sample( intermission, 255, 128, 1000, 1 );

		pac_x = - 100;
		pac_y = SCREEN_H / 2 - 19;

		blinky_x = -200;
		blinky_y = SCREEN_H / 2 - 19;

		inky_x = -250;
		inky_y = SCREEN_H / 2 - 19;

		pinky_x = -300;
		pinky_y = SCREEN_H / 2 - 19;

		clyde_x = -350;
		clyde_y = SCREEN_H / 2 - 19;

		int ctr = 0;
		while( pac_x != 1500 )
		{
			masked_blit( pac, buffer, 0, 0, pac_x, pac_y, pacleft->w, pacleft->h );
			masked_blit( blinky, buffer, 0, 0, blinky_x, blinky_y, blinky->w, blinky->h );
			masked_blit( inky, buffer, 0, 0, inky_x, inky_y, inky->w, inky->h );
			masked_blit( pinky, buffer, 0, 0, pinky_x, pinky_y, pinky->w, pinky->h );
			masked_blit( clyde, buffer, 0, 0, clyde_x, clyde_y, clyde->w, clyde->h );

			blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H );
			clear_to_color( buffer, makecol( 0, 0, 0 ) );

			++pac_x;
			++blinky_x;
			++inky_x;
			++pinky_x;
			++clyde_x;

			masked_blit( pac2, buffer, 0, 0, pac_x, pac_y, pacleft->w, pacleft->h );
			masked_blit( blinky2, buffer, 0, 0, blinky_x, blinky_y, blinky->w, blinky->h );
			masked_blit( inky2, buffer, 0, 0, inky_x, inky_y, inky->w, inky->h );
			masked_blit( pinky2, buffer, 0, 0, pinky_x, pinky_y, pinky->w, pinky->h );
			masked_blit( clyde2, buffer, 0, 0, clyde_x, clyde_y, clyde->w, clyde->h );

			blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H );
			clear_to_color( buffer, makecol( 0, 0, 0 ) );

			++pac_x;
			++blinky_x;
			++inky_x;
			++pinky_x;
			++clyde_x;
		}
		while( pac_x != -500 )
		{
			masked_blit( pacleft, buffer, 0, 0, pac_x, pac_y, pacleft->w, pacleft->h );
			masked_blit( conf, buffer, 0, 0, blinky_x, blinky_y, conf->w, conf->h );
			masked_blit( conf, buffer, 0, 0, inky_x, inky_y, conf->w, conf->h );
			masked_blit( conf, buffer, 0, 0, pinky_x, pinky_y, conf->w, conf->h );
			masked_blit( conf, buffer, 0, 0, clyde_x, clyde_y, conf->w, conf->h );

			blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H );
			clear_to_color( buffer, makecol( 0, 0, 0 ) );

			--pac_x;
			--blinky_x;
			--inky_x;
			--pinky_x;
			--clyde_x;

			masked_blit( pac2left, buffer, 0, 0, pac_x, pac_y, pacleft->w, pacleft->h );
			masked_blit( conf2, buffer, 0, 0, blinky_x, blinky_y, conf->w, conf->h );
			masked_blit( conf2, buffer, 0, 0, inky_x, inky_y, conf->w, conf->h );
			masked_blit( conf2, buffer, 0, 0, pinky_x, pinky_y, conf->w, conf->h );
			masked_blit( conf2, buffer, 0, 0, clyde_x, clyde_y, conf->w, conf->h );

			blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H );
			clear_to_color( buffer, makecol( 0, 0, 0 ) );

			--pac_x;
			--blinky_x;
			--inky_x;
			--pinky_x;
			--clyde_x;
		}
		rest( 2900 );
		stop_sample( intermission );

		for( ctr = 0; ctr < 240; ++ctr )
		{
			take[ ctr ] = 0;
		}

		for( ctr = 0; ctr < 4; ++ctr )
		{
			takeP[ ctr ] = 0;
		}

		takeChr = 1;

		++stage;

		pac_x    = 308 - 19;
		pac_y    = 524 - 19;

		blinky_x = 308 - 19;
		blinky_y = 257 - 19;

		inky_x   = 274 - 19;
		inky_y   = 321 - 19;

		pinky_x  = 308 - 19;
		pinky_y  = 321 - 19;

		clyde_x  = 342 - 19;
		clyde_y  = 321 - 19;

		confuseBlinky = 0;
		confuseinky   = 0;
		confusePinky  = 0;
		confuseClyde  = 0;

		wayPacman  = RIGHT;
		wayBlinky  = RIGHT;
		wayinky    = RIGHT;
		wayPinky   = LEFT;
		wayClyde   = LEFT;

		turnPacman = RIGHT;

		homeinky   = 0;
		homePinky  = 0;
		homeClyde  = 0;

		draw( wayPacman );

		textprintf_ex(screen, pacfont, SCREEN_W / 2 - 137 , 389 - 9, makecol(253, 253, 253), -1, "Next Stage");

		play_sample( start, 255, 128, 1000, 0 );

		rest( 4000 );

		timeStart = time( NULL );

		play_sample( enemy, 255, 128, 1000, 1 );
	}
}

/*###########################################################################*/
/*                           End of Pacman_91044046.c                        */
/*###########################################################################*/
