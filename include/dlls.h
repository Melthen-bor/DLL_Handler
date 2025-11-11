#ifndef DLL_HANDLER_DLLS
#define DLL_HANDLER_DLLS
#ifndef DLL_HANDLER_IN_ROOT
#include <dllH/functions.h>
#else
#include <functions.h>
#endif
struct dllH_dll{
    dllH_string name;
    struct dllH_function_list funcs;
    dllH_handle handle;
}
struct dllH_dll dllH_load_dll(dllH_string);
dllH_bool dllH_load_function(struct dllH_dll*,dllH_string);
void dllH_discard_dll(struct dllH_dll*);
#endif