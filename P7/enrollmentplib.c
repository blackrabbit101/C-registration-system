/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enrollmentplib.h"
#include "corelib.h"
#include "studentplib.h"
#include "courseplib.h"



/*
* Student (in order)
 *  blazer_id
 *  first_name
 *  middle_initial
 *  last_name
 *  address
 *  city
 *  state
 *  zip
 *  status (enum inactive, active)
*/

int import_enrollments_node(char const filename[], enrollment_node_type *head_node) {
    FILE *input;
    char line[line_length_max];
    char chunks[chunk_count_max][chunk_length_max]; // 2d array
    int count;
    count = 0;
    int is_head_node;
    enrollment_node_type *current_node;
    
    is_head_node = 1;
    input = fopen(filename,"r");
    if (input != NULL){
        //start processing file
        while(file_read_line(input, line) > 0) {
                if(string_split(line, ',',chunks)==4){
                    
           if ( is_head_node == 1){
              strcpy(head_node-> crn, chunks[0]);
               strcpy(head_node-> blazer_id, chunks[1]);
                strcpy(head_node-> grade, chunks[2]);
                 head_node-> status = atoi(chunks[3]);
                 
                 
                 head_node-> next_enrollment_node = NULL;
                 is_head_node = 0;
                 count++;
                 current_node = head_node;
                
    }else{
                     current_node->next_enrollment_node =(enrollment_node_type*)malloc(sizeof(enrollment_node_type));
                  strcpy(current_node-> crn, chunks[0]);
               strcpy(current_node-> blazer_id, chunks[1]);
                strcpy(current_node-> grade, chunks[2]);
                 current_node-> status=  atoi(chunks[3]);
                       
                       
                       current_node->next_enrollment_node->next_enrollment_node = NULL;
                       current_node = current_node->next_enrollment_node;
  
    }
    }
    }
    }else{
      // display a message   
    }
        
    fclose(input);
    
    
    
    
    return(count);
    
    
}

int display_enrollments_node(enrollment_node_type *head_node) {
    // is the head_node null
    //is the head node poiting to itself
    enrollment_node_type*current_node;
    
    if (head_node == NULL){
        // do nothing
    }else if (head_node->next_enrollment_node == head_node){
        
    }else{
        current_node= head_node;
        while (current_node != NULL){
            // send the current node to the display function
            display_enrollment_node(current_node);
            current_node = current_node->next_enrollment_node;
        }
    }
    //consider returning the count
   return(0);     
}

