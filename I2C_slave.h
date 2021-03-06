#ifndef I2C_SLAVE_H
#define I2C_SLAVE_H

volatile uint8_t buffer_address;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];
volatile uint8_t datalog[0xFF],dataloglevel;
void I2C_init(uint8_t address);
void I2C_stop(void);
ISR(TWI_vect);

char last_status;

#endif // I2C_SLAVE_H
