#include <iostream>
#include <string.h>

typedef char* Name;
typedef char** NameList;
typedef char*** ClassList;

void show_name_list(NameList, int);
void free_name_list(NameList, int);

void show_class_list(ClassList, int);
int longest_string_len(NameList, int);

NameList append_str(Name, NameList, int);
ClassList append_doc(NameList, ClassList, int);

NameList append_str(Name name, NameList name_list, int list_length)
{
    Name curr_name;
    name_list = (NameList) realloc(name_list, list_length);
    curr_name = (Name) malloc(strlen(name)+1);

    if (name_list && curr_name){
        strcpy(curr_name, name);
        name_list[list_length-1] = curr_name;
    }

    else{
        printf("Cannot allocate dynamic memory\n");
        exit(1);
    }

    return name_list;
}

ClassList append_doc(NameList name_list, ClassList classes, int class_num)
{
    classes = (ClassList) realloc(classes, class_num);

    if (classes)
        classes[class_num-1] = name_list;

    else{
        printf("Cannot allocate dynamic memory\n");
        exit(1);
    }

    return classes;
}

void show_class_list(ClassList classes, int class_num)
{
    for (int i=0; i < class_num; i++){
        puts("*************************");
        show_name_list(classes[i], 3);
    }
}

int main()
{
    NameList student_names1 = NULL;
    NameList student_names2 = NULL;
    ClassList classes = NULL;

    char name1[3][10] = {
        "borann",
        "chan",
        "rathnak"
    };

    char name2[3][10] = {
        "rathnak",
        "chan",
        "borann"
    };

    int student_num1 = 0;
    int student_num2 = 0;

    int class_num = 0;

    for (int i=0; i < 3; i++){
        student_names1 = append_str(
                name1[i], student_names1, ++student_num1);
    }

    for (int i=0; i < 3; i++){
        student_names2 = append_str(
                name2[i], student_names2, ++student_num2);
    }

    classes = append_doc(student_names1, classes, ++class_num);
    classes = append_doc(student_names2, classes, ++class_num);

    show_class_list(classes, class_num);

    return 0;
}

void show_name_list(NameList name_list, int list_length)
{
    for (int i=0; i < list_length; i++){
        printf("(%d): %s\n", i, name_list[i]);
    }
}

void free_name_list(NameList name_list, int list_length)
{
    for (int i=0; i < list_length; i++){
        printf("free (%d): %s\n", i, name_list[i]);
        free(name_list[i]);
    }
    printf("Successfully free list\n");
    free(name_list);
}

int longest_string_len(NameList name_list, int list_length)
{
    int longest_len = 0;
    int curr_len;
    for (int i=0; i < list_length; i++){
        curr_len = strlen(name_list[i]);
        longest_len = longest_len < curr_len ? curr_len : longest_len;
    }
    return longest_len;
}
