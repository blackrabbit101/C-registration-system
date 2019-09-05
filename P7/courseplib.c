/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseplib.h"
#include "corelib.h"



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

int import_courses_node(char const filename[], course_node_type *head_node) {
    FILE *input;
    char line[line_length_max];
    char chunks[chunk_count_max][chunk_length_max]; // 2d array
    int count;
    count = 0;
    int is_head_node;
    course_node_type *current_node;
    
    is_head_node = 1;
    input = fopen(filename,"r");
    if (input != NULL){
        //start processing file
        while(file_read_line(input, line) > 0) {
                if(string_split(line, ',',chunks)==8){
                    
           if ( is_head_node == 1){
              strcpy(head_node-> crn, chunks[0]);
               strcpy(head_node-> semester, chunks[1]);
                strcpy(head_node-> department, chunks[2]);
                 strcpy(head_node-> number, chunks[3]);
                 strcpy(head_node-> description, chunks[4]);
                 head_node-> hours = atoi(chunks[5]);
                strcpy(head_node-> instructor, chunks[6]);
               head_node-> status = atoi(chunks[7]);
                 
                 head_node-> next_course_node = NULL;
                 is_head_node = 0;
                 count++;
                 current_node = head_node;
                
    }else{
                     current_node->next_course_node =(course_node_type*)malloc(sizeof(course_node_type));
                   strcpy(current_node->next_course_node->crn,chunks[0]);
                     strcpy(current_node->next_course_node->semester,chunks[1]);
                      strcpy(current_node->next_course_node->department,chunks[2]);
                       strcpy(current_node->next_course_node->number,chunks[3]);
                       strcpy(current_node->next_course_node->description,chunks[4]);
                     current_node->next_course_node->hours = atoi(chunks[5]);
                      strcpy(current_node->next_course_node->instructor,chunks[6]);
                       current_node->next_course_node->status = atoi(chunks[7]);
                       
                       
                       current_node->next_course_node->next_course_node = NULL;
                       current_node = current_node->next_course_node;
  
    }
    }
    }
    }else{
      // display a message   
    }
        
    fclose(input);
    
    
    
    
    return(count);
    
    
}

int display_courses_node(course_node_type *head_node) {
    // is the head_node null
    //is the head node poiting to itself
    course_node_type*current_node;
    
    if (head_node == NULL){
        // do nothing
    }else if (head_node->next_course_node == head_node){
        
    }else{
        current_node= head_node;
        while (current_node != NULL){
            // send the current node to the display function
            display_course_node(current_node);
            current_node = current_node->next_course_node;
        }
    }
    //consider returning the count
   return(0);     
}

/* int examine_courses_node(course_node_type *head_node ) {
    course_node_type *current_node;

    current_node = head_node;
    
    printf("Description                                 Value\n");
    printf("===============================================================\n");
    printf("Address of head_node                            %p\n", head_node);    
    printf("head_node.first_name                            %s\n", head_node->first_name);
    printf("head_node.middle_initial                        %s\n", head_node->middle_initial);
    printf("head_node.last_name                             %s\n", head_node->last_name);
    printf("head_node.blazer_id                             %s\n", head_node->semester);
    printf("head_node.address                              %s\n", head_node->address);
    printf("head_node.city                                  %s\n", head_node->city);
    printf("head_node.state                                 %s\n", head_node->state);
    printf("head_node.zip                                   %s\n", head_node->zip);
    
    printf("Address of head_node.first_name                 %p\n", &(head_node->first_name));
    printf("Address of head_node.middle_initial             %p\n", &(head_node->middle_initial));
    printf("Address of head_node.last_name                  %p\n", &(head_node->last_name));
    printf("Address of head_node.blazer_id                  %p\n", &(head_node->semester));
    printf("Address of head_node.address                    %p\n", &(head_node->address));
    printf("Address of head_node.city                       %p\n", &(head_node->city));
    printf("Address of head_node.state                      %p\n", &(head_node->state));
    printf("Address of head_node.zip                        %p\n", &(head_node->zip));
    printf("Address of head_node.next_course_node          %p\n", head_node->next_course_node);
    
    
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
       // printf("Address of current_node.next_course_node       %p\n", current_node->next_course_node);
        printf("current_node.address                            %p\n", current_node->address);
        printf("current_node.city                               %p\n", current_node->city);
        printf("current_node.state                              %p\n", current_node->state);
        printf("current_node.zip                                %p\n", current_node->zip);  
        printf("Address of current_node.next_course_node       %p\n", current_node->next_course_node);
        current_node = current_node->next_course_node;
    }
    printf("===============================================================\n");
    return( 0 );    
}
*/

int display_course_node(course_node_type *course_node ) {
    printf("crn:                     %s\n",course_node->crn);
    printf("semester:                 %s\n",course_node->semester);
    printf("department:                      %s\n",course_node->department);
    printf("number:                      %s\n",course_node->number);
    printf("description                         %s\n", course_node->description);
    printf("hours                            %d\n", course_node->hours);
    printf("instructor                           %s\n", course_node->instructor);
    printf("status                             %d\n", course_node->status);  
    printf("next_course_node :             %p\n",course_node->next_course_node);
     
}