/*int examine_emrollments_node(enrollment_node_type *head_node ) {
    enrollment_node_type *current_node;

    current_node = head_node;
    
    printf("Description                                 Value\n");
    printf("===============================================================\n");
    printf("Address of head_node                            %p\n", head_node);    
    printf("head_node.first_name                            %s\n", head_node->first_name);
    printf("head_node.middle_initial                        %s\n", head_node->middle_initial);
    printf("head_node.last_name                             %s\n", head_node->last_name);
    printf("head_node.blazer_id                             %s\n", head_node->blazer_id);
    printf("head_node.address                              %s\n", head_node->address);
    printf("head_node.city                                  %s\n", head_node->city);
    printf("head_node.state                                 %s\n", head_node->state);
    printf("head_node.zip                                   %s\n", head_node->zip);
    
    printf("Address of head_node.first_name                 %p\n", &(head_node->first_name));
    printf("Address of head_node.middle_initial             %p\n", &(head_node->middle_initial));
    printf("Address of head_node.last_name                  %p\n", &(head_node->last_name));
    printf("Address of head_node.blazer_id                  %p\n", &(head_node->blazer_id));
    printf("Address of head_node.address                    %p\n", &(head_node->address));
    printf("Address of head_node.city                       %p\n", &(head_node->city));
    printf("Address of head_node.state                      %p\n", &(head_node->state));
    printf("Address of head_node.zip                        %p\n", &(head_node->zip));
    printf("Address of head_node.next_student_node          %p\n", head_node->next_student_node);
    
    
    printf("===============================================================\n");
    
    while (current_node != NULL) {
        printf("Address of current_node                         %p\n", current_node);    
        printf("current_node.first_name                         %s\n", current_node->first_name);
        printf("current_node.middle_initial                     %s\n", current_node->middle_initial);
        printf("current_node.last_name                          %s\n", current_node->last_name);
        printf("current_node.blazer_id                          %s\n", current_node->blazer_id);  
        printf("current_node.address                            %s\n", current_node->address);
        printf("current_node.city                               %s\n", current_node->city);
        printf("current_node.state                              %s\n", current_node->state);
        printf("current_node.zip                                %s\n", current_node->zip);  

        printf("Address of current_node.first_name              %p\n", &(current_node->first_name));
        printf("Address of current_node.middle_initial          %p\n", &(current_node->middle_initial));
        printf("Address of current_node.last_name               %p\n", &(current_node->last_name));
        printf("Address of current_node.blazer_id               %p\n", &(current_node->blazer_id));
       // printf("Address of current_node.next_student_node       %p\n", current_node->next_student_node);
        printf("current_node.address                            %p\n", current_node->address);
        printf("current_node.city                               %p\n", current_node->city);
        printf("current_node.state                              %p\n", current_node->state);
        printf("current_node.zip                                %p\n", current_node->zip);  
        printf("Address of current_node.next_student_node       %p\n", current_node->next_student_node);
        current_node = current_node->next_student_node;
    }
    printf("===============================================================\n");
    return( 0 );    
}
*/



int display_enrollment_node(enrollment_node_type *enrollment_node ) {
    printf("first_name:                     %s\n",enrollment_node->crn);
    printf("middle_initial:                 %s\n",enrollment_node->blazer_id);
    printf("last_name:                      %s\n",enrollment_node->grade);
    printf("blazer_id:                      %s\n",enrollment_node->status);
  
     
}

int export_enrollments_node(char const filename[], enrollment_node_type *head_node) {
     enrollment_node_type *current_node;

    int count;

    FILE *input;

   

    count = 0;

    current_node = head_node;

    input = fopen( filename, "w" );

   

    while (( current_node != NULL ) && ( current_node->next_enrollment_node != current_node )) {

        fprintf( input, "%s,%s,%s,%d\n",

                current_node->crn,

                current_node->blazer_id,

                current_node->grade,

                current_node->status);
        
                

        current_node = current_node->next_enrollment_node;

        count++;

    }

    fclose( input );

   

    return( count );
    
    
    
}

int add_enrollment_node(enrollment_node_type *head_node,  enrollment_node_type *enrollment_node) {
    enrollment_node_type*current_node;
   if (head_node == NULL) {
       head_node = enrollment_node;
   }else if (head_node->next_enrollment_node == head_node){
       copy_enrollment_node(head_node,enrollment_node);
   }else{
       // look for the end of the list
       current_node = head_node;
       while (current_node ->next_enrollment_node !=NULL){
           current_node = current_node-> next_enrollment_node;
            head_node = head_node->next_enrollment_node;
       }
   head_node->next_enrollment_node = (enrollment_node_type*)malloc(sizeof(enrollment_node_type));
       copy_enrollment_node(head_node->next_enrollment_node,enrollment_node);
       head_node->next_enrollment_node->status = 1;
       head_node->next_enrollment_node->next_enrollment_node= NULL;
   }
}

