/**
 *  Print Pyramid
 * 
     Level = 4
                        *
                    *   *   *
                *   *   *   *   *
            *   *   *   *   *   *   *
 * 
 **/

#include <iostream>
#include <string>
using namespace std;

void printPyramid(int level){
    string spaces = " ";
    for(int i = 1; i <= level; ++i){

        //print spaces, maintain half pyramid spaces
        int spaces = (level-i)*2;
        while(spaces){
            cout<< " ";
            --spaces;
        }

        //print starts
        int stars = (i*2)-1;
        while(stars){
            if(i == 1){
                cout<< "*";
                break;
            }
            cout<<"* ";
            --stars;
        }
        cout<<endl;
    }
}

int main()
{
    printPyramid(7);
    return 0;
}
