*This project has been created as part of the 42 curriculum by eschloss.*  

# LIBFT - 42 Core Curriculum

## **Description**
This project involves coding a C library called 'Libft', which involves numerous general purpose functions for the student's programs and a Makefile to compile and execute the functions. Examples of the original functions can be found in the Linux manual pages.

This project aims to help the student understand how these functions work by implementing them themselves and learning how to use them effectively. The creation of this library will be valuable for future C school assignments. 

## **Instructions**
In order to execute the library 'Libft' and make use of the Makefile, make sure you are in the root direcotory. A 'Makefile' automates the compilation process by creating an executable command. It optimizes the build time by only recompiling the specific source files (.c) that have been changed since the last compile time by looking at the timestamps of the source files and comparing them to the resulting object files. 

*Chose one of the following commands to type into the terminal:*

#### Make  
Runs the first target by default, resulting in compiling the source (.c) files into object (.o) files by implementing the following flags:  
**Wall** - enables warnings avoidable code constructs (i.e. unitialized vars, functions without return values, etc.);  
**Wextra** - enables additional warings (i.e 'empty' if-bodies, unused-but-set parameters, etc);  
**Werror** - treats warnings as compilation errors.  
And then bundles the individual object files into a single archive calles 'libft.a' by using the following flags:  
**ar** - lower-level archiver tool to create, modify and exract static libraries;  
**r (replace)** - replaces old files with new ones, creates them if they dont exist;  
**c (create)** - creates archive if it doesnt exist, surpressing warning that normally appears;  
**s (symbol tabe)** - generates/updates symbol table(index), allows linker to quickly locate symbols;  

#### Make clean  

Removes the compiled object files by using the flags:  
**rm** - permanently deletes files and directories;  
**f (force)** - ignores non-existent files. Otherwise, trying to delete non-existing file would throw a silent warning - wont ask for confirmation.  

#### Make fclean  
Removes the compiled object files (clean) and the archived library 'libft.a'.  

#### Make re  
A shortcut for doing a full clean (removing object files and the archived library) and compiling and archiving the object files.  

## **Resources**  
The following resources have been used during the build of this project.

### **Websites and Articles**  
**Libft - 42 Cursus** https://medium.com/@piolodale/libft-42-cursus-871329cc51d3   
An article of another 42 cadet documenting project 'Libft'.  
**GNU make** https://www.gnu.org/software/make/manual/make.html  
GNU user manual for Make.  
**Makefile Basics: Beginner-Intermediate** https://medium.com/@ayogun/makefile-basics-beginner-intermediate-c92377542c2c  
A makefile guide.  
**Learn Makefiles with the tastiest examples** https://makefiletutorial.com/  
A Makefile guide.  
**How to Use Linux's ar Command to Create Static Libraries** https://www.howtogeek.com/427086/how-to-use-linuxs-ar-command-to-create-static-libraries/  
A guide on the usage of the command 'ar'.  
**Linker** https://www.geeksforgeeks.org/software-engineering/linker/  
Geeksforgeeks page on what a linker is.  
**Tutorialspoint** https://www.tutorialspoint.com/  
A website providing clear and compact explanations on different subjects around the programming language C: specific functions, header files, etc.  
**Build your own C library** https://dev.to/valeriochiodi/build-your-own-c-library-16oo  
The place where this project started.  

### **Videos**  
**mycodeschool** https://www.youtube.com/@mycodeschool
mycodeschool is an educational initiative. Our aim is to present some core concepts of computer programming through illustrated examples and creative teaching techniques.  
**Bro Code** https://www.youtube.com/@BroCodez  
Short vidoes on different subjects around the programming language C.  
**thenewboston** https://www.youtube.com/@thenewboston  
Videos around all kinds of computer programming, both back-end and front-end, some videos might be a bit outdates.  

### **AI Usage**  
During the build of this project, Generative Artificial Intelligence chatbots 'ChatGPT' and 'Claude' have been used. **No copying of code** at any time during the build of this project has taken place. When making use of GAI, the chatbots had been clearly instructed to ask critical questions, be strict and **never give away the answers under any circumstances**.  

## **Library Description**  

### **Section 1 - C standard library functions**   
Clones of functions that already exist in the programming language C. 