int export_courses_node(char const filename[], course_node_type *head_node) {
     course_node_type *current_node;

    int count;

    FILE *input;

   

    count = 0;

    current_node = head_node;

    input = fopen( filename, "w" );

   

    while ( current_node != NULL ) {

        fprintf( input, "%s,%s,%s,%s,%s,%d,%s,%d\n",

                current_node->crn,

                current_node->semester,

                current_node->department,

                current_node->number,
        
                current_node->description,

                current_node->hours,

                current_node->instructor,

                current_node->status); 

        current_node = current_node->next_course_node;

        count++;

    }

    fclose( input );

   

    return( count );
    
    
    
}

int add_course_node(course_node_type *head_node,  course_node_type *course_node) {
    course_node_type*current_node;
   if (head_node == NULL) {
       head_node = course_node;
   }else if (head_node->next_course_node == head_node){
       copy_course_node(head_node,course_node);
   }else{
       // look for the end of the list
       current_node = head_node;
       while (current_node ->next_course_node !=NULL){
           current_node = current_node-> next_course_node;
           head_node = head_node->next_course_node;
       }
       
       head_node->next_course_node = (course_node_type*)malloc(sizeof(course_node_type));
       copy_course_node(head_node->next_course_node,course_node);
       head_node->next_course_node->status = 1;
       head_node->next_course_node->next_course_node= NULL;
         
       
   }
}

int remove_course_node(course_node_type *head_node, course_node_type *course_node) {
   // check if the student exist
    //we could remove the node
    // we could change the status .. (not availiable)
    // remove the nodes
    
    course_node_type *current_node;
    int found;
    found = 0;
    if (head_node == NULL){
        // do nothing..
    } else if (head_node->next_course_node == head_node){
        // no student to remove
    }else {
        
        if((compare_course_node(head_node,course_node)== 1) && (head_node->next_course_node == NULL)){
            strcpy(head_node->crn,"");
            strcpy(head_node->semester,"");
            strcpy(head_node->department,"");
            strcpy(head_node->number,"");
            strcpy(head_node->description,"");
            head_node->hours= atoi("");
            strcpy(head_node->instructor,"");
            head_node->status= atoi("");
                  
            head_node->next_course_node = head_node;
            found = 1;
        }
                // we have to handle the headnode a little differently
        else if (compare_course_node(head_node,course_node) == 1){
        copy_course_node(head_node,head_node->next_course_node);
        head_node->next_course_node = head_node->next_course_node->next_course_node;
        }else{
            current_node = head_node;
        
        // handles then node inside the chain       
        while (current_node->next_course_node != NULL) {
            if(compare_course_node(current_node->next_course_node  ,course_node)== 1) {
                //we need to remove this node
                head_node->status= 0;
                found =1;
                
                 
               
                break;
            }else {
                 current_node = current_node->next_course_node;
                 head_node = head_node->next_course_node;
            }
        }
    }
}
    return(found);
}

int isa_courses_all_fields_list(course_node_type *head_node, course_node_type *course_node) {
   int found;
    found =0;
    course_node_type*current_node;
    if (head_node == NULL){
        
    }else if (head_node->next_course_node = head_node){
        
    }else{
       current_node = head_node;
       while(current_node != NULL){
           if (compare_course_node(current_node,course_node) == 1){
               found = 1;
           }else{
               current_node = current_node->next_course_node;
           }
    }
}
    return(found); 
}

int isa_course_node(course_node_type *head_node, char crn[]) {
  // return 0 or 1 if we have a match
    // check if our head null is null
    // check if head node points to its self
    int found;
    found =0;
    course_node_type*current_node;
    if (head_node == NULL){
        
    }else if (head_node->next_course_node = head_node){
        
    }else{
       current_node = head_node;
       while(current_node != NULL){
           if (string_compare(crn,current_node->crn,case_insensitive) == 0){
               found = 1;
           }
    }
}
    return(found);
}

int get_course_all_fields_list(course_node_type *head_node, course_node_type *course_node) {
   // return 0 or 1 
  //to do by tuesday
    
}

/*int get_course_node(course_node_type *head_node, char crn[], course_node_type *course_node) {
  //  need to leverage the return value as well as the student node
    // assume student_node is a pointer to a declared but uninitialized space in memory
    student_node_type*current_node;
    
    if(head_node == NULL){
        
    }else if (head_node->next_course_node == head_node){
     // cant do anything   
    }else{
     current_node = head_node;
     while (current_node != NULL){
         if(string_compare(current_node->crn,crn, case_insensitive)== 0){
             //we have a match
             copy_student_node(student_node,current_node);
             // do you copy the pointer
         }
     }
    }
}
*/



