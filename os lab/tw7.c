#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int referenceString[]={1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
int lengthOfReferenceString = sizeof(referenceString) / sizeof(int);
int pagePresentInFrames , pageFaults, i ,j, k; 

void printPagesInFrames( int frame[], int numberOfFrames ){
    for( k=0; k < numberOfFrames; k++) 
        printf("\t %d",frame[k] );
}

int findIndexOfLeastRecentlyUsed( int lruCounter[], int numberOfFrames ){
    int lruValue = -1;
    int indexOfLRU = 0;
    for( int i=0; i<numberOfFrames; i++ ){
        if( lruCounter[i] == -1 ) 
            return i;
        else if( lruCounter[i] > lruValue ) {
            lruValue = lruCounter[i];
            indexOfLRU = i;
        } 
    }
    return indexOfLRU;
}

void fifoPageReplacement( int numberOfFrames ){
    int frame[5] = {-1, -1, -1, -1, -1};
    pageFaults = 0; 
    j=0; 
    printf("\n FIFO Page replacement using %d frames, initial frames = ", numberOfFrames);
    printPagesInFrames( frame, numberOfFrames );
    printf("\n Page in reference string\t\t Pages in Frames");
    for( i=0; i<lengthOfReferenceString; i++ ) {
        printf("\n\t\t %d\t\t",referenceString[i]);
        pagePresentInFrames=0; 
        for(k=0; k < numberOfFrames; k++) 
            if( frame[k] == referenceString[i] )
                pagePresentInFrames=1; 
        if ( pagePresentInFrames == 0 ) { 
            frame[j]=referenceString[i]; 
            j=(j + 1) % numberOfFrames;  
            pageFaults++; 
            printPagesInFrames( frame, numberOfFrames );
        }
    }
    printf("\n Page Faults are = %d\n", pageFaults);
}

void lruPageReplacement( int numberOfFrames ){ 
    int lruCounter[5] = {-1, -1, -1, -1, -1};
    int frame[5] = {-1, -1, -1, -1, -1};
    pageFaults = 0;
    printf("\n LRU Page replacement using %d frames, initial frames = ", numberOfFrames);
    printPagesInFrames( frame, numberOfFrames );
    printf("\n Page in reference string\t\t Pages Frames");
    for( i=0; i<lengthOfReferenceString; i++ ) {
        printf("\n\t\t %d\t\t",referenceString[i]);
        pagePresentInFrames=0; 
        for(k=0; k < numberOfFrames; k++) 
            if( frame[k] == referenceString[i]) {
                pagePresentInFrames=1; 
                lruCounter[k] = 0; 
            }
            else if( lruCounter[k] != -1 )
                lruCounter[k]++; 
        if ( pagePresentInFrames == 0 ) {
            j = findIndexOfLeastRecentlyUsed( lruCounter, numberOfFrames );
            frame[j]=referenceString[i];
            lruCounter[j] = 0; 
            pageFaults++; 
            printPagesInFrames( frame, numberOfFrames );
        }
    }
    printf("\n Page Faults are = %d\n",pageFaults);
}

int main() { 
    printf("\n Reference string = ");
    for( i=0; i < lengthOfReferenceString; i++) 
        printf(" %d",referenceString[i]);
    fifoPageReplacement( 2 ); 
    lruPageReplacement( 2 ); 
    return 0; 
}
