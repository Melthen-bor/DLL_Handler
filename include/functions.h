#ifndef DLL_HANDLER_FUNCTIONS
#define DLL_HANDLER_FUNCTIONS
#ifndef DLL_HANDLER_IN_ROOT
#include <dllH/data_types.h>
#else
#include <data_types.h>
#endif
struct dllH_function{
    dllH_string name;
    dllH_handle handle;
};
#define dllH_func_call(ret,..) (ret(*)(__VA_ARGS__))
struct dllH_function_list{
    int64_t size;
    struct dllH_function* ptrs;
};
struct dllH_function_list dllH_create_funcs_list(void);
void dllH_add_func(struct dllH_function_list*,struct dllH_function);
struct dllH_function dllH_get_function(struct dllH_function_list,uint64_t);
int64_t dllH_find_function(struct dllH_function_list,dllH_string);
void dllH_destroy_list(struct dllH_function_list*);
#endif