#ifndef __COMMON_H__
#define __COMMON_H__

#include <Windows.h>
#include <type.h>

void usleep( DWORD waitTime );
void sleep( DWORD waitTime );
void gotoxy( int x, int y );
void cursor_view( char show );

#endif
