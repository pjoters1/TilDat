#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main(){
    // Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

    GPIOTE->CONFIG[0] = (1)|(17 << 8)|(2 << 16);
    GPIOTE->CONFIG[1] = (3)|(13 << 8)|(3 << 16);
    GPIOTE->CONFIG[2] = (3)|(14 << 8)|(3 << 16);
    GPIOTE->CONFIG[3] = (3)|(15 << 8)|(3 << 16);

    GPIOTE->INTEN = 1;
    //ppi
	PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->OUT[1]);

	PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[2]);

	PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[3]);

	PPI->CHEN = 0x111;

    int sleep = 0;
    while(1){


        sleep = 10000;
        while(--sleep);
    }
    return 0;
}