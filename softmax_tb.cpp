#include <iostream>
#include "softmax.h"


hls::vector<float, 4> my_array = {8, 1, 2, 3};
hls::vector<float, 4> softmax ;

int main() {


	get_softmax(my_array, softmax);



	 for (int i=0;i<softmax.size();++i)
	 {

		 std::cout<<softmax[i]<<"  ";
	 }
	 std::cout<<std::endl;

	 std::cout<<std::endl;
    return 0;
}
