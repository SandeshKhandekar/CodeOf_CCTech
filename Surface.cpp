#include <bits/stdc++.h>

using namespace std; 

float exposedToSun(vector<vector<float>> building, double point[]){ 
	map<float,vector<float>> columns; 
	for(auto i:building) 
		columns[i[0]].push_back(i[1]); 

	map<pair<float,float>,float > lastx; 

	float length = INT_MAX; 

	for (auto x:columns) 
	{ 
		vector<float> column = x.second; 
		sort(column.begin(), column.end()); 
		for (float j = 0; j < column.size(); j++) 
		{ 
			for (float i = 0; i < j; i++) 
			{ 
				float y1 = column[i]; 

				// check if rectangle can be formed 
				if (lastx.find({y1, column[j]}) != lastx.end()) 
				{ 
					length =  (x.first - lastx[{y1, column[j]}]) + 
							(column[j] - column[i]) ; 
				} 
				lastx[{y1, column[j]}] = x.first; 
			} 
			} 
		} 

		return length; 
  	 
} 


int main() 
{ 
  vector<vector<float>> caseStudy1 = {{4,0}, {4,-5}, {7,-5}, {7,0}}; 
  vector<vector<float>> caseStudy2 = {{4,0}, {4,-5}, {7,-5}, {7,0}, {0.4,-2},{0.4,-5},{2.5,-5},{2.5,-2}};
  double point[] = {1,1};
  
  
float caseStudy2_exposeSurface = ((exposedToSun(caseStudy1,point)) + 
             (exposedToSun(caseStudy2,point))) - (sqrt(pow(caseStudy2[3][0] - 
    caseStudy2[2][0], 2) + pow(caseStudy2[3][1] - caseStudy2[2][1], 2)) * 1.0 - 0.5) ;

  cout << (exposedToSun(caseStudy1,point)) << "\n";
  cout << caseStudy2_exposeSurface << "\n";
	
   
	return 0; 
} 
/*
Output
8
11.5
*/
