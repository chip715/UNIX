#include "everything.h"
//change math to square
int main(int argc, char* argv[]) {

float freq = 440;
int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
float length_of_sound = 5;

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
{
    float square_wave = 0; 
    float t =  duration/SAMPLE_RATE; 
    for(int n = 1; n < max_number_of_harmonic; n += 2)
    {
        square_wave += sin(n * 2 * pi* freq * t)/n;
    }
      mono(((4/pi) * square_wave) * 0.707); 
}
}
