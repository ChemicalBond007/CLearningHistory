#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int y, f;
	int found = 0;
	for (f = 0; f < 100; f++)
	{
		if (98 * f - n >= 0)
		{
			if ((98 * f - n) % 199 == 0)
			{
				y = (98 * f - n) / 199;
				if (y >= 0 && y < 100)
				{
					printf("%d.%02d\n", y, f);
					found = 1;
					break;
				}
			}
		}
	}
	if (!found)
	{
		printf("No Solution\n");
	}
	return 0;
}