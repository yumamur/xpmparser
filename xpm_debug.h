#ifndef XPM_DEBUG_H
# define XPM_DEBUG_H

# ifdef DEBUG
#  include <stdio.h>
#  if DEBUG == 1
#   define DEBUG_FUNC	printf("Entering: %s\n", __func__);
#  elif DEBUG == 2
#   define DEBUG_FUNC	static void	*addr;							\
    					if (addr != __builtin_frame_address(0))	\
    					{											\
    						addr = __builtin_frame_address(1);		\
    						printf("New frame: %p\n", addr); }		\
    					printf("\tEntering: %s\n",					\
    						__func__);
#  endif /* LEVEL */
# else
#  define DEBUG_FUNC() ;
# endif /* DEBUG */
#endif /* XPM_DEBUG_H */
