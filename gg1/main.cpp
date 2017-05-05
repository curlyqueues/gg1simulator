//
//  main.cpp
//  gg1
//
//  Created by Jordan Scandlyn on 11/10/16.
//  Copyright (c) 2016 Jordan Scandlyn. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <cstdio>
#include <random>
#include <unistd.h>
#include <queue>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>


using namespace std;
void starting();
auto EMAX = 2;
int queue_size = 0;
int buffer[0];
int poisson(double lambda){
    int k=0;
    double L=exp(-lambda), p=1;
    do {
        ++k;
        p *= rand()/(double)RAND_MAX;
    } while (p > L);
    return --k;
}

int arrival(){
    EMAX = 1;
    starting();
    return 0;
}


void departure(int j){
    
    buffer[j] = 0;
}


void starting(){
    
    //time_t timer;
    int average_arrival;
    int sum = 0;
    for(int eventCount = 0; eventCount <= EMAX; eventCount++){
        clock_t startingTime = clock();
        int inloopdouble;
        int startingTimeDouble = startingTime;
        using data_structure = pair < int, int >;
        priority_queue<data_structure> priorityq;
        int val_time = inloopdouble - startingTimeDouble;
        if(abs(val_time) < 1000){
            //do nothing
        
        priorityq.emplace(eventCount, val_time);
        //strftime(buffer, 25, "%S", val_time);
        //puts(buffer);
        sleep(poisson(5));
        const auto& pair = priorityq.top();
        buffer[eventCount] = val_time;
        cout << pair.first << " && " << abs(pair.second) << endl;
        sum = sum + abs(val_time);
            
        }
        clock_t inloop = clock();
        inloopdouble = inloop;
    }
    queue_size = queue_size + EMAX;
    average_arrival = sum / EMAX;
    cout << "# of arrivals: " << EMAX << endl;
    cout << "Average Arrival Rate: " << average_arrival << endl;
    for(int i = 0; i <= EMAX; i++){
        if(buffer[i] % 2 == 0){
            departure(i);
        }
        else{
            arrival();
        }
    }
    
}

int main() {
    
    starting();
    return 0;
}




