
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <time.h>

void random_int(int masterArr[], int size){
	for(int i=0;i<size;++i){

		masterArr[i] = rand() % 10;
	}
}

void print_master(int masterArr[], int size){
	for(int i=0; i<size;++i){
		printf("%d", masterArr[i]);

	}
}
void clearInput(){
	int c;
	while((c=getchar())!='\n'&&c!=EOF);
}

void user_array_input(int userArr[], int size){
    char notnum;
    int counter = 0;
	printf("Enter your guess, 6 digits");
    while (counter < size ) {
       
		notnum=getchar();
		if(isdigit(notnum)){
			userArr[counter++]=notnum-'0';

		}else if(notnum=='\n'){
			if(counter<size){
				printf("You need to enter %d more digits to complete your guess",size-counter);
				continue;
			}
		} else if(notnum != ' ' &&notnum != '\t'){
			printf("A character in your guess was not a digit or a white space\n");
			clearInput();
			counter=0;
		}
    
      
   

	}
	clearInput();
}
void printContent(int userArr[], int size){

	for(int i=0; i<size; i++){
		printf("%d ",userArr[i]);

		
	}
}


int comepareIndices(int userArr[],int masterArr[], int size){
	int correct=0;
	int partiallyCorrect=0;
	
	for(int i=0;i<size;i++){
		if(userArr[i]==masterArr[i]){
			correct+=1;

		} else{
			for (int p=0;p<size;p++){
				if(userArr[i]==masterArr[p] && userArr[p]!=masterArr[p]){
					partiallyCorrect+=1;
					break;
				}
			}
		}
	}
	printf("- %d correct,",correct);
	printf(" %d partically correct",partiallyCorrect);
	
	return correct==size;

}


void guessLoop(int masterArr[], int size){
	printf("For each turn enter 6 digits 0 <= digit <= 9 Spaces or tabs in your response will be ignored\n Enter your guess, 6 digits\n");

	int guesses=0;
	while (1){
		int userArr[6];
		user_array_input(userArr,size);
		
		printf("Guess %d: ",++guesses);
		printContent(userArr,size);
		if(comepareIndices(userArr,masterArr,size)){
			printf("YOU DID IT!");
			break;
		}
	}
	
	

}

unsigned int seed_reader(){
	unsigned int seed;
	printf("Enter the integer value of the seed for the game: ");
	while(scanf("%u",&seed)!=1){
		printf("Try again you made an error");
		scanf("%*[^\n]");
    	scanf("%*c");

	}
	return seed;
}

int main()
{
	unsigned int seed = seed_reader();
    srand(seed);
	
	srand(time(NULL));
	// prints hello world
	int masterArr[6];
	random_int(masterArr,6);
	print_master(masterArr,6);
    
	// int userArr[6];
	// user_array_input(userArr,6,masterArr);
	
	// printContent(userArr,6);
	// comepareIndices(userArr,masterArr,6);

	guessLoop(masterArr,6);
	





	return 0;
	
}



// while len  less than 6 
//     print ("enter %d more characters", 6-len)