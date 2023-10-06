#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// this struct holding  information
struct S
{
    char *firstName;    // pointer to the first name string
    char *lastName;     // pointer to the last name string
    char *phone;        // integer repersenting phone number
    char *emailAddress; // pointer to the email address
};
/*global variables*/

int global_line_count;

// Setter
void setLineCount(int count)
{
    global_line_count = count;
}
// getter
int getLineCount()
{
    return global_line_count;
}
/*
 * Sorting an array of pointer to struct S by first name field
 *@param ss An array of pointer to struct S
 *@param count the number of elements in the array
 */
void sfn(struct S **ss)
{
    int retrievedLineCount = getLineCount();
    for (int i = 0; i < retrievedLineCount; i++)
    {

        for (int j = i + 1; j < retrievedLineCount; j++)
        {
            if (ss[i] == NULL || ss[j] == NULL)
            {
                printf("Invalid pointer detected: ss[%d] = %p, ss[%d] = %p\n", i, ss[i], j, ss[j]);
                continue;
            }
            if (strcmp(ss[i]->firstName, ss[j]->firstName) > 0)
            {
                struct S *temp = ss[i];
                ss[i] = ss[j];
                ss[j] = temp;
            }
        }
    }
}
/*
 * Searching for occurrence of a first ane in an array of S struct
 *@param ss POINTER to an array of pointer s to struct S
 *@param s the STRING searching for
 *@return index if found otherwise 0
 */
int ffn(struct S **ss, char *s)
{
    int i = 0;
    int count = getLineCount();
    while (i < count)
    {
        // printf("Invalid pointer detected: ss[%d] = %s, \n", i, ss[i]->firstName);
        for (int j = 0; ss[i]->firstName[j] != '\0' && s[j] != '\0'; j++)
        {
            if (ss[i]->firstName[j] != s[j])
            {
                break; // Exit the loop if a mismatch is found
            }
            // printf("ss[%d]->firstName[%d]: %d, s[%d]: %d\n", i, j, ss[i]->firstName[j], j, s[j]);
            int len = strlen(ss[i]->firstName);
            if (j == len - 1)
            { // all ASCII MATCH
                return i;
            }
        }

        i++;
    }
    return -1;
}

/*
 *sorts an array of pointer struct S in ascending order based on the last name feild
 *@param ss: A pointer to an array of pointer to struct S
 */
void sln(struct S **ss)
{
    int retrievedLineCount = getLineCount();
    for (int i = 0; i < retrievedLineCount; i++)
    {
        for (int j = i + 1; j < retrievedLineCount; j++)
        {
            if (ss[i] == NULL || ss[j] == NULL)
            {
                printf("Invalid pointer detected: ss[%d] = %p, ss[%d] = %p\n", i, ss[i], j, ss[j]);
                continue;
            }
            if (strcmp(ss[i]->lastName, ss[j]->lastName) > 0)
            {
                struct S *temp = ss[i];
                ss[i] = ss[j];
                ss[j] = temp;
            }
        }
    }
}
/*
 * Check if a given last name is present in an array of `S` structures.
 *@param ss :the array of S structures to search in
 *@param s : the last name to search for
 *@return index  if s in ss,otherwise -1
 */
int fln(struct S **ss, char *s)
{
    int i = 0;
    int count = getLineCount();
    while (++i < count)
    {

        for (int j = 0; ss[i]->lastName[j] != '\0' && s[j] != '\0'; j++)
        {
            if (ss[i]->lastName[j] != s[j])
                break; // Exit the loop if a mismatch is found
            // printf("ss[%d]->firstName[%d]: %d, s[%d]: %d\n", i, j, ss[i]->lastName[j], j, s[j]);
            int len = strlen(ss[i]->lastName);
            if (j == len - 1)
            { // all ASCII MATCH
                return i;
            }
        }
        i++;
    }
    return -1;
}
/*
 *Sorting the array of struct S in ascending order of email addresses using selection sort
 *@param ss POINTER to an array of pointer to struct S
 */
