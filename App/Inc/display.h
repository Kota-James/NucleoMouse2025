#ifndef __DISPLAY_H
#define __DISPLAY_H

#define min(A,B) ((A)>(B))?(B):(A)
#define max(A,B) ((A)>(B))?(A):(B)


void led_write(uint8_t, uint8_t, uint8_t);
void led_write_2(uint8_t);
int select_mode(int);
int __io_putchar(int);


#endif /* __DISPLAY_H */