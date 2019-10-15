// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <ctime>
#include <iostream>
#include "cpp-struct.cpp"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


//The Troublesome Code

InfoNative* generate_response_info_native()
{
	long expiration = 1765416838;
	InfoNative *response = new InfoNative();

	response->usercode = (char*)&"NCDAXA";

	response->admin_email = (char*)&"(REDACTED)";

	//response->already_activated =  1; ---TROUBLE!

	//response->auto_renew =  1; ---TROUBLE!
	*response->version = new unsigned int[4]{ 17, 1, 953, 0 };
	response->company_name = (LPWSTR)"(REDACTED)";
	response->contact_name = (LPWSTR)"(REDACTED)";
	response->country_id = (LPSTR)"(REDACTED)";
	response->country_name = (LPSTR)"(REDACTED)";
	response->email = (LPSTR)"(REDACTED)";
	response->expiration_date_ts = expiration;
	//response->first_activation_ts = 1544492038;  ---TROUBLE!
	std::time_t result = std::time(nullptr);
	long int now = static_cast<long int> (result);
	response->last_erp_check_date = now;
	//response->review_status = 1; ---TROUBLE!
	response->telephone = (LPSTR)"(REDACTED)";
	response->reseller_name = (LPWSTR)"";
	response->max_connections = 16; //16
	response->max_chan = 8; //8
	response->maintenance_expiration_date = expiration;

	response->support_expiration_date = 0;
	response->max_wm_connections = 16;

	return response;
}
//This function is the same as above, but with the troublesome lines uncommented, so you don't have to do that.
InfoNative* generate_response_info_native_with_trouble()
{

	long expiration = 1765416838;
	InfoNative *response = new InfoNative();

	response->usercode = (char*)&"NCDAXA";

	response->admin_email = (char*)&"(REDACTED)";

	response->already_activated =  1; //TROUBLE!

	response->auto_renew =  1; //TROUBLE!
	*response->version = new unsigned int[4]{ 17, 1, 953, 0 };
	response->company_name = (LPWSTR)"(REDACTED)";
	response->contact_name = (LPWSTR)"(REDACTED)";
	response->country_id = (LPSTR)"(REDACTED)";
	response->country_name = (LPSTR)"(REDACTED)";
	response->email = (LPSTR)"(REDACTED)";
	response->expiration_date_ts = expiration;
	response->first_activation_ts = 1544492038;  //TROUBLE!
	std::time_t result = std::time(nullptr);
	long int now = static_cast<long int> (result);
	response->last_erp_check_date = now;
	response->review_status = 1; //TROUBLE!
	response->telephone = (LPSTR)"(REDACTED)";
	response->reseller_name = (LPWSTR)"";
	response->max_connections = 16; //16
	response->max_chan = 8; //8
	response->maintenance_expiration_date = expiration;

	response->support_expiration_date = 0;
	response->max_wm_connections = 16;

	return response;
}
typedef struct
{
	//[MarshalAs(UnmanagedType.LPStr)]
	LPSTR product_code;
	//[MarshalAs(UnmanagedType.U8)]
	long first_activation_ts;
} InfoNativeTeste;

typedef int(*Callback)(InfoNative *);
InfoNativeTeste test;
InfoNative* responseOut;
InfoNative* finalResponse = new InfoNative();
extern "C" __declspec(dllexport) long GetResponse(__int64 a1, Callback a2)
{



	

	MessageBox(NULL, _T("Beginning Test from CPP!"), _T("Hi"), NULL);
	responseOut = generate_response_info_native_with_trouble(); //TODO: Content is troublesome

	int resp = a2(responseOut);



	MessageBox(NULL, _T("Data Sent to .NET!"), _T("Hi"), NULL);
	return  1i64;
}