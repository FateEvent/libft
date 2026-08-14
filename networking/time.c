#include "networking.h"

long double	timeval_tolong(struct timeval *time)
{
	long double	sec;
	long double	usec;

	sec = time->tv_sec;
	usec = time->tv_usec;
	return (sec * 1000 + usec / 1000);
}

long double	length_diff(long double present, long double past)
{
	return (present - past);
}

long double	get_the_time(void)
{
	struct timeval	now;
	long double		sec;
	long double		usec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec;
	usec = now.tv_usec;
	return (sec * 1000 + usec / 1000);
}

void	countdown(struct timeval *start, long duration)
{
	long	sec;
	long	usec;
	long	time;

	gettimeofday(start, NULL);
	sec = start->tv_sec;
	usec = start->tv_usec;
	time = sec * 1000 + usec / 1000;
	while (length_diff(get_the_time(), time) <= duration)

		;
}
