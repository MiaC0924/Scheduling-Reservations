#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

int main(){

    //initial available seat
    int seat[7][21];
    for (int i=0; i<7; i++){
        for (int j=0; j<21; j++){
            seat[i][j] = 0;
        }
    }

    //String arrays for days and times
    int day, arrTime, people, temp;
    char aDay[7][4];
    strcpy(aDay[0],"Sun");
    strcpy(aDay[1],"Mon");
    strcpy(aDay[2],"Tue");
    strcpy(aDay[3],"Wed");
    strcpy(aDay[4],"Thu");
    strcpy(aDay[5],"Fri");
    strcpy(aDay[6],"Sat");
    char aTime[21][5];
    strcpy(aTime[0], "4:00");
    strcpy(aTime[1], "4:15");
    strcpy(aTime[2], "4:30");
    strcpy(aTime[3], "4:45");
    strcpy(aTime[4], "5:00");
    strcpy(aTime[5], "5:15");
    strcpy(aTime[6], "5:30");
    strcpy(aTime[7], "5:45");
    strcpy(aTime[8], "6:00");
    strcpy(aTime[9], "6:15");
    strcpy(aTime[10], "6:30");
    strcpy(aTime[11], "6:45");
    strcpy(aTime[12], "7:00");
    strcpy(aTime[13], "7:15");
    strcpy(aTime[14], "7:30");
    strcpy(aTime[15], "7:45");
    strcpy(aTime[16], "8:00");
    strcpy(aTime[17], "8:15");
    strcpy(aTime[18], "8:30");
    strcpy(aTime[19], "8:45");
    strcpy(aTime[20], "9:00");

    //make random Reservation with estimated service time
    //calculate available table
    for(int i=0; i<100; i++){
        // random day, time and number of people in 100 phone calls
        day = rand()%7;
        arrTime = rand()%21;
        people = (rand()%41)+1;

        if (people <= 2){
            for(int y = arrTime; y < arrTime+4; y++){
                if (seat[day][y]+people < 80){
                    temp = 1;
                }else{
                    temp = 0;
                    break;
                }
            }
        } else if (people > 2 && people <= 7){
            for(int y = arrTime; y < arrTime+5; y++){
                if (seat[day][y]+people < 80){
                    temp = 1;
                }else{
                    temp = 0;
                    break;
                }
            }
        } else if (people > 7 && people <= 11){
            for(int y = arrTime; y < arrTime+7; y++){
                if (seat[day][y]+people < 80){
                    temp = 1;
                }else{
                    temp = 0;
                    break;
                }
            }
        } else{
            for(int y = arrTime; y < arrTime+8; y++){
                if (seat[day][y]+people < 80){
                    temp = 1;
                }else{
                    temp = 0;
                    break;
                }
            }
        }

        //print booking result
        printf("Appointment call # %d:  ",i+1);
        if (temp == 1) {
            printf("%d people recervation made on day %s, arrival time %s pm\n", people, aDay[day], aTime[arrTime]);
            for(int y = arrTime; y < arrTime+4; y++){
                seat[day][y] = seat[day][y]+people;
            }
        }else{printf("appointment denied\n");}
    }


    //display table
    printf("\n");
    printf("       |Sum|Mon|Tue|Wed|Thu|Fri|Sat|\n");
    printf("       |---|---|---|---|---|---|---|\n");
    for(int j = 0; j < 21; j++){
      printf("0%spm|%3d|%3d|%3d|%3d|%3d|%3d|%3d|\n",aTime[j],seat[0][j],seat[1][j],seat[2][j],seat[3][j],seat[4][j],seat[5][j],seat[6][j]);
    }

    return 0;
}
