/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuHD44780.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : LCDHTA
**     Version     : Component 01.029, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-01-25, 20:51, # CodeGen: 409
**     Abstract    :
**          This component implements a driver for multiple 2x16 character displays.
**     Settings    :
**          Component name                                 : McuHD44780
**          HW Interface                                   : 
**            LCD Type                                     : generic
**            LCD Lines                                    : 2
**            Characters per Line                          : 16
**            Line Addresses                               : 
**              Line 1                                     : 0x00
**              Line 2                                     : 0x40
**              Line 3                                     : 0x10
**              Line 4                                     : 0x50
**            LCD Enable Signal                            : Disabled
**            Read from Display                            : Enabled
**              R/W signal                                 : SDK_BitIO
**              Check Busy Flag                            : yes
**            Wait (us)                                    : 0
**            E signal                                     : SDK_BitIO
**            E2                                           : Enabled
**              E2 signal                                  : SDK_BitIO
**            RS signal                                    : SDK_BitIO
**            Data/Control Bus                             : 
**              Data/Control Bus Width                     : 8bit
**              DB0..DB3                                   : Enabled
**                DB0                                      : SDK_BitIO
**                DB1                                      : SDK_BitIO
**                DB2                                      : SDK_BitIO
**                DB3                                      : SDK_BitIO
**              DB4..DB7                                   : Enabled
**                DB4                                      : SDK_BitIO
**                DB5                                      : SDK_BitIO
**                DB6                                      : SDK_BitIO
**                DB7                                      : SDK_BitIO
**              Bits/Byte Bus                              : Disabled
**          System Interface                               : 
**            Wait                                         : McuWait
**     Contents    :
**         WriteLCDCommand  - void McuHD44780_WriteLCDCommand(uint8_t cmd);
**         Write            - void McuHD44780_Write(char ch);
**         WriteLn          - void McuHD44780_WriteLn(void);
**         WriteLineStr     - void McuHD44780_WriteLineStr(uint8_t line, char *str);
**         WriteString      - void McuHD44780_WriteString(char *str);
**         LoadSoftChar     - void McuHD44780_LoadSoftChar(uint8_t charCode, uint8_t *softChar);
**         ShiftLeft        - void McuHD44780_ShiftLeft(void);
**         ShiftRight       - void McuHD44780_ShiftRight(void);
**         GotoXY           - void McuHD44780_GotoXY(uint8_t line, uint8_t column);
**         SetEntryMode     - void McuHD44780_SetEntryMode(bool increment, bool shiftLeft);
**         DisplayOn        - void McuHD44780_DisplayOn(void);
**         DisplayOff       - void McuHD44780_DisplayOff(void);
**         CursorOn         - void McuHD44780_CursorOn(void);
**         CursorOff        - void McuHD44780_CursorOff(void);
**         CursorShiftRight - void McuHD44780_CursorShiftRight(void);
**         CursorShiftLeft  - void McuHD44780_CursorShiftLeft(void);
**         BlinkingOn       - void McuHD44780_BlinkingOn(void);
**         BlinkingOff      - void McuHD44780_BlinkingOff(void);
**         Home             - void McuHD44780_Home(void);
**         Line             - void McuHD44780_Line(uint8_t line);
**         Clear            - void McuHD44780_Clear(void);
**         UseDisplay       - uint8_t McuHD44780_UseDisplay(uint8_t display);
**         DeInit           - void McuHD44780_DeInit(void);
**
** License   :  Open Source (LGPL)
** Copyright : (c) Copyright Erich Styger, 2008-2019, all rights reserved.
** http      : www.mcuoneclipse.com
** 
** This an open source software implementing software using Processor Expert.
** This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
** * This is a free software and there is NO WARRANTY.
** * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
** * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file McuHD44780.h
** @version 01.00
** @brief
**          This component implements a driver for multiple 2x16 character displays.
*/         
/*!
**  @addtogroup McuHD44780_module McuHD44780 module documentation
**  @{
*/         

