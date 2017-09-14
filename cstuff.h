#ifndef _CSTUFF_H
#define _CSTUFF_H

struct mm{
	void *mem;
	long typelen;
	long len;
};

void newmm(struct mm *self, long type);
int mm_push(struct mm *self, void *item);
int mm_pop(struct mm *self, void *ret);
void *mm_get(struct mm *self, long n);
void mm_destroy(struct mm *self);

#endif
