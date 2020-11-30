#pragma once
#ifndef _WIN_UTF8_CONSOLE_H_

#include<stdlib.h>
#include<Windows.h>


#ifdef __cpluspuls
extern "C" {
#endif

	static void set_win_console_utf8()
	{
#ifdef _WIN32

		system( "chcp 65001" );

		SetConsoleCP( 65001 );
		SetConsoleOutputCP( 65001 );

		CONSOLE_FONT_INFOEX info = { 0 };
		info.cbSize = sizeof( info );
		info.dwFontSize.Y = 16;  // leave X=0
		info.FontWeight = FW_NORMAL;
		memcpy( info.FaceName, L"Consolas", sizeof( L"Consolas" ) );
		SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), (int)false, &info );
#endif  // _WIN32
	}

#ifdef __cpluspuls
}
#endif // __cpluspuls


#endif // _WIN_UTF8_CONSOLE_H_
