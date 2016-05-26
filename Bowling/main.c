//
//  main.c
//  Bowling
//
//  Created by tstone10 on 5/26/16.
//  Copyright © 2016 DetroitLabs. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
	
	//int * scoreArray = readAllScores();
	
	//all strikes, score 300
	//int scoreArray[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	//open frames, score 82
	//int scoreArray[] = {9, 0, 3, 5, 6, 1, 3, 6, 8, 1, 5, 3, 2, 5, 8, 0, 7, 1, 8, 1};
	//spares and open frames, score 131
	//int scoreArray[] = {9, 0, 3, 7, 6, 1, 3, 7, 8, 1, 5, 5, 0, 10, 8, 0, 7, 3, 8, 2, 8};
	//spares, strikes and open frames, score 193
	int scoreArray[] = {10, 3, 7, 6, 1, 10, 10, 10, 2, 8, 9, 0, 7, 3, 10, 10, 10};
	
	int scorePointer = 0;
	int scoreTotal = 0;
	
	int currentFrame = 1;
	
	while(currentFrame < 11) {
		if(scoreArray[scorePointer] == 10) {
			scoreTotal += 10 + scoreArray[scorePointer+1] + scoreArray[scorePointer+2];
			scorePointer++;
		}
		else {
			//increment first.
			//we can process two throws at a time if not a strike
			scorePointer++;
			if(scoreArray[scorePointer] + scoreArray[scorePointer-1] == 10) {
				scoreTotal += 10 + scoreArray[scorePointer+1];
			}
			else {
				scoreTotal += scoreArray[scorePointer-1] + scoreArray[scorePointer];
			}
			//move to next set of throws
			scorePointer++;
		}
		
		printf("Score thru frame %d is: %d\n", currentFrame, scoreTotal);
		
		currentFrame++;
	}
	
	printf("your total score is: %d\n", scoreTotal);
	return 0;
}