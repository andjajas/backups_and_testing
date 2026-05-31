#include "gnl.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	// Open a text file in read-only mode
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open file.\n");
		return (1);
	}
	
	line_count = 1;
	// Loop until get_next_line returns NULL (End of File or Error)
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line [%d]: %s", line_count, line);
		free(line); // CRITICAL: You must free the memory allocated by GNL
		line_count++;
	}

	close(fd);
	return (0);
}
