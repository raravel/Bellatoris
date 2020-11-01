#include "common.h"

// from https://gist.github.com/ngryman/6482577
void usleep( DWORD waitTime )
{
	LARGE_INTEGER perfCnt, start, now;

	QueryPerformanceFrequency( &perfCnt );
	QueryPerformanceCounter( &start );

	do {
		QueryPerformanceCounter( (LARGE_INTEGER*)&now );
	} while ( ( now.QuadPart - start.QuadPart ) / (float)( perfCnt.QuadPart ) * 1000 * 1000 < waitTime );
}

void sleep( DWORD waitTime )
{
	usleep( waitTime * 1000 );
}

void cursor_view( char show )
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo( hConsole, &ConsoleCursor );
}


void gotoxy( int x, int y )
{
	COORD pos = { x,y };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), pos );
}