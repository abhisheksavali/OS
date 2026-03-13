#include <stdio.h>

int main() {
    int n,i,time=0,completed=0,smallest;
    int at[20],bt[20],ct[20],tat[20],wt[20],done[20]={0};
    float avg_tat=0,avg_wt=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Arrival time for P%d: ",i+1);
        scanf("%d",&at[i]);
        printf("Bus time for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }
    while(completed<n){
        smallest=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(smallest==-1 || bt[i]<bt[smallest])
                    smallest=i;
            }
        }
        if(smallest==-1){
            time++;
        } else {
            time += bt[smallest];
            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];

            avg_tat += tat[smallest];
            avg_wt += wt[smallest];

            done[smallest]=1;
            completed++;
        }
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f",avg_tat);
    printf("\nAverage Waiting Time = %.2f\n",avg_wt);
    return 0;
}
