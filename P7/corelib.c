/* 
 * File: corelib.c
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 2.0.1 11/15/2018 GCM - Presented Fall 2018
 * Vers: 2.0.0 04/11/2018 GCM - Presented Spring 2018
 * Vers: 1.0.0 04/11/2018 GCM - Original Coding
 * Desc: Code file for implementing corelib.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corelib.h"


int string_split( char contents[], char delimiter, char chunks[][chunk_length_max]) {
    //Derrick,D,Jackson,dwayne1
    // look for eof and the delimeter
    
    int count;
    int chunk_index;
    count = 0;
    int contents_index;
    count = 0;
    
    chunk_index = 0; // specific character in one of our chunks
    contents_index = 0;
    
    
    // make sure that we do not exceed our chunk_length_max
    // make sure that we do not exceed our chunk_count_max
    
    while ((contents[contents_index] != '\0')&& (count < chunk_count_max)){ // not equal to end of string
        // look for delimeter
        if(contents[contents_index] == delimiter){
          chunks[count][chunk_index] = '\0';
          chunk_index =0; // reset so new chunk can be finds
          count++;
        }else{
        // character found that is not the delimiter...
            chunks[count][chunk_index] = contents[contents_index]; // copies character in to the chunk it assigned to
            chunk_index++;
        }
     contents_index++;   
    }
    if((count < chunk_count_max)){
    chunks[count][chunk_index]= '\0';
    }else{
        
    }
    count++;
    return( count );
}

/* Name: int string_compare( char const first[], char const second[], case_sensitivity_type sensitivity )
 * Desc: 
 */
int string_compare( char const first[], char const second[], case_sensitivity_type sensitivity ) {
    int first_length;
    int second_length;
    int shortest_length;
    int index = 0;
    int results;
    char first_modified[30];
    char second_modified[30];
    int validated;

    validated = 0;
    results = 0;

    if (sensitivity == case_sensitive){
        strcpy(first_modified,first);
        strcpy(second_modified, second);
        validated = 1;
    } else if (sensitivity == case_insensitive){
        string_lower(first_modified, first);
        string_lower(second_modified, second);
        validated = 1;
    }

    if (validated = 1){
        // do the rest of the string compare
        first_length = string_length(first_modified);
        second_length = string_length(second_modified);
        if (first_length <= second_length){
            shortest_length = first_length;
        } else {
            shortest_length = second_length;
        }
    }
    
    if ((results == 0) && (first_length < second_length)){
        
        results = -1;
    } else if ((results == 0) && (first_length > second_length)){
        results = 1;
    }else {
    }
        
        while(first_modified[index] != '\0'){
            if(first_modified[index]<second_modified[index]){
                results = -1;
                break;
            }else if (first_modified[index]>second_modified[index]){
                results = 1;
                break;
            }else{
                index++;
            }
        }
        
        
    

    
    return( results );
    
    //return( 0 );
}
int string_length(char const source[]){
  int results; // number of none EOS characters
  results = 0;
  
  while (source[results]!= '\0'){
      results++;
  }
  return (results);
}

// return upper case ASCII values
int string_upper (char destination[], char const source[]){
   int index; 
   int count;
   index = 0;
   count =0;
   
   
   while (source[index]!= '\0'){
       if ((source[index] >= 97) && (source[index] <= 122)){
           destination[index] = source[index] - 32;
           count++;
       }else {
           destination[index] = source[index];
       }
       index++;
   }
   destination[index] ='\0';
   //return{0);
   return(count);
}


// return lower case according to ASCII values
int string_lower (char destination[], char const source[]){
   int index; 
   int count;
   index = 0;
   count =0;
   
   
   while (source[index]!= '\0'){
       if ((source[index] >= 65) && (source[index] <= 90)){
           destination[index] = source[index] + 32;
           count++;
       }else {
           destination[index] = source[index];
       }
       index++;
   }
   destination[index] ='\0';
   //return{0);
   return(count);  
}
int file_read( char file_name[], char contents[] ) { 
    // for our purposes, we can use fscanf or fgetc...
    char current;
    FILE *input;
    int count;
    
    count = 0;
    
    input = fopen( file_name, "r");
    if ( input != NULL) {
        while (fscanf( input, "%c", &current ) != 0 ) {
            contents[ count ] = current;
            count++;
        }
    } else {
        // we do not have an active file...
    }
    
    fclose( input );
    
    return( count );
}
/* Name: int read_line( FILE *input, char line[] )
 * Desc: reads one line at a time from a file based on \n.  line[] will be a 
 * string with a \0.
 */
int file_read_line( FILE *input, char line[] ) {
    // check for a valid file handle...
    // continue collecting characters until we reach '\n'
    // when '\n' is reached, we swap it out with a '\0'
    char current;
    int count;    
    
    count = 0;
    
    if ( input != NULL ) {
        while ((fscanf( input, "%c", &current ) == 1 ) && (current != '\n')) {
                line[ count ] = current;
                count++;
        }        
    }    
    line[ count ] = '\0';    
    
    return( count ); // return the number of characters collected...
}
int char_find( char contents[], int contents_length, char search, int locations[]) {
    // we search through the contents array looking for the search character
    // we return the location where the search character is found 
    // note: no end of string!!!!
    // we need to be careful on overunning our memory
    // notice we do not specify the number of location or the max number of locations.. 
    //we will return the location of the first location_max of the search character
    int count;
    int index;
    count =0;
    index = 0;
    
    while((index< contents_length) && (count < locations_max)){
       if(contents[index ] == search){
           //we have found a match.. sore location
           locations[count]= index;
           count++;
       } else{
           
       }
       index++;
    }
    
    
    
    return( count);// how many times we found the matching character
}
int string_find( char contents[], char search[], int locations[]) {
    int contents_index;
    int search_index;
    int count;
    int match;
    int contents_length;
    int search_length;
    
    contents_index = 0;
    search_index = 0;
    count = 0;
    match = 1;
    contents_length = string_length(contents);
    search_length = string_length(search);
    
    
    // return the 0-based index of each search sub string inside our contents stirng
    if (contents_length >= search_length){
        // we atleast have a valid set of srings
        // should od more eeror checking
        // check for NULL
        // while we do not have eos
        // while match is still true
        // while we still have enough character in our contents
        // what are our conditions to check(atleast three)
       //while ((match == 1) && ) 
        while((contents_length > contents_index + search_length) && (count < locations_max)){
            search_index = 0;
            match = 1;
            while ((search[search_index] != '\0') && (match = 1)){
                if(search[search_index] == contents[contents_index]){
                    // we still have a match
                    search_index++;
                    contents_index++;
                }else{
                    //we have different characters...
                    match = 0;
                    contents_index = contents_index - search_index +1;
                }
            }
            if (match == 1){
                // all of the character must store the location
                locations[count]=  contents_index + 1; 
                count++;
            }
        }
        
        
        
    }else{
        // do nothing
    }
    
    return(count);
}