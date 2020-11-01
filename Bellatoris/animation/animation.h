#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <png2ascii.h>

typedef struct _ani_layer_t {
	ascii_info_t *buf;
	int delay;

	struct _ani_layer_t *next;
	struct _ani_layer_t *prev;
} ani_layer_t;

typedef struct _ani_t {
	ani_layer_t *layers;

	ani_layer_t *first_layer;
	ani_layer_t *last_layer;

	int cnt;
} ani_t;



//ani_layer_t* ani_read_layer( char *png_file );
int add_ani_layer( ani_t **ani, char *png_file, int delay );
ani_t* create_ani_ctx( void );
void play_ani_layer( ani_t *ani );

#endif