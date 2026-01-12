#include "everything.h"

int main(int argc, char* argv[]) 
{

float phase = 0;
float length_of_sound = 5;

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
{
    float triangle_wave= 0; 
    float t =  (1.0 * duration)/SAMPLE_RATE; 
    double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);
    float current_freq = mtof(current_note);
    float max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));
    int rounded_max_number_harm = max_number_of_harmonic;
    float fade_amount = max_number_of_harmonic - rounded_max_number_harm;
    float flip_flop = 1.0;
    if(rounded_max_number_harm <1) rounded_max_number_harm = 1;

        for(int n = 1; n <= rounded_max_number_harm; n +=2)
        {
             triangle_wave += (flip_flop * sin(n * 2 * pi* phase))/(n * n);
             flip_flop *= -1;
        }
   
        float output = triangle_wave * 8/(pi * pi) ; 
        mono(output* 0.707); 

          phase += current_freq / SAMPLE_RATE;
            if (phase > 1.0)  
                phase -= 1.0;
    
  }
}