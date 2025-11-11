#ifndef DLL_HANDLER_IN_ROOT
#include <dllH/dlls.h>
#else
#include <dlls.h>
#endif
#include <stdlib.h>
#include <string.h>
#ifdef WINDOWS
#include <windows.h>
#include <libloaderapi.h>
dllH_string_weird dllH_INTERNALS_string_to_string_weird(dllH_string first){
    size_t size=strlen(first);
    dllH_string_weird out=(dllH_string_weird)malloc(size*2);
    for(size_t index=0;index<size;index++) (index)[out]=(uint16_t)index[first];
    return out;
}
#endif
struct dllH_dll dllH_load_dll(dllH_string name){
    struct dllH_dll out=(struct dllH_dll){0};
    out.name=malloc(strlen(name));
    memcpy(out.name,name,strlen(name));
    out.funcs=dllH_create_funcs_list();
    #ifdef WINDOWS
    out.handle=(dllH_handle)LoadLibraryA((LPCSTR)name);
    if(!out.handle){
        free(out.name);
        dllH_destroy_list(&(out.funcs));
        return (struct dllH_dll){0};
    }
    #endif
    return out;
}
dllH_bool dllH_load_function(struct dllH_dll* dll,dllH_string name){
    struct dllH_function func=(struct dllH_dll){0};
    func.name=malloc(strlen(name));
    memcpy(func.name,name,strlen(name));
    #ifdef WINDOWS
    dllH_string_weird temp_name=dllH_INTERNALS_string_to_string_weird(name);
    func.handle=GetProcAddress(dll->handle,temp_name);
    free(temp_name);
    if(!func.handle){
        free(func.name);
        return 0;
    }
    #endif
    dllH_add_func(dll->funcs,func);
    return 1;
}
void dllH_destroy_list(struct dllH_dll* dll){
    for(int64_t index=0;index<dll->funcs.size;index++) free(index[dll->funcs.ptr].name);
    dllH_destroy_list(&(dll->funcs));
    free(dll->name);
    #ifdef WINDOWS
    FreeLibrary(dll->handle);
    #endif
    memset(dll,0,sizeof(dllH_dll));
}