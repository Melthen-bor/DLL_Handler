#ifndef DLL_HANDLER_DATA_TYPES
#define DLL_HANDLER_DATA_TYPES
#include <inttypes.h>
typedef void* dllH_handle;
typedef char* dllH_string;
typedef char dllH_bool;
#if defined(_WIN64)||defined(_WIN32)
#define WINDOWS
typedef uint16_t* dllH_string_weird;
#endif
#endif