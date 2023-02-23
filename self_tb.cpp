#include <iostream>
#include "SA.h"

hls::vector<hls::vector<double,8>,4> q={
		{ 0.11672673, -2.54870451, -1.44065948 , 0.93661829 , 1.36278968 , 1.04252277,-0.01310938 ,-1.3163937 },
		{ 0.26721599 ,-0.90218255 , 0.07417847 ,-0.10430246,  0.52684253, -0.07081531,-0.60511725 ,-0.55225527},
		{-0.93297509 , 0.28724456,  1.37184579 , 0.41589874,  0.34981245, -0.24753755,-1.24497125, 0.05044148},
		{-0.11414585 ,-0.01545749 ,-0.58376828 ,-0.40193907 , 0.93931836 ,-1.94334363,-0.34770465 , 1.50103406}
};


hls::vector<hls::vector<double,8>,4> k={
		{ 0.11672673, -2.54870451, -1.44065948 , 0.93661829 , 1.36278968 , 1.04252277,-0.01310938 ,-1.3163937 },
		{ 0.26721599 ,-0.90218255 , 0.07417847 ,-0.10430246,  0.52684253, -0.07081531,-0.60511725 ,-0.55225527},
		{-0.93297509 , 0.28724456,  1.37184579 , 0.41589874,  0.34981245, -0.24753755,-1.24497125, 0.05044148},
		{-0.11414585 ,-0.01545749 ,-0.58376828 ,-0.40193907 , 0.93931836 ,-1.94334363,-0.34770465 , 1.50103406}
};


hls::vector<hls::vector<double,8>,4> v={
		{ 0.11672673, -2.54870451, -1.44065948 , 0.93661829 , 1.36278968 , 1.04252277,-0.01310938 ,-1.3163937 },
		{ 0.26721599 ,-0.90218255 , 0.07417847 ,-0.10430246,  0.52684253, -0.07081531,-0.60511725 ,-0.55225527},
		{-0.93297509 , 0.28724456,  1.37184579 , 0.41589874,  0.34981245, -0.24753755,-1.24497125, 0.05044148},
		{-0.11414585 ,-0.01545749 ,-0.58376828 ,-0.40193907 , 0.93931836 ,-1.94334363,-0.34770465 , 1.50103406}
};


hls::vector<hls::vector<double,8>,4> attention=  {
		{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
		{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
		{ 0, 0, 0 , 0 , 0 , 0,0 ,0 },
	    { 0, 0, 0 , 0 , 0 , 0,0 ,0 },
};

int main() {
	get_self_attention(q,k,v,attention);
	int size=attention.size();
	for(int i=0;i<attention.size();i++){
		for(int j=0;j<attention[i].size();j++){
		std::cout<<attention[i][j]<<" ";
		}
		std::cout<<std::endl;
	}


    return 0;
}