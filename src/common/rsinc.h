// all resource indices, used by rxvt.h and rxvtperl.xs

  def (display_name)
  def (term_name)
  def (iconName)
  def (geometry)
  def (reverseVideo)
  def (chdir)
  def (color)
  reserve (color, TOTAL_COLORS)
  def (font)
#if ENABLE_STYLES
  def (boldFont)
  def (italicFont)
  def (boldItalicFont)
  def (intensityStyles)
#endif
  def (name)
  def (title)
  def (loginShell)
  def (multiClickTime)
  def (jumpScroll)
  def (skipScroll)
  def (scrollBar)
  def (scrollBar_floating)
  def (scrollBar_align)
  def (scrollBar_thickness)
  def (scrollTtyOutput)
  def (scrollTtyKeypress)
  def (scrollWithBuffer)
  def (saveLines)
  def (utmpInhibit)
  def (visualBell)
#if ! defined(NO_MAPALERT) && defined(MAPALERT_OPTION)
  def (mapAlert)
#endif
#ifdef META8_OPTION
  def (meta8)
#endif
#ifdef MOUSE_WHEEL
  def (mouseWheelScrollPage)
#endif
  def (backspace_key)

  def (delete_key)

#ifdef PRINTPIPE
  def (print_pipe)
#endif
#if USE_XIM
  def (preeditType)
  def (inputMethod)
#endif
#if XFT
  def (buffered)
#endif
#if ENABLE_FRILLS
  def (depth)
  def (visual)
  def (transient_for)
  def (override_redirect)
  def (pty_fd)
  def (hold)
  def (ext_bwidth)
  def (int_bwidth)
  def (borderLess)
  def (lineSpace)
  def (letterSpace)
  def (cursorUnderline)
  def (urgentOnBell)
  def (refreshRate)
#endif
#if BUILTIN_GLYPHS
  def (skipBuiltinGlyphs)
#endif
#if CURSOR_BLINK
  def (cursorBlink)
#endif
#if ENABLE_XEMBED
  def (embed)
#endif
  def (cutchars)
  def (modifier)
  def (answerbackstring)
#if ENABLE_FRILLS
  def (tripleclickwords)
  def (disablePasteBrackets)
#endif
  def (insecure)
  def (pointerBlank)
  def (pointerBlankDelay)
  def (imLocale)
  def (imFont)
  def (pastableTabs)
#ifndef NO_SECONDARY_SCREEN
  def (secondaryScreen)
  def (secondaryScroll)
#endif
#if ENABLE_FRILLS
  def (rewrapMode)
#endif
#if OFF_FOCUS_FADING
  def (fade)
#endif

#if ISO_14755
  def (iso14755)
  def (iso14755_52)
#endif
#if ENABLE_EWMH
  def (iconfile)
#endif
#ifdef HAVE_XMU
  def (pointerShape)
#endif
