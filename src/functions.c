#ifndef DLL_HANDLER_IN_ROOT
#include <dllH/functions.h>
#else
#include <functions.h>
#endif
#include <stdlib.h>
#include <string.h>
struct dllH_function_list dllH_create_funcs_list(void){
    return {0,0};
}
void dllH_add_func(struct dllH_function_list* self,struct dllH_function item){
    if(!self->size) self->ptr=malloc(sizeof(struct dllH_function));
    else self->ptr=realloc(self->ptr,(self->size+1)*sizeof(struct dllH_function));
    *((self->size++)+self->ptr)=item;
}
struct dllH_function dllH_get_function(struct dllH_function_list this,uint64_t location){
    if(location<this.size) return *(location+this.ptr);
    return (struct dllH_function){0,0};
}
int64_t dllH_find_function(struct dllH_function_list this,dllH_string name){
    for(int64_t index=0; index<this.size; index++) if(!strcmp((index+this.ptr)->name,name)) return index;
}
void dllH_destroy_list(struct dllH_function_list* self){
    if(self->size) free(self->ptr);
    self->size=0;
}