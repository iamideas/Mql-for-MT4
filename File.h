//*******************************************
//           File functions
//res::http://docs.mql4.com/files
//*******************************************
#ifndef FILE_H__
#define FILE_H__

#include"Framework\standardCPPLibrary.h"
#include"DataType.h"
#define DOUBLE_VALUE 8
#define FLOAT_VALUE  4
#define CHAR_VALUE   1
#define SHORT_VALUE  2
#define LONG_VALUE   4
#define INT_VALUE	 4
/*
 * 	 Closes file previously opend by the FileOpen() function.
 * 	 handle - File handle returned by the FileOpen() function.
 */
void FileClose(int handle);

/*
 *   Removes specified file name. To get the detailed error
 * information, call GetLastError(). Files can only be deleted
 * if they are in the terminal_dir\experts\files directory
 * (terminal_directory\tester\files, in case of testing) or its
 * subdirectories.
 *	 Parameters:
 *		filename	  -  	Path to the file.
 */
void FileDelete(string filename);

/*
 *   Flushes all data stored in the file buffer to the disk.
 *	 Notes: The FileFlush() function must be called between
 * operations of file reading and writing in the file.
 * At file closing, the data are flushed to the disk automatically,
 * so there is no need to call the FileFlush() function before
 * calling of the FileClose() function.
 *
 *   handle - File handle returned by the FileOpen() function.
 */
void FileFlush(int handle);

/*
 *   Returns logical true if file pointer is at the end of the file,
 * otherwise returns false. To get the detailed error information,
 * call GetLastError() function. If the file end is reached during
 * reading, the GetLastError() function will return error ERR_END_OF_FILE
 *  (4099).
 */
bool FileIsEnding(int handle);

bool FileIsLineEnding(int handle);

int FileOpen(string filename, int mode, int delimiter=';');

int FileOpenHistory(string filename, int mode, int delimiter=';');

template<typename N>
int FileReadArray(int handle, N array[], int start, int count);

//size DOUBLE_VALUE or FLOAT_VALUE
int FIleReadDouble(int handle, int size=DOUBLE_VALUE);

/*
 * size	  -  	Format size. Can be CHAR_VALUE(1 byte), SHORT_VALUE(2 bytes)
 *             or LONG_VALUE(4 bytes).
 */
int FileReadInteger(int handle, int size=LONG_VALUE);

//Read the number for the current file position before the delimiter, only for csv files.
double FileReadNumber(int handle);

string FileReadstring(int handle, int length=0);

bool FileSeek(int handle, int offset, int origin);

int FileSize(int handle);

int FileTell(int handle);

int FileWrite(int handle, ...);

template<typename N>
int FileWriteArray(int handle, N array[], int start, int count=WHOLE_ARRAY);

int FileWriteDouble(int handle, double value, int size=DOUBLE_VALUE);

int FileWriteInteger(int handle, int value, int size=LONG_VALUE);

int FileWriteString(int handle, string value, int length=-1);

//The function starts the search of files or subdirectories in a directory in accordance with the specified filter.
long  FileFindFirst(
	const string   file_filter,          // String - search filter
	string&        returned_filename,    // Name of the file or subdirectory found
	int            common_flag = 0         // Defines the search
);

//The function continues the search started by FileFindFirst().
bool  FileFindNext(
	long      search_handle,         // Search handle
	string&   returned_filename      // Name of the file or subdirectory found
);

//The function closes the search handle.
void  FileFindClose(
	long  search_handle      //  Search handle
);

//Checks the existence of a file.
bool  FileIsExist(
	const string  file_name,       // File name
	int           common_flag = 0    // Search area
);

//The function opens the file with the specified name and flag.
int  FileOpen(
	string  file_name,           // File name
	int     open_flags,          // Combination of flags
	short   delimiter = '\t',      // Delimiter
	uint    codepage = CP_ACP      // Code page
);

//Close the file previously opened by FileOpen().
void  FileClose(int  file_handle);

//The function copies the original file from a local or shared folder to another file.
bool  FileCopy(
	const string  src_file_name,     // Name of a source file
	int           common_flag,       // Location	
	const string  dst_file_name,     // Name of the destination file
	int           mode_flags         // Access mode
);

//Deletes the specified file in a local folder of the client terminal.
bool  FileDelete(
	const string  file_name,     // File name to delete 
	int           common_flag = 0  // Location of the file to delete
);

