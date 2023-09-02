#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    long long i=deliveries.size()-1;
    
    while(i>=0){
         while(deliveries[i]<=0&&pickups[i]<=0){
            if(i>=0){
                i--;
            }
            else{
                break;
            }
             
        }
        answer=answer+(i+1)*2;
        int bringcap=cap;
        int j=i;
        while(bringcap>0){
            while(deliveries[j]==0){
                j--;
                if(j<0){
                 break;
             }
            }
            if(j<0){
                break;
            }
            deliveries[j]--;
            bringcap--;
            // if(deliveries[j]==0){
            //     j--;
            // }
            // if(j<0){
            //     break;
            // }
            // if(deliveries[j]==0){
            //     j--;
            // }
            // if(j==-1){
            //     break;
            // }
        }
        
        bringcap=cap;
        j=i;
         while(bringcap>0){
             while(pickups[j]==0){
                j--;
                 if(j<0){
                 break;
             }
            }
             if(j<0){
                 break;
             }
            pickups[j]--;
            bringcap--;
            //  if(pickups[j]==0){
            //     j--;
            // }
            //  if(j<0){
            //      break;
            //  }
            //  if(pickups[j]==0){
            //     j--;
            // }
            //  if(j==-1){
            //      break;
            //  }
        }
        // i--;
        
        while(deliveries[i]<=0&&pickups[i]<=0){
            if(i>=0){
                i--;
            }
            else{
                break;
            }
             
        }
        // cout<<i<<" ";
            
        
       
    }
    
    return answer;
}