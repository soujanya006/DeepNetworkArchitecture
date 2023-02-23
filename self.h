#include <iostream>
#include <hls_vector.h>
#include <hls_math.h>

void softmax(hls::vector<hls::vector<double ,8>,4> &x,hls::vector<hls::vector<double ,8>,4> &attention) {
    int n = x.size();
    int m = x[0].size();
    hls::vector<hls::vector<double,8>,4> temp= {
    		{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
			{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
			{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
		    { 0, 0, 0 , 0 , 0 , 0,0 ,0 },
    };
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            temp[i][j] = hls::exp(x[i][j]);
        }
    }
    hls::vector<hls::vector<double,8>,4> temp2= {
    		{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
			{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
			{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
		    { 0, 0, 0 , 0 , 0 , 0,0 ,0 },
    };

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temp[i][j];
        }
        for (int j=0;j<m;j++){
        	temp2[i][j]=temp[i][j]/sum;
        }
    }

    for (int i = 0; i < n; i++){
    	for (int j=0;j<m;j++){
    		attention[i][j]=temp2[i][j];
    	}
    }
}


void get_self_attention(hls::vector<hls::vector<double,8>,4>& q,hls::vector<hls::vector<double,8>,4>
		& k,hls::vector<hls::vector<double,8>,4>& v,hls::vector<hls::vector<double,8>,4>
		&attention )
{
    hls::vector<hls::vector<double,8>,4> scaled= {
    		{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
			{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
			{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
		    { 0, 0, 0 , 0 , 0 , 0,0 ,0 },
    };
    int d_k=8;
    double scale = 1 / sqrt(d_k);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            double sum = 0;
            for (int t = 0; t < d_k; t++) {
                sum += q[i][t] * k[j][t];
            }
            scaled[i][j] = scale * sum;
        }
    }

      softmax(scaled,attention);


}