// setaffin.c -- a wrapper program to set CPU affinity.

#include <windows.h> 
 
int usage(void);
int main(int argc, char* argv[])
{


	HANDLE Process = GetCurrentProcess();	
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcInfo;
	char CmdLine[1024] = "";
	int arg;

	if (argc == 1) {
		usage();
		return 0;
	}

	// There must be a nicer way of getting the command-line
	// all into a nice string, but I dont' know it.  Wish it
	// were sane to write this in Perl instead.
	for (arg = 1; arg < argc; arg++) {
		strcat (CmdLine, argv[arg]);
		strcat (CmdLine, " ");
	}

	printf("\nGetting Startup Info structure.\n");
	GetStartupInfo(&StartupInfo);

	printf ("Setting affinity mask to CPU 0...");
	if (SetProcessAffinityMask( Process, 1)) {
		printf(" succees.\n");
	}
	else {
		printf(" FAILED.\n");
		printf("Please submit a detailed bug report.\n\n");
		return 0;
	}

	

	printf ("Now Launching %s...", CmdLine);
	if (CreateProcess( NULL, CmdLine, NULL, NULL, 0, 0,
			NULL, NULL, &StartupInfo, &ProcInfo)) {
		printf(" success.\n"); 
		return 1;
	}
	else {
		printf(" FAILED.\n");
		printf("Check your command-line for errors.\n\n");
		printf("If you believe it should have worked, please submit a detailed bug report.\n");
		return 0;
	}

}

int usage (void)
{
	printf ("\nUsage:  setaffin <program> <arguments>\n\n");
	return 0;
}
