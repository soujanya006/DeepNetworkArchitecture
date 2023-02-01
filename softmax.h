#include <iostream>
#include <hls_vector.h>
#include "hls_math.h"



void get_exp(float& input, float& destination){
// if(input==-23){
//  destination=hls::exp(input);
// }
// else if(input==3){
//  destination=0.4065696597;
// }
// else {
//  destination=0.0;
// }
 destination=hls::exp(input);
}

void get_softmax(hls::vector<float,4>& input,hls::vector<float,4>& destination){

 int i;
 float m, constant;


 m = -10000.0;
 int size=4;
 for (i = 0; i < size; ++i) {
  if (m < input[i]) {
   m = input[i];
  }
 }



 static float sum = 0.0;

 #pragma HLS DEPENDENCE variable=sum type=intra direction=RAW dependent=true
 float destination1;
 for (i = 0; i < size; ++i) {
  float temp=input[i] - m;
  get_exp(temp,destination1);
  sum += destination1;
 }

 hls::vector<float, 4> local_temp ;

 constant = m + hls::log(sum);
 float destination2;
 for (i = 0; i < size; ++i) {
  float temp=input[i] - constant;
  get_exp(temp,destination2);
  //input[i]=destination2;
  local_temp[i] = destination2;
 }

 for(i =0;i<size;i++){
  destination[i]=local_temp[i];
 }
}
