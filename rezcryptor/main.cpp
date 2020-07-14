#include <Windows.h>
#include "main.h"
#pragma comment( lib, "user32.lib" )

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, INT ) {
	Application::EnableVisualStyles();
	Application::Run( gcnew rezcryptor::main() );
	return TRUE;
}