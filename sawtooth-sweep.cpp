#include "everything.h"

int main(int argc, char* argv[]) 
{

float phase = 0;
float length_of_sound = 5;

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
{
    float sawtooth_wave= 0; 
    float t =  (1.0 * duration)/SAMPLE_RATE; 
    double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);
    float current_freq = mtof(current_note);
    float max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));
    int rounded_max_number_harm = max_number_of_harmonic;
    float fade_amount = max_number_of_harmonic - rounded_max_number_harm;

    if(rounded_max_number_harm <1) rounded_max_number_harm = 1;

        for(int n = 1; n <= rounded_max_number_harm; n ++)
        {
             sawtooth_wave += ((sin(n * 2 * pi* phase))/n);
        }
    //    if (fade_amount>0)
           // sawtooth_wave += (sin((rounded_max_number_harm) * 2 * pi* phase)/(rounded_max_number_harm+1)) * fade_amount;
            float output = sawtooth_wave * 0.5; 
          mono(output* 0.707); 
          phase += current_freq / SAMPLE_RATE;
            if (phase > 1.0)  
                phase -= 1.0;
    
  }
}