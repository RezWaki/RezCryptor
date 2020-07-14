#include "crypt.h"

void CRezCryptor::__cryptfile( String^ input_filename, String^ output_filename, INT key, BOOL mode ) {
	if( input_filename == String::Empty || !IO::File::Exists(input_filename) ) {
		MessageBoxA( NULL, "Specify the right input file path", "Error", MB_ICONERROR );
		return;
	}
	if( output_filename == String::Empty ) {
		MessageBoxA( NULL, "Specify the right output file path", "Error", MB_ICONERROR );
		return;
	}
	if( !key ) {
		MessageBoxA( NULL, "Key can't be null", "Error", MB_ICONERROR );
		return;
	}
	array< unsigned char >^ file_bytes = IO::File::ReadAllBytes( input_filename );
	for( INT i = 0; i < file_bytes->Length; i++ ) {
		if( !mode )
			file_bytes[i] -= key;
		else
			file_bytes[i] += key;
	}
	IO::File::WriteAllBytes( output_filename, file_bytes );
}

void CRezCryptor::highlight_button( Label^ button, BOOL cursor_on ) {
	if( cursor_on ) {
		button->ForeColor = Drawing::Color::Purple;
		button->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 9.75F, Drawing::FontStyle::Bold, Drawing::GraphicsUnit::Point, 
						204) );
	}
	else{
		button->ForeColor = Drawing::Color::FromArgb( 192, 0, 192 );
		button->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 9.75F, Drawing::FontStyle::Regular, Drawing::GraphicsUnit::Point, 
						204) );
	}
}

CRezCryptor gpCryptFuncs;