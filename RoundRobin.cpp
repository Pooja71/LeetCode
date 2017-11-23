#include <iostream>
#include <vector>
#include <algorithm>

class Process    {
public:
    int processId;
    int burstTime;
    int arrivalTime;
    int waitTime;
    int completionTime;
    int turnAroundTime;
    
    Process(int processId, int burstTime, int arrivalTime) : processId(processId), 
                                            burstTime(burstTime), 
                                            arrivalTime(arrivalTime), 
                                            waitTime(0), 
                                            completionTime(0),
                                            turnAroundTime(0)    {}
    int calcWaitTime()    {
        return waitTime = turnAroundTime - burstTime;
    }
    int calcTurnAroundTime()    {
        return completionTime - arrivalTime;
    }
    void completeProcess()    {
        turnAroundTime = calcTurnAroundTime();
        waitTime = calcWaitTime();
    }
};

class RoundRobin    {
    public:
        std::vector<Process> vecProcesses;
        int timeSlice;
    
        void schedule()    {            
            sortBasedOnArrival();
            std::vector<std::pair<int, int>> procList = createProcessList();
            
            bool isDone = false;
            bool isArrived = false;
            int timeCounter = 0;
            int n = vecProcesses.size();
            // Iterate through all process and execute them till all are processed.
            while(!isDone)    {
                
                // Reset flags at the start of iteration over the list of processes.
                isDone = true;
                isArrived = false;
                
                // Go over all the processes
                for(int i = 0; i < n; i++)    {                    
                    
                    // If a process is not complete.
                    if(procList[i].second > 0)    {
                        isDone = false;
                        
                        // if the process has arrived, execute it.
                        if(vecProcesses[i].arrivalTime <= timeCounter)    {    
                            isArrived = true;
                            
                            // Decrease burst time.
                            procList[i].second -= timeSlice;
                            
                            // Increment the processor time.
                            timeCounter += timeSlice;
                            
                            // If process is complete, mark the completion time.
                            if(procList[i].second <= 0 )    {
                                vecProcesses[i].completionTime = timeCounter;
                                std::cout << "Process: " << vecProcesses[i].processId << " with arrival time: " << vecProcesses[i].arrivalTime << " completed at t = " <<vecProcesses[i].completionTime << std::endl; 
                            }
                        }
                    }
                } // end for.
                
                // If no process has arrived yet and executions pending, increase timeCounter.
                if(!isArrived && !isDone)    {
                    timeCounter += timeSlice;
                }               
                
                
            } // end while
            
            int totalExecutionTime = timeCounter;
                float avgWaitingTime = 0;
                float avgTurnAroundTime = 0;
                for(auto proc : vecProcesses)    {
                    proc.completeProcess();
                    avgWaitingTime += proc.waitTime;
                    avgTurnAroundTime += proc.turnAroundTime;
                }
                
                avgWaitingTime /= static_cast<float>(n);
                
                avgTurnAroundTime /= static_cast<float>(n);
                
                std::cout << ":Summary:" << std::endl;
                std::cout << "Completion Time: " << totalExecutionTime << std::endl;
                std::cout << "Avg Waiting Time: " << avgWaitingTime << std::endl;
                std::cout << "Avg Turn Around time: " << avgTurnAroundTime << std::endl;
                
        }
    private:
        static bool compare(Process &lhs, Process &rhs)    {
            return lhs.arrivalTime < rhs.arrivalTime;
        }
    
        // Sort the vector of processes based on their arrival time.
        void sortBasedOnArrival()    {
            sort(vecProcesses.begin(), vecProcesses.end(), compare);            
        }
    
        // Create a copy of list having process ID and burst time for performing scheduling.
        std::vector<std::pair<int, int>> createProcessList()    {
            std::vector<std::pair<int, int>> procList;
            for(auto el : vecProcesses)    {
                procList.emplace_back(std::pair<int, int>(el.processId, el.burstTime));
            }
            return procList;
        }
};


using namespace std;

int main() {
    
    // TestCase 1:
    std::cout << std::endl << "********************** Testcase 1 ****************** " << std::endl;
    RoundRobin scheduleObj;
    scheduleObj.timeSlice = 2;
    scheduleObj.vecProcesses.emplace_back(Process(2, 10, 10));
    scheduleObj.vecProcesses.emplace_back(Process(1, 12, 0));
    scheduleObj.vecProcesses.emplace_back(Process(3, 1, 7));
    scheduleObj.schedule();
    
    // TestCase 2:
    std::cout << std::endl << "********************** Testcase 2 ****************** " << std::endl;
    RoundRobin scheduleObj2;
    scheduleObj2.timeSlice = 2;
    scheduleObj2.vecProcesses.emplace_back(Process(2, 10, 5));
    scheduleObj2.vecProcesses.emplace_back(Process(1, 10, 6));
    scheduleObj2.vecProcesses.emplace_back(Process(3, 10, 1));
    scheduleObj2.schedule();
    
        // TestCase 3:
    std::cout << std::endl << "********************** Testcase 3 ****************** " << std::endl;
    RoundRobin scheduleObj3;
    scheduleObj3.timeSlice = 2;
    scheduleObj3.vecProcesses.emplace_back(Process(2, 4, 3));
    scheduleObj3.vecProcesses.emplace_back(Process(1, 10, 5));
    scheduleObj3.vecProcesses.emplace_back(Process(3, 1, 6));
    scheduleObj3.schedule();
    
        // TestCase 4:
    std::cout << std::endl << "********************** Testcase 4 ****************** " << std::endl;
    RoundRobin scheduleObj4;
    scheduleObj4.timeSlice = 2;
    scheduleObj4.vecProcesses.emplace_back(Process(2, 1, 3));
    scheduleObj4.vecProcesses.emplace_back(Process(1, 5, 7));
    scheduleObj4.vecProcesses.emplace_back(Process(3, 2, 12));
    scheduleObj4.schedule();
    
    return 0;
    
}
