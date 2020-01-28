#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;
void error(){
    cout<<"Failed"<<endl;
    exit(0);
}
int main()
{
    vector <int> states;
    int state = 1;
    stack <char> st;
    char ch;
    while(1){
        switch(state){
            case 1:
                ch = getc(stdin);
                if(ch=='0'){
                    st.push('A');
                    states.push_back(state);
                    state = 2;
                }
                else{
                    error();
                }
                break;
            case 2:
                ch = getc(stdin);
                if(ch=='0'){
                    st.push('A');
                    states.push_back(state);
                    state = 2;
                }
                else if (ch=='1'){
                    states.push_back(state);
                    state = 3;
                }
                else{
                    error();
                }
                break;
            case 3:
                ch = getc(stdin);
                if (ch=='1'){
                    states.push_back(state);
                    state = 4;
                }
                else{
                    error();
                }
                break;
            case 4:
                ch = getc(stdin);
                if(ch=='1' && st.size()!=0){
                    st.pop();
                    states.push_back(state);
                    state = 4;
                }
                else if(ch=='1' && st.size()==0){
                    states.push_back(state);
                    state = 5;
                }
                else{
                    error();
                }
                break;
            case 5:
                ch = getc(stdin);
                if(ch=='1' && st.size()==0){
                    states.push_back(state);
                    state = 5;
                }
                else if(ch=='\n'){
                    states.push_back(state);
                    cout<<"ACCEPTED"<<endl;
                    cout<<"States in order : "<<endl;
                    for(int i=0 ; i<states.size() ; i++){
                        cout<<states[i]<<"\t";
                    }
                    exit(0);
                }
                else{
                    error();
                }
                break;

        }
    }
    return 0;
}
