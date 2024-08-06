#include <string>
#include <vector>
#include<stdlib.h>
#include<iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left=10;
    int right=12;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            left=numbers[i];
            answer=answer+'L';
        }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            right=numbers[i];
            answer=answer+'R';
        }
        else{
            int center=numbers[i];
            if(center==0){
                center=11;
            }
            
            int leftmi=abs(center/3-left/3)+abs(center%3-left%3);
            int rightmi=abs(center/3-(right/3-1))+abs(center%3-(right-(right/3-1)*3));
            if(right==2||right==5||right==8||right==11){
                rightmi=abs(center-right)/3;
            }
            if(left==2||left==5||left==8||left==11){
                leftmi=abs(center-left)/3;
            }
            
            if(leftmi>rightmi){
                right=center;
            answer=answer+'R';
            }
            else if(leftmi<rightmi){
                left=center;
            answer=answer+'L';
            }
            else{
                if(hand=="right"){
                    right=center;
            answer=answer+'R';
                }
                else{
                    left=center;
            answer=answer+'L';
                }
            }
            
        }
        
    }
    return answer;
}