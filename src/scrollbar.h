#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <X11/Xlib.h>

#include "rxvtutil.h"

struct rxvt_term;


#define SB_WIDTH_PLAIN 7


/*
 * NeXT scrollbar defines
 */
#define SB_PADDING 1
#define SB_BORDER_WIDTH 1
#define SB_BEVEL_WIDTH_UPPER_LEFT 1
#define SB_BEVEL_WIDTH_LOWER_RIGHT 2
#define SB_LEFT_PADDING (SB_PADDING + SB_BORDER_WIDTH)
#define SB_MARGIN_SPACE (SB_PADDING * 2)
#define SB_BUTTON_WIDTH (SB_WIDTH_NEXT - SB_MARGIN_SPACE - SB_BORDER_WIDTH)
#define SB_BUTTON_HEIGHT (SB_BUTTON_WIDTH)
#define SB_BUTTON_SINGLE_HEIGHT (SB_BUTTON_HEIGHT + SB_PADDING)
#define SB_BUTTON_BOTH_HEIGHT (SB_BUTTON_SINGLE_HEIGHT * 2)
#define SB_BUTTON_TOTAL_HEIGHT (SB_BUTTON_BOTH_HEIGHT + SB_PADDING)
#define SB_BUTTON_BEVEL_X (SB_LEFT_PADDING)
#define SB_BUTTON_FACE_X (SB_BUTTON_BEVEL_X + SB_BEVEL_WIDTH_UPPER_LEFT)
#define SB_THUMB_MIN_HEIGHT (SB_BUTTON_WIDTH - (SB_PADDING * 2))

enum sb_state {
  SB_STATE_OFF,
  SB_STATE_IDLE,
  SB_STATE_MOTION,
  SB_STATE_UP,
  SB_STATE_DOWN,
};


enum sb_align {
  SB_ALIGN_CENTRE,
  SB_ALIGN_TOP,
  SB_ALIGN_BOTTOM,
};

struct scrollBar_t {
  rxvt_term *term;
  sb_state state; /* scrollbar state                          */
  bool init;      /* scrollbar has been initialised           */
  int beg;        /* slider sub-window begin height           */
  int end;        /* slider sub-window end height             */
  int top;        /* slider top position                      */
  int bot;        /* slider bottom position                   */
  int width;      /* scrollbar width                          */
  int shadow;     /* scrollbar shadow width                   */
  int last_bot;   /* scrollbar last bottom position           */
  int last_top;   /* scrollbar last top position              */
  int last_state; /* scrollbar last state                     */
  sb_align align;
  Window win;
  Cursor leftptr_cursor;
  int (scrollBar_t::*update)(int);
  void setup(rxvt_term *);
  void resize();
  void map(int);
  int show(int);
  void destroy();
  int color();

  bool upButton(int y)
  {
    return false;
  }
  bool dnButton(int y)
  {
    return false;
  }
  int min_height()
  {
    return 10;
  }
  int size()
  {
    return max(end - beg, 0);
  }
  int total_width()
  {
    return width + shadow * 2;
  }
  bool above_slider(int y)
  {
    return y < top;
  }
  bool below_slider(int y)
  {
    return y > bot;
  }
  int position(int y)
  {
    return y - beg;
  }

  GC pscrollbarGC;

 private:
  // update style dependent data
  void update_data();

  // scrollbar-next.C
  int show_next(int);
  // scrollbar-rxvt.C
  int show_rxvt(int);
  // scrollbar-xterm.C
  int show_xterm(int);
  // scrollbar-plain.C
  int show_plain(int);

  void init_next();
};

/*
 *    +-------------+
 *    |             | <---< SB_PADDING
 *    | ::::::::::: |
 *    | ::::::::::: |
 *   '''''''''''''''''
 *   ,,,,,,,,,,,,,,,,,
 *    | ::::::::::: |
 *    | ::::::::::: |
 *    |  +---------------< SB_BEVEL_WIDTH_UPPER_LEFT
 *    |  | :::::::: |
 *    |  V :::: vv-------< SB_BEVEL_WIDTH_LOWER_RIGHT
 *    | +---------+ |
 *    | | ......%%| |
 *    | | ......%%| |
 *    | | .. ()..%%| |
 *    | | ......%%| |
 *    | | %%%%%%%%| |
 *    | +---------+ | <.........................
 *    |             | <---< SB_PADDING         :
 *    | +---------+ | <-+..........            :---< SB_BUTTON_TOTAL_HEIGHT
 *    | | ......%%| |   |         :            :
 *    | | ../\..%%| |   |---< SB_BUTTON_HEIGHT :
 *    | | %%%%%%%%| |   |         :            :
 *    | +---------+ | <-+         :            :
 *    |             |             :            :
 *    | +---------+ | <-+         :---< SB_BUTTON_BOTH_HEIGHT
 *    | | ......%%| |   |         :            :
 *    | | ..\/..%%| |   |         :            :
 *    | | %%%%%%%%| |   |---< SB_BUTTON_SINGLE_HEIGHT
 *    | +---------+ |   |         :            :
 *    |             |   |         :            :
 *    +-------------+ <-+.........:............:
 *    ^^|_________| :
 *    ||     |      :
 *    ||     +---< SB_BUTTON_WIDTH
 *    ||            :
 *    |+------< SB_PADDING
 *    |:            :
 *    +----< SB_BORDER_WIDTH
 *     :            :
 *     :............:
 *           |
 *           +---< SB_WIDTH_NEXT
 */

#endif
