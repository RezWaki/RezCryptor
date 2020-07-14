#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

class CRezCryptor{
	public:
		void __cryptfile( String^ input_filename, String^ output_filename, INT key, BOOL mode );
		void highlight_button( Label^ button, BOOL cursor_on );
};