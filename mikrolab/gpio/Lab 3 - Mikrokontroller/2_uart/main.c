
#include "stdint.h"
#include "gpio.h"
#include "uart.h"
#include "stdio.h"

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for (int i = 0; i<count;i++) {
		uart_send(*letter);
		letter++;
	}
	return count;
}

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTSET = (1 << i);
	}
	for(int i = 13; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	
	int sleep = 0;

	uart_init();

	while(1) {

		if (!(GPIO->IN & (1 << 17))) { //A
			for(int i = 13; i <= 15; i++){
				GPIO->OUTSET = (1 << i);
			}
			uart_send('A');
		}
		if (!(GPIO->IN & (1 << 26))) { //Bb
			for(int i = 4; i <= 15; i++){
				GPIO->OUTCLR = (1 << i);
			}
			uart_send('B');
		}
		char c = uart_read();
		if(c != '\0'){
			iprintf("char: %c\n\r", c);
		}


		sleep = 10000;
		while(--sleep);
	}



	return 0;
}