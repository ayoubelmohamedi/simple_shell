/**
 * _WIFEXITED - holds the last error status
 * @status: to affect
 *
 * Return: status
*/
int _WIFEXITED(int status)
{
	return ((status & 0x7F) == 0);
}
