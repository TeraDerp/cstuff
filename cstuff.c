#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstuff.h"

int mm_push(struct mm *self, void *item){
	/* Grows the array by one typelen and copies value pointed to by item to the newly
	   allocated area
	   Returns: 0 on fail, 1 on success */
	void *ptr=realloc(self->mem, self->len*self->typelen+self->typelen);
	
	if(!ptr){
		perror("realloc");
		return 0;
	}else{
		self->mem=ptr;
		memcpy((char*)self->mem+self->typelen*self->len, item, self->typelen);
		self->len++;
		return 1;
	}
}

void *mm_get(struct mm *self, long n){
	/* Returns a pointer to the nth element */
	void *v;
	v=(char *)self->mem+n*self->typelen;
	return v;
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
		.push=mm_push,
		.get=mm_get,
		.destroy=mm_destroy,
	};
	return;
}
