#ifndef WIN_H
# define WIN_H

#include "structs.h"

#define WIN_RATIO    (16.0f / 9.0f)
#define WIN_WIDTH    800
#define WIN_HEIGHT   (int)(WIN_WIDTH / WIN_RATIO)

int		init_win(t_data *data);
int		close_win(t_data *data);
int		key_handle(int keycode, void *param);

#endif