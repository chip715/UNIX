#include "everything.h"
//change math to square
int main(int argc, char* argv[]) {

float freq = 440;
int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
float length_of_sound = 5;

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
{
    float triangle_wave = 0; 
    float t =  duration/SAMPLE_RATE; 
    float flip_flop = 1.0;
    for(int n = 1; n < max_number_of_harmonic; n += 2)
    {
        triangle_wave += (flip_flop * sin(n * 2 * pi* freq * t))/(n * n);
        //im pretty sure the - 1^((n-1)/2) just make 1 flip flop bewteen 1 and -1
        flip_flop *= -1;

    }
      mono(((8/(pi * pi)) * triangle_wave) * 0.707); 
}
}
