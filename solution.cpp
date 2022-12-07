#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string fname;
    cout<<"Enter the file name: ";
    cin>>fname;

    vector<vector<long double>> content;
    vector<long double> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open()) {
        while(getline(file, line)) {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back( ::stold( word.c_str() ) );
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";

    for(int i=0;i<content.size();i++) {
        for(int j=0;j<content[i].size();j++) {
            cout<< content[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout << "Enter number: ";
    double firstNum;
    cin >> firstNum;

    vector< long double > stepResults;

    // multiply weights
    for( int i = 0; i < content[ 0 ].size(); i++ ) {
        stepResults.push_back( content[ 0 ][ i ] * firstNum );
    }

    // add biases
    for( int i = 0; i < content[ 1 ].size(); i++ ) {
        stepResults[ i ] += content[ 1 ][ i ];
    }

    // multiply weights
    for( int i = 0; i < content[ 2 ].size(); i++ ) {
        stepResults[ i ] *= content[ 2 ][ i ];
    }
    
    // get final result
    long double res = 0;
    for( int i = 0; i < stepResults.size(); i++ ) {
        res += stepResults[ i ];
    }
    res += content[ 3 ][ 0 ];
    
    cout << "Result: "<< res << endl;
    return 0;
}
