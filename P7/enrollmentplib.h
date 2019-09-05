/* 
 * File: enrollmentplib.h
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


#if !defined enrollmentplib_defined

typedef enum enrollment {
    enrollment_crn,enrollment_blazer_id,grade,enrollment_status
} enrollment_enum;

typedef struct enrollment_node {
    char crn[10];
    char blazer_id[20];
    char grade[2];    // will consider an enum as well.
    status_enum status;
    struct enrollment_node *next_enrollment_node;
} enrollment_node_type; 



int import_enrollments_node(char const filename[], enrollment_node_type *head_node);
int display_enrollments_node(enrollment_node_type *head_node);
int examine_enrollments_node(enrollment_node_type *head_node );
int display_enrollment_node(enrollment_node_type *enrollment_node );
int export_enrollments_node(char const filename[], enrollment_node_type *head_node);

int add_enrollment_node(enrollment_node_type *head_node,  enrollment_node_type *enrollment_node);
int remove_enrollment_node(enrollment_node_type *head_node, enrollment_node_type *enrollment_node);

int isa_enrollment_node_all_fields_list(enrollment_node_type *head_node, int *count, enrollment_node_type *enrollment_node);
int isa_enrollment_node(enrollment_node_type *head_node, char crn[], char blazer_id[]);

int get_enrollment_node_all_fields_list(enrollment_node_type *head_node, enrollment_node_type *enrollment_node);
int get_enrollment_node(enrollment_node_type *head_node, char crn[], char blazer_id[], enrollment_node_type *enrollment_node);

int compare_enrollment_node(enrollment_node_type *first_enrollment_node, enrollment_node_type *second_enrollment_node);
int copy_enrollment_node(enrollment_node_type *destination_node, enrollment_node_type *source_node);

int sort_enrollments_node(enrollment_node_type *head_node, enrollment_enum field, order_type order);

int export_report_roster(char const filename[], char crn[], enrollment_node_type *enroll_node); // all students registered for that crn.
// <crn>,<semester>,<department>,<number>,<description>,<hours>,<instructor>,<blazer_id>,<first_name>,<last_name>,<grade>,<status>

#define enrollmentplib_defined

#endif