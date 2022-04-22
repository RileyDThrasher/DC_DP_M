/* 
Student Name: Riley Thrasher

Studen NetID: rdt208

Compiler Used:  g++ BinomialCoefficient.cpp -o ectwo
                ./ectwo

Program Description:
    program that solves binomial coefficient,
        for example, 52 card deck, choosing a specific 5 hands.
        Divide and conquer,
        Dyanmic Programming,
        Memoization.
    
    cout's time at the end to compare run times

*/
 
/* Includes */
 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <sys/time.h>

 using namespace std;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/* Divide & Conquer Binomial Coefficient solution */
int DC_BC(int n, int k) {
 /* base cases */
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;
 /* recursive calls where we see divide and conquer */
 return DC_BC(n - 1, k - 1) + DC_BC(n - 1, k);
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/* Dynamic Programming Binomial Coefficient Solution */
int DP_BC(int n, int k) {
 int C[k + 1];
 /* allocation */
 memset(C, 0, sizeof(C));
 
 /* set 0 to 1 */
 C[0] = 1;
 
 /* loop until found */
    for (int i = 1; i <= n; i++) {
     /* use previous row of pas triangle to compute next row of pas triangle */
        for (int j = min(i, k); j > 0; j--){
         C[j] = C[j] + C[j - 1];
        }
    }
 /* return k */
 return C[k];
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/* Memoization Binomial Coefficinet Solution */
int M_BCUtility(int n, int k, int** dp) {
    /* bases cases start*/
     /* lookup table for value, return it if so */
     if (dp[n][k] != -1) {
        return dp[n][k];
     }
     /* Must not be in table, store value in the table before continuing */
     if (k == 0) {
        dp[n][k] = 1;
        return dp[n][k];
     }
    /* base cases end */
    
    /* Must not be in table, store value in the table before continuing */
    if (k == n) {
        dp[n][k] = 1;
        return dp[n][k];
    }
    
    /* save value in table */
    dp[n][k] = M_BCUtility(n - 1, k - 1, dp) + M_BCUtility(n - 1, k, dp);
    /* send off final answer */
    return dp[n][k];
}
 
int M_BC(int n, int k) {
    /* dp is our lookup table */
     int** dp; 
     dp = new int*[n + 1];

    /* use dp to create table */
        for (int i = 0; i < (n + 1); i++) {
            dp[i] = new int[k + 1];
        }
 
    /* ini with nested loop */
        for (int i = 0; i < (n + 1); i++) {
            for (int j = 0; j < (k + 1); j++) {
                dp[i][j] = -1;
            }
        }
    /* send to utility */
    return M_BCUtility(n, k, dp);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/* Driver code*/
  /*
    main simply inits our deck of cards value 52 with the unique hand value 5.
    Then outputs our binomial Coefficient using whatever program specified.
  */
    int main() {
      int n = 52, k = 5;
      int Solution = 0;
      double t1 = 0;
      double t2 = 0;
      double Speed = 0;
      timeval tim;

      cout << "===================" << endl;
        //-------------------------------------
        /* Divide & Conquer section start */
         cout << "Divide & Conquer solution" << endl;
         /* timer start */
         gettimeofday(&tim, NULL);
         t1 = tim.tv_usec;
         
         /* call our function */
         Solution = DC_BC(n, k);
         
         /* timer end */
         gettimeofday(&tim, NULL);
         t2 = tim.tv_usec;   

         /* output results */   
         cout << "C(" << n << "," << k << ") = " << Solution << endl;
         Speed = t2-t1;
         cout << "time: " << Speed << endl;
        /* Divide & Conquer section end */
        //-------------------------------------
        /* Dynamic Programming section */
         cout << "Dynamic Programming solution" << endl;
         /* timer start */
         gettimeofday(&tim, NULL);
         t1 = tim.tv_usec;
         
         /* call our function */
         Solution = DP_BC(n, k);
         
         /* timer end */
         gettimeofday(&tim, NULL);
         t2 = tim.tv_usec;   

         /* output results */   
         cout << "C(" << n << "," << k << ") = " << Solution << endl;
         Speed = t2-t1;
         cout << "time: " << Speed << endl;
        /* Dynamic Programming section end */
        //-------------------------------------
        /* Memoization section */
         cout << "Memoization solution" << endl;
         /* timer start */
         gettimeofday(&tim, NULL);
         t1 = tim.tv_usec;
         
         /* call our function */
         Solution = M_BC(n, k);
         
         /* timer end */
         gettimeofday(&tim, NULL);
         t2 = tim.tv_usec;   

         /* output results */   
         cout << "C(" << n << "," << k << ") = " << Solution << endl;
         Speed = t2-t1;
         cout << "time: " << Speed << endl;
        /* Memoizaiton section end */
      cout << "===================" << endl;

      return 0;
    }
/* end of program */

































