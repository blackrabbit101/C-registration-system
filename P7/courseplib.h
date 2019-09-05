/* 
 * File: courseplib.h
 * Copy: Copyright (c) 2018 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 2.0.2 12/04/2018 GCM - Presented Fall 2018
 * Vers: 2.0.1 11/27/2018 GCM - Presented Fall 2018
 * Vers: 2.0.0 04/11/2018 GCM - Presented Spring 2018
 * Vers: 1.0.0 04/11/2018 GCM - Original Coding
 * Desc: Header file for aggregating data functions using pointers
 */

#if !defined status_enum_declared
typedef enum {
    inactive,active
} status_enum;
#define status_enum_declared
#endif

#if !defined order_type_declared
typedef enum {
    ascending,descending
} order_type;
#define order_type_declared
#endif

#if !defined courseplib_defined

typedef enum course {
    crn,semester,department,course_status
} course_enum;
 

typedef struct course_node {
    char crn[10]; 
    char semester[10];
    char department[4];
    char number[10];
    char description[50];
    int hours;
    char instructor[30];   
    status_enum status;
    struct course_node *next_course_node;
} course_node_type; 

int import_courses_node(char const filename[], course_node_type *head_node);
int display_courses_node(course_node_type *head_node);
int examine_courses_node(course_node_type *head_node );
int display_course_node(course_node_type *course_node );
int export_courses_node(char const filename[], course_node_type *head_node);

int add_course_node(course_node_type *head_node,  course_node_type *course_node);
int remove_course_node(course_node_type *head_node, course_node_type *course_node);

int isa_course_node_all_fields_list(course_node_type *head_node, int *count, course_node_type *course_node);
int isa_course_node(course_node_type *head_node, char crn[]);

int get_course_node_all_fields_list(course_node_type *head_node, course_node_type *course_node);
int get_course_node(course_node_type *head_node, char crn[], course_node_type *course_node);

int compare_course_node(course_node_type *first_course_node, course_node_type *second_course_node);
int copy_course_node(course_node_type *destination_node, course_node_type *source_node);

int sort_courses_node(course_node_type *head_node, course_enum field, order_type order);

int export_report_department(char const filename[], char department[], course_node_type *head_node); // all courses by department
int export_report_instructor(char const filename[], char instructor[],course_node_type *head_node); // all courses by instructor

#define courseplib_defined

#endif