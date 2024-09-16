// SJF
#include<stdio.h>
int main(){
    int pid[20], bt[20], wt[20], tat[20];
    float wtavg, tatavg;
    int i, k, n, temp;
    
    printf("\nEnter the number of processes--");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        pid[i] = i;
        printf("\nEnter the burst Time for Process %d--", i);
        scanf("%d", &bt[i]);
    }

    // Sort processes by burst time using Bubble Sort
    for(i = 0; i < n; i++){
        for(k = i+1; k < n; k++){
            if(bt[i] > bt[k]){
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                temp = pid[i];
                pid[i] = pid[k];
                pid[k] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Print the results
    printf("\tProcess \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for(i = 0; i < n; i++)
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", pid[i], bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time-- %f", wtavg / n);
    printf("\nAverage Turnaround Time-- %f\n\n", tatavg / n);
    return 0;    
}
