#include<iostream>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    char **board=new char*[N];
    for(int i=0;i<N;i++){
        board[i]=new char[M];
    }

    for(int i=0;i<N;i++){
        for(int t=0;t<M;t++){
            cin>>board[i][t];
        }
    }
    
    int count3=0;
    int j=0;
    int co=0;
    int count=0;
    int count4=0;
    int count2[10000];
    int count5[10000];
    int col=0;
    for(int i=0;i<=N-8;i++){
        int temp=M-8;
        while(temp>=0){

            if(board[i][j]=='B'){

                for(int t=i;t<8+i;t++){
                    if(col%2==0){
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='B'&&co%2==1){
                                count+=1;
                            }
                            
                            if(board[t][k]=='W'&&co%2==0){
                                count+=1;
                            }
                            co++;
                        }
                    }else{
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='W'&&co%2==1){
                                count+=1;
                            }
                            
                            if(board[t][k]=='B'&&co%2==0){
                                count+=1;
                            }
                            co++;
                        }
                    }
                    col+=1;
                }

                for(int t=i;t<8+i;t++){
                    if(col%2==0){
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='W'&&co%2==1){
                                count4+=1;
                            }
                            
                            if(board[t][k]=='B'&&co%2==0){
                                count4+=1;
                            }
                            co++;
                        }
                    }else{
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='B'&&co%2==1){
                                count4+=1;
                            }
                            
                            if(board[t][k]=='W'&&co%2==0){
                                count4+=1;
                            }
                            co++;
                        }
                    }
                    col+=1;
                }

            }else{

                for(int t=i;t<8+i;t++){
                    if(col%2==0){
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='W'&&co%2==1){
                                count+=1;
                            }
                            
                            if(board[t][k]=='B'&&co%2==0){
                                count+=1;
                            }
                            co++;
                        }
                    }else{
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='B'&&co%2==1){
                                count+=1;
                            }
                            
                            if(board[t][k]=='W'&&co%2==0){
                                count+=1;
                            }
                            co++;
                        }
                    }
                    col+=1;
                }

                for(int t=i;t<8+i;t++){
                    if(col%2==0){
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='B'&&co%2==1){
                                count4+=1;
                            }
                            
                            if(board[t][k]=='W'&&co%2==0){
                                count4+=1;
                            }
                            co++;
                        }
                    }else{
                        for(int k=j;k<8+j;k++){
                            if(board[t][k]=='W'&&co%2==1){
                                count4+=1;
                            }
                            
                            if(board[t][k]=='B'&&co%2==0){
                                count4+=1;
                            }
                            co++;
                        }
                    }
                    col+=1;
                }

            }
            j+=1;
            temp-=1;
            
            count5[count3]=count4;
            count2[count3]=count;
            count3+=1;
            count=0;
            count4=0;
        }

        j=0;
    }

    int min=count2[0];
    int temp1,temp2;
    int min2=count5[0];
    for(int t=0;t<(N-7)*(M-7);t++){
        
        if(count2[t]<=min){
            min=count2[t];
        }
    }
    
    for(int t=0;t<(N-7)*(M-7);t++){
        if(count5[t]<=min2){
            min2=count5[t];
        }
    }
   
    
    
    if(min<=min2){
        cout<<min;
    }else{
        cout<<min2;
    }
}
