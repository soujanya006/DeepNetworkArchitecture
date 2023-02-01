#include <iostream>
#include <hls_vector.h>
#include "hls_math.h"


void get_exp(float& input,float& output){
 output=hls::exp(input);
}
void get_sum(float& sum,float& destination1){
 sum=sum+destination1;
}

// void get_div(float& destination2,float& sum, float&temp){
//  temp=destination2/sum;
// }

void get_softmax(hls::vector<float,4>& input,hls::vector<float,4>& destination){

   float sum=0.0;
   int size=4;
   float destination1;
   hls::vector<float, 4> local_temp_new;
   for (int i =0;i<size;i++) {
    get_exp(input[i],destination1);
    local_temp_new[i]=destination1;
   }
   for (int i=0;i<size;i++){
    sum+=local_temp_new[i];
   }
   float temp_sum=sum;
   hls::vector<float, 4> local_temp ;
   float temp;
   float destination2;
   for (int i = 0; i < size; i++) {
    get_exp(input[i],destination2);
    // get_div(destination2,sum,temp);
     local_temp[i] = destination2;
   }
   hls::vector<float, 4> local_temp2;
   for (int i=0;i<size;i++){
    local_temp2[i]=local_temp[i]/temp_sum;
   }
 for(int i =0;i<size;i++){
  destination[i]=local_temp2[i];
 }


}