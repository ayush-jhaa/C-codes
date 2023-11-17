#include "types.h"
#include <lpc21xx.h>
#include "defines.h"

#define ROWS 16
#define COLS 20

u8 kpmLUT[4][4]=
{
    {7,8,9,10},
        {4,5,6,11},
        {1,2,3,12},
        {16,0,14,13}

};

void InitKPM(void)
{
    // cfg row lines are output
          WRITENIBBLE(IODIR1,ROWS,15);

          // COLOUMN LINES ARE DEFAULT INPUT

}

u8 colscan(void)
{
   u8 t;
   // return status of keypress.
   t= READNIBBLE(IOPIN1,COLS);
        return ((t<15)?0:1);
}
u8 rowcheck(void)
{
   u8 rNo;

   // check row in which key was pressed
    for(rNo=0;rNo<4;rNo++)
    {
                  // ground iteratively one row at  a time
                        // keeping all other row high
                   WRITENIBBLE(IOPIN1,ROWS,(~((1<<rNo)&15)) );
                         if(!(colscan()))
                         {
                            break;
                         }
                }
     // ground all rows
      WRITENIBBLE(IOPIN1,ROWS,0);
     // return row in which key was pressed 
      return rNo;
}

u8 colcheck()
{
  u8 cNo;
        // check col in which key was pressed

        for(cNo=0; cNo<4;cNo++)
        {
                if(!(((READNIBBLE(IOPIN1,COLS))>>cNo)&1))
                {
                   break;
                }

        }
           return cNo;
}

u8 keyscan()
{
  u8 rNo,cNo,keyV;

        // wait to detect any press

        while(colscan());

        // get row in which key was pressed
         rNo=rowcheck();

        // get col in which key was pressed
         cNo=colcheck();
        //map key pressed from look up table
        keyV=kpmLUT[rNo][cNo];

        // return key pressed
         return keyV;
}