int remove_enrollment_node(enrollment_node_type *head_node, enrollment_node_type *enrollment_node) {
   // check if the student exist
    //we could remove the node
    // we could change the status .. (not availiable)
    // remove the nodes
    
    enrollment_node_type *current_node;
    int found;
    found = 0;
    if (head_node == NULL){
        // do nothing..
    } else if (head_node->next_enrollment_node == head_node){
        // no student to remove
    }else {
        
        if((compare_enrollment_node(head_node,enrollment_node)== 1) && (head_node->next_enrollment_node == NULL)){
            strcpy(head_node->crn,"");
            strcpy(head_node->blazer_id,"");
            strcpy(head_node->grade,"");
            head_node->status = atoi("");
            
                  
            head_node->next_enrollment_node = head_node;
            found = 1;
        }
                // we have to handle the headnode a little differently
        else if (compare_enrollment_node(head_node,enrollment_node) == 1){
        copy_enrollment_node(head_node,head_node->next_enrollment_node);
        head_node->next_enrollment_node = head_node->next_enrollment_node->next_enrollment_node;
        }else{
            current_node = head_node;
        
        // handles then node inside the chain       
        while (current_node->next_enrollment_node != NULL) {
            if(compare_enrollment_node(current_node,enrollment_node)== 1) {
                //we need to remove this node
                found =1;
                
                head_node->status= 0;
                
                break;
            }else {
                 current_node = current_node->next_enrollment_node;
                 head_node = head_node->next_enrollment_node;
            }
        }
    }
}
    return(found);
}

int isa_enrollment_all_fields_list(enrollment_node_type *head_node, enrollment_node_type *enrollment_node) {
   int found;
    found =0;
    enrollment_node_type*current_node;
    if (head_node == NULL){
        
    }else if (head_node->next_enrollment_node = head_node){
        
    }else{
       current_node = head_node;
       while(current_node != NULL){
           if (compare_enrollment_node(current_node,enrollment_node) == 1){
               found = 1;
           }else{
               current_node = current_node->next_enrollment_node;
           }
    }
}
    return(found); 
}

int isa_enrollment_node(enrollment_node_type *head_node, char crn[], char blazer_id[]) {
  // return 0 or 1 if we have a match
    // check if our head null is null
    // check if head node points to its self
    int found;
    found =0;
   enrollment_node_type*current_node;
    if (head_node == NULL){
        
    }else if (head_node->next_enrollment_node = head_node){
        
    }else{
       current_node = head_node;
       while(current_node != NULL){
           if (string_compare(blazer_id,current_node->blazer_id,case_insensitive) == 0){
               found = 1;
           }
    }
}
    return(found);
}

int get_enrollment_all_fields_list(enrollment_node_type *head_node, enrollment_node_type *enrollment_node) {
   // return 0 or 1 
  //to do by tuesday
    
}

int get_enrollment_node(enrollment_node_type *head_node, char crn[], char blazer_id[], enrollment_node_type *enrollment_node) {
  //  need to leverage the return value as well as the student node
    // assume student_node is a pointer to a declared but uninitialized space in memory
    enrollment_node_type*current_node;
    
    if(head_node == NULL){
        
    }else if (head_node->next_enrollment_node == head_node){
     // cant do anything   
    }else{
     current_node = head_node;
     while (current_node != NULL){
         if((string_compare(current_node->blazer_id,blazer_id, case_insensitive)== 0)&&(string_compare(current_node->crn,crn, case_insensitive)== 0)){
             //we have a match
             copy_enrollment_node(enrollment_node,current_node);
             // do you copy the pointer
             break;
             
         }else {
             current_node=current_node->next_enrollment_node;
         }
     }
    }
}

int compare_enrollment_node(enrollment_node_type *first_enrollment_node, enrollment_node_type *second_enrollment_node) {
 return((string_compare(first_enrollment_node->crn,second_enrollment_node->crn,case_insensitive) == 0 ) &&
         (string_compare(first_enrollment_node->blazer_id,second_enrollment_node->blazer_id,case_insensitive) ==0 ) &&
       (string_compare(first_enrollment_node->grade,second_enrollment_node->grade,case_insensitive) == 0) )
         ;
}

int copy_enrollment_node(enrollment_node_type *destination_node, enrollment_node_type *source_node) {
   strcpy(destination_node->crn, source_node->crn); 
   strcpy(destination_node->blazer_id, source_node->blazer_id);
   strcpy(destination_node->grade, source_node->grade);
   (destination_node->status = source_node->status);
   
   
   // set it right now to NULL for a better reason later
   return(0);
}

