#include <iostream>
#include <Windows.h>
void extraeConsonantesA(LPCSTR cadena_original, LPSTR cadena_sin_consonantes);
void extraeConsonantesW(LPCWSTR cadena_original, LPWSTR cadena_sin_consonantes);
void extraeConsonantes();
int main()
{
	LPSTR str_sin_consonantes;
	const char* str_a_convertir = "Texto de prueba";
	extraeConsonantesA(str_a_convertir, str_sin_consonantes);
	return 0;
}

void extraeConsonantesA(LPCSTR cadena_original, LPSTR cadena_sin_consonantes)
{
	
	wchar_t* str_convertida = nullptr;
	int num_caracteres_necesarios = 0;
	int num_caracteres_convertidos = 0;

	// primer llamada a MultiByteToWideChar es usada para calcular cuantos caracteres necesitamos para la conversion
	num_caracteres_necesarios = MultiByteToWideChar(
		CP_ACP,
		0,
		cadena_original,
		strlen(cadena_original) * sizeof(char),
		str_convertida,
		0
	);

	str_convertida = new wchar_t[num_caracteres_necesarios + 1];
	memset(str_convertida, 0, (num_caracteres_necesarios + 1) * sizeof(wchar_t));

	num_caracteres_convertidos = MultiByteToWideChar(
		CP_ACP,
		0,
		cadena_original,
		strlen(cadena_original) * sizeof(char),
		str_convertida,
		num_caracteres_necesarios
	);

	std::cout << "string original: " << cadena_original << std::endl;
	std::wcout << "String convertida a wchar_t: " << str_convertida << std::endl;

	// TAREA: USAR WideCharToMultiByte

	delete[] str_convertida;
	str_convertida = nullptr;
	int MultiByteToWideChar(
		[in]            UINT                              CodePage,
		[in]            DWORD                             dwFlags,
		[in]            _In_NLS_string_(cbMultiByte)LPCCH lpMultiByteStr,
		[in]            int                               cbMultiByte,
		[out, optional] LPWSTR                            lpWideCharStr,
		[in]            int                               cchWideChar
	);
	extraeConsonantesW(str_convertida, cadena_sin_consonantes);
}
void extraeConsonantesW(LPCWSTR cadena_original, LPWSTR cadena_sin_consonantes)
{

}
void extraeConsonantes()
{

}