#ifndef __McuHD44780_H
#define __McuHD44780_H

/* MODULE McuHD44780. */
#include "McuLib.h" /* SDK and API used */
#include "McuHD44780config.h" /* configuration */



/* ID's for the soft characters which can be used as first argument for McuHD44780_LoadSoftChar().
  Note that ID's can start with zero, but if you want to use a zero byte in McuHD44780_WriteString()
  then this would be the zero delimiter byte, so not very useful. */
#define McuHD44780_SOFTCHAR_UE 1 /*<! ID for '�' */
#define McuHD44780_SOFTCHAR_AE 2 /*<! ID for '�' */
#define McuHD44780_SOFTCHAR_OE 3 /*<! ID for '�' */

/* support for custom soft characters in the display which can be used with McuHD44780_LoadSoftChar() */
extern const uint8_t McuHD44780_SoftCharUE[8]; /* � */
extern const uint8_t McuHD44780_SoftCharAE[8]; /* � */
extern const uint8_t McuHD44780_SoftCharOE[8]; /* � */

#define McuHD44780_MAX_LCD_LINE_CHARS  16 /* number of chars of the LCD on a line */


void McuHD44780_WriteLCDData(uint8_t ch);
/*
** ===================================================================
**     Method      :  McuHD44780_WriteLCDData (component LCDHTA)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void McuHD44780_Init(void);
/*
** ===================================================================
**     Method      :  McuHD44780_Init (component LCDHTA)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void McuHD44780_Clear(void);
/*
** ===================================================================
**     Method      :  Clear (component LCDHTA)
**
**     Description :
**         Clears the display and moves the cursor to the first line.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_Home(void);
/*
** ===================================================================
**     Method      :  Home (component LCDHTA)
**
**     Description :
**         Moves the cursor to the beginning of the first line.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_GotoXY(uint8_t line, uint8_t column);
/*
** ===================================================================
**     Method      :  GotoXY (component LCDHTA)
**
**     Description :
**         Places the cursor on a specified position on the display.
**     Parameters  :
**         NAME            - DESCRIPTION
**         line            - Line number starting with 1
**         column          - Column number starting with 1
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_ShiftLeft(void);
/*
** ===================================================================
**     Method      :  ShiftLeft (component LCDHTA)
**
**     Description :
**         Shifts all characters to the left.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuHD44780_Write(ch)   McuHD44780_WriteLCDData((uint8_t)ch)
/*
** ===================================================================
**     Method      :  Write (component LCDHTA)
**
**     Description :
**         Write a single character to the display
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to write
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_WriteLn(void);
/*
** ===================================================================
**     Method      :  WriteLn (component LCDHTA)
**
**     Description :
**         Writes a new line to the display
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_WriteString(char *str);
/*
** ===================================================================
**     Method      :  WriteString (component LCDHTA)
**
**     Description :
**         Writes a string to the display at the current cursor
**         position.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string (zero byte terminated)
**                           to write to the display
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_WriteLineStr(uint8_t line, char *str);
/*
** ===================================================================
**     Method      :  WriteLineStr (component LCDHTA)
**
**     Description :
**         Writes a full line to the display (clears the rest of the
**         line).
**     Parameters  :
**         NAME            - DESCRIPTION
**         line            - Line number (starting with 1).
**       * str             - Pointer to the string which should be
**                           shown on the display.
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_LoadSoftChar(uint8_t charCode, uint8_t *softChar);
/*
** ===================================================================
**     Method      :  LoadSoftChar (component LCDHTA)
**
**     Description :
**         Loads a user defined (softchar) into the display CGRAM.
**     Parameters  :
**         NAME            - DESCRIPTION
**         charCode        - The character code to be defined
**                           (0..7)
**       * softChar        - Pointer to an array of 8 bytes
**                           defining the soft character
**                           Example of the soft character '�':
**                           const byte SoftCharUE[8] = { // �
**                           0x11, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0d, 0
**                           //  X...X
**                           //  .....
**                           //  X...X
**                           //  X...X
**                           //  X...X
**                           //  X..XX
**                           //  .XX.X
**                           };
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_Line(uint8_t line);
/*
** ===================================================================
**     Method      :  Line (component LCDHTA)
**
**     Description :
**         Sets the current line.
**     Parameters  :
**         NAME            - DESCRIPTION
**         line            - Line number, starting with 1
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_ShiftRight(void);
/*
** ===================================================================
**     Method      :  ShiftRight (component LCDHTA)
**
**     Description :
**         Shifts all characters to the right.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_CursorOn(void);
/*
** ===================================================================
**     Method      :  CursorOn (component LCDHTA)
**
**     Description :
**         Enables the cursor.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_CursorOff(void);
/*
** ===================================================================
**     Method      :  CursorOff (component LCDHTA)
**
**     Description :
**         Disables the cursor.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_DisplayOn(void);
/*
** ===================================================================
**     Method      :  DisplayOn (component LCDHTA)
**
**     Description :
**         Sends the display on command to the display.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_DisplayOff(void);
/*
** ===================================================================
**     Method      :  DisplayOff (component LCDHTA)
**
**     Description :
**         Sends the display off command to the display.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_BlinkingOn(void);
/*
** ===================================================================
**     Method      :  BlinkingOn (component LCDHTA)
**
**     Description :
**         Sends the display off command to the display.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_BlinkingOff(void);
/*
** ===================================================================
**     Method      :  BlinkingOff (component LCDHTA)
**
**     Description :
**         Puts the display in blinking off mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_SetEntryMode(bool increment, bool shiftLeft);
/*
** ===================================================================
**     Method      :  SetEntryMode (component LCDHTA)
**
**     Description :
**         Configures the display entry mode, if the cursor has to
**         shift and/or if the display shall shift content while
**         displaying text.
**     Parameters  :
**         NAME            - DESCRIPTION
**         increment       - Increments (TRUE) or
**                           decrements (FALSE) the display address by 1
**                           when a character code is written into or
**                           read from DDRAM. The cursor or blinking
**                           moves to the right when incremented by 1
**                           and to the left when decremented by 1.
**         shiftLeft       - The display does not shift if
**                           the 'shift' is FALSE. If 'shift' is TRUE,
**                           it will seem as if the cursor does not move
**                           but the display does.
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_WaitForLCDReady(void);
/*
** ===================================================================
**     Method      :  McuHD44780_WaitForLCDReady (component LCDHTA)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

uint8_t McuHD44780_UseDisplay(uint8_t display);
/*
** ===================================================================
**     Method      :  UseDisplay (component LCDHTA)
**
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         display         - Has to be either 1 (top display,
**                           using E1) or 2 (bottom display, using E2)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void McuHD44780_CursorShiftRight(void);
/*
** ===================================================================
**     Method      :  CursorShiftRight (component LCDHTA)
**
**     Description :
**         Shift the cursor to the right.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_CursorShiftLeft(void);
/*
** ===================================================================
**     Method      :  CursorShiftLeft (component LCDHTA)
**
**     Description :
**         Shift the cursor to the left.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_WriteLCDCommand(uint8_t cmd);
/*
** ===================================================================
**     Method      :  WriteLCDCommand (component LCDHTA)
**
**     Description :
**         Writes a command to the display
**     Parameters  :
**         NAME            - DESCRIPTION
**         cmd             - command passed to the LCD
**     Returns     : Nothing
** ===================================================================
*/

void McuHD44780_DeInit(void);
/*
** ===================================================================
**     Method      :  DeInit (component LCDHTA)
**
**     Description :
**         Driver de-initialization routine
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END McuHD44780. */

#endif
/* ifndef __McuHD44780_H */
/*!
** @}
*/
