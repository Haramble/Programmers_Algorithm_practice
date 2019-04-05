#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    if(N==1) answer = 4;
    else if(N==2) answer = 6;
    else{
        long long a[3] = {1,2,2};
        for(int i=3; i<N; i++){
            a[2] = a[0]+a[1];
            a[0] = a[1];
            a[1] = a[2];
        }

        answer = a[1]*4 + a[0]*2;
    }

    return answer;
}
