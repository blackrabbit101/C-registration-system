/* 
 * File: studentplib.h
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

#if !defined studentplib_defined

typedef enum student {
    blazer_id,city,state,student_status
} student_enum;

typedef struct student_node {
    char blazer_id[20];    
    char first_name[15];
    char middle_initial[2];
    char last_name[10];
    char address[30];
    char city[20];
    char state[20];
    char zip[10];
    status_enum status;
    struct student_node *next_student_node;
} student_node_type; 

int import_students_node(char const filename[], student_node_type *head_node);
int display_students_node(student_node_type *head_node);
int examine_students_node(student_node_type *head_node );
int display_student_node(student_node_type *student_node );
int export_students_node(char const filename[], student_node_type *head_node);

int add_student_node(student_node_type *head_node,  student_node_type *student_node);
int remove_student_node(student_node_type *head_node, student_node_type *student_node);

int isa_student_node_all_fields_list(student_node_type *head_node, int *count, student_node_type *student_node);
int isa_student_node(student_node_type *head_node, char blazer_id[]);

int get_student_node_all_fields_list(student_node_type *head_node, student_node_type *student_node);
int get_student_node(student_node_type *head_node, char blazer_id[], student_node_type *student_node);

int compare_student_node(student_node_type *first_student_node, student_node_type *second_student_node);
int copy_student_node(student_node_type *destination_node, student_node_type *source_node);

int sort_students_node(student_node_type *head_node, student_enum field, order_type order);

int export_report_transcript(char const filename[], char blazer_id[], student_node_type *student_head_node); // transcript
/* blazer_id: <blazer_id>
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

#define studentplib_defined

#endif