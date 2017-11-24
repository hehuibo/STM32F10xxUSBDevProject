#include "main.h"

int main(void)
{	
  uint8_t i = 0;
  AppTaskInit();

  while(1){
    for(i=0; i< MAX_FUNCITEM; i++){
      g_fnAppTaskAry[i]();
    }
    i = 0;			
  }
}

