
#include "hero.h"
#include <Windows.h>

static void idle_ani_ctx( hero_t *hero )
{
	hero->idle = create_ani_ctx();
	add_ani_layer( &hero->idle, ".\\assets\\hero\\adventurer-idle-2-00.png", IDLE_DELAY );
	add_ani_layer( &hero->idle, ".\\assets\\hero\\adventurer-idle-2-01.png", IDLE_DELAY );
	add_ani_layer( &hero->idle, ".\\assets\\hero\\adventurer-idle-2-02.png", IDLE_DELAY );
	add_ani_layer( &hero->idle, ".\\assets\\hero\\adventurer-idle-2-03.png", IDLE_DELAY );
}

static void attack1_ani_ctx( hero_t * hero )
{
	const int ATTACK_IDX = 0;
	hero->attack[ATTACK_IDX] = create_ani_ctx();
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack1-00.png", ATTACK1_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack1-01.png", ATTACK1_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack1-02.png", ATTACK1_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack1-03.png", ATTACK1_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack1-04.png", ATTACK1_DELAY );
}

static void attack2_ani_ctx( hero_t * hero )
{
	const int ATTACK_IDX = 1;
	hero->attack[ATTACK_IDX] = create_ani_ctx();
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack2-00.png", ATTACK2_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack2-01.png", ATTACK2_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack2-02.png", ATTACK2_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack2-03.png", ATTACK2_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack2-04.png", ATTACK2_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack2-05.png", ATTACK2_DELAY );
}

static void attack3_ani_ctx( hero_t * hero )
{
	const int ATTACK_IDX = 2;
	hero->attack[ATTACK_IDX] = create_ani_ctx();
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack3-00.png", ATTACK3_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack3-01.png", ATTACK3_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack3-02.png", ATTACK3_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack3-03.png", ATTACK3_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack3-04.png", ATTACK3_DELAY );
	add_ani_layer( &hero->attack[ATTACK_IDX], ".\\assets\\hero\\adventurer-attack3-05.png", ATTACK3_DELAY );
}

hero_t* create_hero_ctx( void )
{
	hero_t *hero = (hero_t*)malloc( sizeof( hero_t ) );

	idle_ani_ctx( hero );
	attack1_ani_ctx( hero );
	attack2_ani_ctx( hero );
	attack3_ani_ctx( hero );

	hero->status = IDLE;
	return hero;
}

void hero_process( void )
{
	hero_t *hero = create_hero_ctx();
	printf( "Start Processing\n" );
	time_t t = 0;

	hero_status event;

	while ( 1 ) {
		t = time( NULL );
		if ( GetAsyncKeyState( ATTACK_KEY ) ) {
			hero->status = ATTACK;
		}

		if ( hero->last_behavior_time >= t + 1000 ) {
			hero->status = IDLE;
		}

		// FSM
		switch(  )
	}
}