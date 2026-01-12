#include "everything.h"

int main(int argc, char* argv[]) {
//int max_number
//float freq
//float impulse_wave
//How to caluculate max number of harmonic
//nyquiest = samplerate/2
//for(int n = 1; n < max_number; n + 1)
//{
//impulse_wave = sin(n * 2 * pi* freq)
//}
//impulse_wave/max_number
//ran this code, and its telling me that it needs to calculate 48000 times per second

//Try 2
//tyring to caluculat max number of harmonic
//float freq = 440;
//int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
//float length_of_sound;

//for(int n = 1; n < max_number_of_harmonic; n ++)
//{
//    for(float duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
//    {
//    impulse_wave += sin(n * 2 * pi* freq * duration)
//    }
//
//}

//try 2 todl me my order of for loop was wrong

//here is try 3

//float freq = 440;
//int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
//float length_of_sound = 5;//pretend this is in seconds for me
//float t = length_of_sound/SAMPLE_RATE
//for(float duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
//{
   // float impulse_wave = 0 //I think this will be the value of samples to be printed out?
  //  for(int n = 1; n < max_number_of_harmonic; n ++)
   //     {
  //      
  //      impulse_wave += sin(n * 2 * pi* freq * t)
    //    }
//
//}

//try 4, telling me that my t variable isnt calculating

//float freq = 440;
//int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
//float length_of_sound = 5;//pretend this is in seconds for me

//for(float duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)
//{
  //  float impulse_wave = 0 //I think this will be the value of samples to be printed out?
   // float t =  duration/SAMPLE_RATE; //how to calulate current decrete sample moment
   // for(int n = 1; n < max_number_of_harmonic; n ++)
      //  {
        
      //  impulse_wave += sin(n * 2 * pi* freq * t)
       // }
        //impulse_wave/max_number_of_harmonic

//}


// try 5
//float freq = 440;
//int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
//float length_of_sound = 5;//pretend this is in seconds for me

//for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)//told me to change to int
//{
    //float impulse_wave = 0; //I think this will be the value of samples to be printed out?
    //float t =  duration/SAMPLE_RATE; //how to calulate current decrete sample moment
   // for(int n = 1; n < max_number_of_harmonic; n ++)
   // {
    ////impulse_wave += sin(n * 2 * pi* freq * t);
   // }
  //      float Current_Sample = impulse_wave/max_number_of_harmonic; //Told me I need to assign the value 

//}

//try 6

//float freq = 440;
//int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
//float length_of_sound = 5;//pretend this is in seconds for me

//for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)//told me to change to int
//{
 //   float impulse_wave = 0; //I think this will be the value of samples to be printed out?
   // float t =  duration/SAMPLE_RATE; //how to calulate current decrete sample moment
   // for(int n = 1; n < max_number_of_harmonic; n ++)
   // {
   //     impulse_wave += sin(n * 2 * pi* freq * t);
    //}
   //   mono(impulse_wave/max_number_of_harmonic); //Told me I need to put this in mono and refer to Everthing.h, not sure why

//}

float freq = 440;
int max_number_of_harmonic = (SAMPLE_RATE/(2 * freq));
float length_of_sound = 5;//pretend this is in seconds for me

for(int duration = 0; duration < length_of_sound * SAMPLE_RATE; duration++)//told me to change to int
{
    float impulse_wave = 0; //I think this will be the value of samples to be printed out?
    float t =  duration/SAMPLE_RATE; //how to calulate current decrete sample moment
    for(int n = 1; n < max_number_of_harmonic; n ++)
    {
        impulse_wave += sin(n * 2 * pi* freq * t);
    }
      mono(impulse_wave/max_number_of_harmonic); //Told me I need to put this in mono and refer to Everthing.h, not sure why

}

}
