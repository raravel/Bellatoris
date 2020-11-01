#include <stdio.h>
#include <png2ascii.h>
#include "animation/animation.h"
#include "common.h"

int main( int argc, char *argv[] )
{
	cursor_view( 0 );
	

	int idle_delay = 50000;
	int attack1_delay = 5000;
	int attack2_delay = 5000;
	int attack3_dealy = 5000;

	hero_process();
	return 0;
}
