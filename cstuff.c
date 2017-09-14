#include <stdlib.h>
#include <string.h>

#include "cstuff.h"

int mm_push(struct mm *self, void *item){
	/* Grows the array by one typelen and copies value pointed to by item to the newly
	   allocated area
	   Returns: -1 on fail, 0 on success */
	void *ptr=realloc(self->mem, self->len*self->typelen+self->typelen);
	
	if(!ptr)
		return -1;
	else{
		self->mem=ptr;
		memcpy((char*)self->mem+self->typelen*self->len, item, self->typelen);
		self->len++;
		return 0;
	}
}

int mm_pop(struct mm *self, void *ret){
	/* Writes last element to ret and removes it */
	void *ptr;
	memcpy(ret, mm_get(self, self->len-1), self->typelen);
	self->len--;
	
	ptr=realloc(self->mem, self->len*self->typelen);
	
	if(!ptr)
		return -1;
	else{
		self->mem=ptr;
		return 0;
	}
	
}

void *mm_get(struct mm *self, long n){
	/* Returns a pointer to the nth element */
	return (char *)self->mem+n*self->typelen;
}

void mm_destroy(struct mm *self){
	/* Frees stuff. Doesn't free self */
	free(self->mem);
	return;
}

void newmm(struct mm *self, long type){
	/* Constructor. Initializes self, uses type */
	*self=(struct mm){
		.mem=(void*)0,
		.typelen=type,
		.len=0,
	};
	return;
}
