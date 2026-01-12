#include "everything.h"
//change the math to be a sawtooth
int main(int argc, char* argv[]) {
float freq = 440;
int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
float length_of_sound = 5;

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
{
    float sawtooth_wave = 0; 
    float t =  duration/SAMPLE_RATE; 
    for(int n = 1; n < max_number_of_harmonic; n ++)
    {
        sawtooth_wave += ((sin(n * 2 * pi* freq * t))/n);
    }
      mono(sawtooth_wave * 0.5); 
}

}
