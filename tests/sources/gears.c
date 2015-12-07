/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gears.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:41:10 by amulin            #+#    #+#             */
/*   Updated: 2015/12/07 14:41:12 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

/*
 * Load the full content of a file into a char*
*/
char	*file_to_str(char *filename)
{
	char		*buf;
	char		*str;
	int			fd;
	int			gnlret;

	buf = ft_strnew(10);
	str = ft_strnew(1);

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putendl("<< ERROR >> file_to_str() : open() fail");
		exit(1);
	}
	while ((gnlret = get_next_line(fd, &buf)))
	{
		str = ft_strjoin(str, buf);
		if (gnlret < 0)
		{
			ft_putendl("<< ERROR >> file_to_str() : gnl() fail");
			exit(1);
		}
	}
	if (close(fd))
	{
		ft_putendl("<< ERROR >> file_to_str() : close() fail");
		exit(1);
	}
//	ft_putendl(str);
	return (str);
}


/*
 * Compare the full content of both .txt files
*/
int	compare(char *file1, char *file2)
{
	char	*buf1;
	char	*buf2;
	int		ret;

	if (!file1 || !file2)
		return (-1);
	buf1 = file_to_str(file1);

//	printf("buf1 = %s\n", buf1);

	buf2 = file_to_str(file2);

//	printf("buf2 = %s\n", buf2);

	ret = ft_strcmp(buf1, buf2);
	return (ret != 0);
}


/*
 * Redirect stream to a file named after the filename parameter, 
 * and check of error.
*/

FILE	*hijack_stream(char *filename, FILE *stream)
{
	FILE	*fp;

	if (!(fp = freopen(filename, "w", stream)))
	{
		printf("<< ERROR >> redirect_stream : failed to redirect stream to '%s'\n",
				filename);
		return (NULL);
	}
	return (fp);
}

/*
 * This function is designed to output one string including one converted arg to
 * the print function pointer passed to it, supposedly printf() or ft_printf()
*/
int	pass_and_print(int (*printfn)(const char * restrict, ...),
		char *str, void *arg, char *type)
{
	if (!ft_strcmp(type, "int"))
		printfn(str, *(int*)arg);
	else if (!ft_strcmp(type, "char"))
		printfn(str, *(char*)arg);
	else if (!ft_strcmp(type, "none"))
		printfn(str);
	else if (!ft_strcmp(type, "str"))
		printfn(str, (char*)arg);
	else
		return (1);
	return (0);
}

/*
 * Capture and compare the output of the string given in parameter.
 * Output from ft_printf() is stored into dummy.txt
 * Output from printf() is stored into reference.txt
 * Notice : stdout is not reset to terminal within this function, be careful
 * for future function output in calling function.
*/
int	capture_and_cmp(char *str, void *arg, char *type)
{
	char	*file1 = "dummy.txt";
	char	*file2 = "reference.txt";
	int		res;

	usleep(1000);
	if (!hijack_stream(file1, stdout))
		return (-1);
	if (pass_and_print(&ft_printf, str, arg, type))
		return (-2);

	if (!hijack_stream(file2, stdout))
		return (-1);
	if (pass_and_print(&(printf), str, arg, type))
		return (-2);
	
	reset_stdout();

	if ((res = compare(file1, file2)) < 0)
		printf("<< ERROR >> capture_and_cmp() : Error in compare() function return\n");
	return (res);
}

/*
 * Reset stdout to terminal
*/
int	reset_stdout(void)
{
	FILE	*fp;

	if (!(fp = freopen("/dev/tty", "w", stdout)))
	{
		printf("<< ERROR >> reset_stdout : freopen() FAIL");
		return (1);
	}
	return (0);
}


