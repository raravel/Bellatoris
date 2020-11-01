#ifndef __HERO_H__
#define __HERO_H__

#include <animation/animation.h>
#include <png2ascii.h>
#include <type.h>

#define MAX_ATTACK_COMBO 3

/* Key Config */
#define ATTACK_KEY 0x41 // 'A' key

#define IDLE_DELAY 50000
#define ATTACK1_DELAY 5000
#define ATTACK2_DELAY 5000
#define ATTACK3_DELAY 5000

#define HERO_FSM(event, status) ((event * HERO_STATUS_MAX) + status)

typedef enum {
	NONE,
	IDLE,
	ATTACK,
	HERO_STATUS_MAX,
} hero_status;

typedef struct _hero_t {
	
	uint_32		status;
	time_t		last_behavior_time;
	uint_8		attack_combo;
	ani_t		*attack[MAX_ATTACK_COMBO];
	ani_t		*idle;

} hero_t;

void hero_process( void );


#endif