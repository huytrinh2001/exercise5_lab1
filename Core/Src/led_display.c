#include "main.h"
#include"led_display.h"
#define NUMBER_OF_SEVEN_SEGMENT_LED 	1
#define NUMBER_OF_DECIMAL 				10


uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL]={0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f};

uint8_t sevenSegmentLEDBuffer[NUMBER_OF_SEVEN_SEGMENT_LED];
uint8_t update_7_segment_led_buffer(uint8_t val, uint8_t idx){
	if(idx>=NUMBER_OF_DECIMAL) return 0;
	sevenSegmentLEDBuffer[idx]=val;
	return 1;
}



void seven_segment_led_driver(void){
	uint8_t temp = sevenSegmentLEDConversion[sevenSegmentLEDBuffer[0]];
	if(temp & 0x01){
		HAL_GPIO_WritePin(A_SEGMENT_GPIO_Port,A_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(A_SEGMENT_GPIO_Port,A_SEGMENT_Pin,SET);
	}
	if(temp & 0x02){
		HAL_GPIO_WritePin(B_SEGMENT_GPIO_Port,B_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(B_SEGMENT_GPIO_Port,B_SEGMENT_Pin,SET);
	}
	if(temp & 0x04){
		HAL_GPIO_WritePin(C_SEGMENT_GPIO_Port,C_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(C_SEGMENT_GPIO_Port,C_SEGMENT_Pin,SET);
	}
	if(temp & 0x08){
		HAL_GPIO_WritePin(D_SEGMENT_GPIO_Port,D_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(D_SEGMENT_GPIO_Port,D_SEGMENT_Pin,SET);
	}
	if(temp & 0x10){
		HAL_GPIO_WritePin(E_SEGMENT_GPIO_Port,E_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(E_SEGMENT_GPIO_Port,E_SEGMENT_Pin,SET);
	}
	if(temp & 0x20){
		HAL_GPIO_WritePin(F_SEGMENT_GPIO_Port,F_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(F_SEGMENT_GPIO_Port,F_SEGMENT_Pin,SET);
	}
	if(temp & 0x40){
		HAL_GPIO_WritePin(G_SEGMENT_GPIO_Port,G_SEGMENT_Pin,RESET);
	}
	else{
		HAL_GPIO_WritePin(G_SEGMENT_GPIO_Port,G_SEGMENT_Pin,SET);
	}

}

void traffic_LED(uint8_t value){
	if(value>=0 && value<=3){
		HAL_GPIO_WritePin(RED_LED_1_GPIO_Port,RED_LED_1_Pin,SET);
		HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port,YELLOW_LED_1_Pin,SET);
		HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port,GREEN_LED_1_Pin,RESET);

		HAL_GPIO_WritePin(RED_LED_2_GPIO_Port,RED_LED_2_Pin,RESET);
		HAL_GPIO_WritePin(YELLOW_LED_2_GPIO_Port,YELLOW_LED_2_Pin,SET);
		HAL_GPIO_WritePin(GREEN_LED_2_GPIO_Port,GREEN_LED_2_Pin,SET);
	}

	if(value>=4 && value<=5){
		HAL_GPIO_WritePin(RED_LED_1_GPIO_Port,RED_LED_1_Pin,SET);
		HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port,YELLOW_LED_1_Pin,RESET);
		HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port,GREEN_LED_1_Pin,SET);

		HAL_GPIO_WritePin(RED_LED_2_GPIO_Port,RED_LED_2_Pin,SET);
		HAL_GPIO_WritePin(YELLOW_LED_2_GPIO_Port,YELLOW_LED_2_Pin,RESET);
		HAL_GPIO_WritePin(GREEN_LED_2_GPIO_Port,GREEN_LED_2_Pin,SET);
	}

	if(value>=6 && value<=9){
		HAL_GPIO_WritePin(RED_LED_1_GPIO_Port,RED_LED_1_Pin,RESET);
		HAL_GPIO_WritePin(YELLOW_LED_1_GPIO_Port,YELLOW_LED_1_Pin,SET);
		HAL_GPIO_WritePin(GREEN_LED_1_GPIO_Port,GREEN_LED_1_Pin,SET);

		HAL_GPIO_WritePin(RED_LED_2_GPIO_Port,RED_LED_2_Pin,SET);
		HAL_GPIO_WritePin(YELLOW_LED_2_GPIO_Port,YELLOW_LED_2_Pin,SET);
		HAL_GPIO_WritePin(GREEN_LED_2_GPIO_Port,GREEN_LED_2_Pin,RESET);
	}
}
