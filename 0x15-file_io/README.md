C - File I/O

C programming language provides several functions and system calls for performing file Input/Output (I/O) operations. File I/O is an essential part of any program that needs to store or retrieve data from external storage devices, such as a hard disk or USB drive.

In C programming, file I/O can be performed using the standard input/output library functions or using the lower-level system calls. The standard library functions provide a high-level interface that abstracts the details of the underlying system calls, making it easier to read and write data to files. The system calls, on the other hand, provide a lower-level interface that offers more control over the file I/O operations.
Opening a File

Before performing any file I/O operations, you must first open the file. The open() system call is used to open a file in C programming. The function takes two arguments: the file name and the file access mode. The file access mode is specified using the oflag argument, which can take one or more of the following flags:

    O_RDONLY: Read-only mode
    O_WRONLY: Write-only mode
    O_RDWR: Read-write mode
    O_CREAT: Create the file if it does not exist
    O_TRUNC: Truncate the file if it exists
    O_APPEND: Append data to the end of the file

The open() system call returns a file descriptor, which is an integer that identifies the file and is used in subsequent file I/O operations.
Closing a File

Once you have finished using a file, you must close it using the close() system call. The close() function takes a single argument, which is the file descriptor returned by the open() function.
Reading and Writing to a File

To read from or write to a file, you can use the read() and write() system calls. These functions take three arguments: the file descriptor, a pointer to the buffer where the data is to be read or written, and the number of bytes to read or write.

The read() function returns the number of bytes read, which may be less than the number of bytes requested if the end of the file is reached. The write() function returns the number of bytes written, which may be less than the number of bytes requested if there is not enough space on the file system.
File Positioning

You can move the file position pointer using the lseek() system call. The lseek() function takes three arguments: the file descriptor, the offset to move the file pointer, and the reference point from which the offset is applied.
Buffered I/O

The standard I/O library provides buffered I/O functions such as fread(), fwrite(), fseek(), and ftell(). These functions are used to perform file I/O operations using a buffer in memory, which can improve performance when reading or writing large amounts of data.
Conclusion

C programming language provides several functions and system calls for file I/O operations. Understanding the basic concepts of file I/O, such as opening and closing files, reading and writing data, and positioning the file pointer, is essential for any program that needs to interact with external storage devices.
