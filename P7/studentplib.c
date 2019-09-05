/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentplib.h"
#include "corelib.h"
#include "courseplib.h"
#include "enrollmentplib.h"


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

int import_students_node(char const filename[], student_node_type *head_node) {
    FILE *input;
    char line[line_length_max];
    char chunks[chunk_count_max][chunk_length_max]; // 2d array
    int count;
    count = 0;
    int is_head_node;
    student_node_type *current_node;
    
    is_head_node = 1;
    input = fopen(filename,"r");
    if (input != NULL){
        //start processing file
        while(file_read_line(input, line) > 0) {
                if(string_split(line, ',',chunks)==9){
                    
           if ( is_head_node == 1){
              strcpy(head_node->blazer_id, chunks[0]);
               strcpy(head_node->first_name, chunks[1]);
                strcpy(head_node->middle_initial, chunks[2]);
                 strcpy(head_node->last_name, chunks[3]);
                 strcpy(head_node-> address, chunks[4]);
                strcpy(head_node-> city, chunks[5]);
                strcpy(head_node->state, chunks[6]);
                 strcpy(head_node->zip, chunks[7]);
                 head_node->status = atoi(chunks[8]);
                 
                 head_node-> next_student_node = NULL;
                 is_head_node = 0;
                 count++;
                 current_node = head_node;
                
    }else{
                     current_node->next_student_node =(student_node_type*)malloc(sizeof(student_node_type));
                   strcpy(current_node->next_student_node->blazer_id,chunks[0]);
                     strcpy(current_node->next_student_node->first_name,chunks[1]);
                      strcpy(current_node->next_student_node->middle_initial,chunks[2]);
                       strcpy(current_node->next_student_node->last_name,chunks[3]);
                       strcpy(current_node->next_student_node->address,chunks[4]);
                     strcpy(current_node->next_student_node->city,chunks[5]);
                      strcpy(current_node->next_student_node->state,chunks[6]);
                       strcpy(current_node->next_student_node->zip,chunks[7]);
                       current_node->next_student_node->status = atoi(chunks[8]);
                       
                       current_node->next_student_node->next_student_node = NULL;
                       current_node = current_node->next_student_node;
  
    }
    }
    }
    }else{
      // display a message   
    }
        
    fclose(input);
    
    
    
    
    return(count);
    
    
}

int display_students_node(student_node_type *head_node) {
    // is the head_node null
    //is the head node poiting to itself
    student_node_type*current_node;
    
    if (head_node == NULL){
        // do nothing
    }else if (head_node->next_student_node == head_node){
        
    }else{
        current_node= head_node;
        while (current_node != NULL){
            // send the current node to the display function
            display_student_node(current_node);
            current_node = current_node->next_student_node;
        }
    }
    //consider returning the count
   return(0);     
}