//Moves a file from a local or shared folder to another folder.
bool  FileMove(
	const string  src_file_name,    // File name for the move operation
	int           common_flag,      // Location
	const string  dst_file_name,    // Name of the destination file
	int           mode_flags        // Access mode
);

//Writes to a disk all data remaining in the input / output file buffer.
void  FileFlush(int  file_handle );


/*
	Gets an integer property of a file.There are two variants of the function.
	1. Get a property by the handle of a file.
*/
long  FileGetInteger(
	int                         file_handle,   // File handle
	ENUM_FILE_PROPERTY_INTEGER  property_id    // Property ID
);
//2. Get a property by the file name.
long  FileGetInteger(
	const string                file_name,            // File name
	ENUM_FILE_PROPERTY_INTEGER  property_id,          // Property ID
	bool                        common_folder = false   // The file is viewed in a local folder (false)
);

//Defines the end of a file in the process of reading.
bool  FileIsEnding(int  file_handle );

//Defines the line end in a text file in the process of reading.
bool  FileIsLineEnding(int  file_handle);

/*
	Reads from a file of BIN type arrays of any type except string(may be an array of structures, not 
containing strings, and dynamic arrays).
*/
template<typename TYPE>
uint  FileReadArray(
	int    file_handle,               // File handle
	TYPE   array[],                   // Array to record
	int    start = 0,                   // start array position to write
	int    count = WHOLE_ARRAY          // count to read
);

/*
	Reads from the file of CSV type string from the current position to a delimiter(or till the end of 
the text line) and converts the read string to a bool type value.
*/
bool  FileReadBool(int  file_handle);

/*
	Reads from the file of CSV type a string of one of the formats : "YYYY.MM.DD HH:MI:SS", "YYYY.MM.DD" 
or "HH:MI:SS" - and converts it into a value of datetime type.
*/
datetime  FileReadDatetime(int  file_handle);

//Reads a double - precision floating point number(double) from the current position of the binary file.
double  FileReadDouble(int  file_handle);

//Reads the single - precision floating point number(float) from the current position of the binary file.
float  FileReadFloat(int  file_handle);

/*
	The function reads int, short or char value from the current position of the file pointer depending on 
the length specified in bytes.
*/
int  FileReadInteger(
	int  file_handle,        // File handle
	int  size = INT_VALUE      // Size of an integer in bytes
);

//The function reads an integer of long type(8 bytes) from the current position of the binary file.
long  FileReadLong(int  file_handle);

/*
	The function reads from the CSV file a string from the current position till a separator(or till 
the end of a text string) and converts the read string to a value of double type.
*/
double  FileReadNumber(int  file_handle);

//The function reads from a string from the current position of a file pointer in a file.
string  FileReadString(
	int  file_handle,     // File handle
	int  length = -1        // Length of the string
);

/*
	The function reads contents into a structure passed as a parameter from a binary - file, 
starting with the current position of the file pointer.
*/
template<typename TYPE>
uint  FileReadStruct(
	int          file_handle,        // file handle
	const TYPE   struct_object,      // target structure to which the contents are read
	int          size = -1             // structure size in bytes
);

//The function moves the position of the file pointer by a specified number of bytes relative to the specified position.
bool  FileSeek(
	int                  file_handle,     // File handle
	long                 offset,          // In bytes
	ENUM_FILE_POSITION   origin           // Position for reference
);

//The function writes the value of a double parameter to a file, starting from the current position of the file pointer.
uint  FileWriteDouble(
	int     file_handle,     // File handle
	double  value            // Value to write
);

//The function writes the value of the float parameter to a bin - file, starting from the current position of the file pointer.
uint  FileWriteFloat(
	int    file_handle,     // File handle
	float  value            // Value to be written
);

/*
	The function writes into a bin - file contents of a structure passed as a parameter, starting from the 
current position of the file pointer.
*/
template<typename TYPE>
uint  FileWriteStruct(
	int          file_handle,       // File handle
	const TYPE&  struct_object,     // link to an object
	int          size = -1            // size to be written in bytes
);

//The function creates a folder in the Files directory(depending on the value of common_flag).
bool  FolderCreate(
	string  folder_name,       // String with the name of the new folder
	int     common_flag = 0      // Scope
);

//The function removes the specified directory.If the folder is not empty, then it can't be removed.
bool  FolderDelete(
	string  folder_name,       // String with the name of the folder to delete
	int     common_flag = 0      // Scope
);

//The function deletes all files in a specified folder.
bool  FolderClean(
	string  folder_name,       // String with the name of the deleted folder
	int     common_flag = 0      // Scope
);
#endif
