#include "traffic_lights.h"

void init(unsigned char *lights)
{
    *lights &= ~(*lights);
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    unsigned char mask = 1 << (light_num - 1);
    *lights |= mask;
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    unsigned char mask = ~(1 << (light_num - 1));
    *lights &= mask;
}

void next_step(unsigned char *lights)
{
    unsigned char test = 1 << (sizeof(unsigned char) * 4 - 1);
    unsigned char mask = (*lights & test) == 0 ? 0 : 1;
    *lights = 0x0F & ((*lights << 1) | mask);
}

void reverse(unsigned char *lights)
{
    *lights = 0x0F & ~(*lights);
}

void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    if (lights_1 == lights_2)
    {
        return;
    }

    *lights_1 ^= *lights_2;
    *lights_2 = *lights_1 ^ *lights_2;
    *lights_1 ^= *lights_2;
}
