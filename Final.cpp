#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct Process {
	int baseReg;
	int limitReg;
	int timeLimit;
};
struct Hole {
	int baseReg;
	int limitReg;
};

//int main()
//{
//	printf("Hello");
//	}


   
Process* initializeReadyQueue(int* totalMemory, int* n) {
	Process* readyQueue = new Process[100];
	int index = 0;
	while (index < 8 && *totalMemory > 50) {
		Process* temp = new Process;
		temp->baseReg = 1024 - *totalMemory;
		temp->limitReg = rand() % 450 + 50;
		if (*totalMemory - temp->limitReg > 0) {
			temp->timeLimit = rand() % 30 + 1;
			*totalMemory -= temp->limitReg;
			readyQueue[index]=*temp;
			index++;
		}
		else {
			delete temp;
		}
	}
	*n = index;
	return readyQueue;
}

Process* initializePendingJobs(int &np) {
	Process* Jobs= new Process[100];
	int index = 0;
	while (index < 12) {
		Process* temp = new Process;
		temp->baseReg = -1;
		temp->limitReg = rand() % 450 + 50;
		temp->timeLimit = rand() % 30 + 1;
	    Jobs[index]=*temp;
		index++;

	}
	np=index;
	return Jobs;
}


void defragmentation(Hole* Holes,Process* readyQueue,int &n, int &nh) {
	for (int i = 0; i < n; i++) {
		if(readyQueue[i].timeLimit > 0)
		{
			if (i == 0) {
			readyQueue[i].baseReg = 256;
			}
			else {
				readyQueue[i].baseReg = readyQueue[i-1].baseReg + readyQueue[i-1].limitReg;
			}
		}
	}
	for (int i = 1; i < nh; i++) {
		Holes[0].limitReg += Holes[i].limitReg;
	}
	Holes[0].baseReg = 1024 - Holes[0].limitReg;
	nh=1;
}


void removeJob(Process* readyQueue, int index, int &n, Hole* Holes, int &nh) {
	Process* processToRemove = new Process;
	*processToRemove = readyQueue[index];
	if (index == n - 1) {
		Holes[0].limitReg += processToRemove->limitReg;
		Holes[0].baseReg = 1024 - Holes[0].limitReg;
		for (int i = 0; i < nh; i++) {
			if ((Holes[i].baseReg + Holes[i].limitReg) == Holes[0].baseReg) {
				Holes[0].baseReg = Holes[i].baseReg;
				Holes[0].limitReg += Holes[i].limitReg;
				for(int j=i; j<nh-1; j++)
					Holes[j] = Holes[j+1];
				nh--;
			}
		}
		//n--;
	}
	else {
		bool filled = false;
		for (int i = 0; i < nh && !filled; i++) {
			if ((Holes[i].baseReg + Holes[i].limitReg) == processToRemove->baseReg) {
				Holes[i].limitReg += processToRemove->limitReg;
				filled = true;
			}
			else if ((processToRemove->baseReg + processToRemove->limitReg) == Holes[i].baseReg) {
				Holes[i].limitReg += processToRemove->limitReg;
				Holes[i].baseReg = processToRemove->baseReg;
				filled = true;
			}
		}
		for(int i=0; i<nh; i++)
		{
			for(int j=i+1; j<nh; j++)
			{
				if(Holes[i].baseReg == Holes[j].baseReg)
				{
					while(j<nh-1){
						Holes[j] = Holes[j+1];
					}
					nh--;
					j = nh+1;
					i = nh+1;
				}
			}
		}
		if (!filled) {
			Hole* temp = new Hole;
			temp->baseReg = processToRemove->baseReg;
			temp->limitReg = processToRemove->limitReg;
			Holes[nh] = *temp;
			nh++;
			if (nh > 3) {
				defragmentation(Holes, readyQueue, n, nh);
			}
		}
		else {
			
		}
	}
}
bool isEmpty(Process* Queue, int n) {

	for(int i=0; i<n; i++)
		if(Queue[i].timeLimit > 0)
			return false;
	return true;
}
void AddJobsToQueue(Process* pendingJobs, Process* readyQueue, Hole* Holes, int &n, int &nh, int &np){
	defragmentation(Holes, readyQueue, n, nh);
	for(int i=0; i<np; i++)
	{
		for(int j=0; j<nh; j++)
		{
			if((pendingJobs[i].timeLimit > 0)&&(pendingJobs[i].limitReg <= Holes[j].limitReg))
			{
				readyQueue[n] = pendingJobs[i];
				n++;
				pendingJobs[i].timeLimit = -1;
				if(pendingJobs[i].limitReg == Holes[j].limitReg)
				{
					while(j<nh-1)
					{
						Holes[j] = Holes[j+1];
					}
					nh--;
				}
				else
				{
					Holes[j].baseReg += pendingJobs[i].limitReg;
					Holes[j].limitReg -= pendingJobs[i].limitReg;
				}
				printf( "New job added, size: %d \n", pendingJobs[i].limitReg);
				int mem = 0;
				for (int k = 0; k < nh; k++) {
					mem += Holes[k].limitReg;
				}
				printf("Current External Fragmentation: %d\n",mem );
				return;
			}
		}
	}
}
int main()
{

int totalMemory = 1024;
int n, np;
	Process* readyQueue;
	Hole* Holes = new Hole[100];
	int nh = 1;
	srand(time(0));
	Holes--;
	//Allocating OS
	totalMemory -= 256;
	//Creating Processes Randomly for ready Queue;
	readyQueue = initializeReadyQueue(&totalMemory, &n);
	printf("Initial External Fragmentation: %d\n", totalMemory);
	Holes[0].baseReg = 1024 - totalMemory;
	Holes[0].limitReg = totalMemory;
	printf("Total Processes Created: %d\n",n);
	int clock = 0;
	Process* pendingJobs = initializePendingJobs(np);
	while (!isEmpty(pendingJobs, np) || !isEmpty(readyQueue, n)) {
		// go through All the processes and tick their clock once
		
		for (int i = 0; i < n; i++) {
			
			readyQueue[i].timeLimit--;
		
			if (readyQueue[i].timeLimit == 0) {
				removeJob(readyQueue, i, n, Holes, nh);
				printf( "Job id %d completed, removing job\n",i);
			}
		}
		totalMemory = 0;
		for (int i = 0; i < nh; i++) {
			totalMemory += Holes[i].limitReg;
		}
		if (totalMemory > 50) {
			AddJobsToQueue(pendingJobs, readyQueue, Holes, n, nh, np);

		}
		clock++;
	}
	return 0;
}

