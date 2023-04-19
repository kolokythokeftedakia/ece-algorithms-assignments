#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum candidates{Candidate0, Candidate1, Candidate2};

int main(void){

	srand(time(NULL));

	int const citizens=20;
	int const numOfCandidates=3;

	enum candidates Cand;

	printf("\n");

    int  Vote[citizens];
	for(int i=0;i<citizens;i++){
		Vote[i]=rand()%numOfCandidates;
		printf("Vote[%d]=Candidate %d\n",i,Vote[i]);
	}
	printf("\n");

	// PROCESS TOUR -----------------------------------
		int WhoNeedsToTour[numOfCandidates];
		for(int i=0;i<numOfCandidates;i++)
			WhoNeedsToTour[i]=1; // everyone needs to tour

		int popularity;
		for(int i=0;i<numOfCandidates;i++){
			Cand=i;
			popularity=0;
			for(int j=0;j<citizens;j++){
				if(Vote[j]==Cand){
					++popularity;
				}
			}
			if(!(popularity<(citizens/2))){
				WhoNeedsToTour[Cand]=0;
			}
		}
	// END PROCESS TOUR -----------------------------------

	printf("\n");
	for(int i=0;i<numOfCandidates;i++){
		printf("Tour[%d]=Candidate %d\t",i,WhoNeedsToTour[i]);
	}

	return 0;
}