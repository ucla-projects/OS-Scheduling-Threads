#include "schedos-app.h"
#include "x86sync.h"

/*****************************************************************************
 * schedos-1
 *
 *   This tiny application prints red "1"s to the console.
 *   It yields the CPU to the kernel after each "1" using the sys_yield()
 *   system call.  This lets the kernel (schedos-kern.c) pick another
 *   application to run, if it wants.
 *
 *   The other schedos-* processes simply #include this file after defining
 *   PRINTCHAR appropriately.
 *
 *****************************************************************************/

#ifndef PRINTCHAR
#define PRINTCHAR	('1' | 0x0C00)
#endif

void
start(void)
{
	int i;
    int chara = PRINTCHAR;

	for (i = 0; i < RUNCOUNT; i++) {
		// Write characters to the console, yielding after each one.
		sys_sync_mech(chara);
        // Exercise 6: fixed race condition by calling sys_sync_mech, defined in schedos-app.h
	}
    
    // Exercise 2: schedos processes actually exit via sys_exit()
	sys_exit(0);
}
