//********************************************************
// Lab3.c
// Author: Lorenzo Wyman
// UCFID: 5464079
// Date: 9/27/24
// Class: COP 3223, Professor Parra
// Purpose: This program is intended to display and collect user
//          inputted values with only the use of pointers.
// Input: from the user
//
// Output: (to the command line) The result of what the user inputted
//         using pointers.
// //********************************************************

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n; 
    
    printf("Enter how many scores do you have: ");
    scanf("%d",&n);
    
    float*userScores = (float *)malloc(n * sizeof(float));
    
    //this is just checking to see like error controls.
    if(userScores == NULL) {
        printf("Memory allocation failed.\n");

        return 1;
    }


    printf("Okay! Now enter all your %d scores seperated by space: ",n);
        //loop that allows the user to input multiple values and then print them after
        for(int i = 0; i < n; i++){
            scanf("%f",userScores + i);
        }
    

    printf("\nPerfect! Here are all the scores you entered....\n");
    
        for(int i = 0; i < n; i++){
            printf("(%.2lf) ", *(userScores + i));
        }
            printf("\n");

        float *largestScore = userScores;

        for(int i = 1; i < n; i++){
            if(*(userScores + i) >= *largestScore){
                largestScore = userScores + i;
            }
        }
            printf("\nThe largest score entered is: %.2lf\n", *largestScore);
        // important to always free at the end. if not it wont be good.
            free(userScores);
    return 0;
}


