#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {

    vector<int> answer;

    int cyear=stoi(today.substr(0,4));
    int cmonth=stoi(today.substr(5,2));
    int cday=stoi(today.substr(8,2));




    for(int i=0;i<privacies.size();i++){
        int dyear,dmonth,dday;
  
        dyear=stoi(privacies[i].substr(0,4));
        dmonth=stoi(privacies[i].substr(5,2));
        dday=stoi(privacies[i].substr(8,2));
        int pmonth;
        for(int j=0;j<terms.size();j++){
            if(privacies[i][11]==terms[j][0]){
                if(terms[j].size()==3){
                    pmonth=stoi(terms[j].substr(2,1));
                }
                else if(terms[j].size()==5){

                    pmonth=stoi(terms[j].substr(2,3));

                }
                else{
                     pmonth=stoi(terms[j].substr(2,2));
                }
                break;
            }

        }

        dmonth=dmonth+pmonth;
        if(dmonth>12){
            dyear=dyear+(dmonth-1)/12;
            if(dmonth%12==0){
                dmonth=12;
            }
            else{
            dmonth=dmonth%12;
            }
        }

        cout<<dyear<<" "<<dmonth<<" ";
        if(cyear>dyear){
            answer.push_back(i+1);
        }
        else if(cyear==dyear){
            if(cmonth>dmonth){
                answer.push_back(i+1);
            }
            else if(cmonth==dmonth){
                if(cday>=dday){
                    answer.push_back(i+1);
                }
            }
        }
    }


    return answer;
}