void sem(struct S **ss)
{
    int count = getLineCount();
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (ss[i] == NULL || ss[j] == NULL)
            {
                printf("Invalid pointer detected: ss[%d] = %p, ss[%d] = %p\n", i, ss[i], j, ss[j]);
                continue;
            }

            if (strcmp(ss[i]->emailAddress, ss[j]->emailAddress) > 0)
            {
                struct S *temp = ss[i];
                ss[i] = ss[j];
                ss[j] = temp;
            }
        }
        // printf("ss[%d]->email: %s\n", i, ss[i]->emailAddress);
    }
}

/*
 *Search for a specific email address in an array of struct S
 *@param ss the array of pointer to struct S
 *@param s the email address searching for
 *return index is s is found otherwise -1
 */
int fem(struct S **ss, char *s)
{
    int count = getLineCount();
    int i = 0;
    while (i < count)
    {
        // printf("ss[%d]->Email: %s, s: %s\n", i, ss[i]->emailAddress, s);
        for (int j = 0; ss[i]->emailAddress[j] != '\0' && s[j] != '\0'; j++)
        {
            // printf("ss[%d]->email: %s\n", i, ss[i]->emailAddress);
            // printf("ss[%d]->Email [%d]: %c, s[%d]: %c\n", i, j, ss[i]->emailAddress[j], j, s[j]);
            if (ss[i]->emailAddress[j] != s[j])
            {
                break; // Exit the loop if a mismatch is found
            }
            int len = strlen(ss[i]->emailAddress);

            if (j == len - 1)
            { // all characters matched
                return i;
            }
        }

        i++;
    }
    return -1;
}

/*
 * Sorts an array of pointer to struct S in ascending order of phone number
 * Uses bubble sort algorithm to compare phone number of all pairs of elements
 *@param ss: Pointer to an array of pointer to struct S
 */
void sph(struct S **ss)
{
    int count = getLineCount();
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (ss[i] == NULL || ss[j] == NULL)
            {
                printf("Invalid pointer detected: ss[%d] = %p, ss[%d] = %p\n", i, ss[i], j, ss[j]);
                continue;
            }
            if (ss[i]->phone > ss[j]->phone)
            {
                struct S *s = ss[i];
                ss[i] = ss[j];
                ss[j] = s;
            }
        }
        // printf("ss[%d]->phone: %s\n", i, ss[i]->phone);
    }
}
/*
 * searching for given phone number the array of struct S pointers
 *@param ss: array of struct S pointer
 *@param s: phone number to search for
 *@return 1 if phone number found otherwise 0
 */
int fph(struct S **ss, char *s)
{
    int count = getLineCount();
    int i = 0;
    while (i < count)
    {
        for (int j = 0; ss[i]->phone[j] != '\0' && s[j] != '\0'; j++)
        {
            // printf("ss[%d]->email: %s\n", i, ss[i]->emailAddress);
            // printf("ss[%d]->Email [%d]: %c, s[%d]: %c\n", i, j, ss[i]->emailAddress[j], j, s[j]);
            if (ss[i]->phone[j] != s[j])
            {
                break; // Exit the loop if a mismatch is found
            }
            int len = strlen(ss[i]->phone);

            if (j == len - 1)
            { // all characters matched
                return i;
            }
        }
        i++;
    }
    return -1;
}

/*
 * read file from given filename,
 *@param S : struct data need to be write into
 *@param retrievedLineCount : length of reading file
 *@Param fileName: fileName
 */
