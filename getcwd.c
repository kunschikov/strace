#include "defs.h"

int
sys_getcwd(struct tcb *tcp)
{
	if (exiting(tcp)) {
		if (syserror(tcp))
			tprintf("%#lx", tcp->u_arg[0]);
		else
			printpathn(tcp, tcp->u_arg[0], tcp->u_rval - 1);
		tprintf(", %lu", tcp->u_arg[1]);
	}
	return 0;
}
