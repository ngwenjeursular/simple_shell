/**
* _strcmp - compare the first string with second string.
* @s1: shows first string
* @s2: shows second string
* Return: 0 if they are equal, another number if not
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, cp = 0;

	while (cp == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		cp = *(s1 + i) - *(s2 + i);
		i++;
	}
	return (cp);
}

/**
 * _isalpha - Shows 1 if the input is a
 * letter Another cases, shows 0
 *
 * @c: The character in ASCII code
 *
 * Return: 1 for letters. 0 for the rest.
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}

/**
* reverse_array - reverse the content of an array
* @a: array
* @n: number of elements of the array
* Return: no return
*/
void reverse_array(int *a, int n)
{
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		/*Swap elements at left and right indices*/
		int temp = a[left];

		a[left] = a[right];
		a[right] = temp;

		left++;
		right--;
	}
}
/**
 * intlen - Determine Length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
* _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
