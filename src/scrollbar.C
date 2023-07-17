/*----------------------------------------------------------------------*
 * File:	scrollbar.C
 *----------------------------------------------------------------------*
 *
 * Copyright (c) 1997,1998 mj olesen <olesen@me.QueensU.CA>
 * Copyright (c) 1998      Alfredo K. Kojima <kojima@windowmaker.org>
 *				- N*XTstep like scrollbars
 * Copyright (c) 1999-2001 Geoff Wing <gcw@pobox.com>
 * Copyright (c) 2004-2006 Marc Lehmann <schmorp@schmorp.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *----------------------------------------------------------------------*/

#include "../config.h" /* NECESSARY */
#include "rxvt.h"      /* NECESSARY */

/*----------------------------------------------------------------------*/

/*
 * Map or unmap a scrollbar.  Returns non-zero upon change of state
 */
void scrollBar_t::map(int map)
{
  if (map) {
    state = SB_STATE_IDLE;

    if (!win)
      resize();
    else
      XMapWindow(term->dpy, win);
  } else {
    state = SB_STATE_OFF;

    if (win)
      XUnmapWindow(term->dpy, win);
  }
}

void scrollBar_t::resize()
{
  int delayed_init = 0;
  int window_sb_x = term->szHint.width - total_width();

  update_data();

  if (!win) {
    /* create the scrollbar window */
    win = XCreateSimpleWindow(term->dpy, term->parent, window_sb_x, 0, total_width(), term->szHint.height, 0, term->pix_colors[Color_fg], term->pix_colors[color()]);
    XDefineCursor(term->dpy, win, leftptr_cursor);

    XSelectInput(term->dpy, win, ExposureMask | ButtonPressMask | ButtonReleaseMask | Button1MotionMask | Button2MotionMask | Button3MotionMask);
    term->scrollbar_ev.start(term->display, win);

    delayed_init = 1;
  } else
    XMoveResizeWindow(term->dpy, win, window_sb_x, 0, total_width(), term->szHint.height);

  show(1);

  if (delayed_init)
    XMapWindow(term->dpy, win);
}

/*
 * Update current scrollbar view w.r.t. slider heights, etc.
 */
int scrollBar_t::show(int refresh)
{
  int ret;

  if (!state)
    return 0;

  if (refresh) {
    int sb_top = term->view_start - term->top_row;
    int sb_bot = sb_top + (term->nrow - 1);
    int sb_len = max(term->nrow - 1 - term->top_row, 1);
    int n = min(min_height(), size());

    top = beg + (sb_top * (size() - n)) / sb_len;
    bot = top + ecb_div_ru((sb_bot - sb_top) * (size() - n), sb_len) + n;
    /* no change */
    if (top == last_top && bot == last_bot && (state == last_state || !(state == SB_STATE_UP || state == SB_STATE_DOWN)))
      return 0;
  }

  ret = (this->*update)(refresh);

  last_top = top;
  last_bot = bot;
  last_state = state;

  return ret;
}

void scrollBar_t::setup(rxvt_term *term)
{
  int i;
  const char *scrollalign, *thickness;

  this->term = term;
  scrollalign = term->rs[Rs_scrollBar_align];
  thickness = term->rs[Rs_scrollBar_thickness];

  width = SB_WIDTH;

  if (thickness && (i = atoi(thickness)) >= SB_WIDTH_MINIMUM)
    width = min(i, SB_WIDTH_MAXIMUM);

  /* align = SB_ALIGN_CENTRE; */
  if (scrollalign) {
    if (strncasecmp(scrollalign, "top", 3) == 0)
      align = SB_ALIGN_TOP;
    else if (strncasecmp(scrollalign, "bottom", 6) == 0)
      align = SB_ALIGN_BOTTOM;
  }
  last_state = SB_STATE_OFF;
  /* cursor scrollBar: Black-on-White */
  leftptr_cursor = XCreateFontCursor(term->dpy, XC_left_ptr);
}

void scrollBar_t::destroy()
{
  XFreeGC(term->dpy, pscrollbarGC);
}

int scrollBar_t::color()
{
  return Color_border;
}

void scrollBar_t::update_data()
{
  beg = 0;
  end = term->szHint.height;
  update = &scrollBar_t::show_plain;
}

/*----------------------- end-of-file (C source) -----------------------*/
