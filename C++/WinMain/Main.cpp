#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

/* 
	The #pragma is directive for implement preprocessor instructions

	comment( comment-type [, "commentstring" ] ) "Places a comment record into an .o file or .exe file"
	comment-type:
		compiler
		exestr
		lib
		linker
		user
*/

//#pragma comment( linker, "/subsystem:console" )
#pragma comment( linker, "/subsystem:windows" )

// Described below
LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

/* 
	Every Windows programm includes an entry-point function WinMain or wWinMain
	
	WinMain - the command-line arguments are passed as an ANSII string
	wWinMain - the command-line arguments are passed as an Unicode string

	The function return an integer value. It not used by operating system, but can be used as status code to some other program

	With MinGW compiler use WinMain function!!!
*/

int WINAPI wWinMain( HMODULE hInstance, HMODULE hPrevInstance, PWSTR lpCmdLine, int nShowCmd ) 
{
	// When uses MinGW compiler, to hide console window
	// ShowWindow( GetConsoleWindow(), SW_HIDE );

	// Register the window class
	const wchar_t CLASS_NAME[] = L"Test";

	// Structure consist of various fields that describe a window class
	WNDCLASS windowClass = {};
	windowClass.lpfnWndProc = WindowProc;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = CLASS_NAME;

	// Register a window class with the operating system for subsequent use in calls to the CreateWindowEx function 
	RegisterClass( &windowClass );

	// Function create the window ( overlapped, pop-up, or child ) return HWND of created window or NULL
	HWND hwnd = CreateWindowEx( 
		0,						// Optional window styles 
		CLASS_NAME, 			// Window class
		L"Text message", 		// Window text
		WS_OVERLAPPEDWINDOW,	// Window style ( The several flags combined with bitwise OR )
		CW_USEDEFAULT,			// X
		CW_USEDEFAULT,			// Y
		CW_USEDEFAULT,			// nWidth
		CW_USEDEFAULT,			// nHeight
		NULL,					// Parent window
		NULL,					// Menu
		hInstance,				// Instance handle
		NULL					// Additional application data 
		);

		if( hwnd == NULL )
			return 0;

		// Sets the specified window's show state. Return BOOL value "If previously visible is non zero else is zero"
		ShowWindow( hwnd, nShowCmd );

		// Run the message loop
		MSG msg = {};

		/* Retrieves a message from the calling thread's message queue. The function dispatches incoming sent messages until a posted message is available for retrievals
		Return BOOL value non zero if retrieved message is other than WM_QUIT
		If retrieve message is  WM_QUIT return zerro
		If there is an error retur mineus one */
		while( GetMessage( &msg, NULL, 0, 0 ) )
		{
			/* Translate virtual-key messages into character messages. The character messages are posted to the calling thread's message queue, to be read the next time the thread calls the Get/PeekMessage functions
			Return BOOL "If message is not translated return is zero, if translated return is non zero" */ 
			TranslateMessage( &msg );

			/*  Dispatches a message to a window procedure. It is typically used to dispatch a message retrieved by GetMessage functio.
			Return LRESULT value specifies the value returned by the window procedure */
			DispatchMessage( &msg );
		}

	return 0;
}


/*
	An application-defined function that process messages sent to a window. Window procedure.

	Return type LRESULT. The value is the result of the message processing and depend on the message sent.	
*/

LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch( uMsg )
	{
		case WM_DESTROY:
		{
			/* Indicates to the system that a thread has made a request to terminate ( quit ). It is typically used in response to a WM_DESTROY message.
			This function does not return a value */
			PostQuitMessage( 0 );
			return 0;
		}
		case WM_PAINT:
		{
			/* Structure contains information for an application. This information can be used to paint the client area of a window owned by that apllication. */
			PAINTSTRUCT ps;

			/* Function prepares the specified window for a painting and fills a PAINTSTRUCT wint information about the painting.
			Return handle to a display device context for the specified window
			If function fails, the return value is NULL */
			HDC hdc = BeginPaint( hwnd, &ps );
			
			/* Function fills a rectangle by using the specifified brush. This function includes tje lef and top borders, but excludes right and bottom border of the rectangle.
			Return value is nonzero is function succeed
			If function fails return value is zerro.  */
			FillRect( hdc, &ps.rcPaint, ( HBRUSH ) ( COLOR_WINDOW+1 ) );
			
			/* Fuction marks the end of painting in the spicified window. This function is required for each call to the BeginPaint function, but only after painting is complete.
			Return value is always nonzero. */
			EndPaint( hwnd, &ps );	
		}
			return 0;
	}

	/* Calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every massage is processed.
	Return value LPARAM is the result of the message processing and depends on the messsage. */
	return DefWindowProc( hwnd, uMsg, wParam, lParam );
}