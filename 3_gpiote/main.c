#include <stdint.h>
#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main(){
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i); 
	}

    GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
	GPIO->PIN_CNF[15] = (3 << 2);
	GPIO->PIN_CNF[16] = (3 << 2);

    while(1){
        
    }

}