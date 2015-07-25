/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

/*
 * This function captures the terminal output into a file instead of terminal,
 * then resets output to terminal before ending.
 * Note : ft_printf always get written to the file first no matter if called
 * after printf in the code. This needs to be investigated.
 * For now, let's just make sure to call ft_printf first in every test run.
*/
int	capture_example(char *str)
{
	int		i;
	FILE	*fp;

	i = 0;

	ft_printf("ft_printf test %d, s = ""%s""\n", i, str);
	printf("printf test %d, s = ""%s""\n", i, str);
	i++;
	if (!(fp = freopen("file1.txt", "w", stdout)))
		printf("<< ERROR >> freopen() FAIL\n");
	
	ft_printf("ft_printf test %d, s = ""%s""\n", i, str);
	printf("print test %d, s = ""%s""\n", i, str);
	i++;
	
	if (!(fp = freopen("/dev/tty", "w", stdout)))
		printf("<< ERROR >> freopen() FAIL\n");

	ft_printf("ft_printf test %d, s = ""%s""\n", i, str);
	printf("printf test %d, s = ""%s""\n", i, str);
	i++;
	
	return (0);
}

/*
 * This fuction should give a similar result but in addition should react correctly
 * when the program is piped.
 * However, it doesn't work as intended. printf() and fprintf() don't react the
 * same way.
*/
int	capture_pipecompatible(void)
{
	int		old_stdout;
	FILE	*fp1;
	FILE	*fp2;

//	Save the original stdout file descriptor
	old_stdout = dup(1);

	printf("Capture test init, string 0 (stdout)\n");
	ft_printf("ft_printf() test\n");

//	Redirect stdout to file1.txt, close the original stream, return the file stream
	if (!(fp1 = freopen("file1.txt", "w", stdout)))
		printf("Error in freopen()\n");
	
	printf("Capture test 1, string 1 (captured)\n");
	ft_printf("Capture test 1 bis, string 1 (captured)\n");

//	Generate original stream from old_stdout file descriptor
	if (!(fp2 = fdopen(old_stdout, "w")))
		printf("Error in fopen()\n");

	printf("Capture test 2, string 2 (after fdopen())\n");
	ft_printf("Capture test 2 bis, string 2 (after fdopen())\n");

//	Close the stream associated with file1.txt
	if (fclose(stdout))
		printf("Error in fclose()\n");

	printf("Capture test 3, string 3 (after fclose())\n");
	ft_printf("Capture test 3 bis, string 3 (after fclose())\n");

//	Re-associate stdout to the original stream
	*stdout = *fp2;

	printf("Capture test 4, string 4 (after reassociate)\n");
	ft_printf("Capture test 4 bis, string 4 (after reassociate)\n");

//	Close the original file descriptor (required for piping to work sanely)
	if (close(old_stdout))
		printf("Error in close()\n");

	printf("Capture test 5, string 5 (after close())\n");
	printf("Capture test 5 bis, string 5 (after close())\n");
	
	return (0);
}


