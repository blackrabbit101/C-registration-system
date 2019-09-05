/*
 * Name: P7 (draft)
 * Description: Utilizing functions, build a command line utility that will 
 * model a student, course enrollment system similar to UAB's BlazerNET.  Your 
 * system must be able to handle the addition and removal of students and 
 * courses as well as the enrollment and withdrawal of a student from a course.
 * Your solution must also utilize separate header files as well as pointers per
 * the function signatures listed in the provided header files.

 * Input and Output files will be utilized as well as command line switches to 
 * control behavior.
 */

/* Problem{01}: Utilizing notes starting with Class_18, build a command line 
 * tool that will accept three hard coded csv files representing/containing  the
 *  following information:
 * 
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
 * 
 * Course (in order)
 *  crn
 *  semester (FA2018,SP2019, etc...)
 *  department
 *  number
 *  description (no commas)
 *  hours
 *  instructor
 *  status (enum inactive, active)
 * 
 * Enrollemt
 *  crn
 *  blazer_id
 *  status (enum inactive, active)
 *  grade (A, B, C, D, F, N, W )
 * 
 * All information and options must be provided from the command line based on 
 * the following switches/tiers and order:
 * Arguments:
 *  argv[1]: table options are /student /course /enrollment
 *  argv[2]: action options are /add /remove /sort /display /export
 *  argv[3]: add options are based on table
 *              /student /add <blazer_id> <first_name> <middle_initial> <last_name> <address> <city> <state> <zip>
 *              /course /add <crn> <semester> <department> <number> <description> <hours> <instructor>
 *              /enrollment /add <crn> <blazer_id>
 *  argv[3]: remove options are based on table
 *              /student /remove <blazer_id> --> active goes to inactive
 *              /course /remove <crn> --> active goes to inactive
 *              /enrollment /remove <crn> <blazer_id> --> active goes to inactive and grade goes to W
 *  argv[3]: sort options are based on table
 *              /student /sort <any field> /ascending or /descending>
 *              /course /sort <any field> /ascending or /descending>
 *              /enrollment /sort <any field> /ascending or /descending>
 *  argv[3]: display options are based on table
 *              /student requires /blazer_id <blazer_id>
 *              /course requires /crn <crn>
 *              /enrollmeent can utilize
 *                  /crn <crn> /blazer_id <blazer_id>
 *                  /crn <crn> 
 *                  /blazer_id <blazer_id>
 *           export options are based on table
 *              /student /export /blazer_id <blazer_id>
 *              /course /export /department <department> /number <number>
 *              /course /export /instructor <instructor>
 *              /enrollment /export /crn <crn>      
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courseplib.h"
#include "studentplib.h"
#include "enrollmentplib.h"
#include "corelib.h"

    int main(int argc, char** argv) {
        int i;
        FILE *input;
        student_node_type* student_head_node;
        student_head_node = (student_node_type *)malloc(sizeof(student_node_type));
        student_node_type* student_node;
        student_node = (student_node_type *)malloc(sizeof(student_node_type));
        
          course_node_type* course_head_node;
        course_head_node = (course_node_type *)malloc(sizeof(course_node_type));
        course_node_type* course_node;
        course_node = (course_node_type *)malloc(sizeof(course_node_type));
        
        enrollment_node_type* enrollment_head_node;
        enrollment_head_node = (enrollment_node_type *)malloc(sizeof(enrollment_node_type));
        enrollment_node_type* enrollment_node;
        enrollment_node = (enrollment_node_type *)malloc(sizeof(enrollment_node_type));
        
        for (i = 0; i < argc; i++) {
        printf("\t%i: %s\n", i, argv[i]);        
    }
        if (strcmp( argv[1], "/student" ) == 0) {
            // help explicitly called
            import_students_node("students.csv",student_head_node);
            
              if (strcmp( argv[2], "/add" ) == 0) {
                  strcpy(student_node->blazer_id, argv[3]);
               strcpy(student_node->first_name, argv[4]);
                strcpy(student_node->middle_initial, argv[5]);
                 strcpy(student_node->last_name, argv[6]);
                 strcpy(student_node-> address, argv[7]);
                strcpy(student_node->city, argv[8]);
                strcpy(student_node->state, argv[9]);
                 strcpy(student_node->zip, argv[10]);
                
                  add_student_node(student_head_node, student_node);
                    export_students_node("students.csv", student_head_node);
            } else if(strcmp( argv[2], "/sort" ) == 0){
                if (strcmp( argv[3], "/blazer_id" ) == 0){
                if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_students_node(student_head_node,0,ascending);
                }else {
                     sort_students_node(student_head_node,0,descending);  
                }
                }else if ((strcmp( argv[3], "/city" ) == 0)){
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_students_node(student_head_node,1,ascending);
                }else {
                     sort_students_node(student_head_node,1,descending);  
                }
                }else if(strcmp( argv[3], "/state" ) == 0){
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_students_node(student_head_node,2,ascending);
                }else {
                     sort_students_node(student_head_node,2,descending);  
                }
                }else {
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_students_node(student_head_node,3,ascending);
                }else {
                          // status
                     sort_students_node(student_head_node,3,descending);  
                }
                }
                 export_students_node("students_sorted.csv", student_head_node);
             }else if (strcmp( argv[2], "/export" ) == 0){
               
                export_report_transcript("report.csv",argv[3],student_head_node);
            
                
            }else if (strcmp( argv[2], "/display" ) == 0){
                get_student_node( student_head_node, argv[3],student_node);
                display_student_node(student_node);
            }else {
                
                get_student_node( student_head_node, argv[3], student_node);
                 remove_student_node(student_head_node,student_node);
                 export_students_node("students.csv", student_head_node);
            }
            
        } else if (strcmp( argv[1], "/course" ) == 0){
          import_courses_node("courses.csv",course_head_node);
               if (strcmp( argv[2], "/add" ) == 0) {
                strcpy(course_node->crn, argv[3]);
               strcpy(course_node->semester, argv[4]);
                strcpy(course_node->department, argv[5]);
                 strcpy(course_node->number, argv[6]);
                 strcpy(course_node->description, argv[7]);
                course_node->hours = atoi(argv[8]);
                strcpy(course_node->instructor, argv[9]);
                 
                         
                  add_course_node(course_head_node, course_node);
                    export_courses_node("courses.csv", course_head_node);
            
                } else if(strcmp( argv[2], "/sort" ) == 0){
                   
                if (strcmp( argv[3], "/crn" ) == 0){
                if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_courses_node(course_head_node,0,ascending);
                }else {
                     sort_courses_node(course_head_node,0,descending);  
                }
                }else if ((strcmp( argv[3], "/semester" ) == 0)){
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_courses_node(course_head_node,1,ascending);
                }else {
                     sort_courses_node(course_head_node,1,descending);  
                }
                }else if(strcmp( argv[3], "/state" ) == 0){
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_courses_node(course_head_node,2,ascending);
                }else {
                     sort_courses_node(course_head_node,2,descending);  
                }
                }else {
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_courses_node(course_head_node,3,ascending);
                }else {
                          // status
                     sort_courses_node(course_head_node,3,descending);  
                }
                }
                 }else if (strcmp( argv[2], "/export" ) == 0){
                     if (strcmp(argv[3],"/instructor")==0){
                         
                         export_report_instructor("report_instuctor.csv",argv[4], course_head_node);
                     }else {
                         export_report_department("report_department.csv",argv[4], course_head_node);
                     }
                
                  }else if (strcmp( argv[2], "/display" ) == 0){
                      get_course_node( course_head_node, argv[3],course_node);
                display_course_node(course_node);
                    }else {
                // remove
                      strcpy(course_node->crn, argv[3]);
               strcpy(course_node->semester, argv[4]);
                strcpy(course_node->department, argv[5]);
                 strcpy(course_node->number, argv[6]);
                 strcpy(course_node->description, argv[7]);
                course_node->hours=  atoi(argv[8]);
                strcpy(course_node->instructor, argv[9]);
                strcpy( student_node->zip,(argv[10]));
                 remove_course_node(course_head_node,course_node);
                 export_courses_node("courses.csv", course_head_node);
            }
        } else if (strcmp( argv[1], "/enrollment" ) == 0) {
            import_enrollments_node("enrollments.csv",enrollment_head_node);
               if (strcmp( argv[2], "/add" ) == 0) {

               strcpy(enrollment_node->crn, argv[3]);
                strcpy(enrollment_node->blazer_id, argv[4]);
                 strcpy(enrollment_node->grade, argv[5]);
                  enrollment_node->status = 1;
              
                         
                  add_enrollment_node(enrollment_head_node, enrollment_node);
                    export_enrollments_node("enrollments.csv", enrollment_head_node);
            
            } else if(strcmp( argv[2], "/sort" ) == 0){
                
                if (strcmp( argv[3], "/enrollment_crn" ) == 0){
                if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_enrollments_node(enrollment_head_node,0,ascending);
                }else {
                     sort_enrollments_node(enrollment_head_node,0,descending);  
                }
                }else if ((strcmp( argv[3], "/enrollment_blazer_id" ) == 0)){
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_enrollments_node(enrollment_head_node,1,ascending);
                }else {
                     sort_enrollments_node(enrollment_head_node,1,descending);  
                }
                }else if(strcmp( argv[3], "/grade" ) == 0){
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_enrollments_node(enrollment_head_node,2,ascending);
                }else {
                     sort_enrollments_node(enrollment_head_node,2,descending);  
                }
                }else {
                      if (strcmp( argv[4], "/ascending" ) == 0){
                    sort_enrollments_node(enrollment_head_node,3,ascending);
                }else {
                          // status
                     sort_enrollments_node(enrollment_head_node,3,descending);  
                }
                }
             }else if (strcmp( argv[2], "/export" ) == 0){
                 import_students_node("students.csv", student_head_node);
            export_report_roster("Crn_roster_enrollment.csv",argv[3],enrollment_head_node);
             }else if (strcmp( argv[2], "/display" ) == 0){
                  get_enrollment_node( enrollment_head_node, argv[3],argv[4],enrollment_node);
                display_enrollment_node(enrollment_node);
             }else {
                // remove enrollments
                 get_enrollment_node(enrollment_head_node,argv[3],argv[4],enrollment_node);
                 remove_enrollment_node(enrollment_head_node,enrollment_node);
                 export_enrollments_node("enrollments.csv", enrollment_head_node);
            }
        }else{
            
        }
    return(0);  
    }