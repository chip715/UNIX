#include "everything.h"

//try 1
// int main(int argc, char* argv[]) 
// {
// //now to make a sweep the freq has to change.
// //as the time goes, freq goes down
// float length_of_sound = 5;//pretend this is in seconds for me
// for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)//told me to change to int
// {
//     float impulse_wave = 0; 
//     float t =  duration/SAMPLE_RATE; //how to calulate current decrete sample moment
//     double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);//was suggested to use Scale  works similary to max
//     float current_freq = mtof(current_note);
//     int max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));//calcuate the current MAX number of Harmonics
//         for(int n = 1; n < max_number_of_harmonic; n ++)
//         {
//             impulse_wave += sin(n * 2 * pi* current_freq * t);
//         }
//           mono((impulse_wave/max_number_of_harmonic)*0.707); //Told me I need to put this in mono and refer to Everthing.h, not sure why

    
//   }
// }
// try 2

// int main(int argc, char* argv[]) 
// {

// //i need to store the current phase
// float phase = 0;
// float length_of_sound = 5;//pretend this is in seconds for me
// for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)//told me to change to int
// {
//     float impulse_wave = 0; 
//     float t =  (1.0 * duration)/SAMPLE_RATE; // it told me that it might be a zero dividing 2 integers together
//     double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);//was suggested to use Scale  works similary to max
//     float current_freq = mtof(current_note);
//     int max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));//calcuate the current MAX number of Harmonics
//         for(int n = 1; n < max_number_of_harmonic; n ++)
//         {
//             impulse_wave += sin(n * 2 * pi* phase); // told me to get rid of t not quite sure if I understand, because I have extra unit of sample
//         }
//           mono((impulse_wave/max_number_of_harmonic)*0.707); //Told me I need to put this in mono and refer to Everthing.h, not sure why
//           phase += current_freq / SAMPLE_RATE;
//             if (phase > 1.0)  // prevents pit curshing
//                 phase -= 1.0;
    
//   }
// }


//try 3
//I asked gemini why this code doest not produce most smooth sound
//I tried the suggestion but I dont know if it fixed it.
// int main(int argc, char* argv[]) 
// {

// float phase = 0;
// float length_of_sound = 5;

// for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
// {
//     float impulse_wave = 0; 
//     float t =  (1.0 * duration)/SAMPLE_RATE; 
//     double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);
//     float current_freq = mtof(current_note);
//     float max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));
//     int rounded_max_number_harm = max_number_of_harmonic;
//     if(rounded_max_number_harm <1) rounded_max_number_harm = 1;

//         for(int n = 1; n <= rounded_max_number_harm; n ++)// added equal sign cause at first there is 0 harmonic
//         {
//             impulse_wave += sin(n * 2 * pi* phase); 
//         }

//         float output=impulse_wave/rounded_max_number_harm ;//the max number of Harmonic is int, and since ints does rounding, it make it unsmooth, so if we do calcuation before hand it will be better?
//           mono(output* 0.707); 
//           phase += current_freq / SAMPLE_RATE;
//             if (phase > 1.0)  
//                 phase -= 1.0;
    
//   }
// }


//try no 4 
// int main(int argc, char* argv[]) 
// {

// float phase = 0;
// float length_of_sound = 5;

// for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
// {
//     float impulse_wave = 0; 
//     float t =  (1.0 * duration)/SAMPLE_RATE; 
//     double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);
//     float current_freq = mtof(current_note);
//     float max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));
//     int rounded_max_number_harm = max_number_of_harmonic;
//     float fade_amount = max_number_of_harmonic - rounded_max_number_harm;

//     if(rounded_max_number_harm <1) rounded_max_number_harm = 1;

//         for(int n = 1; n <= rounded_max_number_harm; n ++)// added equal sign cause at first there is 0 harmonic
//         {
//             impulse_wave += sin(n * 2 * pi* phase); 
//         }
//         if (fade_amount>0)
//             impulse_wave += sin((rounded_max_number_harm+1) * 2 * pi* phase) * fade_amount; //this part was given by Gemini to smooth out the bumps. but seems to lower the amplituded of the the most recent harmonic by the ration of what the difference is between the floating harmonic limit and rounded harmonic limit
//         float output=impulse_wave/(max_number_of_harmonic) ;//the max number of Harmonic is int, and since ints does rounding, it make it unsmooth, so if we do calcuation before hand it will be better?
//           mono(output* 0.707); 
//           phase += current_freq / SAMPLE_RATE;
//             if (phase > 1.0)  
//                 phase -= 1.0;
    
//   }
// }

int main(int argc, char* argv[]) 
{

float phase = 0;
float length_of_sound = 5;

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
{
    float impulse_wave = 0; 
    float t =  (1.0 * duration)/SAMPLE_RATE; 
    double current_note = scale(t, 0, length_of_sound, 127.0, 0.0);
    float current_freq = mtof(current_note);
    float max_number_of_harmonic = (SAMPLE_RATE/(2 * current_freq));
    int rounded_max_number_harm = max_number_of_harmonic;
    float fade_amount = max_number_of_harmonic - rounded_max_number_harm;

    if(rounded_max_number_harm <1) rounded_max_number_harm = 1;

        for(int n = 1; n <= rounded_max_number_harm; n ++)// added equal sign cause at first there is 0 harmonic
        {
            impulse_wave += sin(n * 2 * pi* phase); 
        }
        if (fade_amount>0)
            impulse_wave += sin((rounded_max_number_harm+1) * 2 * pi* phase) * fade_amount; //this part was given by Gemini to smooth out the bumps. but seems to lower the amplituded of the the most recent harmonic by the ration of what the difference is between the floating harmonic limit and rounded harmonic limit
        float output=impulse_wave/(max_number_of_harmonic) ;//the max number of Harmonic is int, and since ints does rounding, it make it unsmooth, so if we do calcuation before hand it will be better?
          mono(output* 0.707); 
          phase += current_freq / SAMPLE_RATE;
            if (phase > 1.0)  
                phase -= 1.0;
    
  }
}