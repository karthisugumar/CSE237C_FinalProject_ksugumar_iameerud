#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

#include "types.h"


struct Rmse
{
    int num_sq;
    float sum_sq;
    float error;
    
    Rmse(){ num_sq = 0; sum_sq = 0; error = 0; }
    
    float add_value(float d_n)
    {
        num_sq++;
        sum_sq += (d_n*d_n);
        error = sqrtf(sum_sq / num_sq);
        return error;
    }
    
};

Rmse rmse;

int main()
{
    //int r,c,s;
    float temp;
    DTYPE in[NUM_INCHAN][IN_ROWS][IN_COLS];
    float gold;
    FILE *fp;

    DTYPE out[NUM_OUTCHAN][OUT_ROWS][OUT_COLS];
    

    fp = fopen("relu_in.dat", "r");
    for(int ofm=0; ofm < NUM_INCHAN; ofm++) {
		for(int r=0; r < IN_ROWS; r++) {
			for(int c=0; c < IN_COLS; c++) {
				fscanf(fp, "%f\n", &temp);
//				cout << "KERNEL: " << temp << endl;
			in[ofm][r][c] = temp;
			}
		}
    }
    fclose(fp);

    relu(in, out);

    fp = fopen("relu_out.dat", "r");
    for(int ofm=0; ofm < NUM_OUTCHAN; ofm++) {
    	for(int r=0; r < OUT_ROWS; r++) {
			for(int c=0; c < OUT_COLS; c++) {
				fscanf(fp, "%f\n", &temp);
				cout << "OUT: " << out[ofm][r][c] << endl;
			rmse.add_value(out[ofm][r][c] - temp);
        	}
    	}
    }
    fclose(fp);

    // printing error results
    printf("----------------------------------------------\n");
    printf("   RMSE ");
    printf("%f\n", rmse.error);
    printf("----------------------------------------------\n");

    if (rmse.error > 0.001) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "*******************************************\n");
        return 1;
    }else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "PASS: The output matches the golden output!\n");
        fprintf(stdout, "*******************************************\n");
        return 0;
    }
    return 0;
}
