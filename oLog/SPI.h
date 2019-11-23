/*
 * SPI.h
 *
 * Created: 23.11.2019 12:53:18
 *  Author: lipsk
 */ 


#ifndef SPI_H_
#define SPI_H_

/* SPI pins configuration for OLED display */
#define DISPLAY_CLK_DIR     DDRB
#define DISPLAY_CLK_PORT    PORTB
#define DISPLAY_CLK_PIN     5

#define DISPLAY_DATA_DIR    DDRB
#define DISPLAY_DATA_PORT   PORTB
#define DISPLAY_DATA_PIN    3

#define DISPLAY_CS_DIR      DDRB
#define DISPLAY_CS_PORT     PORTB
#define DISPLAY_CS_PIN      2

#define DISPLAY_DC_DIR      DDRB
#define DISPLAY_DC_PORT     PORTB
#define DISPLAY_DC_PIN      1

#define DISPLAY_RESET_DIR   DDRB
#define DISPLAY_RESET_PORT  PORTB
#define DISPLAY_RESET_PIN   0



#endif /* SPI_H_ */