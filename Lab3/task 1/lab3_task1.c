
#define GPIOB_BASE_ADDR		0x40020400
#define GPIOB_MODER			(*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER		(*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOB_ODR			(*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))
#define RCC_AHB1ENR			(*(unsigned long *)(0x40023800 + 0x30))
#define TRUE				1
#define FALSE				0


int main(void){

	RCC_AHB1ENR |= (0x01 << 1);
	GPIOB_MODER &= ~(0x03 << 3*2);
	GPIOB_MODER |= (0x01 << 3*2);
	GPIOB_OTYPER &= ~(0x01 << 3*1);
	GPIOB_ODR &= ~(0x01 << 3*1);
	GPIOB_ODR |= (0x01 << 3*1);
	while(TRUE){
		GPIOB_ODR &= ~(0x01 << 3*1);
		
		for( unsigned int i = 0; i < 10000; i++){
			__asm("nop");
		}
       GPIOB_ODR |= (0x01 << 3*1);
	}

	return 0;
}
