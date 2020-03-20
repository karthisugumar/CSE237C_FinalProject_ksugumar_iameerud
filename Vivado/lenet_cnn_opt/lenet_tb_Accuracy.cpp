#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#include "lenet.h"
#include "test_set_in_small.h"

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
    float gold;
    FILE *fp;

    DTYPE img[C1_NUM_INCHAN][C1_IN_ROWS][C1_IN_COLS];
    DTYPE out[PREDS];

    int test_size = 500;
    float accuracy = 0;

    fp = fopen("test_set_out.dat", "r");

    for (int t=0; t<test_size; t++) {
		for(int ifm=0; ifm < C1_NUM_INCHAN; ifm++) {
			for(int r=0; r < C1_IN_ROWS; r++) {
				for(int c=0; c < C1_IN_COLS; c++) {
				img[ifm][r][c] = test_set[t][ifm][r][c];
				}
			}
		}

		lenet(img, out);

		const int N = sizeof(out) / sizeof(DTYPE);
		int pred = distance(out, max_element(out, out + N));

		fscanf(fp, "%f\n", &temp);
//		cout << "GOLDEN: " << temp << endl;
//		cout << "PRED: " << pred << endl;
		if(pred == temp) accuracy++;

		//if(pred != temp) cout << "WRONG @ id: " << t << endl;

//	   rmse.add_value((float)(pred - temp));
    }
	fclose(fp);

    printf("----------------------------------------------\n");
    printf("   ACCURACY ");
    printf("%.2f\n", accuracy/test_size*100, "%%");
    printf("----------------------------------------------\n");

}
