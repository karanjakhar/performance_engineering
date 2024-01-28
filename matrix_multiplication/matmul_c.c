#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define n 4096
double A[n][n], B[n][n], C[n][n];

float tdiff(struct timeval start, struct timeval end){
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec -  
                              start.tv_usec)) * 1e-6; 
    return time_taken;
}

int main(int argc, char *argv[]){
    struct timeval start, end;
    int i, j, k;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            A[i][j] = i*j;
            B[i][j] = i*j;
            C[i][j] = 0;
        }
    }

    gettimeofday(&start, NULL);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    gettimeofday(&end, NULL);

    printf("Time taken: %f\n", tdiff(start, end));

    return 0;
}
