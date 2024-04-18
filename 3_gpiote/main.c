#include <stdint.h>
#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main(){
	//initialiserer LED
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i); 
	}
	//initialiserer button_1
    GPIO->PIN_CNF[13] = (3 << 2);

    //Config button_1 og LED_1 - LED_4
	GPIOTE->CONFIG[0] = (1 << 0)|(13 << 8)|(2 << 16); //A=event=1, B=GPIO-pin=13,C=HiToLo=2

    GPIOTE->CONFIG[1] = (3 << 0)|(17 << 8)|(3 << 16)|(1 << 20); //A=task=3, B=GPIO-pin=17, C=Toggle=3, D=Initial Output Value = 1
    GPIOTE->CONFIG[2] = (3 << 0)|(18 << 8)|(3 << 16); //A=task=3, B=GPIO-pin=18, C=Toggle=3
    GPIOTE->CONFIG[3] = (3 << 0)|(19 << 8)|(3 << 16); //A=task=3, B=GPIO-pin=19, C=Toggle=3
    GPIOTE->CONFIG[4] = (3 << 0)|(20 << 8)|(3 << 16)|(1 << 20); //A=task=3, B=GPIO-pin=20, C=Toggle=3, D=Initial Output Value = 1

	PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]); //EventEndPoint=0(Button1)
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]); //TaskEndPoint=1(LED1)

    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]); //EventEndPoint=0(Button1)
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[2]); //TaskEndPoint=2(LED2)

    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]); //EventEndPoint=0(Button1)
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[3]); //TaskEndPoint=3(LED3)

    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]); //EventEndPoint=0(Button1)
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[4]); //TaskEndPoint=4(LED4)


    while(1){    
    }return 0;

}