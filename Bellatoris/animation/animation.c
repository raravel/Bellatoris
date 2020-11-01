#include <stdio.h>
#include "animation.h"
#include "../common.h"

png_rgba_pixel_t prev_p;

void test_print( ascii_info_t *info )
{
	for ( int y = 0; y < info->height; y++ ) {
		for ( int x = 0; x < info->width; x++ ) {
			png_rgba_pixel_t p = info->color[y][x];
			if ( p.alpha == 0 ) {
				printf( "  " );
			} else {
				if ( memcmp( &prev_p, &p, sizeof( png_rgba_pixel_t ) ) != 0 ) {
					printf( "\033[38;2;%d;%d;%dm", p.red, p.green, p.blue );
					prev_p = p;
				}
				printf( "%c%c", info->buf[y][( x * 2 )], info->buf[y][( x * 2 ) + 1] );
			}
		}
		printf( "\n" );
	}
}

void play_ani_layer( ani_t *ani )
{
	ani_layer_t *layer = NULL;
	for ( layer = ani->first_layer; layer != NULL; layer = layer->next ) {
		gotoxy( 0, 10 );
		test_print( layer->buf );
		usleep( layer->delay );
	}
}

ani_layer_t* read_ani_layer( char *png_file )
{
	png_minfo_t *png_info = read_png( png_file );
	ani_layer_t *layer = NULL;

	if ( !png_info ) {
		return NULL;
	}

	printf( "============== read complete\n" );

	layer = (ani_layer_t*)malloc( sizeof( ani_layer_t ) );
	memset( layer, 0x0, sizeof( ani_layer_t ) );
	layer->buf = png2ascii( png_info );

	free_png_minfo( png_info );
	return layer;
}

int add_ani_layer( ani_t **ani, char *png_file, int delay )
{
	if ( !ani ) {
		return 1;
	}

	ani_layer_t *layer = read_ani_layer( png_file );
	if ( !layer ) {
		return 1;
	}
	layer->delay = delay;


	if ( (*ani)->layers == NULL ) {
		// first item
		( *ani )->layers = layer;
		( *ani )->first_layer = layer;
		( *ani )->last_layer = layer;
	} else {
		ani_layer_t *next = (*ani)->last_layer;
		layer->prev = next;
		next->next = layer;
		( *ani )->last_layer = layer;
	}
	return 0;
}

ani_t* create_ani_ctx( void )
{
	ani_t *ani = (ani_t*)malloc( sizeof( ani_t ) );
	memset( ani, 0x0, sizeof( ani_t ) );
	ani->cnt = 0;
	return ani;
}