int examine_students_node(student_node_type *head_node ) {
    student_node_type *current_node;

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

int display_student_node(student_node_type *student_node ) {
    printf("first_name:                     %s\n",student_node->first_name);
    printf("middle_initial:                 %s\n",student_node->middle_initial);
    printf("last_name:                      %s\n",student_node->last_name);
    printf("blazer_id:                      %s\n",student_node->blazer_id);
    printf("address                         %s\n", student_node->address);
    printf("city                            %s\n", student_node->city);
    printf("state                           %s\n", student_node->state);
    printf("zip                             %s\n", student_node->zip);  
    printf("next_student_node :             %p\n",student_node->next_student_node);
     
}

int export_students_node(char const filename[], student_node_type *head_node) {
     student_node_type *current_node;

    int count;

    FILE *input;

   

    count = 0;

    current_node = head_node;

    input = fopen( filename, "w" );
    if (current_node->next_student_node != current_node){
   

    while ( current_node != NULL )  {

        fprintf( input, "%s,%s,%s,%s,%s,%s,%s,%s,%d\n",

                current_node->first_name,

                current_node->middle_initial,

                current_node->last_name,

                current_node->blazer_id,
        
                current_node->address,

                current_node->city,

                current_node->state,

                current_node->zip,
                current_node->status);

        current_node = current_node->next_student_node;

        count++;

    }

    fclose( input );
    }else{
        printf("student export not working\n");
    }
   

    return( count );
    
    
    
}

int add_student_node(student_node_type *head_node,  student_node_type *student_node) {
    student_node_type*current_node;
   if (head_node == NULL) {
       head_node = student_node;
   }else if (head_node->next_student_node == head_node){
       copy_student_node(head_node,student_node);
   }else{
       // look for the end of the list
       current_node = head_node;
       while (current_node ->next_student_node !=NULL){
           current_node = current_node-> next_student_node;
           head_node = head_node->next_student_node;
       }
       
       head_node->next_student_node = (student_node_type*)malloc(sizeof(student_node_type));
       copy_student_node(head_node->next_student_node,student_node);
       head_node->next_student_node->status = 1;
       head_node->next_student_node->next_student_node= NULL;
         
       
   }
}

int remove_student_node(student_node_type *head_node, student_node_type *student_node) {
   // check if the student exist
    //we could remove the node
    // we could change the status .. (not availiable)
    // remove the nodes
    
    student_node_type *current_node;
    int found;
    found = 0;
    if (head_node == NULL){
        // do nothing..
    } else if (head_node->next_student_node == head_node){
        // no student to remove
    }else {
        
        if((compare_student_node(head_node,student_node)== 1) && (head_node->next_student_node == NULL)){
            strcpy(head_node->blazer_id,"");
            strcpy(head_node->first_name,"");
            strcpy(head_node->middle_initial,"");
            strcpy(head_node->last_name,"");
            strcpy(head_node->address,"");
            strcpy(head_node->city,"");
            strcpy(head_node->state,"");
            strcpy(head_node->zip,"");
                  
            head_node->next_student_node = head_node;
            found = 1;
        }
                // we have to handle the headnode a little differently
        else if (compare_student_node(head_node,student_node) == 1){
        copy_student_node(head_node,head_node->next_student_node);
        head_node->next_student_node = head_node->next_student_node->next_student_node;
        }else{
            current_node = head_node;
        
        // handles then node inside the chain       
        while (current_node->next_student_node != NULL) {
            if(compare_student_node(current_node,student_node)== 1) {
                //we need to remove this node
                head_node->status= 0;
                found =1;
                break;
            }else {
                 current_node = current_node->next_student_node;
                 head_node = head_node->next_student_node;
            }
        }
    }
}
    return(found);
}

int isa_student_all_fields_list(student_node_type *head_node, student_node_type *student_node) {
   int found;
    found =0;
    student_node_type*current_node;
    if (head_node == NULL){
        
    }else if (head_node->next_student_node = head_node){
        
    }else{
       current_node = head_node;
       while(current_node != NULL){
           if (compare_student_node(current_node,student_node) == 1){
               found = 1;
           }else{
               current_node = current_node->next_student_node;
           }
    }
}
    return(found); 
}

int isa_student_node(student_node_type *head_node, char blazer_id[]) {
  // return 0 or 1 if we have a match
    // check if our head null is null
    // check if head node points to its self
    int found;
    found =0;
    student_node_type*current_node;
    if (head_node == NULL){
        
    }else if (head_node->next_student_node = head_node){
        
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

int get_student_all_fields_list(student_node_type *head_node, student_node_type *student_node) {
   // return 0 or 1 
  //to do by tuesday
    
}

int get_student_node(student_node_type *head_node, char blazer_id[], student_node_type *student_node) {
  //  need to leverage the return value as well as the student node
    // assume student_node is a pointer to a declared but uninitialized space in memory
    student_node_type*current_node;
    
    if(head_node == NULL){
        
    }else if (head_node->next_student_node == head_node){
     // cant do anything   
    }else{
     current_node = head_node;
     while (current_node->next_student_node != NULL){
         if(string_compare(current_node->blazer_id,blazer_id, case_insensitive)== 0){
             //we have a match
             copy_student_node(student_node,current_node);
             break;
             // do you copy the pointer
         } else{
             current_node=current_node->next_student_node;
         }
     }
    }
    
    
}

int compare_student_node(student_node_type *first_student_node, student_node_type *second_student_node) {
 return((string_compare(first_student_node->first_name,second_student_node->first_name,case_insensitive) == 0 ) &&
         (string_compare(first_student_node->middle_initial,second_student_node->middle_initial,case_insensitive) ==0 ) &&
       (string_compare(first_student_node->last_name,second_student_node->last_name,case_insensitive) == 0) &&
        (string_compare(first_student_node->blazer_id,second_student_node->blazer_id,case_insensitive) ==0 )&&
          (string_compare(first_student_node->address,second_student_node->address,case_insensitive) ==0 )&&
          (string_compare(first_student_node->city,second_student_node->city,case_insensitive) ==0 )&&
          (string_compare(first_student_node->state,second_student_node->state,case_insensitive) ==0 )&&
          (string_compare(first_student_node->zip,second_student_node->zip,case_insensitive) ==0 )
         );
}

int copy_student_node(student_node_type *destination_node, student_node_type *source_node) {
   strcpy(destination_node->first_name, source_node->first_name); 
   strcpy(destination_node->middle_initial, source_node->middle_initial);
   strcpy(destination_node->last_name, source_node->last_name);
   strcpy(destination_node->blazer_id, source_node->blazer_id);
   strcpy(destination_node->address, source_node->address); 
   strcpy(destination_node->city, source_node->city);
   strcpy(destination_node->state, source_node->state);
   strcpy(destination_node->zip, source_node->zip);
   destination_node->status = source_node->status;
   // set it right now to NULL for a better reason later
   return(0);
}

int sort_students_node(student_node_type *head_node, student_enum field, order_type order){
    // check if head_node is null or empty --> nothing
    // check if the head_node is alone
    // compare the values from the same field or two nodes
    // depending on the order (ascending);
    // if it is less than --> swap the nodes
    // what does it mean to swap a node?
   // swap the addresses that next_node points to ... (better)
    // swap the data
 
 student_node_type*temp_node;
 student_node_type*current_node;
 
    int Continue = 1;
    int n_index;
    char word_temp[25];
    int n;
    int found = 1;
    if(head_node == NULL){
        
    }else if (head_node->next_student_node == head_node){
     // cant do anything   
    }else{    
        if( field == blazer_id){
            if (order == ascending) { 
                while(found == 1){
                    current_node=head_node;
                    while (current_node->next_student_node != NULL){
                        if (string_compare(current_node->blazer_id,current_node->next_student_node->blazer_id, case_insensitive)== 1){
                            //we need to switch
                           
                           copy_student_node(temp_node,current_node);
                         copy_student_node(current_node,current_node->next_student_node);
                         copy_student_node(current_node->next_student_node,temp_node);
                             current_node= current_node->next_student_node;
                            // do you copy the pointer
                            found=1;
                            break;
                        }else {
                            //do nothing

                            current_node=current_node->next_student_node;
                            found = 0;
                        }
                    }
                }
            } else{
           // descending
              while(found== 1){
     while (current_node->next_student_node != NULL){
         if(string_compare(current_node->blazer_id,current_node->next_student_node->blazer_id, case_insensitive)== -1){
             //we need to switch
             copy_student_node(temp_node,current_node);
             copy_student_node(current_node,current_node->next_student_node);
             copy_student_node(current_node->next_student_node,temp_node);
             current_node= current_node->next_student_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             current_node=current_node->next_student_node;
             found = 0;
         }
     }
           }
     }
}else if (field == city){
           if (order == ascending) { 
                while(found == 1){
                    current_node=head_node;
                    while (current_node->next_student_node != NULL){
                        if (string_compare(current_node->city,current_node->next_student_node->city, case_insensitive)== 1){
                            //we need to switch
                           
                           copy_student_node(temp_node,current_node);
                         copy_student_node(current_node,current_node->next_student_node);
                         copy_student_node(current_node->next_student_node,temp_node);
                             current_node= current_node->next_student_node;
                            // do you copy the pointer
                            found=1;
                            break;
                        }else {
                            //do nothing

                            current_node=current_node->next_student_node;
                            found = 0;
                        }
                    }
                }
            } else{
           // descending
              while(found== 1){
     while (current_node->next_student_node != NULL){
         if(string_compare(current_node->city,current_node->next_student_node->city, case_insensitive)== -1){
             //we need to switch
             copy_student_node(temp_node,current_node);
             copy_student_node(current_node,current_node->next_student_node);
             copy_student_node(current_node->next_student_node,temp_node);
             current_node= current_node->next_student_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             current_node=current_node->next_student_node;
             found = 0;
         }
     }
           }
     }
}else if (field == state){
           if (order == ascending) { 
                while(found == 1){
                    current_node=head_node;
                    while (current_node->next_student_node != NULL){
                        if (string_compare(current_node->state,current_node->next_student_node->state, case_insensitive)== 1){
                            //we need to switch
                           
                           copy_student_node(temp_node,current_node);
                         copy_student_node(current_node,current_node->next_student_node);
                         copy_student_node(current_node->next_student_node,temp_node);
                             current_node= current_node->next_student_node;
                            // do you copy the pointer
                            found=1;
                            break;
                        }else {
                            //do nothing

                            current_node=current_node->next_student_node;
                            found = 0;
                        }
                    }
                }
            } else{
           // descending
              while(found== 1){
     while (current_node->next_student_node != NULL){
         if(string_compare(current_node->state,current_node->next_student_node->state, case_insensitive)== -1){
             //we need to switch
             copy_student_node(temp_node,current_node);
             copy_student_node(current_node,current_node->next_student_node);
             copy_student_node(current_node->next_student_node,temp_node);
             current_node= current_node->next_student_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             current_node=current_node->next_student_node;
             found = 0;
         }
     }
           }
     }
}else{
       if (order == ascending) { 
                while(found == 1){
                    current_node=head_node;
                    while (current_node->next_student_node != NULL){
                        if (current_node->status>current_node->next_student_node->status){
                            //we need to switch
                           
                           copy_student_node(temp_node,current_node);
                         copy_student_node(current_node,current_node->next_student_node);
                         copy_student_node(current_node->next_student_node,temp_node);
                             current_node= current_node->next_student_node;
                            // do you copy the pointer
                            found=1;
                            break;
                        }else {
                            //do nothing

                            current_node=current_node->next_student_node;
                            found = 0;
                        }
                    }
                }
            } else{
           // descending
              while(found== 1){
     while (current_node->next_student_node != NULL){
         if(current_node->status<current_node->next_student_node->status){
             //we need to switch
             copy_student_node(temp_node,current_node);
             copy_student_node(current_node,current_node->next_student_node);
             copy_student_node(current_node->next_student_node,temp_node);
             current_node= current_node->next_student_node;
             // do you copy the pointer
             found=1;
             break;
         }else {
             //do nothing
             current_node=current_node->next_student_node;
             found = 0;
         }
     }
           }
     }    
}
}
}
int export_report_transcript(char const filename[], char blazer_id[],student_node_type *student_head_node){ // transcript
/* blazer_id: <blazer_id>
 * 
 
 * first_name: <first_name>
 * middle_iniital: <middle_initial>
 * first_name: <first_name>
 * address: <address>
 * city: <city>
 * state: <state>
 * zip: <zip>
 * status: <status>
 * total_hours: <total_hours>
 * gpa: <gpa>
 * 
 * <crn>,<semester>,<department>,<number>,<description>,<hours>,<instructor>,<grade>,<status>
 * <crn>,<semester>,<department>,<number>,<description>,<hours>,<instructor>,<grade>,<status>
 * ...
 * <crn>,<semester>,<department>,<number>,<description>,<hours>,<instructor>,<grade>,<status>
 * 
 * 
 */
    int hours = 0;
    int add_hours= 0;
    int gpa_tot=0;
    int multi= 0;
  
    
    FILE *input;
     
    input = fopen(filename, "w");
  enrollment_node_type* enrollment_head_node;
        enrollment_head_node = (enrollment_node_type *)malloc(sizeof(enrollment_node_type));
        enrollment_node_type* enroll_node;
        enroll_node = (enrollment_node_type *)malloc(sizeof(enrollment_node_type));
        
          course_node_type* course_head_node;
        course_head_node = (course_node_type *)malloc(sizeof(course_node_type));
        course_node_type* course_node;
        course_node = (course_node_type *)malloc(sizeof(course_node_type));
    enrollment_node_type *loop_node;
    import_enrollments_node("enrollments.csv",enrollment_head_node);
      import_courses_node("courses.csv",course_head_node);
   
    while(student_head_node != NULL){
        if (string_compare(student_head_node->blazer_id,blazer_id,case_insensitive)==0){
            get_enrollment_node(enrollment_head_node,crn,blazer_id,enroll_node);
            get_course_node(course_head_node, crn, course_node);
            fprintf(input, "%s,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%d\n",
                    enroll_node->crn,course_node->semester,course_node->department,course_node->number,course_node->description,course_node->hours, enroll_node->grade,student_head_node->status);
            student_head_node= student_head_node->next_student_node;
            hours = course_node->hours;
            add_hours= hours + add_hours;
            if (string_compare(enroll_node->grade,"A",case_insensitive)==0){
                multi = 4;
            }else if (string_compare(enroll_node->grade,"B",case_insensitive)==0){
                multi = 3;
            }else if (string_compare(enroll_node->grade,"C",case_insensitive)==0){
                multi = 2;
            }else if (string_compare(enroll_node->grade,"D",case_insensitive)==0){
                multi = 1;
            }else{
                multi = 0;
            }
                
            gpa_tot= hours*multi + gpa_tot;
        }else{
          student_head_node= student_head_node->next_student_node;
        }
    }
      fprintf(input,"Gpa:     %d",gpa_tot/add_hours);
       fprintf(input,"hours:     %d",add_hours);
       fclose(input);
             /* first_name: <first_name>
 * middle_iniital: <middle_initial>
 * first_name: <first_name>
 * address: <address>
 * city: <city>
 * state: <state>
 * zip: <zip>
 * status: <status>
 * total_hours: <total_hours>
 * gpa: <gpa>
}
              * */

}