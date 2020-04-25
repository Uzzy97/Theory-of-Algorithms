#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>

#include <string.h>
#include <math.h>


int main(int argc, char *argv[])  
{ 
    int opt; 
      
    while((opt = getopt(argc, argv, "a")) != -1)  
    {  
        switch(opt)  
        {  i
      
            case 'a':  
                printf("Anything you want with -a");  
                break;  
            case 'b':  
                printf("Anything you wanted here -b");  
                break;  
            case 't':  
                printf("Test goes here -t");  
                break;
            case 'h'; 
                printf("Instructions for running the project --help");  
                break;  				
            case '?':  
                printf("unknown option: %c\n", optopt); 
                break;  
        }  
    }  
      
    // optind is for the extra arguments 
    // which are not parsed 
    for(; optind < argc; optind++){      
        printf("extra arguments: %s\n", argv[optind]);  
    } 
      
    return 0; 
} 
