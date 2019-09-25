#include <stdio.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("\nUsage:\n");
		printf("-d\tRead what's in the clipboard.\n");
		printf("-e\tClear what's in the clipboard.\n");
		printf("-h\tPrint this message.\n");
		return 1;
	}
	else if (argc >= 3)
	{
		printf("\nToo many arguments, exiting...\n");
		return 1;
	}
	else {
		if (strcmp(argv[1], "-e") == 0)
		{
			OpenClipboard(NULL);
			EmptyClipboard();
			CloseClipboard();
			printf("\nThe Clipboard has been cleared.\n");
			return 0;
		}
		else if (strcmp(argv[1], "-d") == 0)
		{
			OpenClipboard(NULL); // According to MSDN, this should be set to NULL. 
			HANDLE hData = GetClipboardData(CF_TEXT); // CF_TEXT to print ASCII and Unicode strings.

			// If/Else statment to exit if no data in clipboard, otherwise print what's stored. 
			if (!hData) {
				printf("\nNo Data in the Clipboard.\n");
				return 1;
			}
			else {
				printf("\n");
				printf(hData);
				printf("\n");
			}
			CloseClipboard(); // After opening a Handle to the clipboard, close after you're done with it. 
			return 0;
		}
		else if (strcmp(argv[1], "-h") == 0)
		{
			printf("\nUsage:\n");
			printf("-d\tRead what's in the clipboard.\n");
			printf("-e\tClear what's in the clipboard.\n");
			printf("-h\tPrint this message.\n");
			return 0;
		}
		else {
			printf("\nNot a valid option, exiting...\n");
			return 1;
		}
	}
}