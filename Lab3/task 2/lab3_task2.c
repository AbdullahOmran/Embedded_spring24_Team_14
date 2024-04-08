
#define GPIOB_BASE_ADDR		0x40020400
#define GPIOB_MODER			(*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER		(*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOB_PUPDR			(*(unsigned long *)(GPIOB_BASE_ADDR + 0x0c))
#define GPIOB_ODR			(*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))
#define GPIOB_IDR			(*(unsigned long *)(GPIOB_BASE_ADDR + 0x10))
#define RCC_AHB1ENR			(*(unsigned long *)(0x40023800 + 0x30))
#define TRUE				1
#define FALSE				0

void initialize_LEDs(void);
void initialize_button(void);
void initialize(void);
void delay(unsigned int milliseconds);

int main(void){

	initialize();
	unsigned char btnState = 0;
	unsigned char prevBtnState = 0;
	unsigned int active_pin = 0;

	while (TRUE)
	{
		// read button
		btnState = (GPIOB_IDR & (0x01 << 3)) >> 3;
		// detect falling edge (button press)
		if(prevBtnState && !btnState){
			// code for changing color of the LED
			GPIOB_ODR &= ~(0x01 << 5);
			GPIOB_ODR &= ~(0x01 << 6);
			GPIOB_ODR &= ~(0x01 << 7);

			if (active_pin & (0x01)){
				GPIOB_ODR &= ~(0x01 << 5);
				GPIOB_ODR |= (0x01 << 5);
			}
			if ((active_pin & (0x01 << 1)) >> 1){
				GPIOB_ODR &= ~(0x01 << 6);
				GPIOB_ODR |= (0x01 << 6);
			}
			if ((active_pin & (0x01 << 2)) >> 2){
				GPIOB_ODR &= ~(0x01 << 7);
				GPIOB_ODR |= (0x01 << 7);
			}

			active_pin %= 8 ;
			active_pin++;

		}
		// update prev state
		prevBtnState = btnState;
		// add delay for debouncing
		delay(1000);
	}

	return 0;
}

void initialize_LEDs(void){
	for (unsigned int i = 5; i < 8; i++){
		GPIOB_MODER &= ~(0x03 << i*2);
		GPIOB_MODER |= (0x01 << i*2);
		GPIOB_OTYPER &= ~(0x01 << i*1);
		GPIOB_PUPDR &= ~(0x03 << i*2);
	}
}

void initialize_button(void){
	GPIOB_MODER &= ~(0x03 << 3*2);
	GPIOB_OTYPER &= ~(0x01 << 3*1);
	GPIOB_PUPDR &= ~(0x03 << 3*2);
	GPIOB_PUPDR |= (0x01 << 3*2);
}
void initialize(void){
	RCC_AHB1ENR |= (0x01 << 1);
	initialize_LEDs();
	initialize_button();
}
void delay(unsigned int milliseconds){
	for (unsigned int i = 0; i < milliseconds; i++){
        __asm("nop");
    }
}