void readFromFile(struct S ***ss, int *retrievedLineCount, char *fileName)
{
    FILE *f = fopen(fileName, "r");
    char line[100];
    int count_line = 0;
    // No file, no work
    if (f == NULL)
    {
        printf("Open file failed\n");
        return;
    }
    // Counting file lines
    while (fgets(line, sizeof(line), f) != NULL)
    {
        count_line++;
    }
    *retrievedLineCount = count_line;
    setLineCount(count_line);
    rewind(f); // Rewind the file pointer to the beginning of the file
    // Allocate memory for ss
    *ss = malloc(*retrievedLineCount * sizeof(struct S *));
    // Allocate memory for each struct S
    for (int i = 0; i < *retrievedLineCount; i++)
    {
        (*ss)[i] = malloc(sizeof(struct S));
        (*ss)[i]->firstName = malloc(80 * sizeof(char));     // First name can contain up to 80 chars
        (*ss)[i]->lastName = malloc(80 * sizeof(char));      // Same size for last name
        (*ss)[i]->phone = malloc(15 * sizeof(char));         // 15 digit of phone number
        (*ss)[i]->emailAddress = malloc(160 * sizeof(char)); // Email address can be up to 160 chars

        fscanf(f, "%s %s %s %s", (*ss)[i]->firstName, (*ss)[i]->lastName, (*ss)[i]->phone, (*ss)[i]->emailAddress);
    }
    fclose(f);
}
/*
 * !!!!!!!!!!!!FREE MEMORY AFTER USING!!!!!!!!!!!!!!!!!
 */
void freeMemory(struct S **ss, int retrievedLineCount)
{
    for (int i = 0; i < retrievedLineCount; i++)
    {
        free(ss[i]->firstName);
        free(ss[i]->lastName);
        free(ss[i]->phone);
        free(ss[i]->emailAddress);
        free(ss[i]);
    }

    free(ss);
}

void handle_exception()
{
    printf("Not found 404\n");
}
void correct(int result)
{
    printf("Found at index of %d (sorted) \n", result);
}
int main(int argc, char **argv)
{
    /*Local variable*/
    char buffer[100];
    int result;
    struct S **ss = NULL;
    int retrievedLineCount = 0;
    // read file
    readFromFile(&ss, &retrievedLineCount, argv[1]);
    // Print the read data
    // for (i = 0; i < retrievedLineCount; i++)
    // {
    //     printf("Read from file: firstName = %s, lastName = %s, phone = %s, emailAddress = %s\n",
    //            ss[i]->firstName, ss[i]->lastName, ss[i]->phone, ss[i]->emailAddress);
    // }

    int command = 10;
    while (command != 0)
    {
        char *val = malloc(100 * sizeof(char));
        fgets(buffer, sizeof(buffer), stdin);
        command = atoi(buffer);
        fgets(buffer, sizeof(buffer), stdin);
        strcpy(val, buffer);
        switch (command)
        {
        case 1:
            printf("looking for email %s\n", val);
            sem(ss);
            // printf("found it? %d\n", fem(ss, val));
            result = fem(ss, val);
            if (result == -1)
            {
                handle_exception();
            }
            else
            {
                correct(result);
            }
            break;
        case 2:
            printf("looking for first name %s\n", val);
            sfn(ss);
            // printf("found it? %d\n", ffn(ss, val));
            result = ffn(ss, val);
            if (result == -1)
            {
                handle_exception();
            }
            else
            {
                correct(result);
            }
            break;
        case 3:
            printf("looking for last name %s\n", val);
            sln(ss);
            // printf("found it? %d\n", fln(ss, val));
            result = fln(ss, val);
            if (result == -1)
            {
                handle_exception();
            }
            else
            {
                correct(result);
            }
            break;
        case 4:
            printf("looking for phone %s\n", val);
            sph(ss);
            // printf("found it? %d\n", fph(ss, val));
            result = fph(ss, val);
            if (result == -1)
            {
                handle_exception();
            }
            else
            {
                correct(result);
            }
            break;
        default:
            break;
        }
        free(val);
    }
    freeMemory(ss, retrievedLineCount);
    return 0;
}