int sort_enrollments_node(enrollment_node_type *head_node, enrollment_enum field, order_type order){
    // check if head_node is null or empty --> nothing
    // check if the head_node is alone
    // compare the values from the same field or two nodes
    // depending on the order (ascending);
    // if it is less than --> swap the nodes
    // what does it mean to swap a node?
   // swap the addresses that next_node points to ... (better)
    // swap the data
     // check if head_node is null or empty --> nothing
    // check if the head_node is alone
    // compare the values from the same field or two nodes
    // depending on the order (ascending);
    // if it is less than --> swap the nodes
    // what does it mean to swap a node?
   // swap the addresses that next_node points to ... (better)
    // swap the data
 
 enrollment_node_type*temp_node;
 
    int Continue = 1;
    int n_index;
    char word_temp[25];
    int n;
    int found = 1;
    if(head_node == NULL){
        
    }else if (head_node->next_enrollment_node == head_node){
     // cant do anything   
    }else{
    
     if( field == 0){
       if (order == ascending) { 
           while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(string_compare(head_node->crn,head_node->next_enrollment_node->crn, case_insensitive)== 1){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(string_compare(head_node->crn,head_node->next_enrollment_node->crn, case_insensitive)== -1){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
     }
} else if (field == 1){
    if (order == ascending) { 
           while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(string_compare(head_node->blazer_id,head_node->next_enrollment_node->blazer_id, case_insensitive)== 1){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(string_compare(head_node->blazer_id,head_node->next_enrollment_node->blazer_id, case_insensitive)== -1){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
     }
}else if (field== 2){
    if (order == ascending) { 
           while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(string_compare(head_node->grade,head_node->next_enrollment_node->grade, case_insensitive)== 1){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(string_compare(head_node->grade,head_node->next_enrollment_node->grade, case_insensitive)== -1){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
     }
} else {
    //status
    if (order == ascending) { 
           while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(head_node->status> head_node->next_enrollment_node->status){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node= head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_enrollment_node != NULL){
         if(head_node->status < head_node->next_enrollment_node->status){
             //we need to switch
             copy_enrollment_node(temp_node,head_node);
             copy_enrollment_node(head_node,head_node->next_enrollment_node);
             copy_enrollment_node(head_node->next_enrollment_node,temp_node);
             head_node=head_node->next_enrollment_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_enrollment_node;
             found = 0;
         }
     }
           }
     }
}

}
 
}
int export_report_roster(char const filename[], char crn[], enrollment_node_type *enroll_node){
    FILE *input;
    input = fopen(filename, "w");
    student_node_type* student_head_node;
        student_head_node = (student_node_type *)malloc(sizeof(student_node_type));
        student_node_type* student_node;
        student_node = (student_node_type *)malloc(sizeof(student_node_type));
        
          course_node_type* course_head_node;
        course_head_node = (course_node_type *)malloc(sizeof(course_node_type));
        course_node_type* course_node;
        course_node = (course_node_type *)malloc(sizeof(course_node_type));
    enrollment_node_type *loop_node;
    import_students_node("students.csv",student_head_node);
      import_courses_node("courses.csv",course_head_node);
    // all students registered for that crn.
   // <crn>,<semester>,<department>,<number>,<description>,<hours>,<instructor>,<blazer_id>,<first_name>,<last_name>,<grade>,<status>
    while(enroll_node != NULL){
        if (string_compare(enroll_node->crn,crn,case_insensitive)==0){
            get_student_node(student_head_node,enroll_node->blazer_id,student_node);
            get_course_node(course_head_node, crn, course_node);
            fprintf(input, "%s,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%d\n",
                    enroll_node->crn,course_node->semester,course_node->department,course_node->number,course_node->description,course_node->hours,student_node->blazer_id,student_node->first_name,student_node->last_name, enroll_node->grade,student_node->status);
            enroll_node= enroll_node->next_enrollment_node;
        }else{
            enroll_node=enroll_node->next_enrollment_node;
        }
    }
}

 