int compare_course_node(course_node_type *first_course_node, course_node_type *second_course_node) {
 return((string_compare(first_course_node->crn,second_course_node->crn,case_insensitive) == 0 ) &&
         (string_compare(first_course_node->semester,second_course_node->semester,case_insensitive) ==0 ) &&
       (string_compare(first_course_node->department,second_course_node->department,case_insensitive) == 0) &&
        (string_compare(first_course_node->number,second_course_node->number,case_insensitive) ==0 )&&
          (string_compare(first_course_node->description,second_course_node->description,case_insensitive) ==0 )&&
          (first_course_node->hours == second_course_node->hours) == 0 )&&
          (string_compare(first_course_node->instructor,second_course_node->instructor,case_insensitive) ==0 )&&
          ((first_course_node->status == second_course_node->status) ==0 );
         ;
}

int copy_course_node(course_node_type *destination_node, course_node_type *source_node) {
   strcpy(destination_node->crn, source_node->crn); 
   strcpy(destination_node->semester, source_node->semester);
   strcpy(destination_node->department, source_node->department);
   strcpy(destination_node->number, source_node->number);
   strcpy(destination_node->description, source_node->description); 
   (destination_node->hours = source_node->hours );
   strcpy(destination_node->instructor, source_node->instructor);
   destination_node->status = source_node->status;
   
   // set it right now to NULL for a better reason later
   return(0);
}

int sort_courses_node(course_node_type *head_node, course_enum field, order_type order){
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
     // check if head_node is null or empty --> nothing
    // check if the head_node is alone
    // compare the values from the same field or two nodes
    // depending on the order (ascending);
    // if it is less than --> swap the nodes
    // what does it mean to swap a node?
   // swap the addresses that next_node points to ... (better)
    // swap the data
 
 course_node_type*temp_node;
 
    int Continue = 1;
    int n_index;
    char word_temp[25];
    int n;
    int found = 1;
    if(head_node == NULL){
        
    }else if (head_node->next_course_node == head_node){
     // cant do anything   
    }else{
    
     if( field == 0){
       if (order == ascending) { 
           while(found= 1){
     while (head_node->next_course_node != NULL){
         if(string_compare(head_node->crn,head_node->next_course_node->crn, case_insensitive)== 1){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_course_node != NULL){
         if(string_compare(head_node->crn,head_node->next_course_node->crn, case_insensitive)== -1){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
     }
} else if (field == 1){
    if (order == ascending) { 
           while(found= 1){
     while (head_node->next_course_node != NULL){
         if(string_compare(head_node->semester,head_node->next_course_node->semester, case_insensitive)== 1){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_course_node != NULL){
         if(string_compare(head_node->semester,head_node->next_course_node->semester, case_insensitive)== -1){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
     }
}else if (field== 2){
    if (order == ascending) { 
           while(found= 1){
     while (head_node->next_course_node != NULL){
         if(string_compare(head_node->department,head_node->next_course_node->department, case_insensitive)== 1){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_course_node != NULL){
         if(string_compare(head_node->department,head_node->next_course_node->department, case_insensitive)== -1){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
     }
} else {
    //status
    if (order == ascending) { 
           while(found= 1){
     while (head_node->next_course_node != NULL){
         if(head_node->status> head_node->next_course_node->status){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node= head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
    } else{
           // descending
              while(found= 1){
     while (head_node->next_course_node != NULL){
         if(head_node->status < head_node->next_course_node->status){
             //we need to switch
             copy_student_node(temp_node,head_node);
             copy_student_node(head_node,head_node->next_course_node);
             copy_student_node(head_node->next_course_node,temp_node);
             head_node=head_node->next_course_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             head_node=head_node->next_course_node;
             found = 0;
         }
     }
           }
     }
}

}
 
}
    

 
int get_course_node(course_node_type *head_node, char crn[], course_node_type *course_node) {
  //  need to leverage the return value as well as the student node
    // assume student_node is a pointer to a declared but uninitialized space in memory
    course_node_type*current_node;
    
    if(head_node == NULL){
        
    }else if (head_node->next_course_node == head_node){
     // cant do anything   
    }else{
     current_node = head_node;
     while (current_node != NULL){
         if(string_compare(current_node->crn,crn, case_insensitive)== 0){
             //we have a match
             copy_course_node(course_node,current_node);
             break;
             // do you copy the pointer
         }else {
             current_node = current_node->next_course_node;
         }
     }
    }
    
    
}
int export_report_instructor(char const filename[], char instructor[],course_node_type *head_node){
    FILE *input;
    input= fopen(filename, "w");
    while( head_node != NULL){
        if (string_compare(instructor,head_node->instructor, case_insensitive)== 0){
            fprintf( input, "%s,%s\n",

                head_node->instructor,

                head_node->crn);

               

        head_node = head_node->next_course_node;
        }else {
       head_node = head_node->next_course_node;
        }
    }
    fclose(input);
}
int export_report_department(char const filename[], char department[], course_node_type *head_node){
    FILE *input;
    input = fopen(filename,"w");
    while( head_node != NULL){
        if (string_compare(department,head_node->department, case_insensitive)== 0){
            fprintf( input, "%s,%s\n",

                head_node->department,

                head_node->number);

               

        head_node = head_node->next_course_node;
        }else {
       head_node = head_node->next_course_node;
        }
    }
    fclose(input);
}