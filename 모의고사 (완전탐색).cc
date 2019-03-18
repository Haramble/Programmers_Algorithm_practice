#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int a1_answer[5] = {1,2,3,4,5};
    int a2_answer[8] = {2,1,2,3,2,4,2,5};
    int a3_answer[10] = {3,3,1,1,2,2,4,4,5,5};
    int a1=0, a2=0, a3=0, i=0;
    vector<int>::iterator it;
    for(it=answers.begin(); it<answers.end(); it++){
        if(*it == a1_answer[i%5]) a1++;
        if(*it == a2_answer[i%8]) a2++;
        if(*it == a3_answer[i%10]) a3++;
        i++;
    }
    vector<int> answer;
    if(a1==a2 && a2==a3){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else{
        if(a1>a2 && a1>a3) answer.push_back(1);
        else if(a2>a1 && a2>a3) answer.push_back(2);
        else if(a3>a1 && a3>a2) answer.push_back(3);
        else if(a1==a2 && a1>a3){
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(a1==a3 && a1>a2){
            answer.push_back(1);
            answer.push_back(3);
        }
        else if(a2==a3 && a2>a1){
            answer.push_back(2);
            answer.push_back(3);
        }

    }
    return answer;
}
