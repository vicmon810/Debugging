#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct S
{
    char *firstName;    // pointer to the first name string
    char *lastName;     // pointer to the last name string
    int phone;          // integer representing phone number
    char *emailAddress; // pointer to the email address
};

int main(int argc, char **argv)
{
    int count = 0;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Open file failed\n");
        return 1;
    }

    struct S **ss = (struct S **)malloc(100 * sizeof(struct S **));
    struct S *s = malloc(sizeof(*s));

    for (int i = 0; i < 10; i++)
    {
        s[i].firstName = malloc(80 * sizeof(char));                                              // first name can contain up to 80 chars
        s[i].lastName = malloc(80 * sizeof(char));                                               // same size for last name
        s[i].emailAddress = malloc(160 * sizeof(char));                                          // email address can be up to 160 chars
        fscanf(f, "%s %s %d %s", s[i].firstName, s[i].lastName, &s[i].phone, s[i].emailAddress); // read each detail
        ss[count] = s;
    }
    fclose(f);

    // free memory
    for (int i = 0; i < 10; i++)
    {
        free(s[i].firstName);
        free(s[i].lastName);
        free(s[i].emailAddress);
    }
    free(s);

    return 0;
}