**ft_isapha(), ft_isdigit(), ft_isalnum(), ft_isascii(), ft_isprint()**  
Returning 0 or 1, if the character sent is alphabetical, numerical, alphanumerical, an ASCII value or a printable value.  
**ft_strlen()**  
Counts the length of a string and returns its length as *size_t*.  
**ft_memset() and ft_bzero()**  
Both take a *void* pointer as a parameter and modify the values of a specified number of bytes. To be able to traverse the void pointer and individually change the bytes, we make use of typecasting. ft_memset() travels across the void pointer up to a certain length and modifies every value to a specific int. ft_bzero(), does not allow a specific int, but changes the values to null bytes '\0'.  
**ft_memcpy() and ft_memmove()**  
Both functions use typecasting to traverse the void pointers. ft_memcpy() receives two void pointer and copies the values of the source pointer to the destination pointer, untill a certain length. The copying can cause an error if the pointers overlap. ft_memmove() handles this through copying backwards or using ft_memmove() by firstly checking in the memory if the destination pointer is positioned after or before the source pointer.  
**ft_strlcpy()**  
Receives two string pointers and copies the values of the source pointer to the destination pointer, untill a certain length. It returns the length of the source, whether the copying succeeded or not.  
**ft_strlcat**  
Concatenates the source string onto the end of the destination string untill a specific length. It returns the length of the string, whether it was successful or not.  
**ft_toupper() and ft_tolower()**  
These functions take an int and check if its equal to its lowercase or uppercase ASCII value, and convert it into uppercase or lowercase.  
**ft_strchr() and ft_strrchr()**  
Returns a pointer to the first occurence of the character c in the string and returns a pointer to the last occurence of the character c in the string, respectively.  
**ft_strncamp()**  
Takes to strings and compares them up untill a certain number. When there is a difference, the value of this difference is returned. When there is no difference, 0 is returned.  
**ft_memchr() and ft_memcmp()**  
These functions work the same as ft_strchr() and ft_strncmp(), but take void pointers instead.  
**ft_strnstr()**  
This function searches for a substring ('needle') in the original string('haystack'), up to a certain length. When found, it returns a pointer to the beginning of the substring in the orgininal string. If not, NULL is returned.  
**ft_atoi()**  
Converting a string into an integer, under specific conditions:
- The string can be given any amount of whitespaces at the beginning;
- It can only contain one minus or plus character;
- The number must be positioned directly after the minus or plus character;
- When a non-numeric value is encountered, the string stops;
- When a non-numeric value is encountered before a numeric one, no conversion happens and 0 is returned.  

**ft_calloc**  
This function allocates requested memory using malloc and returns a pointer to it. It holds a block of memory and sets all the bytes in the allocated memory to zero.  
**ft_strdup()**  
Copies the contents of a string into a newly allocated string and returns this string.  
### **Section 2 - Additional functions**   
Functions that are either not included in the libc, or exist in a different form.  

**ft_substr()**  
Allocates memory using malloc for a new string that is returned, the size of this string is based on the given index up untill the given length. If the index is bigger than the length of the string or the given length is 0, a blank string is returned.  
**ft_strjoin()**  
Adds two strings together into a newly allocated string. If one string is empy, a copy of the other string is returned.  
**ft_strtrim()**  
One string will be trimmed at the end and the beginning, based on the values of the other string. The result is returned in a newly allocated string.  
**ft_split()**  
This functions splits a string into multiple strings, based on the seperator 'c'. These words will be stored in a multidimensional array, the amount of pointer is allocated firstly based on the amount of words in the string. Than memory is allocated per array, to store the content of each word. A double pointer to this array of arrays is returned.  
**ft_itoa()**  
Converts an integer into a newly allocated string. It can both handle positive and negative integers.  
**ft_strmapi() and ft_striteri()**  
Both functions apply the function passed as a parameter to every character of a string. ft_striteri() modifies the characters immediately, while ft_strmapi() returns an allocted string with the modified results.  
**ft_putchar_fd(), ft_putstr_fd(), ft_putendl_fd(), ft_putnbr_fd()**  
Write a character, a string, a string followed by a newline and a number, with a given file descriptor.  
### **Section 3 - Linked list**   
Implementing functions using a structure to manipulate linked list.

**ft_lstnew()**  
Creates a new allocated lists and sets the given 'content' to content, while its pointer 'next' is set to NULL.  
**ft_lstadd_front()**  
Adds a new node to the front of an existing list. The new node's 'next' pointer is set to the head and the head's pointer to the new node, making it the new head.  
**ft_lstsize()**  
Iterates through the linked list, counting the amount of times it uses the 'next' pointer, untill it's equal to NULL and therefore returing the amount of nodes.  
**ft_lstadd_back()**  
Adds a new node to the end of an existing list. We set the 'next' pointer of the last node to the new node.  
**ft_lstdelone()**  
Takes a node and deletes its content using the 'del' function that was passed as a parameter. After the deletion of the contents, the memory it was holding, will be freed, using free().  
**ft_lstclear()**  
Instead of deleting one node, this function deletes and frees an entire list. The head is set to NULL.  
**ft_lstiter() and ft_lstmap()**  
The function 'f' that has been passed as a parmater will be applied to the content of every node of the list. ft_lstiter() modifies the list directly, ft_lstmap() allocates a new list and in case of malloc failure will use the passed function 'del' to clear the newlist and return NULL.  

*I hope to have informed you enough with the information given, enjoy using this library!*  
*- Elouise Schlösser*

