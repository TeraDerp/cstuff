#ifndef _CSTUFF_H
#define _CSTUFF_H

struct mm{
	void *mem;
	long typelen;
	long len;
	
	int (*push)(struct mm *self, void *item);/* Appends an element */
	void *(*get)(struct mm *self, long n);/* Gets an element */
	void (*destroy)(struct mm *self);/* Frees the object.
		(Doesn't call free on the pointer passed to it itself) */
};

void newmm(struct mm *self, long type);
int mm_push(struct mm *self, void *item);
void *mm_get(struct mm *self, long n);
void mm_destroy(struct mm *self);

#endif
